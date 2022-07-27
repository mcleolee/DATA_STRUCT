#include <stdio.h>
#include <string.h>
#include "sort.h"


void swap(int *p,int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void show(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        printf("arr[%d]=%d",i,arr[i]);
    }
    puts("");
}

void selection_sort(int *arr,int len)
{
    for(int i=0; i<len-1 ;i++)
    {
        int min =i;
        for(int j=i; j<len-1;j++)
        {
            if(arr[min] > arr[j+1])
            {
                min = j+1;
            }
        }
        if(min != i)
        {
            swap(arr+i,arr+min);
        }
    }
}

