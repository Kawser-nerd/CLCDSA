#include<stdio.h>
long long MAX(long long a,long long b){return a<b?b:a;}
int R=1,C=1,H[1000010]={0};
long long N[1000010]={-1000};
void hin(long long a){
  int i=C++;
  for(N[R]=a;a<N[H[i/2]];i/=2)H[i]=H[i/2];
  H[i]=R++;
}
//?????????????
int hout(){
  int rt=H[1],nt=1,i=0,k=H[--C];
  while(nt-i){
    H[i=nt]=k;
    if(i*2  <C&&N[  k  ]>N[H[i*2  ]])H[i]=H[nt=i*2  ];
    if(i*2+1<C&&N[H[nt]]>N[H[i*2+1]])H[i]=H[nt=i*2+1];
  }
  return rt;
}
long long CO[100010];
void dijk(int v,int e,int *fr,int *to,int *co,int mi){
  int i,id[1000010],ta[100010],nt[100010],f[100010]={0};
  for(i=0;i<v;i++)ta[i]=-1;
  for(i=0;i<v;i++)CO[i]=1000000000;
  for(i=CO[mi]=0;i<e;i++){
    nt[i]=ta[fr[i]];
    ta[fr[i]]=i;
  }
  while(--v){
    f[mi]=1;
    for(i=ta[mi];i+1;i=nt[i]){
      if(CO[to[i]]>CO[mi]+co[i])hin(CO[id[R]=to[i]]=CO[mi]+co[i]);
    }
    while(f[mi]&&C-1)mi=id[hout()];
    if(f[mi])break;
  }
}
int main(){
  int a,b,i;
  int n,m,fr[100010],to[100010],co[100010];
  long long t,max=0,go[100010],e[100010];
  scanf("%d %d %lld",&n,&m,&t);
  for(i=0;i<n;i++)scanf("%lld",&e[i]);
  for(i=0;i<m;i++){
    scanf("%d %d %d",&a,&b,&co[i]);
    fr[i]=a-1;
    to[i]=b-1;
  }
  dijk(n,m,fr,to,co,0);
  for(i=0;i<n;i++)go[i]=CO[i];
  dijk(n,m,to,fr,co,0);
  for(i=0;i<n;i++)max=MAX(max,e[i]*(t-CO[i]-go[i]));
  printf("%lld\n",max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:42:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %lld",&n,&m,&t);
   ^
./Main.c:43:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%lld",&e[i]);
                   ^
./Main.c:45:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&a,&b,&co[i]);
     ^