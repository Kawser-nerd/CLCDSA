#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

void llSort(ll d[],int s){
  int i,j; ll key,t;
  if(s<=1) return;

  key=(d[0]+d[s-1])/2; i=-1; j=s;
  for(;;){
    while(d[++i] < key); while(d[--j] > key);
    if(i>=j) break; t=d[i]; d[i]=d[j]; d[j]=t;
  }
  llSort(d,i); llSort(d+j+1,s-j-1);
}

int main(){
  int i,j,k,l,m,n;
  ll a[1000],b[1000];
  ll res;

  int size,count=0;
  scanf("%d",&size);
  while(size--){
    scanf("%d",&n);
    rep(i,n) scanf("%lld",a+i);
    rep(i,n) scanf("%lld",b+i);

    llSort(a,n); llSort(b,n);
    res=0;
    rep(i,n) res += a[i]*b[n-1-i];
    
    printf("Case #%d: %lld\n",++count,res);
  }
  
  return 0;
}
