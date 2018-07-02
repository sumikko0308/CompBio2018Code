#include<stdio.h>

int main(void){
  int i, w, Ej[50], h;
  double t, dt, b, c, SS, S, II, I, RR, R, E, Ei, EE, j;
  double e;//外出しているときの感染率

  FILE *fp;
  fp=fopen("output_04-3.txt","w");

  dt=1;
  S=30.0;
  E=5.0;
  I=0.0;
  R=0.0;
  b=0.025;
  c=0.0034;
  e=0.0044;
  Ej[0]=E;

  t=0.0;
  fprintf(fp, "%d, %d\n", Ej[0], 0);
  fprintf(fp,"%f, %f, %f, %f, %f\n", t+1, S, E, I, R);

i=1;
    t=dt*i;
    SS=S-(b+e)*S*E*dt;
    EE=E+(b+e)*S*E*dt;
    II=-c*I*dt;
    RR=R+c*I*dt;

    Ej[i]=(b+e)*S*E*dt;
    j=(b+e)*S*E*dt;

    S=SS;
    E=EE;
    I=II;
    R=RR;


      fprintf(fp, "%d, %d, %f\n", Ej[i], i, j);
      fprintf(fp,"%f, %f, %f, %f, %f\n", t+1, S, E, I, R);

for(i=2; i<=4; i++){
  t=dt*i;
  Ei=Ej[i-2];

  SS=S-(b+e)*S*E*dt;
  EE=E+(b+e)*S*E*dt-Ei*dt;
  II=I+Ei*dt-c*I*dt;
  RR=R+c*I*dt;

  Ej[i]=(b+e)*S*E*dt;
  j=(b+e)*S*E*dt;

  S=SS;
  E=EE;
  I=II;
  R=RR;

  fprintf(fp,"%d, %d, %f\n", Ej[i], i, j);

    fprintf(fp,"%f, %f, %f, %f, %f\n", t+1, S, E, I, R);
 }

 for(i=5; i<=6; i++){
   t=dt*i;
   Ei=Ej[i-2];

   SS=S-e*S*E*dt;
   EE=E+e*S*E*dt-Ei*dt;
   II=I+Ei*dt*-c*I*dt;
   RR=R+c*I*dt;

   Ej[i]=e*S*E*dt;
   j=e*S*E*dt;

   S=SS;
   E=EE;
   I=II;
   R=RR;

   fprintf(fp, "%d, %d, %f\n", Ej[i], i, j);
   fprintf(fp, "%f, %f, %f, %f, %f\n", t+1, S, E, I,  R);
 }

i=7;
for(w=0; w<100; w++){
  if(i!=28){
  if((i%7==5) || (i%7==6)){
    t=dt*i;
    Ei=Ej[i-2];

    SS=S-e*S*E*dt;
    EE=E+e*S*E*dt-Ei*dt;
    II=I+Ei*dt*-c*I*dt;
    RR=R+c*I*dt;

    Ej[i]=e*S*E*dt;
    j=e*S*E*dt;

    S=SS;
    E=EE;
    I=II;
    R=RR;

    fprintf(fp, "%d, %d, %f, %d\n", Ej[i], i, j, 888);
    fprintf(fp, "%f, %f, %f, %f, %f\n", t+1, S, E, I,  R);
    i=i+1;
  }

  else{
    if(I>=4){
      for(h=0; h<7; h++){
        t=dt*i;
        Ei=Ej[i-2];

        SS=S-e*S*E*dt;
        EE=E+e*S*E*dt-Ei*dt;
        II=I+Ei*dt*-c*I*dt;
        RR=R+c*I*dt;

        Ej[i]=e*S*E*dt;
        j=e*S*E*dt;

        S=SS;
        E=EE;
        I=II;
        R=RR;

        fprintf(fp, "%d, %d, %f, %d\n", Ej[i], i, j, 777);
        fprintf(fp, "%f, %f, %f, %f, %f\n", t+1, S, E, I,  R);
        i=i+1;
      }
    }
    else{
    t=dt*i;
    Ei=Ej[i-2];

    SS=S-(b+e)*S*E*dt;
    EE=E+(b+e)*S*E*dt-Ei*dt;
    II=I+Ei*dt-c*I*dt;
    RR=R+c*I*dt;

    Ej[i]=(b+e)*S*E*dt;
    j=(b+e)*S*E*dt;

    S=SS;
    E=EE;
    I=II;
    R=RR;

    fprintf(fp,"%d, %d, %f, %d\n", Ej[i], i, j, 999);
      fprintf(fp,"%f, %f, %f, %f, %f\n", t+1, S, E, I, R);
      i=i+1;
    }
  }
}
else{
  break;
}
}
  fclose(fp);
  return 0;
}
