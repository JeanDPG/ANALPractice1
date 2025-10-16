#ifndef EXTERN_H
#define EXTERN_H

/* constants */

#ifndef ERR
  #define ERR -1
  #define OK (!(ERR))
#endif

int swap(int* a, int* b);

#endif