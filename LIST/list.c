/*
* LIST.c
* written by Fabio Ferrero
* fabio.ferrero@icloud.com
*/

#include "list.h"

typedef struct node * link;

struct node {
    Item item;
    link next;
};

struct list {
    link head;
    int size;
};
