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
  int i, **p = NULL, suma_ob = 0, n_ob = 0, min_ob, max_ob = 0;
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
  suma_ob += n_ob;
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
    suma_ob += n_ob;
  }
  t2 = clock(); /*Almacenamiento del tiempo al finalizar*/
  
  /*Almacenamiento de las caracteristicsd de la funcion de ordenacion indicada con los parametros dados*/
  ptime->time = (double)(t2 - t1) / (double)n_perms;
  ptime->N = N;
  ptime->n_elems = n_perms;
  ptime->average_ob = (double)suma_ob / n_perms;
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
short generate_sorting_times(pfunc_sort method, char *file, int num_min, int num_max, int incr, int n_perms)
{
  TIME_AA *ptime = NULL;
  int i, j, flag, tam;

  if (!file || num_min < 0 || num_max < 0) /*Control de errores*/
    return ERR;



  tam = (num_max - num_min) / incr + 1; /*Reserva dinamica de la tabla de datos*/

  ptime = (TIME_AA *)calloc(tam, sizeof(TIME_AA)); /*Reserva de memoria*/
  if (!ptime)
    return ERR;

  for (i = num_min, j = 0, flag = 0; i <= num_max; j++, i += incr)
  { /*Ordenacion y almacenamiento de datos*/
    flag = average_sorting_time(method, 100, i, &ptime[j]);
    if (flag == -1)
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
short save_time_table(char *file, PTIME_AA ptime, int n_times)
{
  FILE *f = NULL;
  int i;
  if (!file || !ptime || n_times < 1) /*Control de errores*/
    return ERR;

  f = fopen(file, "w"); /*Apertura de archivo*/
  if (!f)
    return ERR;

  for (i = 0; i < n_times; i++) /*Escritura de la tabla en el fichero proporcionado*/
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
