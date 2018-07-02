#include<stdio.h>

int main(void){
  int i, Ej[10];
  double t, dt, b, c, SS, S, II, I, RR, R, E, Ei, EE, j;

  FILE *fp;
  fp=fopen("output_01.txt","w");

  dt=1;
  S=30.0;
  E=5.0;
  I=0.0;
  R=0.0;
  b=0.025;
  c=0.0034;
  Ej[0]=E;

  t=0.0;
  fprintf(fp, "%d, %d\n", Ej[0], 0);
  fprintf(fp,"%f, %f, %f, %f, %f\n", t, S, E, I, R);

i=1;
    t=dt*i;
    SS=S-(b*S*E*dt);
    EE=E+b*S*E*dt;
    II=-c*I*dt;
    RR=R+c*I*dt;

Ej[i]=b*S*E*dt;
j=b*S*E*dt;

S=SS;
E=EE;
I=II;
R=RR;

      fprintf(fp, "%d, %d, %f\n", Ej[i], i, j);
      fprintf(fp,"%f, %f, %f, %f, %f\n", t, S, E, I, R);


for(i=2; i<=10; i++){
  t=dt*i;
  Ei=Ej[i-2];

  SS=S-(b*S*E*dt);
  EE=E+b*S*E*dt-Ei*dt;
  II=I+Ei*dt-c*I*dt;
  RR=R+c*I*dt;

  Ej[i]=b*S*E*dt;
  j=b*S*E*dt;

  S=SS;
  E=EE;
  I=II;
  R=RR;

  fprintf(fp,"%d, %d, %f\n", Ej[i], i, j);

    fprintf(fp,"%f, %f, %f, %f, %f\n", t, S, E, I, R);
 }
  fclose(fp);
  return 0;
}
