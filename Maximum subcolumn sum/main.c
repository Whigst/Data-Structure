/**
 * @fileName:      main.c 
 * @author:        QWQ534 
 * @date:          2023-12-22 10:03:38
 * @description:   
 **/
#include <stdio.h>

#define N 9

int Test(int a[], int start, int end);              //分而治之
int Test2(int a[]);                                 //在线处理
int Max(int a, int b, int c);

int main(void)
{
    // int a[N] = {4, -3, 5, -2, -1, 2, 6, -2, 3};
    int a[N] = {-1, -2, -3, -2, -2, -4, -5, -8, -9};

    printf("%d\n", Test(a, 0, N - 1));
    printf("%d\n", Test2(a));
}

int Test(int a[], int start, int end)
{
    int MaxOfLeft = 0, MaxOfRight = 0, MaxOfCenter = 0;
    int Left_Sum = 0, Right_Sum = 0, Max_LeftSum = 0, Max_RightSum = 0;

    int center = (start + end) / 2;

    if(start == end)
    {
        return a[start];
    }

    MaxOfLeft = Test(a, start, center);
    MaxOfRight = Test(a, center + 1, end);

    for(int i = 0; i <= center - start; i++)
    {
        Left_Sum += a[center - i];
        if(Left_Sum > Max_LeftSum)
            Max_LeftSum = Left_Sum;
    }

    for(int j = 1; j <= end - center; j++)
    {
        Right_Sum += a[center + j];
        if(Right_Sum > Max_RightSum)
            Max_RightSum = Right_Sum;
    }

    MaxOfCenter = Max_LeftSum + Max_RightSum;

    return Max(MaxOfCenter, MaxOfLeft, MaxOfRight);
}

int Test2(int a[])
{
    int CurrentSum, MaxSum, LastSum;
    CurrentSum = LastSum = 0;
    MaxSum = 0;
    int i = 0;

    for(i = 0; i < N; i++)
    {
        CurrentSum += a[i];
        if(CurrentSum > MaxSum)
        {
            MaxSum = CurrentSum;
        }
        else if(CurrentSum < 0)
        {
            CurrentSum = 0;
        }
    }

    return MaxSum;
}

int Max(int a, int b, int c) {
	int max;
	
	if (a > b)
		max = a;
	else
		max = b;

	if (max > c)
		max = max;
	else
		max = c;

	return(max);
}