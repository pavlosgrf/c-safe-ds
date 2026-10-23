#include <stdio.h>
#include <stdlib.h> // for malloc and free

int main(void) {
    int on_stack = 42;


     // The pointer variable on_heap itself lives on the stack.
    int *on_heap = malloc(sizeof(int));
    // Always check malloc's result. Dereferencing NULL crashes the program.
    if (on_heap == NULL) { 
        printf("malloc failed\n");
        return 1;
    }
    *on_heap = 99;

    printf("stack variable: value %d at %p\n", on_stack, (void *)&on_stack);
    printf("heap variable:  value %d at %p\n", *on_heap, (void *)on_heap);
    printf("the pointer itself lives at %p\n", (void *)&on_heap);

    free(on_heap);
    on_heap = NULL;
    return 0;
}