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
#include <stdlib.h>

/***************************************************/
/* Function: SelectSort    Date:                   */
/* Your comment                                    */
/***************************************************/


int median(int *tabla, int ip, int iu, int *pos);
void swap1(int *x, int *y);
int merge(int* tabla, int ip, int iu, int imedio);
int min(int *array, int ip, int iu);
int max(int a, int b);
int partition(int *tabla, int ip, int iu, int *pos);
int partition1(int *tabla, int ip, int iu, int *pos);

int median_avg(int *tabla, int ip, int iu, int *pos);
int median_stat(int *tabla, int ip, int iu, int *pos);

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
    if (m == ERR) /*Control de errores*/
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
    if (m == ERR) /*Control de errores*/ 
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


int merge(int* tabla, int ip, int iu, int imedio){
  int j1=ip, j2=imedio, *t=NULL, m=0, coste=0;

  if(!tabla) return ERR; /*Control de errores*/

  t=(int*)calloc(iu-ip+1, sizeof(int));
  if(!t) return ERR;

  while((j1<imedio)&&(j2<=iu)){
    if(tabla[j1]<tabla[j2]){
      t[m]=tabla[j1];
      j1++;
      m++;
    }
    else{
      t[m]=tabla[j2];
      j2++;
      m++;
    }
  }
  coste=m;

  while(j1<imedio){
    t[m]=tabla[j1];
    j1++;
    m++;
  }
  while(j2<=iu){
    t[m]=tabla[j2];
    j2++;
    m++;
  }

  for(m=0; m<=iu-ip; m++) tabla[ip+m]=t[m]; /*Copiamos la tabla ordenada en el espacio adecuado de la tabla proporcionada*/
  free(t);

  return coste; /*Devolvemos el coste*/
}
int MergeSortProf(int* tabla, int ip, int iu){
  int imedio, m1, m2, m3;

  if(!tabla||ip>iu) return ERR;

  if(ip==iu) return 0;

  imedio=(iu-ip)/2+ip;
  m1=MergeSortProf(tabla, ip, imedio);
  if(m1==ERR) return ERR;
  m2=MergeSortProf(tabla,imedio+1, iu);
  if(m2==ERR) return ERR;


  m3=merge(tabla, ip, iu, imedio+1);
  if(m3==ERR) return ERR;

  return max(m1,m2)+1;
}

int MergeSort(int* tabla, int ip, int iu){
  int imedio, m1, m2, m3;

  if(!tabla||ip>iu) return ERR;

  if(ip==iu) return OK;

  imedio=(iu-ip)/2+ip;
  m1=MergeSort(tabla, ip, imedio);
  if(m1==ERR) return ERR;
  m2=MergeSort(tabla,imedio+1, iu);
  if(m2==ERR) return ERR;


  m3=merge(tabla, ip, iu, imedio+1);
  if(m3==ERR) return ERR;

  return m1+m2+m3;
}

/*status QS(tabla T, ind P, ind U)
    si P>U:
        devolver ERROR;
    si P==U:
        devolver OK;
    else:
        M=Partir(T,P,U);
        si P<M-1:
            QS(T,P,M-1);
        si M+1 < U:
            QS(T,M+1,U);
devolver OK;
*/
void WorstCaseMergeRec(int *tabla,int *aux,int ip,int iu){
  int i,j;
    if(ip >= (iu -1 )){
        return ;
    }
     
    for(i=ip,j=ip;i<iu;i+=2,j++){
        aux[j]=tabla[i];
        aux[j+(iu-ip+1)/2]=tabla[i+1];
    }
     for(i=ip;i<=iu;i++){
      tabla[i]=aux[i];
    }

    WorstCaseMergeRec(tabla,aux,ip,(iu-ip)/2+ip);

    WorstCaseMergeRec(tabla,aux,(iu-ip)/2+1+ip,iu);
    return ;
}
void WorstCaseMerge(int *tabla, int ip,int iu){

  int *aux=NULL;
    if(!tabla || ip>iu){
        return ;
    }
    aux=(int*)calloc(iu-ip+1,sizeof(int));
    if(!aux){
      return;
    } 

    WorstCaseMergeRec(tabla,aux,ip,iu);
    free(aux);
    return ;
}
int max(int a, int b){
  if(a<b){
    return b;
  }
  return a;
}
int QuickSortProfAux(int *tabla, int ip, int iu)
{
    int pos, cont,l=0,r=0;
    if (!tabla || ip > iu)
    {
        return ERR;
    }

    if (ip == iu)
    {

        return 0;
    }
    else
    { 
      cont= partition1(tabla, ip, iu, &pos);
      if(cont==ERR){
        return ERR;
      }
      if(ip<pos){
         l= QuickSortProf(tabla, ip, pos - 1);
      }
      if(iu>pos){
        r= QuickSortProf(tabla, pos + 1, iu);
      }
    }
    
    return 1+max(l,r);
}
int QuickSortProf(int *tabla, int ip, int iu)
{
    int pos, cont,l=0,r=0;
    if (!tabla || ip > iu)
    {
        return ERR;
    }

    if (ip == iu)
    {

        return 0;
    }
    else
    { 
      cont= partition(tabla, ip, iu, &pos);
      if(cont==ERR){
        return ERR;
      }
      if(ip<pos){
         l= QuickSortProf(tabla, ip, pos - 1);
      }
      if(iu>pos){
        r= QuickSortProf(tabla, pos + 1, iu);
      }
    }
    
    return 1+max(l,r);
}
int QuickSort(int *tabla, int ip, int iu)
{
    int pos, cont;
    if (!tabla || ip > iu)
    {
        return ERR;
    }

    if (ip == iu)
    {
        return 0;
    }
    else
    {
      cont = partition(tabla, ip, iu, &pos);
      if(cont==ERR){
        return ERR;
      }
      if(ip<pos){
         cont += QuickSort(tabla, ip, pos - 1);
      }
      if(iu>pos){
        cont += QuickSort(tabla, pos + 1, iu);
      }
    }

    return cont;
}
/*ind Partir(tabla T, ind P, ind U)
    M=Medio(T,P,U);
    k=T[M];
    swap(T[P],T[M]);
    M=P;
    para i de P+1 a U:
        si T[i]<k:
            M++;
            swap(T[i],T[M]);
    swap(T[P],T[M]);
devolver M;
*/
int partition1(int *tabla, int ip, int iu, int *pos)
{
    int cont, k, m, i;
    if (!tabla || ip > iu || !pos)
    {
        return ERR;
    }
    cont = median_stat(tabla, ip, iu, pos);
    if(cont==ERR){
        return ERR;
      }
    m = *pos;
    k = tabla[m];

    swap1(&tabla[ip], &tabla[m]);
    m = ip;
    for (i = ip + 1; i <= iu; i++)
    {
        cont++;
        if (tabla[i] < k)
        {
            m++;
            swap1(&tabla[i], &tabla[m]);
        }
    }

    swap1(&tabla[ip], &tabla[m]);
    *pos = m;
    return cont;
}
int partition(int *tabla, int ip, int iu, int *pos)
{
    int cont, k, m, i;
    if (!tabla || ip > iu || !pos)
    {
        return ERR;
    }
    cont = median(tabla, ip, iu, pos);
    if(cont==ERR){
        return ERR;
      }
    m = *pos;
    k = tabla[m];

    swap1(&tabla[ip], &tabla[m]);
    m = ip;
    for (i = ip + 1; i <= iu; i++)
    {
        cont++;
        if (tabla[i] < k)
        {
            m++;
            swap1(&tabla[i], &tabla[m]);
        }
    }

    swap1(&tabla[ip], &tabla[m]);
    *pos = m;
    return cont;
}

int median(int *tabla, int ip, int iu, int *pos)
{
    if (!tabla || ip > iu || !pos)
    {
        return ERR;
    }
    *pos = ip;
    return 0;
}


int median_avg(int *tabla, int ip, int iu, int *pos)
{
    if (!tabla || ip > iu || !pos)
    {
        return ERR;
    }
    
    *pos=(iu+ip)/2;
    return 0;
}

int median_stat(int *tabla, int ip, int iu, int *pos)
{
  int media;
    if (!tabla || ip > iu || !pos)
    {
        return ERR;
    }

    media=(iu-ip)/2+ip;
    
    if(tabla[ip]>tabla[iu]){
      if(tabla[ip]>tabla[media]){
        if(tabla[media]>tabla[iu]){
          *pos=media;
        } 
        else{
          *pos=iu;
        }
      }
      else{
        *pos=ip;
        return 2;
      }
    }
    else{
      if(tabla[iu]>tabla[media]){
        if(tabla[ip]>tabla[media]){
          *pos=ip;
        }
        else{
          *pos=media;
        }
      }
      else{
        *pos=iu;
        return 2;
      }
    }

    return 3;
}