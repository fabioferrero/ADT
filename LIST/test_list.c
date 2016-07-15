
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

    printf("\nSecond element: %d\n", elem);

    printf("List size: %d\n", list_size(myList));

    list_destroy(myList);

    printf("List destroyed\n");

    return 0;
}
