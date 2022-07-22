//链表
#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef char linklist_data_t;

typedef struct linklist
{
    linklist_data_t data;
    struct linklist *next;
}lklst_node, *lklst_ptr_node;

//也可以
// typedef struct linklist lklst_node;
// typedef struct linklist* lklst_ptr_node;
// struct linklist{
//     linklist_data_t data;
//     lklst_ptr_node *next;
// };
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//创建头节点
//作用：统一插入操作时的代码
//是第一个节点
//不储存数据
lklst_ptr_node create_linklist(void);

//链表比较重要的：插入
//地址不连续，一开始只知道头节点的地址
//next 先指向 头节点
//malloc 申请到之后会返回地址
//然后 头节点的next指向下一个结点的地址
// H = H->next
//头 -> 0 -> 1
//在头和0之间插入一个p
//区别：头插和尾插，而尾插可以被头插替换掉
//这里指向的顺序很重要
//头插：
//p的next = h的next
//h的next = p
//尾插：
//h的next = p
//p的next = NULL
//而h的next == NULL
//总结：
//1. 找到插入位置的前一个节点地址
//2. 插入，先插后边
int insert_linklist(lklst_ptr_node L, int pos, linklist_data_t data);

//计算一下len的长度
//int get_len_linklist();












#endif