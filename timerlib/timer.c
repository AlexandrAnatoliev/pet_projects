// timer.c
#include <stdio.h>
#include <time.h>   			// for clock_t, clock(), CLOCKS_PER_SEC

#define TIMER_START double time_spent = 0.0; clock_t begin = clock(); 
#define TIMER_STOP clock_t end = clock(); time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
#define TIMER_PRINT printf("runtime = %f sec\n", time_spent);

// operation:					measuring the program running time
// precondition:	TIMER_START	"create a variable to store code execution time and timer start
//					TIMER_STOP	"timer stop and measure operaing time in seconds"
// postcondition:	TIMER_PRINT	"print the run time"


union time_u
{
	clock_t clk;	// разные форматы хранения времени
	double dbl;
};

int start(union time_u *time);

int stop(union time_u *time);

int show(union time_u *time);

int start(union time_u *time)
{
	time->clk = clock();
	return 0;
}


int stop(union time_u *time)
{
	clock_t begin = time->clk;
	clock_t end = clock();
	time->dbl = (double)(end - begin) / CLOCKS_PER_SEC;
	return 0;
}
	

int show(union time_u *time)
{
	printf("\nruntime = %f sec\n\n", time->dbl);
	return 0;
}

int main(void)
{
	union time_u time;
	start(&time);
	for(int i = 0; i < 1000; i++)
	{
		for(int j = 1; j < 1000; j++)
			i/j;
	}
	stop(&time);
	show(&time);
	return 0;
}
