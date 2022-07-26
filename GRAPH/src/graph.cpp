#include <stdio.h>
#include <stdlib.h>

#define N 1024
typedef char sqG_data_t;

typedef struct G
{
    sqG_data_t v_buf[N];
    int e_buf[N][N];

    int v_number;
    int e_number;
    int flag[N];
}sqg_node,*sqg_pnode;

sqg_pnode create_sqg()
{
    sqg_pnode G = (sqg_pnode)malloc(sizeof(sqg_node));
    if(NULL == G)
    {
        printf("malloc failed\n");
        return NULL;
    }

    //储存顶点
    printf("plz input v_number\n");
    scanf("%d",&(G->v_number));
    getchar();
    printf("plz input v data\n");
    for(int i=0;i<G->v_number;i++)
    {
        scanf("%c",&(G->v_buf[i]));
        getchar();
    }

    //储存边
    for(int i=0;i<G->v_number;i++)
    {
        for(int j=0;j<G->v_number;j++)
        {
            if(i == j)
            {
                G->e_buf[i][j] = 0;
            }
            else
            {
                G->e_buf[i][j] = 69;
            }
        }
        
    }

    printf("plz input E_number\n");
    scanf("%d",&(G->e_number));
    getchar();
    int A,B,weight;
    for(int i=0;i<G->e_number;i++)
    {
        printf("plz input A and B\neg: 0 1 100\n");
        scanf("%d%d%d",&A,&B,&weight);

        G->e_buf[A][B]= weight; // 有向只要这一句，如果无向的就要下面那一句
        // G->e_buf[A][B]= weight;
    }
    return G;
}

int show_graph(sqg_pnode G)
{
    printf("V data is \n");
    for(int i=0;i<G->v_number;i++)
    {
        printf("%c ",G->v_buf[i]);
    }
    printf("\n");
    printf("E data is \n");
    for(int i=0;i<G->v_number;i++)
    {
        for(int j=0;j<G->v_number;j++)
        {
            printf("%d ",G->e_buf[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main()
{
    printf("init!\n");
    sqg_pnode G = create_sqg();
    show_graph(G);
    return 0;
}

