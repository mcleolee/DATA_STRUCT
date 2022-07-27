#include <stdio.h>
#include <stdlib.h>

#define N 1024

typedef char sqTree_data_type;

typedef struct sqtree
{
    sqTree_data_type buf[N];
    int len;
}sqt_node,*sqt_ptr_node;

sqt_ptr_node malloc_sqtree()
{
    sqt_ptr_node T = (sqt_ptr_node)malloc(sizeof(sqt_node));
    if(NULL == T)
    {
        printf("memory allocate failed\n");
        return NULL;
    }
    T->len = 0;
    return T;
}

int create_sqtree(sqt_ptr_node T, int layer)
{
    sqTree_data_type ch;
    scanf("%c",&ch); //ABDH**I***EJ***CF**G***

    T->len++; //0->1
    if('*' == ch)
    {
        return 0;
    }
    T->buf[layer] = ch;//layer=0 T->buf[0]
    create_sqtree(T, 2*layer+1); 
    create_sqtree(T, 2*layer+2); 
    return 0;
}

int show_sqtree(sqt_ptr_node T)
{
    printf("\n");
    for(int i=0; i < (T->len); i++)
    {
        printf("buf[%d]=%c\n",i,T->buf[i]);
    }
    printf("\n");
}

int main()
{
    sqt_ptr_node T = malloc_sqtree();
    printf("\n--- input the tree code ---\n");
    create_sqtree(T,0);

    show_sqtree(T);
}