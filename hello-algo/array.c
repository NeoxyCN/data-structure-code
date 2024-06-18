#include <stdlib.h>

int array_randomAccess(int *nums, int size) {
    int randomIndex = rand() % size;
    int randomNum = nums[randomIndex];

    return randomNum;
}

void array_insert(int *nums, int size, int num, int index) {
    for (int i = size - 1; i > index; i--) {
        nums[i] = nums[i - 1];
    }
    nums[index] = num;
}

void array_removeItem(int *nums, int index, int size) {
    for (int i = index; i < size - 1; i++) {
        nums[i] = nums[i + 1];
    }
}

// return the count of the array
int array_traverse(int *nums, int size) {
    int count = 0;

    // `i < size` instead of `i <= size`,
    // the first index of array is 0
    for (int i = 0; i < size; i++) {
        count += nums[i];
    }

    return count;
}

int array_find(int *nums, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (nums[i] == target) {
            return i;
        }
    }

    return -1;
}

int *array_extend(int *nums, int size, int enlarge) {
    int *new_array = (int *) malloc(sizeof(int) * (size + enlarge));

    // copy array
    for (int i = 0; i < size; i++) {
        new_array[i] = nums[i];
    }

    for (int i = size; i <(size + enlarge); i++) {
        new_array[i] = 0;
    }

    return new_array;
}
