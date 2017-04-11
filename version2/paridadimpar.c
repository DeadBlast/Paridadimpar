#include<stdio.h>
#include<stdlib.h>
#include <getopt.h>
#include<string.h>
#include "paridad.h"
int i=0,n=0,k=2,option=0;
//Funcion que muestra los comandos de ayuda!
void help(){
  puts("\t\t**********AYUDA*********");
  puts("Comandos disponibles:");
  puts("-n\tUn numero entero mayor a 3!");
  puts("-s \tDebe ser una cadena separada por ',' y esta debe de tener longitud 2^n");
  puts("\tDebes introducir primero el tamano y luego la cadena");
  puts("\nEjemplo de uso: -n 3 -s 1,2,1,3,1,2,1,3");
}
int main(int argc,char *argv[]){
  //Numero de argumentos necesarios
  if(argc!=5){
    help();
  }
  else{
    //Uso de getopt para obtener los argumentos
  while((option=getopt(argc,argv,"n:s:"))!=-1){
    switch (option) {
      case 'n':
      //n tiene que ser mayor o igual a 3
          n=atoi(optarg);
          if(n>=3){
            //Elevamos k para obtener su rango.
            for(i=1;i<n;i++){
              k=k*2;
            }
          }
          else{
            help();
          }
      break;
      case 's':
      /*Primero debe estar el argumento "-n" para asi poder
      crear un arreglo de dimension "k" (el cual esta en funcion de n)*/
        if(strlen(optarg)==(k*2)-1&&n>0){
          //Usamos un token para separar mi argumento por las comas
          const char s[1]=",";
          char *token;
          token=strtok(optarg,s);
          i=0;
          int array[k];
          /*Con esto almacenamos los valores separados en un arreglo
          para despues analizarlo*/
          while(token!=NULL){
            array[i]=atoi(token);
            i++;
            token=strtok(NULL,s);
          }
          //Le introducimos a nuestra funcion los datos del arreglo
          //de su tamaño k y n
          paridadimpar(array,k,n);
        }
        else{
          help();
        }
      break;
        default:
          printf("Error inesperado! :c\n");
        break;
    }
  }
  return 1;
}
}
