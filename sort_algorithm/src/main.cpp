#include <stdio.h>
#include "sort.h"

int main()
{
    printf("\n---sort algorithm---\n\n");
    int arr[5] = {2,45,67,254,421};

    // selection_sort(arr,5);
    insert_sort(arr,5);
    // shell_sort(arr,5);

    show(arr,5);
}