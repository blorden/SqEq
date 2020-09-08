#include <stdio.h>
#include <assert.h>
#include <locale.h>
#include <stdbool.h>

/*
    Эта программа представляет собой набор юнит-тестов.

    При вызове программа принимает следующий аргумент:

    (без аргумента)     запуск всевозможных юнит-тестов.
    0                   запуск юнит-теста, при котором квадратное уравнение не должно иметь корней.
    1                   запуск юнит-теста, при котором квадратное уравнение должно иметь один корень.
    2                   запуск юнит-теста, при котором квадратное уравнение должно иметь два корня.
    inf                 запуск юнит-теста, при котором квадратное уравнение должно иметь бесконечно много корней.
*/

/*++
    mgetline

    Эта функция считывает строку до '\n'.

    Принимает следующие аргументы:

        *file       указатель на FILE, откуда ведется чтение строки.
        *str        строка, куда будет считываться строка.
        len         максимальная длина считываемой строки.

    Возвращает следующие значения:
    
        0           чтение прошло успешно.
        1           чтение не удалось.  
--*/

int mgetline (const FILE *file, char *str, const size_t mlen);

/*++
    equ 

    Эта функция проверяет, равны ли строки.

    Принимает следующие аргументы:

        *str1       первая строка.
        *str2       вторая строка.

    Возвращает следующие значения:
        
        false       строки не равны.
        true        строки равны.   
--*/

bool equ (const char *str1, const char *str2);

//==================================================================

/*++

    dou0

    Фукция,  исполняющая юнит-тест, при котором квадратное уравнение не должно иметь корней.

    dou1

    Функция, исполняющая юнит-тест, при котором квадратное уравнение имеет один корень.

    dou2

    Функция, исполняющая юнит-тест, при котором квадратное уравнение имеет два корная.

    douinf

    Функция, исполняющая юнит-тест, при котором квадратное уравнение имеет бесконечно много корней.

    doall 

    Функция, исполняющая все юнит тесты.

--*/

void dou0   ();
void dou1   ();
void dou2   ();
void douinf ();
void douall ();

//==================================================================

int main (int argc, char **argv) 
    {

    setlocale(LC_ALL, "Rus");

    if (argc == 1)
        douall();
    else 
        {
        if      (equ(argv[1], "0"))
            dou0();

        else if (equ(argv[1], "1"))
            dou1();

        else if (equ(argv[1], "2"))
            dou2();

        else if (equ(argv[1], "inf"))
            douinf();                   
        else
            printf("Некорректный аргумент.");
        }
    
    return 0;   
    }

//==================================================================

int mgetline (const FILE *file, char *str, const size_t mlen)
    {

    int  i = 0;
    char o = 0;

    while (fscanf(file, "%c", &o))
        {


        if (o == '\n')
            break;

        if (i >= mlen)
            {
            fseek(file, -i, SEEK_CUR);

            return 1;
            }

        str[i] = o;
        i++;
        }

    if (i >= mlen)
        {
        fseek(file, -1, SEEK_CUR);
        
        return 1;   
        }   

    str[i] = '\0';  

    return 0;       
    }   

//==================================================================

bool equ (const char *str1, const char *str2)
    {
        size_t len1 = strlen(str1),
               len2 = strlen(str2);  

        if (len1 != len2)
            return false;

        int i = 0;

        for (; i < len1; ++i)
            if (str1[i] != str2[i])
                return false;

        return true;               
    }   

//==================================================================

void dou0 () 
    {
    system("./SqEq<u0>temp");

    FILE *temp = NULL;

    temp = fopen("temp", "r");

    char buf[100];

    mgetline(temp, buf, 100);

    mgetline(temp, buf, 100);
    assert(equ(buf, "Колво корней: 0"));

    mgetline(temp, buf, 100);
    assert(equ(buf, "Корней нет."));

    printf("\nu0: OK\n");   

    fclose(temp);
    system("rm temp");
    }

//==================================================================

void dou1 ()
    {
    system("./SqEq<u1>temp");

    FILE *temp = NULL;

    temp = fopen("temp", "r");

    char buf[100];

    assert(!mgetline(temp, buf, 100));

    assert(!mgetline(temp, buf, 100));
    assert(equ(buf, "Колво корней: 1"));

    assert(!mgetline(temp, buf, 100));
    assert(equ(buf, "Корень: -1.000000"));

    printf("\nu1: OK\n");

    fclose(temp);
    system("rm temp");
    }   

//==================================================================

void dou2 ()
    {
    system("./SqEq<u2>temp");

    FILE *temp = NULL;

    temp = fopen("temp", "r");

    char buf[100];

    assert(!mgetline(temp, buf, 100));

    assert(!mgetline(temp, buf, 100));
    assert(equ(buf, "Колво корней: 2"));

    assert(!mgetline(temp, buf, 100));
    assert(equ(buf, "Первый корень: -0.381966"));

    assert(!mgetline(temp, buf, 100));
    assert(equ(buf, "Второй корень: -2.618034"));

    printf("\nu2: OK\n");

    fclose(temp);
    system("rm temp");      
    }

//==================================================================    

void douinf () 
    {
    system("./SqEq<uinf>temp");

    FILE *temp = NULL;

    temp = fopen("temp", "r");

    char buf[100];

    assert(!mgetline(temp, buf, 100));

    assert(!mgetline(temp, buf, 100));
    assert(equ(buf, "Колво корней: inf"));

    assert(!mgetline(temp, buf, 100));
    assert(equ(buf, "Корней бесконечно много."));

    printf("\nuinf: OK\n");

    fclose(temp);
    system("rm temp");      
    }   

//==================================================================    

void douall ()
    {
    dou0();
    printf("=====================\n");

    dou1();
    printf("=====================\n");

    dou2();
    printf("=====================\n");

    douinf();   
    }   

//==================================================================    