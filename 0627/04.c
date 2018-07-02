#include<stdio.h>

int main(void){
  int i, j, Ej[50], w;
  double t, dt, b, c, SS, S, II, I, RR, R, E, Ei, EE;
  double e;//外出しているときの感染率

  FILE *fp;
  fp=fopen("output_04.txt","w");

  dt=1;
  S=30.0;
  E=5.0;
  I=0.0;
  R=0.0;
  b=0.005;
  c=0.0034;
  e=0.0044;
  Ej[0]=E;

  t=0.0;
  fprintf(fp, "%d, %d\n", Ej[0], 0);
  fprintf(fp,"%f, %f, %f, %f, %f\n", t, S, E, I, R);

i=1;
    t=dt*i;
    SS=S-b*S*(E+e)*dt;
    EE=E+b*S*(E+e)*dt;
    II=-c*I*dt;
    RR=R+c*I*dt;

    S=SS;
    E=EE;
    I=II;
    R=RR;

Ej[j]=b*S*(E+e)*dt;
      fprintf(fp, "%d, %d\n", Ej[j], j);
      fprintf(fp,"%f, %f, %f, %f, %f\n", t, S, E, I, R);

j=0;
for(i=2; i<=4; i++){
  t=dt*i;
  Ei=Ej[j];

  SS=S-b*S*(E+e)*dt;
  EE=E+b*S*(E+e)*dt-Ei*dt;
  II=I+Ei*dt-c*I*dt;
  RR=R+c*I*dt;

  Ej[j+2]=b*S*(E+e)*dt;

  S=SS;
  E=EE;
  I=II;
  R=RR;
  j=j+1;

  fprintf(fp,"%d, %d\n", Ej[j], j);

    fprintf(fp,"%f, %f, %f, %f, %f\n", t, S, E, I, R);
 }

j=3;
 for(i=5; i<=6; i++){
   t=dt*i;
   Ei=Ej[j];

   SS=S-b*S*e*dt;
   EE=E+b*S*e*dt-Ei*dt;
   II=I+Ei*dt*-c*I*dt;
   RR=R+c*I*dt;

   Ej[j+2]=b*S*e*dt;

   S=SS;
   E=EE;
   I=II;
   R=RR;
   j=j+1;

   fprintf(fp, "%d, %d\n", Ej[j], j);
   fprintf(fp, "%f, %f, %f, %f, %f\n", t, S, E, I,  R);
 }

for(w=1; w<=4; w++){
  j=w*7+1;
 for(i=w*7; i<=w*7+4; i++){
   t=dt*i;
   Ei=Ej[j];

   SS=S-b*S*(E+e)*dt;
   EE=E+b*S*(E+e)*dt-Ei*dt;
   II=I+Ei*dt-c*I*dt;
   RR=R+c*I*dt;

   Ej[j+2]=b*S*(E+e)*dt;

   S=SS;
   E=EE;
   I=II;
   R=RR;
   j=j+1;

   fprintf(fp,"%d, %d\n", Ej[j], j);

     fprintf(fp,"%f, %f, %f, %f, %f\n", t, S, E, I, R);
  }

 j=w*7+4;
  for(i=w*7+5; i<=w*7+6; i++){
    t=dt*i;
    Ei=Ej[j];

    SS=S-b*S*e*dt;
    EE=E+b*S*e*dt-Ei*dt;
    II=I+Ei*dt*-c*I*dt;
    RR=R+c*I*dt;

    Ej[j+2]=b*S*e*dt;

    S=SS;
    E=EE;
    I=II;
    R=RR;
    j=j+1;

    fprintf(fp, "%d, %d\n", Ej[j], j);
    fprintf(fp, "%f, %f, %f, %f, %f\n", t, S, E, I,  R);
  }
}

  fclose(fp);
  return 0;
}
