int paridadimpar(int arreglo[],int k,int n){
  int j,tam=2,i,h,l=1,total=0,paridad_impar=0;
  while(tam<=k-1){
    for(j=0;j<=k-tam;j++){
      for(i=1;i<=n;i++){
        total=0;
        for(h=j;h<=l;h++){
          if(arreglo[h]==i){
            total+=1;
          }
        }
        if(total%2==1){
          i=n+1;
          paridad_impar=1;
        }
        else{
          paridad_impar=0;
        }
      }
      if(paridad_impar==0){
        fprintf(stderr, "Subcadena con error:\n [");
        for(i=j;i<=l;i++){
          fprintf(stderr, "%d ",arreglo[i] );
        }
        fprintf(stderr, "]");
        j=k;
        tam=k;
      }
      l+=1;
    }
    l=tam;
    tam+=1;
  }
  if(paridad_impar){
    return 1;
  }
  else{
    return 0;
  }
}
