#include <stdio.h>
#include <string.h>
#include "sort.h"

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void show(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("arr[%d]=%d", i, arr[i]);
    }
    puts("");
}

void selection_sort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i; j < len - 1; j++)
        {
            if (arr[min] > arr[j + 1])
            {
                min = j + 1;
            }
        }
        if (min != i)
        {
            swap(arr + i, arr + min);
        }
    }
}

void insert_sort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int end = i;
        int temp = arr[i + 1];

        while (end >= 0)
        {
            if (arr[end] > temp)
            {
                arr[end + 1] = arr[end]; // 向后移一位
            }
            else
            {
                break;
            }
            end--;
        }
        arr[end + 1] = temp;
    }
}

void shell_sort(int *arr, int len)
{
    int w = len/2;
    while (w)
    {
        for (int i = 0; i < len - 1; i += w)
        {
            int end = i;
            int temp = arr[i + w];

            while (end >= 0)
            {
                if (arr[end] > temp)
                {
                    arr[end + w] = arr[end]; // 向后移一位
                }
                else
                {
                    break;
                }
                end -= w;
            }
            arr[end + w] = temp;
        }
    }
}