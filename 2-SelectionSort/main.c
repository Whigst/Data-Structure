/**
 * @fileName:      main.c 
 * @author:        QWQ534 
 * @date:          2023-12-07 10:47:40
 * @description:   Selection Sorting Algorithm
 **/

#include <stdio.h>

#define ElementType int                                         //Can't be set as float or double

#define Swap(a, b) \
        a ^= b;    \
        b ^= a;    \
        a ^= b

int ScanForMin( ElementType List[], int i, int N );
void SelectionSort( ElementType List[], int N );

int main(void)
{
    ElementType List[10] = { 2, 3, 5, 3, 9, 7, 0, 11, 10, 4 };

    SelectionSort(List, 10);

    for(int i = 0; i < 10; i++)
    {
        printf("%d\t", List[i]);
    }

    return 0;
}

/**
 * @brief  This function 
 * @param  ElementType List[] 传入的待排序的数组
 *         i 从第几个数字开始扫描
 *         N 待排序数字总数,也表示循环次数
 * @retval result 此次扫描中找到的未排序数列中的最小的数字的下标
 **/
int ScanForMin( ElementType List[], int i, int N )
{
    int result = i;
    int j;

    for(j = i; j < N; j++)
    {
        if(List[result] > List[j])
        {
            result = j;
        }
    }

    return result;
}

/**
 * @brief  This function 
 * @param  ElementType List[] 传入的待排序的数组
 *         N 待排序数字总数
 * @retval None
 **/
void SelectionSort( ElementType List[], int N )
{
    int i;
    int MinPosition = 0;
    for(i = 0; i < N; i++)
    {
        MinPosition = ScanForMin( List, i, N );
        if(i != MinPosition)
        {
            Swap(List[i], List[MinPosition]);
        }
    }
}
