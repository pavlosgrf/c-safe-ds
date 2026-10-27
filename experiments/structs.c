#include <stdio.h>   
#include <stdlib.h>  // malloc, free
#include <stddef.h>  // offsetof


// a simple struct

typedef struct{
    int x;
    int y;
} Point;


//different variables force the compiler to add padding to the struct
typedef struct{
    char a;
    int b;
    char c;
} Padded; 

// same variables but order as larger to smaller, much less padding needed
typedef struct{
    int b;
    char a;
    char c;
 } OrderedPadded;

// a struct that contains a pointer to another struct of the same type
//it is a building block for linked lists, trees, and other data structures
 typedef struct Node{
    int value;
    struct Node *next;
} Node;
 

static void move_point(Point *p, int dx, int dy){
    p->x += dx;   // p->x is (*p).x
    p->y += dy;
}

int main(void){
Point a = {3,4}; //insert value to struct
printf("Point a: (%d, %d),sizeof(Point) = %zu\n", a.x, a.y, sizeof(Point));

move_point(&a, 10,10);
printf("Point a after move: (%d, %d)\n", a.x, a.y);

//---------------

Point *heap_point = malloc(sizeof(Point)); // allocate memory for a Point on the heap
if (heap_point == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1; }

heap_point->x = 5; // -> because h is a pointer
heap_point->y = 6;
printf("Point on heap: (%d, %d)\n", heap_point->x, heap_point->y);
free(heap_point); // free the allocated memory
heap_point = NULL; // good practice to avoid dangling pointer


//---------------

// demonstrate how padding affects the size of a struct
//offset is the distance in bytes from the start of the struct to the member
printf("Size of Padded struct: %zu, offsets a: %zu, b: %zu, c: %zu\n", 
    sizeof(Padded), offsetof(Padded, a), offsetof(Padded, b), offsetof(Padded, c));

printf("Size of OrderedPadded struct: %zu, offsets b: %zu, a: %zu, c: %zu\n",
    sizeof(OrderedPadded), offsetof(OrderedPadded, b), offsetof(OrderedPadded, a), offsetof(OrderedPadded, c));

 
 //---------------

 //preview of a linked list using the Node struct
 // Three nodes, each pointing to the next. The last points to NULL.

 Node n3 = {30, NULL};
 Node n2 = {20, &n3};
 Node n1 = {10, &n2};

 for (Node *current = &n1; current != NULL; current = current->next) {
    printf("Node value: %d\n", current->value); 
 }
 printf("NULL\n");

 return 0;

}