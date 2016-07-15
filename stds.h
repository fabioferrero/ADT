
#include "LIST/item.h"
#include "LIST/list.h"

typedef struct fifo * Fifo;

Item    fifo_get(Fifo, int index);

// define a Gederic get function that maps to the correct function
// depending on the type of the first parameter
#define get(x, y) _Generic((x), List: list_get, \
                                  Fifo: fifo_get)(x, y)
