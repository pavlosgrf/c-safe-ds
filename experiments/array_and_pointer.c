#include <stdio.h>
#include <stddef.h> // for size_t, ptrdiff_t

int main(void){

    int array[5]={10,20,30,40,50};

    int *p = array; // pointer to the first element of the array

    size_t total_bytes = sizeof(array); // total bytes occupied by the array
    size_t count = sizeof(array) / sizeof(array[0]); // number of elements in the array
    printf("Total bytes: %zu, elemenent size : %zu, elements %zu\n", total_bytes, sizeof(array[0]), count);

    for (size_t i = 0; i < count; i++) {
        printf("array[%zu] = %d | *(p + %zu) = %d | address %p\n",
               i, array[i], i, *(p + i), (void *)&array[i]);
    }

    // Pointer arithmetic is scaled: p + 1 moves by sizeof(int) bytes.
    printf("p     = %p\n", (void *)p);
    printf("p + 1 = %p\n", (void *)(p + 1));

    // Subtracting two pointers gives the distance in ELEMENTS, not bytes.
    ptrdiff_t distance = (p + 3) - p;
    printf("(p + 3) - p = %td elements\n", distance);

    return 0;


}