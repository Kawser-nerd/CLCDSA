#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_V 1005
#define MAX_E 2000000
#define INF 1000000

int N,E;
char wordlist[1005][31];

typedef struct {int from,to;}edge;

edge es[MAX_E];

int d[MAX_V];

bool if_link(char str1[],char str2[]);

void make_route(int t);

void bellmanford(int s);

int main(void){
  char first[31],last[31];
  int i,j,k,ans;
  edge tmp;

  scanf("%s%s",wordlist[0],last);
  scanf("%d",&N);
  for(i=1;i<N+1;i++){
    scanf("%s",wordlist[i]);
  }
  strcpy(wordlist[N+1],last);
  if(!strcmp(wordlist[0],wordlist[N+1])){
    putchar('0');
    putchar('\n');
    printf("%s\n",wordlist[0]);
    printf("%s\n",wordlist[N+1]);
    return 0;
  }
  k=0;
  for(i=0;i<N+2;i++){
    for(j=0;j<N+2;j++){
      if(if_link(wordlist[i],wordlist[j])){
        tmp.from = i;
        tmp.to = j;
        es[k] = tmp;
        k++;
      }
    }
  }
  E=k;
  bellmanford(0);
  if(d[N+1] == INF){
    printf("-1\n");
  }else{
    make_route(d[N+1]);
  }
  return 0;
}

void bellmanford(int s){
  int i;
  for(i=0;i<N+2;i++){
    d[i] = INF;
  }
  d[s] = 0;
  while(true){
    bool update = false;
    for(i=0;i<E;i++){
      edge e = es[i];
      if(d[e.from] != INF && d[e.to] > d[e.from] + 1){
        //printf("Yeah!");
        d[e.to] = d[e.from] + 1;
        update = true;
      }
    }
    if(!update) break;
  }
}


bool if_link(char str1[],char str2[]){
  int len,i,count=0;
  len = strlen(str1);
  for(i=0;i<len;i++){
    if(str1[i] != str2[i]){
      count++;
    }
  }
  if(count==1){
    return true;
  }else{
    return false;
  }
}

void make_route(int t){
  int i,j;
  char route[1005][31];
  strcpy(route[t],wordlist[N+1]);
  for(i=t-1;i>=0;i--){
    for(j=0;j<N+2;j++){
      if(d[j] == i && if_link(wordlist[j],route[i+1])){
        strcpy(route[i],wordlist[j]);
      }
    }
  }
  printf("%d\n",t-1);
  for(i=0;i<t+1;i++){
    printf("%s\n",route[i]);
  }
} ./Main.c: In function ‘main’:
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s",wordlist[0],last);
   ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",wordlist[i]);
     ^