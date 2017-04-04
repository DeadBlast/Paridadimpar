#include<stdio.h>
#include<stdlib.h>
#include "paridad.h"
#include<math.h>
int a=0,b=2,i,n;
int main(){
  do{
    puts("Dame un numero:");
    scanf("%d",&n);
  }while(n<3);
  int const k=pow(2,n);
  int arreglo[k];
  for(i=0;i<k;i++){
    scanf("%d",&arreglo[i]);
  }
  if(paridadimpar(arreglo,k,n)){
    printf("Si hay paridad! 0");
  }
  else{
    printf("No hay paridad! 1");
  }
  return 1;
}
