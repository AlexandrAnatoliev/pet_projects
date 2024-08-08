// timerlib.h - статическая библиотека для измерения времени работы программы

#include <time.h>

union time_u		// объединение для хранения времени
{
	clock_t clk;	// clock_t(long)- для замера времени 
	double dbl;		// double		- для вывода на экран в виде десятичной дроби
};

int start(union time_u *time);
// operation:		старт таймера
// precondition:	*time	- указатель на объединение хранящее время
// postcondition:	в объединение заносится текущее время (целочисленный тип clock_t)

int stop(union time_u *time);
// operation:		остановка таймера
// precondition:	*time	- указатель на объединение хранящее время
// postcondition:	в объединение заносится время работы прогорммы (вещественный тип double)

int show(union time_u *time);
// operation:		вывод времени работы программы
// precondition:	*time	- указатель на объединение хранящее время
// postcondition:	время работы выводится в секундах с точностью шесть знаков после запятой

