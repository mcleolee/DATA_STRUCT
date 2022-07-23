#include "sqlist.h" //有结构体的声明
#include <stdlib.h>
#include <stdio.h>
//CREATE sequence list
//1.transfer address
//2.use malloc inside the function(declare of cycle problem)

sql_pnode create_sqlist(void)
{
    //给结构体申请空间
    sql_pnode L = (sql_pnode)malloc(sizeof(sql_node));
    //转换成 sql_pnode 类型,不然会报错
    if(NULL == L)
    {
        printf("malloc is default\n");
        //设计时自检,成品应该删除
        return NULL;
    }
    //数组没必要初始化,但长度(len)要,不然就随机数了
    L->len=0;//数组指针的用法!!!
    return L;
}

//插入
int insert_sqlist(sql_pnode L, sqlist_data_t data, int pos)
{
    //判断插入位置是否有效
    if(pos < 0 || pos > L->len) //pos > L->len 要不要取等
    {
        printf("pos if default\n");
        return -1;
    }
    //判断顺序表是否为满
    if(0 == full_sqlist(L))
    {
        printf("the list is full\n");
        return  -1;
    }
    //
    //实现插入
    //1.移动
    //2.赋值

    //表中元素依次移动
    int i;
    for(i=L->len-1;i >= pos;i--)
    {
        L->buf[i+1] = L->buf[i];
    }
    //赋值
    L->buf[pos] = data;
    L->len++;
}

//判空
int empty_sqlist(sql_pnode L)
{
    if(0 == L->len) 
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

//判断顺序表是否为满
int full_sqlist(sql_pnode L)
{
    if(N == L->len) //在判断时,常量放在左边
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

//打印顺序表
int show_sqlist(sql_pnode L)
{
    //判空
    if(0 == empty_sqlist(L))
    {
        printf("list is empty\n");
        return -1;
    }

    int i;
    for(i=0;i<L->len;i++)
    {
        printf("buf[%d]=%d",i,L->buf[i]);
    }
    printf("\n");
}

//delete
int delete_sqlist(sql_pnode L,sqlist_data_t data)
{
    //判空
    if(0 == empty_sqlist(L))
    {
        printf("list is empty\n");
        return -1;
    }
    //判断有没有这个值
    int ret = search_sqlist(L,data);
    if(-2 == ret)
    {
        printf("no find for the data\n");
        return -1;
    }
    //找到之后就删除
    int i;
    for ( i = ret; i < L->len ; i++)
    {
        L->buf[i] = L->buf[i+1];
    }
    return 0;
    

}

//search base on value
int search_sqlist(sql_pnode L,sqlist_data_t data)
{
    //判空
    if(0 == empty_sqlist(L))
    {
        printf("list is empty\n");
        return -1;
    }
    int i;
    for(i=0;i<L->len;i++)
    {
        if (data == L->buf[i])
        {
            return i;
        }
    }
    return -2;
}

//change   base on address to change value
int change_sqlist(sql_pnode L,sqlist_data_t data,int pos)
{
    //判空
    if(0 == empty_sqlist(L))
    {
        printf("list is empty\n");
        return -1;
    }
    //位置合不合法
    //判断修改位置是否有效
    if(pos < 0 || pos >= L->len) //pos > L->len 要不要取等
    {
        printf("pos if default\n");
        return -1;
    }
    //修改
    L->buf[pos] = data;
    return 0;
}

//---------HOMEWORK------------
//delete  base on address
// int delete_sqlist_position(sql_pnode L, int pos)
// {
//     if(0 == empty_sqlist(L))
//     {
//         printf("L is empty\n");
//         return -1;
//     }

//     if(0 > pos || L->len <=pos)
//     {

//     }
// }