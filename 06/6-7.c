#include<stdio.h>

int main(void){
  int i;
  double x, xx, K;

  //パラメータ表示
  K=100.0;

  //初期値
  x=10.0;

  for(i=0; i<1000; i++){
    xx=x*x/(2*x-K);
    x=xx;
  }

  printf("%f\n", x);

  return 0;
}
