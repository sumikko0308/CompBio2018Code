#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100


int main(void){
  int a[N], aa[N], i, t, r1, r2, r, k, A, TT, S, T;
  srand(time(NULL));
  k=90;
  TT=0;
  S=0;

for(T=0; T<10000; T++){

  for(i=0; i<k; i++){
    a[i]=0;
  }

  for(i=k; i<N; i++){
    a[i]=1;
  }

  for(i=0; i<N; i++){
    printf("%d ", a[i]);
  }

  printf("\n");

  for(t=2; t<10000; t++){
    for(i=0; i<N; i++){
      r1=rand()%N;
      r2=rand()%N;
      r=rand()%2;
      if(r==0){
        aa[i]=a[r1];
      }
      if(r==1){
        aa[i]=a[r2];
      }
    }

    for(i=0; i<N; i++){
      a[i]=aa[i];
  }

A=0;
 for(i=0; i<N; i++){
   A=A+a[i];
 }
 if(A==0){
   S=S+1;
   TT=TT+t;
   break;
 }
}

printf("%d\n", t);

if(S==100){
  printf("%d\n", TT/100);
  break;
}

}
  return 0;
}
