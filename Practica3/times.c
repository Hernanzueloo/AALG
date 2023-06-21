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
#include <time.h>
#include "sorting.h"
#include "search.h"
#include "permutations.h"
#include <stdio.h>
#include <stdlib.h>

/***************************************************/
/* Function: average_sorting_time Date:            */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short average_sorting_time(pfunc_sort metodo, int n_perms, int N, PTIME_AA ptime)
{ 

  int i, **p = NULL, n_ob = 0, min_ob=0, max_ob = 0;
  double suma_ob=0;
  clock_t t1, t2;

  
  if (n_perms < 1 || N < 1 || !ptime || !metodo)
    return ERR; /*Control de errores*/
  
  p = generate_permutations(n_perms, N); /*Generacion de permutaciones y control de errores*/
  if (!p)
    return ERR;
  t1 = clock(); /*Almacenamiento del tiempo al comenzar*/
  /*LLamamos a la función una primera vez para inicializar los valores*/

  n_ob = metodo(p[0], 0, N - 1);
  if ((n_ob < 0)) /*Control de errores*/
  {
    for (i = N - 1; i >= 0; i--)
    {
      free(p[i]);
    }
    free(p);
    return ERR;
  }

  /*Inicializamos los valores*/
  min_ob = n_ob;
  max_ob = n_ob;
  suma_ob += (double)n_ob/n_perms;
  /*Seguimos ejecutando metodo n_perms veces*/
  for (i = 1; i < n_perms; i++)
  {
    n_ob = metodo(p[i], 0, N - 1);
    if ((n_ob) < 0) /*Control de errores*/
    {
      for (i = n_perms - 1; i >= 0; i--)
      {
        free(p[i]);
      }
      free(p);
      return ERR;
    }
   
    if (n_ob < min_ob) /*Actualizacion del min_ob si es pertinente*/
    {
      min_ob = n_ob;
    }
    else if (n_ob > max_ob) /*Actualizacion del max_ob si es pertinente*/
    {
      max_ob = n_ob;
    }
    suma_ob += (double)n_ob/n_perms;
  }
  t2 = clock(); /*Almacenamiento del tiempo al finalizar*/
  
  /*Almacenamiento de las caracteristicsd de la funcion de ordenacion indicada con los parametros dados*/
  ptime->time = (double)(t2 - t1) / (double)n_perms;
  ptime->N = N;
  ptime->n_elems = n_perms;
  ptime->average_ob =suma_ob;
  ptime->min_ob = min_ob;
  ptime->max_ob = max_ob;
 
  for (i = 0; i <n_perms; i++) /*Liberacion de la memoria*/
      {

        free(p[i]);
      }
  
  free(p);
 
  return OK;
}

/***************************************************/
/* Function: generate_sorting_times Date:          */
/*                                                 */
/* Your documentation                              */
/***************************************************/

/*ret = generate_sorting_times(MergeSort, nombre,num_min, num_max,incr, n_perms);*/
short generate_sorting_times(pfunc_sort method, char *file, int num_min, int num_max, int incr, int n_perms)
{ 
 
  TIME_AA *ptime = NULL;
  int i, j=0, flag=-1, tam;
  
  if (!file || num_min < 0 || num_max < 0 || num_max< num_min) /*Control de errores*/
    return ERR;

  

  tam = ((num_max - num_min) / incr )+ 1; /*Reserva dinamica de la tabla de datos*/
 
  printf("\ncalloc 1\n");
  ptime = (TIME_AA *)calloc(tam, sizeof(TIME_AA)); /*Reserva de memoria*/
  if (!ptime)
    return ERR;
  
  for (i = num_min, j = 0, flag = -1; i <= num_max && j<tam; j++, i+= incr)
  { /*Ordenacion y almacenamiento de datos*/
    flag = average_sorting_time(method, n_perms, i, &ptime[j]); 
    if (flag == ERR)
    { 
      free(ptime);
      return ERR;
    }
  }
  
  if (save_time_table(file, ptime, tam) < 0) /*Guardar en fichero controlando errores*/
  {
    free(ptime);
    return ERR;
  }
  free(ptime); /*Liberacion de memoria*/
  return OK;
}

/***************************************************/
/* Function: save_time_table Date:                 */
/*                                                 */
/* Your documentation                              */
/***************************************************/
short save_time_table(char *file, PTIME_AA ptime, int N)
{
  FILE *f = NULL;
  int i;
  if (!file || !ptime || N < 1) /*Control de errores*/
    return ERR;

  f = fopen(file, "w"); /*Apertura de archivo*/
  if (!f)
    return ERR;
  for (i = 0; i < N; i++) /*Escritura de la tabla en el fichero proporcionado*/
  {
    if (5 > fprintf(f, "%d    %f    %f    %d   %d\n", ptime[i].N, ptime[i].time, ptime[i].average_ob, ptime[i].max_ob, ptime[i].min_ob))
    {
      fclose(f);
      return ERR;
    }
  }
  fclose(f);

  return OK;
}

short average_search_time(pfunc_search method, pfunc_key_generator generator, char order, int N, int n_times, PTIME_AA ptime){
  int i, *table,*keys, pos,max_ob,min_ob,n_ob;
  long count=0;
  PDICT dict;
  clock_t t1, t2;
  printf("\nN: %d ", N);/*Borrar*/
  if(!method||!generator||!ptime||N<0||(((int)order!=SORTED)&&((int)order!=NOT_SORTED))) return ERR;
  dict=init_dictionary(N,order);
  if(!dict) return ERR;
  
  if(order==SORTED){/*Tabla ordenada*/
    table=(int*)calloc(N,sizeof(int));
    if(!table) return ERR;
    uniform_key_generator(table,N,N);
    (void)massive_insertion_dictionary (dict,table,N);
    free(table);
  }
  else{ /*Tabla desordenada*/
    table=generate_perm(N);
    if(!table) return ERR;

    (void)massive_insertion_dictionary (dict, table, N);
    free(table);
  }

  keys=(int*)calloc(N*n_times,sizeof(int));
  if(!keys)  return ERR;
  generator(keys,n_times*N,N);
  
  t1 = clock();

  count=search_dictionary(dict,keys[0],&pos,method);
  max_ob=count;
  min_ob=count;
   
  for(i=1;i<n_times*N;i++){
    
    n_ob=search_dictionary(dict,keys[i],&pos,method);
    if(n_ob<0){
      printf("Caso: %d %d %d ", i, keys[i], n_ob);/*Borrar*/
    }
    if(n_ob>max_ob){
      max_ob=n_ob;
    }
    if(n_ob<min_ob){
      min_ob=n_ob;
    }
    count+=n_ob;
    
  }
  t2 = clock();
  
  ptime->time = (double)(t2 - t1) / ((double)n_times*N);
  ptime->N=N;
  ptime->n_elems= n_times*N;
  ptime->max_ob=max_ob;
  ptime->min_ob=min_ob;
  ptime->average_ob=(double)count/(double)(n_times*N);
  free_dictionary(dict);
  free(keys);
  return OK;
}

short average_search_time_aux(pfunc_search method, pfunc_key_generator generator, char order, int N, int n_times, PTIME_AA ptime,int n_perms){
  int i, *table,*keys, pos,max_ob,min_ob,n_ob, j;
  long count=0;
  PDICT dict;
  clock_t t1, t2;
  printf("\nN: %d ", N);/*Borrar*/

  if(!method||!generator||!ptime||N<0||(((int)order!=SORTED)&&((int)order!=NOT_SORTED))) return ERR;
  
  for(j=1;j<=n_perms;j++){
    dict=init_dictionary(N,order);
    if(!dict) return ERR;
      if(order==SORTED){/*Tabla ordenada*/
        table=(int*)calloc(N,sizeof(int));
        if(!table) return ERR;
        uniform_key_generator(table,N,N);
        (void)massive_insertion_dictionary (dict,table,N);
        free(table);
      }
      else{ /*Tabla desordenada*/
        table=generate_perm(N);
        if(!table) return ERR;

        (void)massive_insertion_dictionary (dict, table, N);
        free(table);
      }

      keys=(int*)calloc(N*n_times,sizeof(int));
      if(!keys)  return ERR;
      generator(keys,n_times*N,N);
      
      t1 = clock();
      n_ob=search_dictionary(dict,keys[0],&pos,method);
      count+=n_ob;
      max_ob=n_ob;
      min_ob=n_ob;
      
      for(i=1;i<n_times*N;i++){
        
        n_ob=search_dictionary(dict,keys[i],&pos,method);
        if(n_ob<0){
          printf("Caso: %d %d %d ", i, keys[i], n_ob);/*Borrar*/
        }
        if(n_ob>max_ob){
          max_ob=n_ob;
        }
        if(n_ob<min_ob){
          min_ob=n_ob;
        }
        count+=n_ob;
        
      }
      free_dictionary(dict);
     free(keys);
  }
  t2 = clock();
  
  ptime->time = (double)(t2 - t1) /( (double)n_times*N*n_perms);
  ptime->N=N;
  ptime->n_elems= n_times*N*n_perms;
  ptime->max_ob=max_ob;
  ptime->min_ob=min_ob;
  ptime->average_ob=(double)count/(double)(n_times*N*n_perms);
  
  return OK;

}

short generate_search_times(pfunc_search method, pfunc_key_generator generator,
int order, char* file, int num_min, int num_max, int incr, int n_times){
  PTIME_AA ptime=NULL;
  int i,j,tam;
  if(!method||!generator||!file||num_min<0||num_max<num_min||n_times<1) return ERR;

  tam = (num_max - num_min) / incr + 1; /*Reserva dinamica de la tabla de datos*/
  ptime = (TIME_AA *)calloc(tam, sizeof(TIME_AA)); /*Reserva de memoria*/  
  if(!ptime){
    return ERR;
  }
  
  for(i=num_min,j=0; i<=num_max && j<tam; i+=incr,j++){
    if(ERR==average_search_time(method, generator, (char)order, i, n_times, &ptime[j])){
      free(ptime);
      return ERR;
    }
  }
  printf("\n");/*Borrar*/
  if(ERR==save_time_table(file,ptime, tam)){
    free(ptime);
    return ERR;
  }
 free(ptime);  /*Posible error*/
  
  return OK;
}

short generate_search_times_aux(pfunc_search method, pfunc_key_generator generator,
int order, char* file, int num_min, int num_max, int incr, int n_times, int n_perms){
  PTIME_AA ptime=NULL;
  int i,j,tam;
  if(!method||!generator||!file||num_min<0||num_max<num_min||n_times<1) return ERR;

  tam = (num_max - num_min) / incr + 1; /*Reserva dinamica de la tabla de datos*/
  ptime = (TIME_AA *)calloc(tam, sizeof(TIME_AA)); /*Reserva de memoria*/  
  if(!ptime){
    return ERR;
  }
  
  for(i=num_min,j=0; i<=num_max && j<tam; i+=incr,j++){
    /*printf("Tamaño: %d\n ",i);*/
    if(ERR==average_search_time_aux(method, generator, (char)order, i, n_times, &ptime[j],n_perms)){
      free(ptime);
      return ERR;
    }
  }
  printf("\n");/*Borrar*/

  if(ERR==save_time_table(file,ptime, tam)){
    free(ptime);
    return ERR;
  }
 free(ptime);  /*Posible error*/
  
  return OK;
}