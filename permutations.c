/**
 *
 * Descripcion: Implementation of function that generate permutations
 *
 * File: permutations.c
 * Autor: Carlos Aguirre
 * Version: 1.1
 * Fecha: 21-09-2019
 *
 */


#include "permutations.h"

#include "extern.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/***************************************************/
/* Function: random_num Date:                      */
/* Authors:                                        */
/*                                                 */
/* Rutine that generates a random number           */
/* between two given numbers                       */
/*                                                 */
/* Input:                                          */
/* int inf: lower limit                            */
/* int sup: upper limit                            */
/* Output:                                         */
/* int: random number                              */
/***************************************************/
int random_num(int inf, int sup)
{

  return rand()/(RAND_MAX+1.) * (sup-inf+1) + inf;

}

/***************************************************/
/* Function: generate_perm Date:                   */
/* Authors:                                        */
/*                                                 */
/* Rutine that generates a random permutation      */
/*                                                 */
/* Input:                                          */
/* int n: number of elements in the permutation    */
/* Output:                                         */
/* int *: pointer to integer array                 */
/* that contains the permitation                   */
/* or NULL in case of error                        */
/***************************************************/
int* generate_perm(int N)
{

  int *perm;
  int j, r;

  perm = (int*)malloc(N*sizeof(int));

  if (perm == NULL) return NULL;

  for (j = 0; j < N; j++) perm[j] = j+1;
  
  for (j = 0; j < N; j++) {
    r = random_num(j,N-1);
    swap(&perm[j], &perm[r]);
  }

  return perm;

}

/***************************************************/
/* Function: generate_permutations Date:           */
/* Authors:                                        */
/*                                                 */
/* Function that generates n_perms random          */
/* permutations with N elements                    */
/*                                                 */
/* Input:                                          */
/* int n_perms: Number of permutations             */
/* int N: Number of elements in each permutation   */
/* Output:                                         */
/* int**: Array of pointers to integer that point  */
/* to each of the permutations                     */
/* NULL en case of error                           */
/***************************************************/
int** generate_permutations(int n_perms, int N)
{

   int** array;
   int i,j;

   if(!(array=(int**)malloc(n_perms*sizeof(int*)))){

        fprintf(stderr, "ERROR: malloc failed in generate_permutations(n_perms=%d, N=%d)\n", n_perms, N);
        return NULL;
    }
   for ( i = 0; i < n_perms; i++)
   {
    if(!(array[i]=generate_perm(N))){
      for ( j = i-1; j >= 0; j--)
      {
        free(array[j]);
      }
      free(array);
    return NULL;
    }
   }
   return array;

}
