#include<stdio.h>

int main(void){
  int i;
  double t, dt, b, r, SS, S, II, I, RR, R;

  FILE *fp;
  fp=fopen("output_6-5.txt","w");

  dt=0.0001;
  S=1000.0;
  I=500.0;
  R=10.0;
  b=0.002;
  r=0.1;

  t=0.0;
  fprintf(fp,"%f, %f, %f, %f\n", t, S, I, R);

  for(i=1; i<=10000; i++){
    t=dt*i;
    SS=S+dt*(-b*S*I);
    II=I+(b*S*I-r*I)*dt;
    RR=R+r*I*dt;

    S=SS;
    I=II;
    R=RR;

      if(i%100==0){
      fprintf(fp,"%f, %f, %f, %f\n", t, S, I, R);
    }
}

  fclose(fp);
  return 0;
}
