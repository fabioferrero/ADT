/*
* LIST.c
* written by Fabio Ferrero
* fabio.ferrero@icloud.com
*/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node * link;

struct node {
    Item item;
    link next;
};

struct list {
    link head;
    link tail;
    int size;
};

link new_Node(Item item, link next) {
    link n = malloc(sizeof *n);
    n->item = item;
    n->next = next;
    return n;
}

void list_init(List * list) {
    *list = malloc(sizeof(**list));
    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->size = 0;
}

void list_add(List list, Item item) {
    if (list->head == NULL) {
        // list is empty
        list->head = new_Node(item, NULL);
        list->tail = list->head;
    } else {
        // list is not empty
        list->tail->next = new_Node(item, NULL);
        list->tail = list->tail->next;
    }
    list->size++;
}

void list_insert(List list, Item item, int index) {
    if (index > list->size) {
        // index exeeds list size
        return;
    }
    int i = 0;
    for (link x = list->head; x != NULL; x = x->next) {
        if (i == index) {
            x->next = new_Node(x->item, x->next);
            x->item = item;
            list->size++;
            return;
        }
        else { i++; }
    }
    if (i == list->size) {
        // Case of insertion at first position after last element
        list->tail->next = new_Node(item, NULL);
        list->tail = list->tail->next;
        list->size++;
    }
}

Item list_remove(List list, int index) {
    if (index >= list->size) {
        // index exeeds list size
        return NULL_ITEM;
    }
    if (index == 0) {
        link x = list->head;
        list->head = list->head->next;
        Item item = x->item;
        free(x);
        list->size--;
        return item;
    }
    int i = 0;
    index--;
    for (link x = list->head; x != NULL; x = x->next) {
        if (i == index) {
            link y = x->next;
            x->next = x->next->next;
            Item item = y->item;
            free(y);
            list->size--;
            return item;
        }
        else { i++; }
    }
    return NULL_ITEM;
}

Item list_get(List list, int index) {
    if (index >= list->size) {
        // index exceeds list size
        return NULL_ITEM;
    }
    int i = 0;
    for (link x = list->head; x != NULL; x = x->next) {
        if (i == index) { return x->item; }
        else { i++; }
    }
    return NULL_ITEM;
}

Item list_set(List list, int index, Item item) {
    return NULL_ITEM;
}

int list_size(List list) {
    return list->size;
}

void list_destroy(List list) {
    for (link x = list->head; list->head != NULL; x = list->head) {
        list->head = list->head->next;
        free(x);
    }
    list->tail = NULL;
    free(list);
}

Item * list_toArray(List list) {
    return NULL;
}

// TODO remove dependency on the type of the element of the list

void list_print(List list) {
    if (list->head != NULL) {
        printf("{ %d", list->head->item);
    } else {
        printf("{ }");
        return;
    }
    for (link x = list->head->next; x != NULL; x = x->next) {
        printf(", %d", x->item);
    }
    printf(" }");
}
