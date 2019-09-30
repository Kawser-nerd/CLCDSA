#include<stdio.h>

void solve(int cases);
char maxchar(int R,int Y,int B);

int main(void){
  int T,i;
  scanf("%d",&T);
  for(i=1;i<=T;i++) solve(i);
  return 0;
}

void solve(int cases){
  int N=0,R=0,O=0,Y=0,G=0,B=0,V=0;
  int i,j,k;
  char c=0,str[1024]="";
  scanf("%d%d%d%d%d%d%d",&N,&R,&O,&Y,&G,&B,&V);
  printf("Case #%d: ",cases);
  if(R>N/2 || Y>N/2 || B>N/2){
    puts("IMPOSSIBLE");
    return;
  }

  for(i=0;i<N;i++){
    switch(c){
    case 'R':
      R--;
      c=maxchar(0,Y,B);
      break;
    case 'Y':
      Y--;
      c=maxchar(R,0,B);
      break;
    case 'B':
      B--;
      c=maxchar(R,Y,0);
      break;
    default:
      c=maxchar(R,Y,B);
      break;
    }
    str[i]=c;
  }
  if(str[N-1]==str[0]){
    str[N-1]^=str[N-2];
    str[N-2]^=str[N-1];
    str[N-1]^=str[N-2];
    }
  puts(str);
}

char maxchar(int R,int Y,int B){
  if(R>=Y && R>=B) return 'R';
  if(B>=R && B>=Y) return 'B';
  return 'Y';
}

