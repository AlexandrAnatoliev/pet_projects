// testlib.c - тесты для проверки библиотеки timerlib.h

#include <stdio.h>
#include "../timerlib.h"

int main(void)
{
	int cnt = 6;	// итераций
	int limit = 1;	// предел перебора значений в цикле

	while(cnt)
	{	
		union time_u time;

		start(&time);
		for(int i = 1; i < limit; i++)
		{
			for(int j = 1; j < limit; j++)
				i/j;
		}

		stop(&time);
		printf("Перебор (в двух циклах) чисел i и j до %d и вычисление i/j заняло:", limit); 
		show(&time);

		limit *= 10;
		cnt--;
	}

	return 0;
}
