#include <stdio.h>
#include "sort.h"

int main()
{
    printf("\n\t\t--------------------\n");
    printf("\t\t---sort algorithm---\n");
    printf("\t\t--------------------\n");

    printf("\n+++ test function +++\n\n");

    

    int arr[1024] = {3,45,67,254,421};

    // printf("length is %d\n",get_length(arr[1024]));   

    selection_sort(arr,5);
    show(arr,5);
    
    insert_sort(arr,5);
    show(arr,5);

    shell_sort(arr,5);
    show(arr,5);

    quick_sort(arr,arr+4);
    show(arr,5);
}