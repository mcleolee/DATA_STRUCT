#include "linkedTree.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    lkt_ptr_node T = create_linkedtree();
    porder_linktree(T);
}