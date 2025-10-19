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
/* Function: InsertSort    Date:                   */
/* Your comment                                    */
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
/* Function: SelectSort    Date:                   */
/* Your comment                                    */
/***************************************************/
int BubbleSort(int* array, int ip, int iu)
{

  int flag = 1, i = iu-1, j = 0, ob = 0;
  
  if(!array ||ip>iu){
    return ERR;
  }
  
  if(iu<2)return 0;
  else{
  while (flag == 1 && i >= ip)
  {
    flag = 0;
    fprintf(stderr, "ob1 = %d\n", ob);
    fprintf(stderr, "ip=%d, i=%d\n", ip, i);
    for (j = ip; j < i; j++)
    {
      ob++;
      fprintf(stderr, "ob2 = %d\n", ob);
      if (array[j] > array[j+1])
      {
        swap(&array[j], &array[j+1]);
        flag = 1;
      }
      
    }
    i--;
  }
  fprintf(stderr, "ob3 = %d\n", ob);
  return ob;
  }
}

