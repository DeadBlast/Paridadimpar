int paridadimpar(int arreglo[],int k,int n){
  int min,tam=2,i,h,max=1,total=0,paridad_impar=0;
  //Con este ciclo while definimos el tamaño de mis cadenas, empezamos en tamaño 2
  while(tam<=k-1){
    /*Con min itero mi rango menor,este empezara en 0
    mi variable "max" me itera el rango maximo*/
    for(min=0;min<=k-tam;min++){
      //Por cada rango obtenido voy a revisarlo con los numeros del 1 hasta "n"
      for(i=1;i<=n;i++){
        total=0;
        //Los rangos empiezan desde min hasta maximo
        for(h=min;h<=max;h++){
          //si hay alguna coincidencia añado una unidal al total
          if(arreglo[h]==i){
            total+=1;
          }
        }
        //En caso de haber una paridad impar se rompe el ciclo de busqueda para esa subcadena
        if(total%2==1){
          i=n+1;
          paridad_impar=1;
        }
        else{
          paridad_impar=0;
        }
      }
      /*Si despues de analizar la primer subcadena no encontramos la paridad impar
      no sera necesario buscar en las demas subcadenas, por lo que mostramos la subcadena con error*/
      if(paridad_impar==0){
        for(i=min;i<max;i++){
          fprintf(stderr, "%d,",arreglo[i] );
        }
        fprintf(stderr, "%d\n",arreglo[max]);
        min=k;
        tam=k;
      }
      //iteramos el valor maximo
      max+=1;
    }
    //Ahora mi maximo va a ser el tamaño
    max=tam;
    //Iteramos el tamaño
    tam+=1;
  }
  /*Si al final de buscar se cumple la paridad impar para cada subcadena mostramos
  la cadena completa ingresada*/
  if(paridad_impar){
    for(int i=0;i<(k-1);i++){
      fprintf(stdout, "%d,",arreglo[i]);
    }
    fprintf(stdout,"%d\n",arreglo[i]);
    //Regresamos un 1 por si lo necesitamos
    return 1;
  }
  else{
    //Regresamos un 0 por si lo necesitamos
    return 0;
  }
}
