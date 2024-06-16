#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode *newListNode(int val) {
    ListNode *node;
    node = (ListNode *) malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void insert(ListNode *n0, ListNode *p) {
    ListNode *n1 = n0->next;
    p->next = n1;
    n0->next = p;
}

// delete the first node after n0
void removeItem(ListNode *n0) {
    if(!n0->next) {
        return;
    }
    // n0 - nxt - p
    //      ^^^
    ListNode *nxt = n0->next;
    ListNode *p = nxt->next;
    free(nxt);
    n0->next = p;
}

ListNode *access(ListNode *head, int index) {
    for()
}

int main(void) {
    // new node
    ListNode *n0 = newListNode(1);
    ListNode *n1 = newListNode(3);

    n0->next = n1;

    return 0;
}
