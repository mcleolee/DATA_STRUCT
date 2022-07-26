#include <stdio.h>
#include <stdlib.h>
#include "linkedTree.h"

lkt_ptr_node create_linkedtree()
{
    linkedtree_data_type ch;
    scanf("%c",&ch);

    if('$' == ch)
        return NULL;

    lkt_ptr_node T = (lkt_ptr_node)malloc(sizeof(lkt_node));
    if(NULL == T)
    {
        printf("memory allocate failed\n");
        return NULL;
    }

    T->data= ch;
    //创建左子树和右子树
    T->left = create_linkedtree();
    T->right = create_linkedtree();

    return T;
}

//porder 先序遍历
int porder_linktree(lkt_ptr_node T)
{
    if(NULL == T)
        return 0;

    printf("data=%c\n",T->data);
    porder_linktree(T->left);
    porder_linktree(T->right);
}