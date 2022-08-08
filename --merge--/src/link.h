#ifndef _LINK_H
#define _LINK_H

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
//               LINKED LIST
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

typedef char linkedList_data_type;

typedef struct linkedList 
{
    linkedList_data_type data;
    struct linkedList *next; // 不能写成lkdlst_ptr_node *next!!!
}lkdlst_node,*lkdlst_ptr_node;

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
lkdlst_ptr_node create_linkedList(void);

// 链表比较重要的：插入
// 地址不连续，一开始只知道头节点的地址
// next 先指向 头节点
// malloc 申请到之后会返回地址
// 然后 头节点的next指向下一个结点的地址
// H = H->next
// 头 -> 0 -> 1
// 在头和0之间插入一个p
// 区别：头插和尾插，而尾插可以被头插替换掉
// 这里指向的顺序很重要
// 头插：
// p的next = h的next
//h的next = p
//尾插：
//h的next = p
//p的next = NULL
//而h的next == NULL
//总结：
//1. 找到插入位置的前一个节点地址
//2. 插入，先插后边
int insert_linkedList(lkdlst_ptr_node LL,int pos, linkedList_data_type data);

// 量长度
int get_length_linkedList(lkdlst_ptr_node LL);

// 菜单
int menu_linkedList();

// 打印
int print_linkedList(lkdlst_ptr_node LL);

// 判空
int empty_linkedList(lkdlst_ptr_node LL);











#endif