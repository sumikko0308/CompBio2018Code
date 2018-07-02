//学級閉鎖が複数回のver(日曜を除けた！！！！)
#include<stdio.h>

int main(void){
  int i;//何日間繰り返したかのカウント
  int w, h, k;//forループに使ってる子たち
  int Ej[200];//Eの値の結果を収納している
  int n;//何回breakしたかのカウント
  int day;//if文で使ってる何日目でループをbreakするか
  int V;//Iの人が何人以上で学級閉鎖にするか
  double t;//日にち
  double dt, b, c, SS, S, II, I, RR, R, EE, E;
  double Ei;//２日前のEの値
  double j;//Eの正確な値
  double e;//外出しているときの感染率

  FILE *fp;
  fp=fopen("output_04-6.txt","w");

  dt=1;
  S=60.0;
  E=5.0;
  I=0.0;
  R=0.0;
  b=0.0025;
  c=0.00034;
  e=0.00044;
  Ej[0]=E;
  n=0;
  day=84;
  V=20;

//初日の状況
  t=0.0;
  fprintf(fp, "%d, %d\n", Ej[0], 0);
  fprintf(fp,"%f, %f, %f, %f, %f\n", t+1, S, E, I, R);

//1日目の状況
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

//2日目以降の状況
i=2;
for(k=0; k<100; k++){

  //wのループで学級閉鎖かそうじゃないかをみていく
for(w=0; w<100; w++){

  //①:終わって欲しい日にちじゃなかったら
  if(i!=day){
    //①-1:Iの数が多く、日曜日じゃなかったらwのループをbreak
    if(I>=V&&i%7!=6){
      break;
    }
    //①-2:Iが少ない、もしくは日曜日だったら
    else{
      //①-2-1:土日だったら
      if((i%7==5) || (i%7==6)){
        t=dt*i;
        Ei=Ej[i-2];

        SS=S-e*S*E*dt;
        EE=E+e*S*E*dt-Ei*dt;
        II=I+Ei*dt-c*I*dt;
        RR=R+c*I*dt;

        Ej[i]=e*S*E*dt;
        j=e*S*E*dt;

        S=SS;
        E=EE;
        I=II;
        R=RR;

        fprintf(fp,"%d, %d, %f, %d\n", Ej[i], i, j, 888);
        fprintf(fp,"%f, %f, %f, %f, %f\n", t+1, S, E, I, R);
        i=i+1;
      }
      //①-2-2:平日だったら
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
//②:終わって欲しい日にちだったらwのループをbreak
else {
  break;
}
}

//学級閉鎖の7日間
for(h=0; h<7; h++){
  //終わって欲しい日にちじゃなかったら
  if(i<day){
  t=dt*i;
  Ei=Ej[i-2];

  SS=S-e*S*E*dt;
  EE=E+e*S*E*dt-Ei*dt;
  II=I+Ei*dt-c*I*dt;
  RR=R+c*I*dt;

  Ej[i]=e*S*E*dt;
  j=e*S*E*dt;

  S=SS;
  E=EE;
  I=II;
  R=RR;

  fprintf(fp,"%d, %d, %f, %d\n", Ej[i], i, j, 777);
  fprintf(fp,"%f, %f, %f, %f, %f\n", t+1, S, E, I, R);
  i=i+1;
}
//終わって欲しい日にちだったらhのループをbreak
else if(i>=day){
  break;
}
}

//終わって欲しい日にちだったらkのループをbreak
if(i>=day){
  break;
}
}

fclose(fp);
return 0;
}
