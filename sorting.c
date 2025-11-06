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
#include <math.h>
#include <string.h>


/***************************************************/
/* Function: InsertSort Date: 10/10/2025           */
/* Authors: Jose Luis Sanchez                      */
/*                                                 */
/* Function that implements the insertsort         */
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
  int i = 0, j = 0, ob = 0, key;
  if(!array ||ip>iu) return ERR;
  
  for (i = ip + 1; i <= iu; i++)
  {
    j = i-1;
    key= array[i];
    
    while (j >= ip)
    {
      ob++;
      if (array[j] > key){
        array[j + 1] = array[j];
        j--;
      }else{
        break;
      }
    }
    array[j+1] = key;
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
  int flag = 1, i = iu, j = 0, ob = 0;
  
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


int quicksort(int* tabla, int ip, int iu){
  int m, pos;
  
  if(ip > iu) return ERR;
  else if(ip == iu) return OK;
  else{
    m = partition(tabla, ip, iu, &pos);
    if(ip < m-1){
      quicksort(tabla, ip, m-1);
    }
    else if( m+1 < iu){
      quicksort(tabla, m+1, iu);
    }
  }
  return OK;
}


int partition(int* tabla, int ip, int iu,int *pos){
  int m, k, i;
  m = median(tabla, ip, iu, pos);
  k = *pos;
  swap(&tabla[ip], &tabla[m]);
  m = ip;

  for (i = ip+1; i < iu; i++)
  {
      if(tabla[i] < k){
        m++;
        swap(&tabla[i], &tabla[m]);
      }
  }
  swap(&tabla[ip], &tabla[m]);
  return m;
}

int median(int *tabla, int ip, int iu,int *pos){
  *pos = ip;
  return 0;
}

int median_avg(int *tabla, int ip, int iu, int *pos){
  
  return (ip + iu)/2;
}

int median_stat(int *tabla, int ip, int iu, int *pos){
    if(tabla[ip] > tabla[iu]){
      if(tabla[*pos] > tabla[ip]){
        return ip;
      }else{
        if(tabla[iu] > tabla[*pos]){
          return iu;
        }else{
          return *pos;
        }
      }
    }else{
      if(tabla[*pos] > tabla[iu]){
        return *pos;
      }else{
        if(tabla[ip] > tabla[*pos]){
          return iu;
        }else{
          return *pos;
        }
      }
    }
  }
  


int mergesort(int* tabla, int ip, int iu){
  int m;
  if(ip > iu) return ERR;
  else if(ip == iu) return OK;
  else{
    m = (int)floor((ip + iu)/2);
    mergesort(tabla, ip, m);
    mergesort(tabla,  m + 1, iu);
    return merge(tabla, ip, iu,m );
  }

}



int merge(int* tabla, int ip, int iu, int imedio){
  int *aux, i,j,k, ob = 1;
  if(!(aux = (int*)malloc((iu - ip + 1) * sizeof(int)))){
    return ERR;
  }
  k = 0;
  
  for ( i = ip, j = imedio + 1; i <= imedio && j <= iu; k++)
  {
    ob++;
    if(tabla[i] < tabla[j]){
      aux[k] = tabla[i];
      i++;
    } 
    else{
      aux[k] = tabla[j];
      j++;
    }
  }
  
  if(i > imedio){
    while(j <= iu){
      aux[k] = tabla[j];
      j++,k++;
    }
  }else if(j > iu){
      while(i <= imedio){
        aux[k] = tabla[i];
        i++,k++;
      }
  }

  memcpy(&tabla[ip], aux, (iu - ip +1) * sizeof(int));

  
  free(aux);
  
  return ob;
  
}