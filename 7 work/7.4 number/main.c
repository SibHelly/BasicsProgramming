#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
// структура записи
struct animal
{
    char name[22]; // название животного
    char area[20]; // название природной зоны
    double money;  // затра на корм за один день
};

void add(char *);    // добавить запись в файл
void edit(char *);   // редактировать запись
void show(char *);   // просмотреть содержимое файла
void search(char *); // найти сведения о количестве животных в определенной зоне, или найти затраты на одного животного в месяц
void del(char *);    // удалить запись из файла

int main(int argc, char *argv[])
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "");
    char filename[50];
    int menu;
    // ввод имени файла для открытия или создания
    if (argc > 1)
        strcpy(filename, argv[1]);
    else
    {
        puts("Введите имя файла:");
        gets(filename);
    }
    do
    {
        system("cls");
        puts("1. Добавление записи");
        puts("2. Редактирование записи");
        puts("3. Просмотр записей");
        puts("4. Поиск");
        puts("5. Удаление записи");
        puts("6. Выход");
        scanf("%d%*c", &menu); // ввод номера действия
        switch (menu)          // система меню, для выбора функции, которую пользователь хочет использовать
        {
        case 1:
            add(filename);
            break; // функця добавления записи
        case 2:
            edit(filename);
            break; // функция редактирования записи
        case 3:
            show(filename);
            break; // функиция просмотра записей
        case 4:
            search(filename);
            break; // функция поиска количества животных в определенной природной зоне или затраты на определенного животно в месяц
        case 5:
            del(filename); // функция удаления записи из бинарного файла путем переписывания в другой бинарный файл
        }
    } while (menu != 6); // если menu равно 6, заканчиваем работу программы
    return 0;
}

// заполнение одной записи (ввод данных о животном)
struct animal input_individual(void)
{
    struct animal individual;
    char *ptmp;
    double itmp;
    char s[30];
    puts("Название животного:");
    // ввод названия животного и природной зоны с клавиатуры, прерывается когда нажат enter
    fgets(individual.name, 22, stdin);
    ptmp = strchr(individual.name, '\n');
    if (ptmp)
        *ptmp = '\0';
    else
        while (getchar() != '\n')
            ;
    individual.name[0] = toupper(individual.name[0]); // делаем первую букву заглавной
    puts("Природная зона:");
    fgets(individual.area, 20, stdin);
    ptmp = strchr(individual.area, '\n');
    if (ptmp)
        *ptmp = '\0';
    else
        while (getchar() != '\n')
            ;
    individual.area[0] = toupper(individual.area[0]); // делаем первую букву заглавной
    puts("Затраты на корм за один день:");
    while (1)
    {
        scanf("%s%*c", s); // вводим затраты на день
        individual.money = atof(s);
        if (individual.money <= 0)
        {
            puts("Введите корректные затраты на корм за один день");
            fflush(stdin);
        }
        else
            break;
    }
    return individual; // возращаем запись
}
// функция добавления записи в файл
void add(char *file)
{
    FILE *f;
    struct animal individual;
    system("CLS");
    char flag = 1, yes;
    if ((f = fopen(file, "ab")) == NULL)
    {
        perror("Ошибка открытия файла");
        puts("Для возврата в меню нажмите Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    while (flag) // добавляем записи пока этого хотим
    {
        individual = input_individual();               // заполняем одну запись о животном
        fwrite(&individual, sizeof(individual), 1, f); // записываем в файл
        puts("Добавить запись еще или выйти? (y/e)");  // Спрашиваем продолжать вводить или нет
        // выходим, если нажали e, или продолжаем, если нажали y
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
    fclose(f); // закрываем файл
    return;
}

// функция вывода на экран одной записи
void print_one(struct animal individual)
{
    printf("Название животного : %s\nПриродная зона : %s\nЗатраты на корм за один день : %.3f\n",
           individual.name, individual.area, individual.money); // вывод на экран одной записи
}

// функция редактирования записи
void edit(char *file)
{
    FILE *f;
    unsigned int n_file;
    struct animal individual;
    char name[22], yes, flag = 1, count = 0;
    system("CLS");
    if ((f = fopen(file, "rb+")) == NULL)
    {
        perror("Ошибка открытия файла");
        puts("Для возврата в меню нажмите Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    // проверяем не пуст ли файл
    rewind(f);
    fseek(f, 0, SEEK_END);
    n_file = ftell(f) / sizeof(individual); /* количество записей в файле */
    fseek(f, 0, SEEK_SET);
    if (n_file == 0)
    {
        puts("Файл пуст, добавьте записи, чтобы редактировать\nДля возврата в меню нажмите Enter");
        while (getchar() != '\n')
            ;
        fclose(f);
        return;
    }
    // если файл не пуст, то просим ввести название животного, чтобы начать редактировать
    printf("Название животного:");
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
    // ищем животное в файле
    while (fread(&individual, sizeof(individual), 1, f))
        if (!strcmp(individual.name, name))
        {
            count++;                      // считаем количество этого животного
            print_one(individual);        // если нашлось выводим на экран
            puts("Редактировать? (y/n)"); // спрашиваем надо ли редактировать
            do
            {
                yes = getchar();
                getchar();
            } while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
            if (yes == 'y' || yes == 'Y') // если да, редактируем
            {
                individual = input_individual();
                fseek(f, -sizeof(individual), SEEK_CUR);
                fwrite(&individual, sizeof(individual), 1, f);
                fseek(f, 0, SEEK_CUR);
                flag = 1;
            }
            // если нет продолжаем поиск
            if (yes == 'n' || yes == 'N')
            {
                continue;
                break;
            }
        }
    // если count=0, то такого животного нет
    if (count == 0)
        puts("Такого животного нет");
    // пока пользователь хочет редактировать продолжаем поиск
    while (flag)
    {
        count = 0; // обнуляем count, для проверки наличия животного
        puts("Продолжить поиск? (y/n)");
        do
        {
            yes = getchar();
            getchar();
        } while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
        if (yes == 'n' || yes == 'N') // если пользователь не хочет продолжать поиск то выходим из поиска для редактирования
        {
            flag = 0;
            puts("Поиск завершен");
            break;
        }
        if (yes == 'Y' || yes == 'y') // если пользователь хочет продолжить редактировать
        {
            system("cls");
            rewind(f);
            // ищем животное
            printf("Название животного:");
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
                if (!strcmp(individual.name, name)) // если нашли редактируем или нет
                {
                    count++;
                    print_one(individual);
                    puts("Редактировать? (y/n)");
                    do
                    {
                        yes = getchar();
                        getchar();
                    } while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
                    if (yes == 'y' || yes == 'Y') // редактируем
                    {
                        individual = input_individual();
                        fseek(f, -sizeof(individual), SEEK_CUR);
                        fwrite(&individual, sizeof(individual), 1, f);
                        fseek(f, 0, SEEK_CUR);
                        flag = 1;
                    }
                    if (yes == 'n' || yes == 'N') // спрашиваем хочет ли пользователь продолжить поиск
                    {
                        continue;
                        break;
                    }
                }
            if (count == 0) // если не нашли животное
                puts("Такого животного нет");
        }
    }
    puts("Для возврата в меню нажмите Enter");
    while (getchar() != '\n')
        ;
    fclose(f); // закрываем файл
    return;
}
// функкция печати содержимого файла
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
        perror("Ошибка открытия файла");
        puts("Для возврата в меню нажмите Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    rewind(f);
    // проверяем не пустой ли файл
    fseek(f, 0, SEEK_END);
    n_file = ftell(f) / sizeof(individual); /* количество записей в файле */
    fseek(f, 0, SEEK_SET);
    if (n_file == 0)
    {
        puts("Файл пуст, для просмотра добавьте записи\nДля возврата в меню нажмите Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    while (n <= 0)
    {
        system("cls");
        printf("Введите количество записей на одной странице: ");
        scanf("%s", s);
        n = atoi(s);
        if (n > 0)
        {
            getchar();
            puts("Для просмотра нажмите Enter");
            while (getchar() != '\n')
                ;
            system("cls");
            break;
        }
    }
    // считаем количество страниц в файле
    n_str = n_file / n + 1;
    // выводим заголовок таблицы
    puts("|  N |  Название животного  |   Природная зона   | Затраты на корм за один день |");
    puts("---------------------------------------------------------------------------------");
    // начинаем считывать записи из файла
    while (fread(&individual, sizeof(individual), 1, f) == 1)
    {
        printf("|%3d |%-22.22s|%-20.20s|%30.2f|\n", ++k, individual.name, individual.area, individual.money);
        // если первая страница и в файле не одна страница, приостанавливаем вывод когда вывели нужное количество записей для одной странциы
        if (k % n == 0 && str == 1 && n_file > n)
        {
            puts("---------------------------------------------------------------------------------");
            printf("                                    %d                                          \n", str);
            puts("Вперед или выход? (f/e)");
            do
            {
                yes = getchar();
                getchar();
            } while (yes != 'f' && yes != 'F' && yes != 'e' && yes != 'E');
            if (yes == 'e' || yes == 'E')
                break;                    // если выход прерываем считывание записей из файла
            if (yes == 'f' || yes == 'F') // если следущая страница
            {
                str++;         // увеличиваем количество страниц
                system("Cls"); // очищаем поле
                // выводим шапку таблицы
                puts("|  N |  Название животного  |   Природная зона   | Затраты на корм за один день |");
                puts("---------------------------------------------------------------------------------");
            }
        }
        // если не первая и не последняя страница
        if (str < n_str && str > 1 && k % n == 0 && k > n && k < n_file)
        {
            puts("---------------------------------------------------------------------------------");
            printf("                                    %d                                          \n", str);
            puts("Вперед или Назад или выход? (f/b/e)"); // выводим наличие трех вариантов действий
            do
            {
                yes = getchar();
                getchar();
            } while (yes != 'f' && yes != 'F' && yes != 'e' && yes != 'E' && yes != 'B' && yes != 'b');
            if (yes == 'e' || yes == 'E') // выход
                break;                    // прерываем считывание записей из файла
            if (yes == 'f' || yes == 'F') // вперед
            {
                str++;         // увеличиваем количество страниц
                system("Cls"); // очищаем поле
                // выводим шапку
                puts("|  N |  Название животного  |   Природная зона   | Затраты на корм за один день |");
                puts("---------------------------------------------------------------------------------");
            }
            if (yes == 'b' || yes == 'B') // если назад
            {
                str--;         // уменьшаем количество страниц
                system("cls"); // очищаем поле
                // выводим шапку
                puts("|  N |  Название животного  |   Природная зона   | Затраты на корм за один день |");
                puts("---------------------------------------------------------------------------------");
                k = k - 2 * n; // изменяем номер, так как он равен последенему номеру на странице, переносим его на первый номер предыдущей страницы
                // например (k=20 - последний на 2 странице (количество записей на странице равно 10) поэтому вычитаем 20, и при выводе k станет равно 1(так как ++k))
                fseek(f, -2 * n * sizeof(individual), SEEK_CUR); // переносим, точку для чтения записей из файла на тоже количество записей
            }
        }
        if (k == n_file) // если k стало равно количеству записей в файле, значит достигли конца файла
        {
            puts("---------------------------------------------------------------------------------");
            printf("                                    %d                                          \n", str);
            if (n_str > 1 && k > n) // выводим два возможных действия
            {
                puts("Назад или выход? (b/e)");
                do
                {
                    yes = getchar();
                    getchar();
                } while (yes != 'e' && yes != 'E' && yes != 'B' && yes != 'b');
                if (yes == 'e' || yes == 'E') // выходим из чтения
                    break;
                if (yes == 'b' || yes == 'B') // вывходим назад
                {
                    str--;
                    l = k - n * str; // узнаеам на сколько ушло от первой записи на странице
                    system("cls");   // очищаем поле
                    puts("|  N |  Название животного  |   Природная зона   | Затраты на корм за один день |");
                    puts("---------------------------------------------------------------------------------");
                    k = k - n - l;                                     // узнаем первый номер на предыдущей странице
                    fseek(f, -(n + l) * sizeof(individual), SEEK_CUR); // переносим точку чтения на первую запись на предыдущей странице
                }
            }
            else // если количество страниц равно 1
            {
                if (k < n || k == n)
                {
                    puts("Выход? (e)"); // делаем возможность выхода
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

// функция поиска записи
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
        perror("Ошибка открытия файла");
        puts("Для возврата в меню нажмите Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    fseek(f, 0, SEEK_END);
    n_file = ftell(f) / sizeof(individual); /* количество записей в файле */
    fseek(f, 0, SEEK_SET);
    if (n_file == 0)
    {
        puts("Файл пуст, добавьте записи, чтобы искать что-либо\nДля возврата в меню нажмите Enter");
        while (getchar() != '\n')
            ;
        fclose(f);
        return;
    }
    rewind(f);
    while (flag) // будет искать столько раз, сколько хочет пользователь
    {
        count = 0;
        k = 0;
        rewind(f);
        printf("A:Узнать количество животных в природной определенной зоне?\nB:Узнать затраты на определенного животного в месяц?\nE:Выход?\n(a/b/e)\n");
        do
        {
            yes = getchar();
            getchar();
        } while (yes != 'a' && yes != 'A' && yes != 'b' && yes != 'B' && yes != 'e' && yes != 'E');
        {
            if (yes == 'e' || yes == 'E') // если пользователь нажал выход
            {
                flag = 0;
                break; // прерываем поиск
            }
            if (yes == 'a' || yes == 'A') // если хочет узнать количество животных в определенной зоне
            {
                puts("Название природной зоны");
                // ввод названия природной зоны
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
                // считываем из файла и считаем количество
                while (fread(&individual, sizeof(individual), 1, f))
                    if (!strcmp(individual.area, area))
                    {
                        count++; // считаем количество животных в природной зоне
                    }
                if (count == 0)
                    puts("Животных в этой природной зоне нет или такой природной зоны нет");
                else
                    printf("Количество животных в этой природной зоне - %d\n", count);
            }
            if (yes == 'B' || yes == 'b') // если найти затраты на определенного животного в месяц
            {
                printf("Название животного:");
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
                // если нет такого животного
                if (count == 0)
                    puts("Такого животного нет");
                rewind(f);
                while (fread(&individual, sizeof(individual), 1, f))
                {
                    ++k;
                    if (!strcmp(individual.name, name))
                    {
                        printf("Номер записи: %d \n", k);
                        // выводим сведения
                        print_one(individual);
                        money = individual.money * 30;
                        printf("Траты за месяц: %.3lf\n", money);
                    }
                }
            }
        }
        puts("Продолжить поиск? (y/n)"); // продолажем поиск пока пользователь хочет
        do
        {
            yes = getchar();
            getchar();
        } while (yes != 'Y' && yes != 'y' && yes != 'N' && yes != 'n'); // если хочет продолжить поиск, то выводим меню для выбоа ключевого поля
        if (yes == 'n' || yes == 'N')                                   // если пользователь не хочет продолжать поиск
        {
            puts("Вы уверены что хотите выйти? (y/n)");
            do
            {
                yes = getchar();
                getchar();
            } while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
            if (yes == 'y' || yes == 'Y') // если хочет выйти закрываем файл и выходим
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

/* функция удаления записи из файла */
void del(char *file)
{
    FILE *f1, *f2;
    unsigned int n, n_file, i;
    struct animal individual;
    char yes;
    system("CLS");
    if ((f1 = fopen(file, "rb+")) == NULL)
    {
        perror("Ошибка открытия файла");
        puts("Для возврата в меню нажмите Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    fseek(f1, 0, SEEK_END);
    n_file = ftell(f1) / sizeof(individual); /* количество записей в файле */
    // проверяем файл на пустоту
    if (n_file == 0)
    {
        fclose(f1);
        puts("Файл пуст\nДля возврата в меню нажмите Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    // если файл не пустой
    puts("Номер удаляемой записи?");
    scanf("%u%*c", &n);
    // проверяем есть ли такой порядковый номер в файле
    if (n > n_file || !n)
    {
        puts("Некорректный номер\n\nДля возврата в меню нажмите Enter");
        while (getchar() != '\n')
            ;
        fclose(f1); // если нет то прерываем поиск и закрываем файл
        return;
    }
    // если есть такой порядковый номер
    fseek(f1, (n - 1) * sizeof(individual), SEEK_SET); /* переместиться к удаляемой записи */
    fread(&individual, sizeof(individual), 1, f1);
    // вывести ее на экран
    print_one(individual);
    puts("\nУдалить? (y/n)");
    do
    {
        yes = getchar();
        getchar();
    } while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
    if (yes == 'n' || yes == 'N') // если пользователь не хочет удалять
    {
        // завершаем
        fclose(f1);
        puts("Удаление отменено\n\nДля возврата в меню нажмите Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    // если пользователь хочет удалить
    /* удаление производится переписыванием всех записей, кроме удаляемой, в новый файл */
    rewind(f1);
    if ((f2 = fopen("temp", "wb")) == NULL) // создаем новый файл
    {
        perror("Ошибка открытия файла");
        puts("Для возврата в меню нажмите Enter");
        while (getchar() != '\n')
            ;
        return;
    }
    i = 0;
    // считываем и переписываем все записи кроме удаляемовй в новый файл
    while (fread(&individual, sizeof(individual), 1, f1) == 1)
    {
        if (++i != n)
            fwrite(&individual, sizeof(individual), 1, f2);
    }
    // закрываем файлы, удаляем старый файл, переименовываем новыый файл без удаляемой записи
    fclose(f1);
    fclose(f2);
    remove(file);
    rename("temp", file);
    puts("Запись удалена\n\nДля возврата в меню нажмите Enter");
    while (getchar() != '\n')
        ;
}
