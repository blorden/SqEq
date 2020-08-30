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

void readCoef (double* a, double* b, double* c);

void getKorni (double a, double b, double c, 
			   double* x1, double* x2, 
			   unsigned int* count);

bool doubleIsZero (const double x);

void printEq (const double x1, const double x2, 
			  const unsigned int count);

double abs (const double x);

//=================================================

int main () 
	{
	setlocale(LC_ALL, "Rus");

	//Coef
	double a, b, c;

	readCoef(&a, &b, &c);

	//Korni
	double x1, x2;
	unsigned int count = 0;

	getKorni(a, b, c, &x1, &x2, &count);

	printEq(x1, x2, count);

	return 0;
	}

//=================================================

void readCoef (double* a, double* b, double* c)
	{
	assert(scanf("%lf %lf %lf", a, b, c));
	//print_coef
	}

//=================================================

void getKorni (double a, double b, double c, 
			   double* x1, double* x2,
			   unsigned int* count) 
	{
	double D = b*b - 4*a*c;

	if (D < 0) 								//D > 0
		{
		*count = 0;

		return;
		} 

	if (doubleIsZero(D)) 					//D = 0
		{
		*count = 1;
		*x1 = -b / 2*a;

		return;
		}	

	*count = 2;								//D = 2
	*x1 = (-b + sqrt(D)) / 2*a;
	*x2 = (-b - sqrt(D)) / 2*a;	
	}

//=================================================

bool doubleIsZero (const double x) 
	{
	return abs(x) < 1e-5;
	}

//==================================================

void printEq (const double x1, const double x2, 
			  const unsigned int count) 
	{
	printf("\nКолво корней: %u\n", count);

	switch (count)
		{
		case 0:								//- -	
			printf("Корней нет.\n");
			break;

		case 1:								//x1 -
			printf("Корень: %.5lf\n", x1);
			break;	

		case 2: 							//x1 x2
			printf("Первый корень: %.5lf\n", x1);
			printf("Второй корень: %.5lf\n", x2);
		}
	}

//==================================================

double abs (const double x) 
	{
	if (x < 0)
		return -x;
	return x;
	}	










