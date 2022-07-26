#ifndef _LINKEDTREE_H
#define _LINKEDTREE_H
typedef char linkedtree_data_type;
typedef struct linkedtree
{
    linkedtree_data_type data;
    struct linkedtree *left;
    struct linkedtree *right;
}lkt_node,*lkt_ptr_node;

lkt_ptr_node create_linkedtree();

//porder 先序遍历
int porder_linktree(lkt_ptr_node T);












#endif