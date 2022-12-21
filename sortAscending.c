/*
 * @Author: luxun59 luxun59@126.com
 * @Date: 2022-12-20 15:34:23
 * @LastEditors: luxun59 luxun59@126.com
 * @LastEditTime: 2022-12-21 10:53:39
 * @FilePath: \algorithm\sortAscending.c
 * @Description: 
 * 
 * Copyright (c) 2022 by luxun59 luxun59@126.com, All Rights Reserved. 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>




//升序





#define BUBBLESORT_ELEM int 

/**
 * @description: 冒泡排序
 *                  首先从数组的第一个元素开始到数组最后一个元素为止，对数组中相邻的两个元素进行比较，
 *                  如果位于数组左端的元素大于数组右端的元素，则交换这两个元素在数组中的位置。这样操
 *                  作后数组最右端的元素即为该数组中所有元素的最大值。接着对该数组除最右端的n-1个元素
 *                  进行同样的操作，再接着对剩下的n-2个元素做同样的操作，直到整个数组有序排列。
 *               时间复杂度:  O(n) ~ O(n^2)
 *               空间复杂度:  O(1)
 * @return {*}
 */

void bubbleSort(BUBBLESORT_ELEM *arr, int length) // arr： 需要排序的数组； length： 数组长度 注： int cnt = sizeof(a) / sizeof(a[0]);获取数组长度
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length -  i - 1; j++)
		{
			if (*(arr+j) > *(arr + j + 1))
			{
				BUBBLESORT_ELEM temp;
				temp = *(arr + j + 1);
				*(arr + j + 1) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}


/**
 * @description: 选择排序
 *               时间复杂度:  O(n^2)
 *               空间复杂度:  O(1)
 * @return {*}
 */

#define SELECTIONSORT_ELEM int 

void selectionSort(SELECTIONSORT_ELEM *arr,int length)
{
    SELECTIONSORT_ELEM  temp;
    unsigned int minindex;
    unsigned int  i,j;
    for(i=0;i<length;i++)
    {
        minindex = i;
        for(j=i;j<length;j++)
        {
            if( *(arr+j) < *(arr+minindex) )
            {
                minindex = j; 
            }
        }
        temp = *(arr+i);
        *(arr+i) = *(arr + minindex);
        *(arr + minindex) = temp;
    }
}



/**
 * @description: 插入排序
 *                  通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
 *               时间复杂度：O(n) ~ O(n^2)
 *               空间复杂度：O(1)
 * @return {*}
 */
#define INSERTIONSORT_ELEM int 

void insertionSort(INSERTIONSORT_ELEM *arr, int length)
{
    int i,j;
    INSERTIONSORT_ELEM temp;
    for (i=1;i<length;i++)
    {
        temp = arr[i];
        j=i-1;
        for(;(j>=0) && (arr[j]>temp);j--) 
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
}



/**
 * @description: 希尔排序
 *                 先将待排记录序列分割成为若干子序列分别进行插入排序，待整个序列中的记录"基本有序"时，
 *                 再对全体记录进行一次直接插入排序。
 *               时间复杂度： O(n log n)
 *               空间复杂度： O(1)
 * @return {*}
 */
#define SHELLSORT_ELEM int 

void shell_sort(SHELLSORT_ELEM *arr, int length) {
    int increasement = length;
	int i, j, k;
	do
	{
		// 确定分组的增量
		increasement = increasement / 3 + 1;
		for (i = 0; i < increasement; i++)
		{
			for (j = i + increasement; j < length; j += increasement)
			{
				if (arr[j] < arr[j - increasement])
				{
					int temp = arr[j];
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement)
					{
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;
				}
			}
		}
	} while (increasement > 1);
}

/**
 * @description: 归并排序 
 *                  先使每个子序列有序，再使子序列段间有序。代价是需要额外的内存空间。
 *               时间复杂度：
 *               空间复杂度：
 * @return {*}
 */
#define SHELLSORT_ELEM int 
// 归并排序
void MergeSort(SHELLSORT_ELEM *arr, int start, int end, SHELLSORT_ELEM * temp) // start和end分别是左边界和右边界
{
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	MergeSort(arr, start, mid, temp);
	MergeSort(arr, mid + 1, end, temp);
 
	// 合并两个有序序列
	int length = 0; // 表示辅助空间有多少个元素
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	while (i_start <= i_end && j_start <= j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[length] = arr[i_start]; 
			length++;
			i_start++;
		}
		else
		{
			temp[length] = arr[j_start];
			length++;
			j_start++;
		}
	}
	while (i_start <= i_end)  // 把剩下数的合并
	{
		temp[length] = arr[i_start];
		i_start++;
		length++;
	}
	while (j_start <= j_end)
	{
		temp[length] = arr[j_start];
		length++;
		j_start++;
	}
	// 把辅助空间的数据放到原空间
	for (int i = 0; i < length; i++)
	{
		arr[start + i] = temp[i];
	}
}














#define SORTELEMTYPE int 

int main (void) {
    SORTELEMTYPE arr[] = {3,5,1,-7,4,9,-6,8,10,4};
    int len = sizeof(arr) / sizeof(SORTELEMTYPE); 
    // int len = sizeof(arr) / sizeof(arr[0]); 获取数据长度
    int i;
    // bubbleSort(arr, len);
    // selectionSort(arr, len);
    // insertionSort(arr,len);
    insertionSort(arr, len);
    for (i=0; i<len; i++)
        printf ("%d\t", arr[i]);
    putchar ('\n');
     
    return 0;
}



