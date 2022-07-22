#ifndef _SQLIST_H  //if there's no define for sqlist,then define _SQLIST_H
#define _SQLIST_H

/*
	function declare
	header file			//usually located at where funtions being used
	marco definition
	type declare
*/

#define N 1024 //a macro definition to N
typedef char sqlist_data_t; //rename,easy to change when type is different

//declare of sequence list struct,
typedef struct sqlist
{
	sqlist_data_t buf[N];
	unsigned int len;
}sql_node, *sql_pnode;
//sql_node = struct sqlist
//sql_pnode = struct sqlist*

//CREATE sequence list
//1.transfer address
//2.use malloc inside the function(declare of cycle problem)
	//why use malloc?
	//if use static,cant be deleted later
	//malloc is easier
sql_pnode create_sqlist(void);

//insert
int insert_sqlist(sql_pnode L, sqlist_data_t data, int pos);

//judge if the sequence list is full?
int full_sqlist(sql_pnode L);

//judge if the sequence list is empty?
int empty_sqlist(sql_pnode L);

//print sequence list
int show_sqlist(sql_pnode L);

//delete
int delete_sqlist(sql_pnode L,sqlist_data_t data);

//search   base on value
int search_sqlist(sql_pnode L,sqlist_data_t data);

//change   base on address to change value
int change_sqlist(sql_pnode L,sqlist_data_t data,int pos);

//---------HOMEWORK------------
//delete  base on address
int delete_sqlist_position(sql_pnode L, int pos);
#endif
