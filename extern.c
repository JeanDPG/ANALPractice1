#include "extern.h"
#include <stdlib.h>

int swap(int* a, int* b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
    return OK;
}