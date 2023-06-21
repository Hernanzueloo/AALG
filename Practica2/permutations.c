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
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include "permutations.h"

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

int random_num(int inf, int sup) /*genera un numero entero aleatorio entre el inf y el sup*/
{
    if (inf > sup)
    { /*Control de errores*/

        return -1;
    }

    return inf + (int)((sup - inf + 1.0) * rand() / (RAND_MAX + 1.0)); /*Formula del libro*/
}

/*Cambia el valor almacenado en cada variable por el de la otra*/

void swap(int *x, int *y)
{
    int aux;

    if (!x || !y)
        return;

    aux = *x;
    *x = *y;
    *y = aux;
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

/*Genera una permutacion de tamanyo N ordenado aleatoriamente de forma equiprobable*/
int *generate_perm(int N)
{

    int i,ret;
    int *perm = NULL;

    if (N < 1) /*Control de errores*/
        return NULL;

    perm = (int *)malloc(N * sizeof(int)); /*Reserva de memoria*/
    if (!perm)                             /*Control de errores*/
        return NULL;

    for (i = 0; i < N; i++) /*Almacena en cada posicion de la permutacion el valor de su posicion mas 1*/
    {
        perm[i] = i + 1;
    }
    for (i = 0; i < N; i++) /*Desordena la permutacion generada anteriormente*/
    {
        ret=random_num(i, N - 1);
        if(ret==-1){
            return NULL;
        }
        swap(&perm[i], &perm[ret]);
    }

    return perm; /*Devuelve el puntero de la permutacion*/
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
int **generate_permutations(int n_perms, int N)
{
    int **tabla = NULL;
    int i;

    if (n_perms < 1 || N < 1) /*Control de errores*/
        return NULL;
    /*Reservamos la memoria*/
    tabla = (int **)malloc(n_perms * sizeof(int *));
    if (!tabla) /*Controlamos que la memoria se haya reservado adecuadamente*/
        return NULL;

    for (i = 0; i < n_perms; i++) /*Generacion de n_perms permutaciones aleatorias*/
    {
        tabla[i] = generate_perm(N);
        if (!tabla[i]) /*Control de errores*/
        {
            for (i = i - 1; i >= 0; i--)
            {
                free(tabla[i]);
            }
            free(tabla);
            return NULL;
        }
    }

    return tabla;
}

