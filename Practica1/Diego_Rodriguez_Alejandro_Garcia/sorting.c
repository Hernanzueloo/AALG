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

/***************************************************/
/* Function: SelectSort    Date:                   */
/* Your comment                                    */
/***************************************************/
/*Cambia los valores almacenados de una variable en la de la otra*/
void swap1(int *x, int *y) 
{
  int aux = *x;
  *x = *y;
  *y = aux;
}


int SelectSort(int *array, int ip, int iu)
{
  int i, m, cont = 0;

  if (!array || ip < 0 || iu < 0 || iu < ip) /*Control de errores*/
    return ERR;

  for (i = ip; i < iu; i++) /*Ordenacion*/
  {
    m = min(array, i+1 , iu); /*Almacenamiento del minimo*/
    cont += iu - i;
    if (m == -1) /*Control de errores*/
      return ERR;

    swap1(&array[m], &array[i]);
  }
  return cont;
}


int SelectSortInv(int *array, int ip, int iu)
{  
  int i, m, cont = 0;

   if (!array || ip < 0 || iu < 0 || iu < ip) /*Control de errores*/
    return ERR;

  /*Ordenacion al contrario que el SelectShort porque el indice comienza por el ultimo y acaba en el primero*/
  for (i = iu; i > ip; i--) 
  {
    
    m = min(array, ip , i-1); /*Almacenamiento del minimo*/
    cont += i - ip;
    if (m == -1) /*Control de errores*/ 
      return ERR;

    swap1(&array[m], &array[i]);
  }
  return cont;
}

int min(int *array, int ip, int iu)
{
  int i, min;
  if (!array || ip > iu || ip < 0) /*Control de errores*/ 
    return ERR;

  min = ip;
  for (i = ip; i <= iu; i++) /*Compara todos los valores de la lista proporcionada para encontrar el minimo*/ 
  {
    if (array[min] > array[i])
    {
      min = i;
    }
  }
  return min;
}
