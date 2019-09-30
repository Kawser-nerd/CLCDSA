#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

void intHeapGoUp(int n,int hp[],int hpi[],int d[]){
  int k,m;
  if(!n) return;
  m=(n-1)/2;
  if(d[hp[m]]<=d[hp[n]]) return;
  k=hp[m]; hp[m]=hp[n]; hp[n]=k;
  hpi[hp[m]]=m; hpi[hp[n]]=n;
  intHeapGoUp(m,hp,hpi,d);
}

void intHeapGoDown(int n,int hp[],int hpi[],int hp_size,int d[]){
  int k,m;
  m=2*n+1; if(m>=hp_size) return;
  if(hp_size>m+1 && d[hp[m]]>d[hp[m+1]]) m++;
  if(d[hp[m]]>=d[hp[n]]) return;
  k=hp[m]; hp[m]=hp[n]; hp[n]=k;
  hpi[hp[m]]=m; hpi[hp[n]]=n;
  intHeapGoDown(m,hp,hpi,hp_size,d);
}

void intHeapInsert(int n,int hp[],int hpi[],int *hp_size,int d[]){
  hp[*hp_size]=n; hpi[n]=(*hp_size)++;
  intHeapGoUp((*hp_size)-1,hp,hpi,d);
}

int intHeapDelete(int hp[],int hpi[],int *hp_size,int d[]){
  int r=hp[0]; hpi[r]=-1;
  if( *hp_size==1 ){(*hp_size)--; return r;}
  hp[0]=hp[--(*hp_size)]; hpi[hp[0]]=0;
  intHeapGoDown(0,hp,hpi,*hp_size,d);
  return r;
}


#define N 3000000

int hp_size, hp[N], hpi[N], d[N];
ll chk[17], lim;

ll solve(void){
  int i,j,k,l,m,n,g;
  ll res = 0;
  
  hp_size=0;
  rep(i,N) hpi[i]=-1;
  rep(i,N) intHeapInsert(i,hp,hpi,&hp_size,d);

  for(;;){
    n = hp[0];
    m = -d[n];
    if(m <= 1) break;

    rep(g,lim) if((1<<g) > m) break;
    g--;
    
    k = (m/(1<<(g-1)))/2;
    d[n]+=2*k*(1<<(g-1)); intHeapGoDown(hpi[n],hp,hpi,hp_size,d);
    REP(i,-(1<<(g-1)),(1<<(g-1))+1) if(i){
      d[n+i]-=k; intHeapGoUp(hpi[n+i],hp,hpi,d);
    }

    res += k * chk[g];
  }

  return res;
}

int main(){
  int i,j,k,l,m,n;
  int size,count=0;
  ll res;

  lim = 2;
  chk[0] = 0;
  chk[1] = 1;
  REP(i,2,9){
    rep(k,N) d[k]=0;
    d[N/2]=-(1<<i);
    
    chk[i]=solve();
    lim=i+1;
  }

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"rest: %d\n",size);
    scanf("%d",&n);

    rep(i,N) d[i]=0;
    while(n--){
      scanf("%d%d",&i,&j); i += N/2;
      d[i] -= j;
    }

    res = solve();
    printf("Case #%d: %lld\n",++count,res);
  }

  return 0;
}
