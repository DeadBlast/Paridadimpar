#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "paridad.h"
int n,i;
int main(){
  do{
    printf("Dame el tanano del arreglo: ");
    scanf("%d",&n);
  }while(n<3);
  const int k=pow(2,n);
  int arreglo[k];
  for(i=0;i<k;i++){
    do{
        printf("Dame el numero %d: ",i+1);
        scanf("%d",&arreglo[i]);
    }while(arreglo[i]<1||arreglo[i]>n);
  }
  if(paridadimpar(arreglo,k,n)==1){
    puts("");
    fprintf(stdout, "[");
    for(int i=0;i<k;i++){
      fprintf(stdout, "%d ",arreglo[i]);
    }
    fprintf(stdout,"]\n");
  }
  return 0;
}
