#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ONEDAY 288

enum STATE {NOTRAINED, RAINED};

void roundTime(bool, int *);
void toMinutes(int *);
void setRainedTime(int, int *, int *, int *);
void printRainedTime(int, int);

int
main(){
  int N, i, j, init, fin;
  int *S, *E, *isRained;
  enum STATE s = NOTRAINED;
  scanf("%d",&N);
  if(N < 1 || 30000 < N){
    return 1;
  }
  S = (int *)malloc(sizeof(int)*N);
  E = (int *)malloc(sizeof(int)*N);
  isRained = (int *)malloc(sizeof(int) * ONEDAY);

  for(i = 0; i < N; i++){
    scanf("%d-%d",&S[i], &E[i]);
    if(S[i] < 0 || 59 < S[i] % 100 || E[i] < 0 || 59 < E[i] % 100 || E[i] < S[i]){
      printf("fail\n");
      return 1;
    }
    roundTime(true,&S[i]);
    toMinutes(&S[i]);
    roundTime(false,&E[i]);
    toMinutes(&E[i]);
  }

  setRainedTime(N, S, E, isRained);

  i = 0;
  while(i <= ONEDAY){
    switch (s){
    case NOTRAINED:
      if(isRained[i]){
        s = RAINED;
        init = i;
      }
      break;
    case RAINED:
      if(!isRained[i] || i == (ONEDAY)){
        s = NOTRAINED;
        fin = i;
        printRainedTime(init, fin);
      }
      break;
    }
    i ++;
  }
  return 0;
}

void 
roundTime(bool isStart, int *time){
  int temp = (*time % 10) % 5;
  if(isStart || !temp){
    *time -= temp;
  } else {
    *time += ( 5 - temp) ;
  }
}

void
toMinutes(int *time){
  int temp = *time % 100;
  *time = (*time - temp) * 60 / 100 + temp;
}

void
setRainedTime(int size, int *initArray, int *finArray, int *Result){
  int i, j;
  for(i = 0; i < size; i++){
    for(j = initArray[i]/5; j < finArray[i]/5; j++){
      Result[j] = 1;
    }
  }
}
void
printRainedTime(int init, int fin){
  int initMin, initHour, finMin, finHour;
  initMin = (init * 5) % 60;
  initHour = ((init * 5) - initMin) / 60 ;
  finMin = (fin * 5) % 60;
  finHour = ((fin * 5) - finMin) / 60 ;
  printf("%02d%02d-%02d%02d\n",initHour, initMin, finHour, finMin);
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d-%d",&S[i], &E[i]);
     ^