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

#include "extern.h"
#include <stdlib.h> 


/***************************************************/
/* Function: InsertSort    Date:                   */
/* Your comment                                    */
/***************************************************/
int InsertSort(int* array, int ip, int iu)
{

  int i = 0, j = 0, ob = 0;

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
/* Function: SelectSort    Date:                   */
/* Your comment                                    */
/***************************************************/
int BubbleSort(int* array, int ip, int iu)
{

  int flag = 1, i = iu, j = 0, ob = 0;

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

