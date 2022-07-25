#include <stdio.h>
#include "linkedStack.h"
#include <stdlib.h>

int main() {
    lkstk_node q, *S;
    S = &q;

    int i, n, e;

    printf("Creat a NULL Stack :\n");
    init_stack(S);

    printf("input the length of the Stack :\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &e);
        push_stack(S, e);
    }
    printf("Is the stack NULL?\n");

    if (empty_stack(S)) {
        printf("Yes!\n");
    } else {
        printf("No!\n");
    }
    printf("The length of stack is %d.\n", length_stack(S));

    printf("The stack is :\n");
    show_stack(S);

    // get_top_stack(S, *e);
    // printf("The top data is %d.\n", e);

    printf("input the data to the stack :\n");
    scanf("%d", &e);
    push_stack(S, e);
    printf("The new stack is :\n");
    show_stack(S);

    // printf("Delete the top data : ");
    // e = exit_stack(S, *e);
    // printf("%d\n", e);

    printf("The new stack is :\n");
    show_stack(S);

    return 0;
}