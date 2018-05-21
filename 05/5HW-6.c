#include<stdio.h>
#include<math.h>

int main(void){
  double N, Tp, p, k;
  N=100.0;

  FILE *fp;
  fp=fopen("5HW-6.txt", "w");

  for(k=0.0; k=100.0; k++){
    p=k/N;
    Tp=-1/p*(2*N*(1-p)*exp(1-p));
    fprintf(fp, "%f, %f\n", Tp, p);
  }

  fclose(fp);
  return 0;
}
