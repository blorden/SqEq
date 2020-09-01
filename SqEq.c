#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <locale.h>

#define print_coef \
	printf("%.5lf\n%.5lf\n%.5lf", *a, *b, *c);

/*

	ax^2 + bx + c = 0

	%lf				a
	%lf				b
	%lf				c
 
*/

/*++ 
	
	getRoots

	Функция, вычисляющая корни квадратного уравнения.
	Принимает следующие аргументы:

	a 		коэффициент перед x^2
	b 		коэффициент перед x
	с 		свободный член

	*x1		первый корень
	*x2		второй корень

	Функция возвращает информацию о вычисленных корнях:

	0		уравнение не имеет решения
	1		уравнение имеет один корень
	2		уравнение имеет два корня
	3		уравнение имеет бесконечно много корней

--*/

unsigned int getRoots (double a, double b, double c, 
			   double* x1, double* x2);

/*++

	doubleIsZero

	Функция, проверяющая, является ли double нулем.
	Принимает следующие аргументы:

	x 		число с плавающей точкой, которое нужно сравнить с нулем

	Функция возвращает следующие значния:

	false	число не ноль
	true	число ноль

--*/

bool doubleIsZero (const double x);

/*++

	printEq

	Функция, печатающая информацию о решении квадратного уравнения.
	Принимает следующие аргументы:

	x1		первый аргумент
	x2		второй аргумент
	
	info	информация о количестве корней:

		0		уравнение не имеет корней
		1		уравнение имеет один корень
		2		уравнение имеет два корня
		3		уравнение имеет бесконечно много корней

--*/

void printEq (const double x1, const double x2, 
			  const unsigned int info);


//=================================================

int main () 
	{
	setlocale(LC_ALL, "Rus");

	//Coef
	double 
		   a 	=	0,
		   b 	=	0,
		   c 	= 	0;

	assert(scanf("%lf%lf%lf", &a, &b, &c) == 3);

	//Roots
	double 
		   x1 	=	0,
		   x2	= 	0;

	unsigned int 
		   info = 0;

	info = getRoots(a, b, c, &x1, &x2);

	printEq(x1, x2, info);

	return 0;
	}

//=================================================

unsigned int getRoots (double a, double b, double c, 
			   double* x1, double* x2) 
	{


	if (a * c == 0)							//D not exist
		return 3;

	double D = b*b - 4*a*c;

	if (D < 0) 							//D > 0
		return 0; 

	if (doubleIsZero(D)) 						//D = 0
		{
		*x1 = -b / 2*a;

		return 1;
		}	

									//D = 2
	*x1 = (-b + sqrt(D)) / 2*a;
	*x2 = (-b - sqrt(D)) / 2*a;	
	return 2;
	}

//=================================================

bool doubleIsZero (const double x) 
	{
	return fabs(x) < 1e-5;
	}

//==================================================

void printEq (const double x1, const double x2, 
			  const unsigned int info) 
	{
	printf("\nКолво корней: ");

	switch (info)
		{
		case 0:							   //- -	
			printf("0\nКорней нет.\n");
			break;

		case 1:							   //x1 -
			printf("1\nКорень: %lf\n", x1);
			break;	

		case 2: 						   //x1 x2
			printf("2\nПервый корень: %lf\n", x1);
			printf("Второй корень: %lf\n", x2);
			break;
		case 3:
			printf("inf\nКорней бесконечно много.\n");
			break;	
		}
	}

//==================================================











