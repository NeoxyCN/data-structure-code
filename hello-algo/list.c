#include <stdlib.h>

typedef struct list{
    int *arr;   // array
    int capacity;
    int size;
    int extendRatio;
} list;

list* list_new() {
    list* nums = malloc(sizeof(list));
    nums->capacity = 10;
    nums->arr = malloc(sizeof(int)* nums ->capacity);
    nums->size = 0;
    nums->extendRatio = 2;

    return nums;
}

void list_delete(list *nums) {
    free(nums->arr);
    free(nums);
}