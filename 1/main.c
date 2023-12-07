/**
 * @fileName:      main.c 
 * @author:        QWQ534 
 * @date:          2023-12-07 10:15:41
 * @description:   计算多项式的值
 **/
#include <stdio.h>
#include <time.h>
#include <math.h>

#define N_MAX 10
#define MAXK 1e7

clock_t Start_Time, Stop_Time;
double Duration;

void Test(double (*test)(int a, double b[], double c), double a[]);
double f1( int n, double a[], double x );
double f2( int n, double a[], double x );

int main(void)
{
	int i;
	double a[N_MAX];

	for( i = 0; i < N_MAX; i++ )
	{
		a[i] = (double)i;
	}

	Test(f1, a);
	Test(f2, a);

	return 0;
}
/**
 * @brief  This function 
 * @param  double (*test)(int a, double b[], double c) 传入的函数
 * @retval None
 **/
void Test(double (*test)(int a, double b[], double c), double a[])
{
	Start_Time = clock();
	for(int i = 0; i < MAXK; i++)
		test(N_MAX - 1, a, 1.1);
	Stop_Time = clock();
	Duration = ((double)(Stop_Time - Start_Time)) / CLK_TCK;
	printf("ticks = %f\n", (double)(Stop_Time - Start_Time));
	printf("Duration = %6.2e\n", Duration);
}
/**
 * @brief  This function 
 * @param  n 多项式的项数
 * @param  a[] 传入的系数
 * @param  x
 * @retval result 多项式的值
 **/
double f1( int n, double a[], double x )
{
	int i;
	double result = 0;

	for( i = 0; i < n; i++ )
	{
		result += (a[i] * pow(x, i));
	}

	return result;
}
/**
 * @brief  This function 
 * @param  n 多项式的项数
 * @param  a[] 传入的系数
 * @param  x
 * @retval result 多项式的值
 **/
double f2( int n, double a[], double x )
{
	int i;
	double result = a[n];

	for( i = n; i > 0; i-- )
	{
		result = a[i - 1] + x * result;
	}

	return result;
}