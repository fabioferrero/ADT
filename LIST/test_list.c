
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

int randomInt(int limit) {
    return rand() % limit;
}

int main() {

    List myList;
    Item elem;

    list_init(&myList);

    printf("List size: %d\n", list_size(myList));

    srand(time(NULL));

    /* Add 5 elements to the list */
    list_add(myList, randomInt(100));
    list_add(myList, randomInt(100));
    list_add(myList, randomInt(100));
    list_add(myList, randomInt(100));
    list_add(myList, randomInt(100));

    /* Print the list on stdout */
    list_print(myList);

    /* Take the second element (index 1) of the List */
    elem = list_get(myList, 1);

    printf("\nList size: %d\n", list_size(myList));
    printf("Second element: %d\n", elem);

    /* Try to set the second element as 0 */
    list_insert(myList, 0, 1);
    printf("Inserted 0 at index 1\n");

    list_print(myList);

    elem = list_get(myList, 1);

    printf("\nList size: %d\n", list_size(myList));
    printf("Second element: %d\n", elem);

    // Remove two elements
    list_remove(myList, 5);
    printf("Removed at index 5\n");
    list_print(myList);
    printf("\nList size: %d\n", list_size(myList));

    list_remove(myList, 4);
    printf("Removed at index 4\n");
    list_print(myList);
    printf("\nList size: %d\n", list_size(myList));

    // Set two elements
    list_set(myList, 0, 0);
    printf("Setted 0 = 0\n");
    list_print(myList);
    printf("\nList size: %d\n", list_size(myList));

    list_set(myList, 1, 1);
    printf("Setted 1 = 1\n");
    list_print(myList);
    printf("\nList size: %d\n", list_size(myList));

    // Try toArray
    Item * myArray = list_toArray(myList);
    printf("Array of 2: %d\n", myArray[2]);

    list_destroy(myList);
    free(myArray);

    printf("List destroyed\n");

    return 0;
}
