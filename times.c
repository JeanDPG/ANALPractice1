/**
 *
 * Descripcion: Implementation of time measurement functions
 *
 * Fichero: times.c
 * Autor: Carlos Aguirre Maeso
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */

#include "times.h"
#include "sorting.h"
#include <time.h>
#include "permutations.h"
#include <stdlib.h>
#include <stdio.h>


/***************************************************/
/* Function: average_sorting_time Date:            */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short average_sorting_time(pfunc_sort metodo, 
                              int n_perms,
                              int N, 
                              PTIME_AA ptime)
{

  int** array_perm;
  int start,stop,i,j,ob_current, ob_min=0, ob_max=0,time=0,ob_average=0;
  array_perm = generate_permutations(n_perms,N);
  
    
 
  ptime->N=N;
  ptime->n_elems=n_perms;
 
  for ( i = 0; i < n_perms; i++)
  {
    start=clock();
    ob_current=metodo(array_perm[i],0,N);
    stop=clock();
    time+=stop-start;
    ob_average+=ob_current;
    
    if (i == 0) {            
        ob_min = ob_current;
        ob_max = ob_current;
    } else {
        if (ob_current < ob_min) ob_min = ob_current;
        if (ob_current > ob_max) ob_max = ob_current;
    }
  }
  
  ptime->time=(time+0.)/n_perms;
  ptime->average_ob=ob_average/n_perms;
  ptime->max_ob=ob_max;
  ptime->min_ob=ob_min;
  
  for ( i = 0; i < n_perms; i++)
  {
    free(array_perm[i]);
  }
  free(array_perm); 
  
  return OK;

}

/***************************************************/
/* Function: generate_sorting_times Date:          */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short generate_sorting_times(pfunc_sort method, char* file, 
                                int num_min, int num_max, 
                                int incr, int n_perms)
{

  int i, num, n_times = (num_max - num_min)/incr + 1;
  
  PTIME_AA ptimes;
  if(!(ptimes=malloc(sizeof(ptimes[0])*n_times))){
    return ERR;
  }
  
  for ( num = num_min, i = 0; num <= num_max; i++, num += incr)
  {
    if(average_sorting_time(method,n_perms,num,&ptimes[i])!=OK){
      fprintf(stderr, "generate_sorting_times returned NULL (n_perms=%d, num=%d)\n", n_perms, num);
      free(ptimes);
      return ERR;
    }
  }
  
  save_time_table(file, ptimes, n_times);
  
  free(ptimes);
  return OK;
}

/***************************************************/
/* Function: save_time_table Date:                 */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short save_time_table(char* file, PTIME_AA ptime, int n_times)
{

  int i;
  FILE *fp;
  
  fp = fopen(file,"a");
  if(fp==NULL)return ERR;
  for ( i = 0; i < n_times; i++)
  {
    fprintf(fp, "%d\t%.3f\t%.3f\t%.3d\t%.3d\n", 
                ptime[i].N, 
                ptime[i].time, 
                ptime[i].average_ob,
                ptime[i].max_ob,
                ptime[i].min_ob);
  }
  fclose(fp);
  return OK;
  

}


