#ifndef _SORT_H
#define _SORT_H

void show(int *arr,int len);
void swap(int *p,int *q);
// int get_length(int arr);

void selection_sort(int *arr,int len);
void insert_sort(int *arr, int len);
void shell_sort(int *arr,int len);
void quick_sort(int *start,int *end);

#endif