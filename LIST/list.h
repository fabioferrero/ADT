/*
 * LIST.h
 * written by Fabio Ferrero
 * fabio.ferrero@icloud.com
 */

/**
 * IMPORTANT: this ADT use item.h as a type for managing elements inside the
 * list. You have to implement it.
 * TODO generic type list
 */
#include "item.h"
#include "stdbool.h"

/**
 * A List is a basic data structure similar to an array, but it has a variable
 * size. When it is created, it is simply void. Adding items in the list make
 * it bigger and bigger, and removing items make it smaller.
 * So it changes its dimension dinamically.
 */
typedef struct list * List;

/**
 * Initialize the List - MANDATORY OPERATION
 */
void    list_init(List *);

/**
 * Add the specified Item at the end of the specified List
 */
void    list_add(List, Item);

/**
 * Inserts the specified Item at the specified position in the List
 */
void    list_insert(List, Item, int index);

/**
 * Remove the item at the specified position in the List
 * @return the item removed from the List
 */
Item    list_remove(List, int index);

/**
 * Returns the item at the specified position in the List
 */
Item    list_get(List, int index);

/**
 * Replaces the item at the specified position in the List with the specified Item
 * @return the Item previously at the specified position
 */
Item    list_set(List, int index, Item);

/**
 * Returns the actual number of items inside the specified List
 */
int     list_size(List);

/**
 * Removes all Items from the specified List
 * @note This function is important in order to avoid MEMORY LEACKS
 */
void    list_destroy(List);

/**
 * Returns an array of Items with all the elements in the specified List
 * @return an array of Items dinamically allocated.
 * @warning remember to free the returned array in order to avoid MEMORY LEACKS
 */
Item *  list_toArray(List);

/**
 * Print the specified List on stdout
 */
void    list_print(List);
