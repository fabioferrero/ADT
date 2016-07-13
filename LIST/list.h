/*
* LIST.h
* written by Fabio Ferrero
* fabio.ferrero@icloud.com
*/

#include "stdbool.h"
#include "item.h"

/**
* A List is a basic data structure similar to an array, but it has a variable
* size.
*/
typedef struct list * List;

/* Initialize the List
- MANDATORY OPERATION */
void    list_init(List);

/* Add the specified Item at the end of the specified List */
void    list_add(List, Item);

/* Inserts the specified Item at the specified position in the List */
void    list_insert(List, Item, int index);

/* Returns the element at the specified position in the specified List */
Item    list_get(List, int index);

/* Replaces the Item at the specified position in the List with the specified Item */
Item    list_set(List, Item, int index);

/* Returns the actual number of elements inside the specified List */
int     list_size(List);

/* Removes all Items from the specified List
- MANDATORY OPERATION in order to avoid MEMORY LEACK */
void    list_destroy(List);

/* Returns an array of Items with all the elements in the specified List */
Item *  list_toArray(List);
