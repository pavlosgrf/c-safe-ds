#include <stdio.h>


int main(void) {
    int x =5;
    int *p=&x; 

    printf("value of x:     %d\n", x);
    printf("address of x:   %p\n", (void *)&x);
    printf("value of p:     %p\n", (void *)p);
    printf("value at *p:    %d\n", *p);

    *p = 10;
    printf("x after *p=10:  %d\n", x);

    int arr[3] = {1,2,3};
        for (int i = 0; i < 3; i++) {
         printf("arr[%d] = %d at %p\n", i, arr[i], (void *)&arr[i]);
    }
    return 0;

}