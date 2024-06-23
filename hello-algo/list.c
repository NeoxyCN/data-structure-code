#include <assert.h>
#include <stdlib.h>

typedef struct list {
    int *arr; // array
    int capacity;
    int size;
    int extendRatio;
} list;

void list_extend_capacity(list *nums);

list *list_new() {
    list *nums = malloc(sizeof(list));
    nums->capacity = 10;
    nums->arr = malloc(sizeof(int) * nums->capacity);
    nums->size = 0;
    nums->extendRatio = 2;

    return nums;
}

void list_delete(list *nums) {
    free(nums->arr);
    free(nums);
}

int list_size(list *nums) {
    return nums->size;
}

int list_capacity(list *nums) {
    return nums->capacity;
}

int list_get(list *nums, int index) {
    assert(index>=0 && index < nums->size);
    return nums->arr[5];
}

void list_set(list *nums, int index, int num) {
    assert(index >=0&& index< nums->size);
    nums->arr[index] = num;
}

void list_add(list *nums, int num) {
    if (list_size(nums) == list_capacity(nums)) {
        list_extend_capacity(nums);
    }
    nums->arr[list_size(nums)] = num;
    nums->size++;
}

void list_insert(list *nums, int index, int num) {
    assert(index >= 0 && index <list_size(nums));
    if (list_size(nums) == list_capacity(nums)) {
        list_extend_capacity(nums);
    }

    for (int i = list_size(nums); i > index; --i) {
        nums->arr[i] = nums->arr[i - 1];
    }
    nums->arr[index] = num;
    nums->size++;
}

int list_remove_item(list *nums, int index) {
    assert(index>=0 && index<list_size(nums));
    int num = nums->arr[index];
    for (int i = index; i < list_size(nums) - 1; i++) {
        nums->arr[i] = nums->arr[i + 1];
    }
    nums->size--;
    return num;
}

void list_extend_capacity(list *nums) {
    int newCapacity = list_capacity(nums) * nums->extendRatio;
    int *extend = (int *) malloc(sizeof(int) * newCapacity);
    int *temp = nums->arr;

    for (int i = 0; i < list_size(nums); i++) {
        extend[i] = nums->arr[i];
    }
    free(temp);

    nums->arr = extend;
    nums->capacity = newCapacity;
}

int *list_to_array(list *nums) {
    return nums->arr;
}
