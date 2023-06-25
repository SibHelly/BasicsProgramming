#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
// ��������� ������
struct animal
{
    char name[22]; // �������� ���������
    char area[20]; // �������� ��������� ����
    double money;  // ����� �� ���� �� ���� ����
};

void add(char *);    // �������� ������ � ����
void edit(char *);   // ������������� ������
void show(char *);   // ����������� ���������� �����
void search(char *); // ����� �������� � ���������� �������� � ������������ ����, ��� ����� ������� �� ������ ��������� � �����
void del(char *);    // ������� ������ �� �����

int main(int argc, char *argv[])
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "");
    char filename[50];
    int menu;
    // ���� ����� ����� ��� �������� ��� ��������
    if (argc > 1)
        strcpy(filename, argv[1]);
    else
    {
        puts("������� ��� �����:");
        gets(filename);
    }
    do
    {
        system("cls");
        puts("1. ���������� ������");
        puts("2. �������������� ������");
        puts("3. �������� �������");
        puts("4. �����");
        puts("5. �������� ������");
        puts("6. �����");
        scanf("%d%*c", &menu); // ���� ������ ��������
        switch (menu)          // ������� ����, ��� ������ �������, ������� ������������ ����� ������������
        {
        case 1:
            add(filename);
            break; // ������ ���������� ������
        case 2:
            edit(filename);
            break; // ������� �������������� ������
        case 3:
            show(filename);
            break; // �������� ��������� �������
        case 4:
            search(filename);
            break; // ������� ������ ���������� �������� � ������������ ��������� ���� ��� ������� �� ������������� ������� � �����
        case 5:
            del(filename); // ������� �������� ������ �� ��������� ����� ����� ������������� � ������ �������� ����
        }
    } while (menu != 6); // ���� menu ����� 6, ����������� ������ ���������
    return 0;
}

// ���������� ����� ������ (���� ������ � ��������)
struct animal input_individual(void)
{
    struct animal individual;
    char *ptmp;
    double itmp;
    char s[30];
    puts("�������� ���������:");
    // ���� �������� ��������� � ��������� ���� � ����������, ����������� ����� ����� enter
    fgets(individual.name, 22, stdin);
    ptmp = strchr(individual.name, '\n');
    if (ptmp)
        *ptmp = '\0';
    else
        while (getchar() != '\n')
            ;
    individual.name[0] = toupper(individual.name[0]); // ������ ������ ����� ���������
    puts("��������� ����:");
    fgets(individual.area, 20, stdin);
    ptmp = strchr(individual.area, '\n');
    if (ptmp)
        *ptmp = '\0';
    else
        while (getchar() != '\n')
            ;
    individual.area[0] = toupper(individual.area[0]); // ������ ������ ����� ���������
    puts("������� �� ���� �� ���� ����:");
    while (1)
    {
        scanf("%s%*c", s); // ������ ������� �� ����
        individual.money = atof(s);
        if (individual.money <= 0)
        {
            puts("������� ���������� ������� �� ���� �� ���� ����");
            fflush(stdin);
        }
        else
            break;
    }
    return individual; // ��������� ������
}
// ������� ���������� ������ � ����
void add(char *file)
{
    FILE *f;
    struct animal individual;
    system("CLS");
    char flag = 1, yes;
    if ((f = fopen(file, "ab")) == NULL)
    {
        perror("������ �������� �����");
        puts("��� �������� � ���� ������� Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    while (flag) // ��������� ������ ���� ����� �����
    {
        individual = input_individual();               // ��������� ���� ������ � ��������
        fwrite(&individual, sizeof(individual), 1, f); // ���������� � ����
        puts("�������� ������ ��� ��� �����? (y/e)");  // ���������� ���������� ������� ��� ���
        // �������, ���� ������ e, ��� ����������, ���� ������ y
        do
        {
            yes = getchar();
            getchar();
        } while (yes != 'y' && yes != 'Y' && yes != 'e' && yes != 'E');
        if (yes == 'y' || yes == 'Y')
        {
            flag = 1;
            system("cls");
        }
        if (yes == 'e' || yes == 'E')
        {
            flag = 0;
        }
    }
    fclose(f); // ��������� ����
    return;
}

// ������� ������ �� ����� ����� ������
void print_one(struct animal individual)
{
    printf("�������� ��������� : %s\n��������� ���� : %s\n������� �� ���� �� ���� ���� : %.3f\n",
           individual.name, individual.area, individual.money); // ����� �� ����� ����� ������
}

// ������� �������������� ������
void edit(char *file)
{
    FILE *f;
    unsigned int n_file;
    struct animal individual;
    char name[22], yes, flag = 1, count = 0;
    system("CLS");
    if ((f = fopen(file, "rb+")) == NULL)
    {
        perror("������ �������� �����");
        puts("��� �������� � ���� ������� Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    // ��������� �� ���� �� ����
    rewind(f);
    fseek(f, 0, SEEK_END);
    n_file = ftell(f) / sizeof(individual); /* ���������� ������� � ����� */
    fseek(f, 0, SEEK_SET);
    if (n_file == 0)
    {
        puts("���� ����, �������� ������, ����� �������������\n��� �������� � ���� ������� Enter");
        while (getchar() != '\n')
            ;
        fclose(f);
        return;
    }
    // ���� ���� �� ����, �� ������ ������ �������� ���������, ����� ������ �������������
    printf("�������� ���������:");
    fgets(name, 22, stdin);
    {
        char *ptmr = strchr(name, '\n');
        if (ptmr)
            *ptmr = '\0';
        else
            while (getchar() != '\n')
                ;
        name[0] = toupper(name[0]);
    }
    // ���� �������� � �����
    while (fread(&individual, sizeof(individual), 1, f))
        if (!strcmp(individual.name, name))
        {
            count++;                      // ������� ���������� ����� ���������
            print_one(individual);        // ���� ������� ������� �� �����
            puts("�������������? (y/n)"); // ���������� ���� �� �������������
            do
            {
                yes = getchar();
                getchar();
            } while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
            if (yes == 'y' || yes == 'Y') // ���� ��, �����������
            {
                individual = input_individual();
                fseek(f, -sizeof(individual), SEEK_CUR);
                fwrite(&individual, sizeof(individual), 1, f);
                fseek(f, 0, SEEK_CUR);
                flag = 1;
            }
            // ���� ��� ���������� �����
            if (yes == 'n' || yes == 'N')
            {
                continue;
                break;
            }
        }
    // ���� count=0, �� ������ ��������� ���
    if (count == 0)
        puts("������ ��������� ���");
    // ���� ������������ ����� ������������� ���������� �����
    while (flag)
    {
        count = 0; // �������� count, ��� �������� ������� ���������
        puts("���������� �����? (y/n)");
        do
        {
            yes = getchar();
            getchar();
        } while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
        if (yes == 'n' || yes == 'N') // ���� ������������ �� ����� ���������� ����� �� ������� �� ������ ��� ��������������
        {
            flag = 0;
            puts("����� ��������");
            break;
        }
        if (yes == 'Y' || yes == 'y') // ���� ������������ ����� ���������� �������������
        {
            system("cls");
            rewind(f);
            // ���� ��������
            printf("�������� ���������:");
            fgets(name, 22, stdin);
            {
                char *ptmr = strchr(name, '\n');
                if (ptmr)
                    *ptmr = '\0';
                else
                    while (getchar() != '\n')
                        ;
                name[0] = toupper(name[0]);
            }
            while (fread(&individual, sizeof(individual), 1, f))
                if (!strcmp(individual.name, name)) // ���� ����� ����������� ��� ���
                {
                    count++;
                    print_one(individual);
                    puts("�������������? (y/n)");
                    do
                    {
                        yes = getchar();
                        getchar();
                    } while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
                    if (yes == 'y' || yes == 'Y') // �����������
                    {
                        individual = input_individual();
                        fseek(f, -sizeof(individual), SEEK_CUR);
                        fwrite(&individual, sizeof(individual), 1, f);
                        fseek(f, 0, SEEK_CUR);
                        flag = 1;
                    }
                    if (yes == 'n' || yes == 'N') // ���������� ����� �� ������������ ���������� �����
                    {
                        continue;
                        break;
                    }
                }
            if (count == 0) // ���� �� ����� ��������
                puts("������ ��������� ���");
        }
    }
    puts("��� �������� � ���� ������� Enter");
    while (getchar() != '\n')
        ;
    fclose(f); // ��������� ����
    return;
}
// �������� ������ ����������� �����
void show(char *file)
{
    FILE *f;
    unsigned int n_file, n_str;
    char yes, s[30];
    struct animal individual;
    int k = 0, str = 1, n = 0, l = 0;
    system("CLS");
    if ((f = fopen(file, "rb")) == NULL)
    {
        perror("������ �������� �����");
        puts("��� �������� � ���� ������� Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    rewind(f);
    // ��������� �� ������ �� ����
    fseek(f, 0, SEEK_END);
    n_file = ftell(f) / sizeof(individual); /* ���������� ������� � ����� */
    fseek(f, 0, SEEK_SET);
    if (n_file == 0)
    {
        puts("���� ����, ��� ��������� �������� ������\n��� �������� � ���� ������� Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    while (n <= 0)
    {
        system("cls");
        printf("������� ���������� ������� �� ����� ��������: ");
        scanf("%s", s);
        n = atoi(s);
        if (n > 0)
        {
            getchar();
            puts("��� ��������� ������� Enter");
            while (getchar() != '\n')
                ;
            system("cls");
            break;
        }
    }
    // ������� ���������� ������� � �����
    n_str = n_file / n + 1;
    // ������� ��������� �������
    puts("|  N |  �������� ���������  |   ��������� ����   | ������� �� ���� �� ���� ���� |");
    puts("---------------------------------------------------------------------------------");
    // �������� ��������� ������ �� �����
    while (fread(&individual, sizeof(individual), 1, f) == 1)
    {
        printf("|%3d |%-22.22s|%-20.20s|%30.2f|\n", ++k, individual.name, individual.area, individual.money);
        // ���� ������ �������� � � ����� �� ���� ��������, ���������������� ����� ����� ������ ������ ���������� ������� ��� ����� ��������
        if (k % n == 0 && str == 1 && n_file > n)
        {
            puts("---------------------------------------------------------------------------------");
            printf("                                    %d                                          \n", str);
            puts("������ ��� �����? (f/e)");
            do
            {
                yes = getchar();
                getchar();
            } while (yes != 'f' && yes != 'F' && yes != 'e' && yes != 'E');
            if (yes == 'e' || yes == 'E')
                break;                    // ���� ����� ��������� ���������� ������� �� �����
            if (yes == 'f' || yes == 'F') // ���� �������� ��������
            {
                str++;         // ����������� ���������� �������
                system("Cls"); // ������� ����
                // ������� ����� �������
                puts("|  N |  �������� ���������  |   ��������� ����   | ������� �� ���� �� ���� ���� |");
                puts("---------------------------------------------------------------------------------");
            }
        }
        // ���� �� ������ � �� ��������� ��������
        if (str < n_str && str > 1 && k % n == 0 && k > n && k < n_file)
        {
            puts("---------------------------------------------------------------------------------");
            printf("                                    %d                                          \n", str);
            puts("������ ��� ����� ��� �����? (f/b/e)"); // ������� ������� ���� ��������� ��������
            do
            {
                yes = getchar();
                getchar();
            } while (yes != 'f' && yes != 'F' && yes != 'e' && yes != 'E' && yes != 'B' && yes != 'b');
            if (yes == 'e' || yes == 'E') // �����
                break;                    // ��������� ���������� ������� �� �����
            if (yes == 'f' || yes == 'F') // ������
            {
                str++;         // ����������� ���������� �������
                system("Cls"); // ������� ����
                // ������� �����
                puts("|  N |  �������� ���������  |   ��������� ����   | ������� �� ���� �� ���� ���� |");
                puts("---------------------------------------------------------------------------------");
            }
            if (yes == 'b' || yes == 'B') // ���� �����
            {
                str--;         // ��������� ���������� �������
                system("cls"); // ������� ����
                // ������� �����
                puts("|  N |  �������� ���������  |   ��������� ����   | ������� �� ���� �� ���� ���� |");
                puts("---------------------------------------------------------------------------------");
                k = k - 2 * n; // �������� �����, ��� ��� �� ����� ����������� ������ �� ��������, ��������� ��� �� ������ ����� ���������� ��������
                // �������� (k=20 - ��������� �� 2 �������� (���������� ������� �� �������� ����� 10) ������� �������� 20, � ��� ������ k ������ ����� 1(��� ��� ++k))
                fseek(f, -2 * n * sizeof(individual), SEEK_CUR); // ���������, ����� ��� ������ ������� �� ����� �� ���� ���������� �������
            }
        }
        if (k == n_file) // ���� k ����� ����� ���������� ������� � �����, ������ �������� ����� �����
        {
            puts("---------------------------------------------------------------------------------");
            printf("                                    %d                                          \n", str);
            if (n_str > 1 && k > n) // ������� ��� ��������� ��������
            {
                puts("����� ��� �����? (b/e)");
                do
                {
                    yes = getchar();
                    getchar();
                } while (yes != 'e' && yes != 'E' && yes != 'B' && yes != 'b');
                if (yes == 'e' || yes == 'E') // ������� �� ������
                    break;
                if (yes == 'b' || yes == 'B') // �������� �����
                {
                    str--;
                    l = k - n * str; // ������� �� ������� ���� �� ������ ������ �� ��������
                    system("cls");   // ������� ����
                    puts("|  N |  �������� ���������  |   ��������� ����   | ������� �� ���� �� ���� ���� |");
                    puts("---------------------------------------------------------------------------------");
                    k = k - n - l;                                     // ������ ������ ����� �� ���������� ��������
                    fseek(f, -(n + l) * sizeof(individual), SEEK_CUR); // ��������� ����� ������ �� ������ ������ �� ���������� ��������
                }
            }
            else // ���� ���������� ������� ����� 1
            {
                if (k < n || k == n)
                {
                    puts("�����? (e)"); // ������ ����������� ������
                    do
                    {
                        yes = getchar();
                        getchar();
                    } while (yes != 'e' && yes != 'E');
                    if (yes == 'e' || yes == 'E')
                        break;
                }
            }
        }
    }
    fclose(f);
    return;
}

// ������� ������ ������
void search(char *file)
{
    FILE *f;
    unsigned int n_file;
    struct animal individual;
    double money;
    char area[20], name[22], yes, flag = 1;
    system("CLS");
    int count = 0, k;
    if ((f = fopen(file, "rb")) == NULL)
    {
        perror("������ �������� �����");
        puts("��� �������� � ���� ������� Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    fseek(f, 0, SEEK_END);
    n_file = ftell(f) / sizeof(individual); /* ���������� ������� � ����� */
    fseek(f, 0, SEEK_SET);
    if (n_file == 0)
    {
        puts("���� ����, �������� ������, ����� ������ ���-����\n��� �������� � ���� ������� Enter");
        while (getchar() != '\n')
            ;
        fclose(f);
        return;
    }
    rewind(f);
    while (flag) // ����� ������ ������� ���, ������� ����� ������������
    {
        count = 0;
        k = 0;
        rewind(f);
        printf("A:������ ���������� �������� � ��������� ������������ ����?\nB:������ ������� �� ������������� ��������� � �����?\nE:�����?\n(a/b/e)\n");
        do
        {
            yes = getchar();
            getchar();
        } while (yes != 'a' && yes != 'A' && yes != 'b' && yes != 'B' && yes != 'e' && yes != 'E');
        {
            if (yes == 'e' || yes == 'E') // ���� ������������ ����� �����
            {
                flag = 0;
                break; // ��������� �����
            }
            if (yes == 'a' || yes == 'A') // ���� ����� ������ ���������� �������� � ������������ ����
            {
                puts("�������� ��������� ����");
                // ���� �������� ��������� ����
                fgets(area, 20, stdin);
                {
                    char *ptmr = strchr(area, '\n');
                    if (ptmr)
                        *ptmr = '\0';
                    else
                        while (getchar() != '\n')
                            ;
                    area[0] = toupper(area[0]);
                }
                // ��������� �� ����� � ������� ����������
                while (fread(&individual, sizeof(individual), 1, f))
                    if (!strcmp(individual.area, area))
                    {
                        count++; // ������� ���������� �������� � ��������� ����
                    }
                if (count == 0)
                    puts("�������� � ���� ��������� ���� ��� ��� ����� ��������� ���� ���");
                else
                    printf("���������� �������� � ���� ��������� ���� - %d\n", count);
            }
            if (yes == 'B' || yes == 'b') // ���� ����� ������� �� ������������� ��������� � �����
            {
                printf("�������� ���������:");
                fgets(name, 22, stdin);
                {
                    char *ptmr = strchr(name, '\n');
                    if (ptmr)
                        *ptmr = '\0';
                    else
                        while (getchar() != '\n')
                            ;
                    name[0] = toupper(name[0]);
                }
                while (fread(&individual, sizeof(individual), 1, f))
                    if (!strcmp(individual.name, name))
                        count++;
                // ���� ��� ������ ���������
                if (count == 0)
                    puts("������ ��������� ���");
                rewind(f);
                while (fread(&individual, sizeof(individual), 1, f))
                {
                    ++k;
                    if (!strcmp(individual.name, name))
                    {
                        printf("����� ������: %d \n", k);
                        // ������� ��������
                        print_one(individual);
                        money = individual.money * 30;
                        printf("����� �� �����: %.3lf\n", money);
                    }
                }
            }
        }
        puts("���������� �����? (y/n)"); // ���������� ����� ���� ������������ �����
        do
        {
            yes = getchar();
            getchar();
        } while (yes != 'Y' && yes != 'y' && yes != 'N' && yes != 'n'); // ���� ����� ���������� �����, �� ������� ���� ��� ����� ��������� ����
        if (yes == 'n' || yes == 'N')                                   // ���� ������������ �� ����� ���������� �����
        {
            puts("�� ������� ��� ������ �����? (y/n)");
            do
            {
                yes = getchar();
                getchar();
            } while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
            if (yes == 'y' || yes == 'Y') // ���� ����� ����� ��������� ���� � �������
            {
                flag = 0;
                break;
            }
            if (yes == 'n' || yes == 'N')
                system("cls");
        }
        if (yes == 'y' || yes == 'Y')
            system("cls");
    }
    fclose(f);
    return;
}

/* ������� �������� ������ �� ����� */
void del(char *file)
{
    FILE *f1, *f2;
    unsigned int n, n_file, i;
    struct animal individual;
    char yes;
    system("CLS");
    if ((f1 = fopen(file, "rb+")) == NULL)
    {
        perror("������ �������� �����");
        puts("��� �������� � ���� ������� Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    fseek(f1, 0, SEEK_END);
    n_file = ftell(f1) / sizeof(individual); /* ���������� ������� � ����� */
    // ��������� ���� �� �������
    if (n_file == 0)
    {
        fclose(f1);
        puts("���� ����\n��� �������� � ���� ������� Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    // ���� ���� �� ������
    puts("����� ��������� ������?");
    scanf("%u%*c", &n);
    // ��������� ���� �� ����� ���������� ����� � �����
    if (n > n_file || !n)
    {
        puts("������������ �����\n\n��� �������� � ���� ������� Enter");
        while (getchar() != '\n')
            ;
        fclose(f1); // ���� ��� �� ��������� ����� � ��������� ����
        return;
    }
    // ���� ���� ����� ���������� �����
    fseek(f1, (n - 1) * sizeof(individual), SEEK_SET); /* ������������� � ��������� ������ */
    fread(&individual, sizeof(individual), 1, f1);
    // ������� �� �� �����
    print_one(individual);
    puts("\n�������? (y/n)");
    do
    {
        yes = getchar();
        getchar();
    } while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
    if (yes == 'n' || yes == 'N') // ���� ������������ �� ����� �������
    {
        // ���������
        fclose(f1);
        puts("�������� ��������\n\n��� �������� � ���� ������� Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    // ���� ������������ ����� �������
    /* �������� ������������ �������������� ���� �������, ����� ���������, � ����� ���� */
    rewind(f1);
    if ((f2 = fopen("temp", "wb")) == NULL) // ������� ����� ����
    {
        perror("������ �������� �����");
        puts("��� �������� � ���� ������� Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    i = 0;
    // ��������� � ������������ ��� ������ ����� ���������� � ����� ����
    while (fread(&individual, sizeof(individual), 1, f1) == 1)
    {
        if (++i != n)
            fwrite(&individual, sizeof(individual), 1, f2);
    }
    // ��������� �����, ������� ������ ����, ��������������� ������ ���� ��� ��������� ������
    fclose(f1);
    fclose(f2);
    remove(file);
    rename("temp", file);
    puts("������ �������\n\n��� �������� � ���� ������� Enter");
    while (getchar() != '\n')
        ;
}
