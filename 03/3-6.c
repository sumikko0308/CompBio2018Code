#include<stdio.h>
#include<math.h>

int main(void){
  int i;
  double x0, xt, x, xx, a;
  double dt;
  x0=10.0;
  x=x0;
  xt=x0;
  a=1.2;
  dt=0.01;

  FILE *fp;
  fp=fopen("3-6.txt", "w");
  fprintf(fp, "%f, %f, %f\n", 0.0, xt, x);

  for(i=1; i<1000; i++){
    xt=x0*exp(a*dt*i);

    xx=x+dt*a*x;
    x=xx;
    fprintf(fp, "%f, %f, %f\n", dt*i, xt, x);
  }

  fclose(fp);
  return 0;
}
