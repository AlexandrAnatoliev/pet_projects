// timerlib.c - исходный код для статической библиотеки

#include <stdio.h>
#include <time.h>

union time_u		// объединение для хранения времени
{
	clock_t clk;	// clock_t(long)- для замера времени 
	double dbl;		// double		- для вывода на экран в виде десятичной дроби
};

int start(union time_u *time)
{
	time->clk = clock();								// засекаем текущее время
	
	return 0;
}


int stop(union time_u *time)
{
	clock_t begin = time->clk;							// время начала работы
	clock_t end = clock();								// конца

	time->dbl = (double)(end - begin) / CLOCKS_PER_SEC;	// заносим измеренное время

	return 0;
}
	

int show(union time_u *time)
{
	printf("\nruntime = %f sec\n\n", time->dbl);		// вывод на экран

	return 0;
}
