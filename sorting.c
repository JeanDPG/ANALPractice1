/**
 *
 * Descripcion: Implementation of sorting functions
 *
 * Fichero: sorting.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */


#include "sorting.h"
#include <stdio.h>
#include "extern.h"
#include <stdlib.h> 


/***************************************************/
/* Function: InsertSort Date: 10/10/2025           */
/* Authors: Jose Luis Sanchez                      */
/*                                                 */
/* Function that implements the bubblesort         */
/* algorithm                                       */
/*                                                 */
/* Input:                                          */
/* int* array: pointer to an array of integers to  */
/*             sort                                */
/* int ip: index of the first element on the range */
/*         to sort                                 */
/* int iu: index of the last element on the range  */
/*         to sort                                 */   
/* Output:                                         */
/* ERR: if there was a problem with prameters      */
/* int: number of basic operations                 */
/***************************************************/
int InsertSort(int* array, int ip, int iu)
{
  int i = 0, j = 0, ob = 0;
  if(!array ||ip>iu) return ERR;
  
  for (i = ip + 1; i <= iu; i++)
  {
    j = i;
    ob++;
    while (j > ip && array[j-1] > array[j])
    {
      swap(&array[j], &array[j-1]);
      j--;
    }
  }
  return ob;
}


/***************************************************/
/* Function: BubbleSort Date: 9/10/2025            */
/* Authors: Jose Luis Sanchez                      */
/*                                                 */
/* Function that implements the bubblesort         */
/* algorithm                                       */
/*                                                 */
/* Input:                                          */
/* int* array: pointer to an array of integers to  */
/*             sort                                */
/* int ip: index of the first element on the range */
/*         to sort                                 */
/* int iu: index of the last element on the range  */
/*         to sort                                 */   
/* Output:                                         */
/* ERR: if there was a problem with parameters     */
/* int: number of basic operations                 */
/***************************************************/
int BubbleSort(int* array, int ip, int iu)
{
  int flag = 1, i = iu-1, j = 0, ob = 0;
  
  if(!array ||ip>iu){
    return ERR;
  }
  while (flag == 1 && i >= ip)
  {
    flag = 0;
    for (j = ip; j < i; j++)
    {
      ob++;
      if (array[j] > array[j+1])
      {
        swap(&array[j], &array[j+1]);
        flag = 1;
      }
    }
    i--;
  }
  return ob;
}

