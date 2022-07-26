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

int create_sqtree(sqt_ptr_node T, int pos) // 值用终端输入
{
    sqTree_data_type ch;
    scanf("%c",&ch);
    T->len++;
    //退出条件,自定义字符
    if('$' == ch)
        return 0;
    //根节点赋值
    T->buf[pos] = ch;
    //通过create函数创建出来，递归
    create_sqtree(T, 2*pos+1); // 左子树 
    create_sqtree(T, 2*pos+2); // 右子树
    return 0;
}

int show_sqtree(sqt_ptr_node T)
{
    for(int i=0; i<T->len; i++)
    {
        printf("buf[%d]=%c",i,T->buf[i]);
    }
    printf("\n");
}

int main()
{
    sqt_ptr_node T = malloc_sqtree();
    create_sqtree(T,0);

    show_sqtree(T);
}