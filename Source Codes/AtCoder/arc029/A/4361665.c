#include<stdio.h>
#include<math.h>

int max(int a, int b);
int min(int a, int b);
int solve(int *time_niku, int *niku, int N);

int max(int a, int b){
  if(a>=b){
    return a;
  }
  else{
    return b;
  }
}

int min(int a, int b){
  if(a<=b){
    return a;
  }
  else{
    return b;
  }
}

//niku[]?i???????????????????0or1???????
//time_niku[]?i???????????????
int solve(int *time_niku, int *niku, int N){
  int time_0=0;
  int time_1=0;

  for(int j=0; j<N; j++){
    if(niku[j]==0){
      time_0=time_0+time_niku[j];
    }
    else{
      time_1=time_1+time_niku[j];
    }
  }
  return max(time_0,time_1);
}

int main(){
  char buf[1024];
  int N;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf,"%d",&N);

  int *time_niku=(int *)malloc(sizeof(int)*N);

  int i=0;
  while(fgets(buf,sizeof(buf),stdin)){
    sscanf(buf,"%d",&time_niku[i]);
    i++;
  }

  // printf("N = %d\n",N);
  // for(int i=0; i<N; i++){
  //   printf("time_niku[%d] = %d\n", i, time_niku[i]);
  // }

  //????
  int state=(int)pow(2,N);
  //printf("state = %d\n",state);
  //niku[state]?j????????????????????????
  int *niku=(int *)malloc(sizeof(int)*N);
  //t_min???????????
  int t_min=1000;

  for(int i=0; i<state; i++){
    int temp=i;
    for(int j=0; j<N; j++){
      niku[j]=temp%2;
      temp=(temp-niku[j])/2;
    }
    int t=solve(time_niku, niku, N);
    //printf("solve's answer is %d\n",t);
    t_min=min(t_min,t);
  }

  printf("%d\n",t_min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:50:25: warning: implicit declaration of function ‘malloc’ [-Wimplicit-function-declaration]
   int *time_niku=(int *)malloc(sizeof(int)*N);
                         ^
./Main.c:50:25: warning: incompatible implicit declaration of built-in function ‘malloc’
./Main.c:50:25: note: include ‘<stdlib.h>’ or provide a declaration of ‘malloc’
./Main.c:47:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^