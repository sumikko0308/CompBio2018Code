#include<stdio.h>
#include<math.h>

int main(void){
  int i;
  double x0, xa, x, xx, K, r;
  double dt;
  x0=10.0;
  x=x0;
  xa=x0;
  K=100.0;
  dt=2.0;
  r=0.8;

  FILE *fp;
  fp=fopen("3HW.txt", "w");
  fprintf(fp, "%f, %f, %f\n", 0.0, xa, x);

  for(i=1; i<3000; i++){
    xa=K/(1+(K/x0-1)*exp(-r*dt*i));

    xx=x+dt*r*(1-x/K)*x;
    x=xx;
    fprintf(fp, "%f, %f, %f\n", dt*i, xa, x);
  }

  fclose(fp);
  return 0;
}
