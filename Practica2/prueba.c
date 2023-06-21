#include <stdio.h>
#include <stdlib.h>
#define ERR -1

void swap1(int *x, int *y) 
{
  int aux = *x;
  *x = *y;
  *y = aux;
  
}

void WorstCaseMerge(int *tabla, int ip,int iu){
  int i,j;
  int aux[10000];

    if(ip >= (iu -1)){
        return ;
    }
        
    for(i=ip,j=ip;i<iu;i+=2,j++){
        aux[j]=tabla[i];
        aux[j+(iu-ip+1)/2]=tabla[i+1];
    }
     for(i=ip;i<=iu;i++){
      tabla[i]=aux[i];
    }

    WorstCaseMerge(tabla,ip,(iu-ip)/2+ip);

    WorstCaseMerge(tabla,(iu-ip)/2+1+ip,iu);
    return ;
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


int median(int *tabla, int ip, int iu, int *pos)
{
    if (!tabla || ip > iu || !pos)
    {
        return ERR;
    }
    *pos = ip;
    return 0;
}
int partition(int *tabla, int ip, int iu, int *pos)
{
    int cont, k, m, i;
    if (!tabla || ip > iu || !pos)
    {
        return ERR;
    }
    cont = median(tabla, ip, iu, pos);
    m = *pos;
    k = tabla[m];

    swap1(&tabla[ip], &tabla[m]);
    m = ip;
    for (i = ip + 1; i <= iu; i++)
    {
        if (tabla[i] < k)
        {
            m++;
            swap1(&tabla[i], &tabla[m]);
            cont++;
        }
    }
    swap1(&tabla[ip], &tabla[m]);
    *pos = m;
    return cont;
}
int quicksort(int *tabla, int ip, int iu){
    int i, pos, cont, cont1, cont2;

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
        if (ip < pos)
        {
            cont1 = quicksort(tabla, ip, pos - 1);
        }
        else
        {
            cont2 = quicksort(tabla, pos + 1, iu);
        }
        cont += cont1 + cont2;
    }
    return cont;
}


int main(){
    int *tabla=NULL, i;
    int n=16;
    tabla=(int*)calloc(n, sizeof(int));
    for(i=1; i<=n; i++){
        tabla[i-1]=i;
    }

    WorstCaseMerge(tabla,0,n-1);
    for(i=0; i<n; i++){
        printf("%d ", tabla[i]);
    }

    
    return 0;
}