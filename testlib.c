// testlib.c - тесты для проверки библиотеки timerlib.h

#include "./timerlib/timerlib.h"

int main(void)
{
	union time_u time;

	start(&time);
	for(int i = 1; i < 10000; i++)
	{
		for(int j = 1; j < 1000; j++)
			i/j;
	}

	stop(&time);
	show(&time);
	return 0;
}
