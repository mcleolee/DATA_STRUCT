#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef char linklist_data_t;
typedef struct linklist
{
    linklist_data_t data;
    struct linklist *next; 
}lklst_node, *lklst_ptr_node;

lklst_ptr_node create_linklist(void);

int insert_linklist(lklst_ptr_node L,int pos,linklist_data_t ISTdata);

int get_length_linklist(lklst_ptr_node L);

int delete_based_value_linklist(lklst_ptr_node L,linklist_data_t DLTdata);

int delete_based_address_linklist(lklst_ptr_node L,int pos);

int empty_linklist(lklst_ptr_node L);

int show_linklist(lklst_ptr_node L);




#endif