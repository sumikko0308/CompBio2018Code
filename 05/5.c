# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define N 50

int main(void){
  int a[N],aa[N],i,t,r1,r2,r,k,p,K,T,S;
  srand(time(NULL));
  k=40;
  S=0;

for(T=0; T<1000; T++){

  for(i=0; i<k; i++){
    a[i]=0;//変異の子
  }

  for(i=k; i<N; i++){
    a[i]=1;//普通の子
  }

  for(i=0; i<N; i++){
    printf("%d",a[i]);
  }
  printf("\n");

  for(t=0; t<100; t++){
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
      printf("%d",a[i]);
    }

K=0;
for(i=0; i<N; i++){
      if (a[i]==0){
        K=K+1;
     }
   }

p=K/N;

printf("\n");

if(p==1){
    S=S+1;
    printf("%d\n",t+2);
    break;
  }
}

      if(S==100){
        break;
}

}

  return 0;
}
