// Jonah Meggs COMP2521 2021

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

typedef struct list *List; //List === struct list *

List listNew(void);
void listInsert(List l, int value);
void listDelete(List l, int value);
void printList(List l);

// Create a new node
struct node* newNode(int value) {
    struct node* n = malloc(sizeof(struct node));
    n->value = value;
    n->next = NULL;
    return n;
}

// Create a new List
List listNew(void) {
    List l = malloc(sizeof(struct list));
    assert(l != NULL);
    l->head = NULL;
    return l;
}

// Insert a value (just adding to the beginning cause ceebs)
void listInsert(List l, int value) {
    struct node* n = newNode(value);
    n->next = l->head;
    l->head = n;
}

// Delete the first instance of `value` if it exists
void listDelete(List l, int value) {
    struct node * tmp;
    if (l->head != NULL && l->head->value == value) {
        tmp = l->head;
        l->head = l->head->next;
        free(tmp);
    } else {
        struct node * curr = l->head;
        while (curr->next != NULL) {
            if (curr->next->value == value) {
                tmp = curr->next;
                curr->next = curr->next->next;
                free(tmp);
                break;
            }
            curr = curr->next;
        }
    }
}

// Print the list so we can see what's happening
void printList(List l) {
    for (struct node * curr = l->head; curr != NULL; curr = curr->next) {
        printf("%d->", curr->value);
    }
    printf("NULL\n");
}

int main(void) {
    // Create List
    List l = listNew();
    printList(l);
    // Test inserting a node
    listInsert(l, 1);
    printList(l);
    // Test inserting more nodes
    listInsert(l, 6);
    listInsert(l, 10);
    listInsert(l, 5);
    listInsert(l, 2);
    printList(l);
    // Test deleting nodes that exist
    listDelete(l, 10);
    listDelete(l, 2);
    printList(l);
    // Test deleting nodes that don't exist
    listDelete(l, 42);
    printList(l);

    return 0;
}