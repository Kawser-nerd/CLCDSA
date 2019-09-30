#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int read_int_from_char(char in[],int l,int ret[]){
  int i,n,fg,mfg;
  if(l<0) {for(i=0;;i++) if(in[i]<' ') break; l=i;}
  n=0; fg=0; mfg=0; ret[0]=0;
  rep(i,l+1){
    if(in[i]=='-'){mfg=1; continue;}
    if(isdigit(in[i])){ret[n]=ret[n]*10+in[i]-'0'; fg=1; continue;}
    if(!fg) continue;
    fg=0; if(mfg){ret[n]=-ret[n]; mfg=0;}
    ret[++n]=0;
  }
  return n;
}

#define N 20000000
signed char mem[N][11];

int is_happy(int n,int b){
  int i,j,k,next;

  if(mem[n][b]>=0) return mem[n][b];
  mem[n][b]=0;

  next=0; j=n;
  while(j){
    k=j%b; j/=b; next+=k*k;
  }

  return mem[n][b]=is_happy(next,b);
}

int main(){
  int i,j,k,l,m,n;
  char tmp[1000];
  int bb[100],bs;
  int size, count=0;

  rep(i,N) rep(j,11) mem[i][j]=-1;
  rep(j,11) mem[1][j]=1;

  gets(tmp); size=atoi(tmp);
  while(size--){
    gets(tmp);
    bs = read_int_from_char(tmp,-1,bb);

    REP(i,2,N){
      rep(j,bs) if(!is_happy(i,bb[j])) break;
      if(j==bs) break;
    }

    printf("Case #%d: %d\n",++count,i);
  }

  return 0;
}
