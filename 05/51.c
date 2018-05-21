# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define N 50

int main(void){
 int a[N],aa[N],i,t,r1,r2,r,k,p,K,S,T, TT;
 srand(time(NULL));
 k=45;
 S=0;
 TT=0;

for(T=0; T<1000; T++){

 for(i=0; i<k; i++){
  a[i]=0;
 }

 for(i=k; i<N; i++){
  a[i]=1;
 }

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
   }

   K=0;
   for(i=0; i<N; i++){
     if(a[i]==0){
       K=K+1;
     }
   }

   p=K/N;
   if(p==1){
     TT=TT+t;
     S=S+1;
     printf("number=%d\n", t+2);
     printf("SUM=%d\n", S);
     break;
   }
 }

 if(S==100){
   printf("sum=%d\n", TT/100);
   break;
 }
}

 return 0;
}
