#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define ull unsigned ll

#define ULL_HASH_SIZE 20000
ull ull_hash_n[ULL_HASH_SIZE]; int ull_hash_d[ULL_HASH_SIZE];

void ullHashClear(void){ memset(ull_hash_d,0,ULL_HASH_SIZE*sizeof(int)); }
int ullHashFunction(ull a){ return (a*1007)%ULL_HASH_SIZE; }

int ullHashGet(ull a){
  int i=ullHashFunction(a);
  for(;;){
    if(ull_hash_n[i]==a && ull_hash_d[i]) break;
    if(!ull_hash_d[i]) break;
    i++; if(i==ULL_HASH_SIZE) i=0;
  }
  if(ull_hash_n[i]!=a) return 0; return ull_hash_d[i];
}

void ullHashSet(ull a,int n){
  int i=ullHashFunction(a);
  for(;;){
    if(ull_hash_n[i]==a && ull_hash_d[i]) break;
    if(!ull_hash_d[i]) break;
    i++; if(i==ULL_HASH_SIZE) i=0;
  }
  ull_hash_n[i]=a; ull_hash_d[i]=n;
}

int ullHashIncrease(ull a){
  int i=ullHashFunction(a);
  for(;;){
    if(ull_hash_n[i]==a && ull_hash_d[i]) break;
    if(!ull_hash_d[i]) break;
    i++; if(i==ULL_HASH_SIZE) i=0;
  }
  ull_hash_n[i]=a; return ++ull_hash_d[i];
}


ull get_hash(ll a,ll b){
  return a*12961784678LL + b;
}

int n;
char dic[10010][12]; int len[10010];
int cnt[10010], bef[10010], aft[10010], add[10010];
ull app[10010], pw[100];
char in[30];

ull hs[10010];

void get_equiv_num(int res[]){
  int i;
  
  ullHashClear();

  rep(i,n){
    hs[i] = get_hash(len[i], app[i]);
    ullHashIncrease(hs[i]);
  }
  rep(i,n) res[i] = ullHashGet(hs[i]);
}

int main(){
  int i,j,k,l,m,q,mx;
  int size,count=0;

  pw[0]=18723;
  REP(i,1,100) pw[i] = pw[i-1]*1007;

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"size %d\n",size);
    printf("Case #%d:",++count);

    scanf("%d%d",&n,&q);
    rep(i,n){
      scanf("%s",dic[i]);
      for(j=0;;j++) if(dic[i][j]<' ') break;
      len[i] = j;
    }

    while(q--){
      scanf("%s",in);
      rep(i,n) cnt[i] = 0, app[i] = 0;

      rep(k,26){
        get_equiv_num(bef);
        rep(i,n) add[i] = 0;
        rep(i,n) rep(j,len[i]) if(dic[i][j]==in[k]){
          app[i] += pw[j]*(in[k]-(ll)'a'+12893);
          add[i]++;
        }
        get_equiv_num(aft);

        rep(i,n) if(bef[i] > aft[i] && add[i]==0) cnt[i]++;

/*        rep(i,n) printf("%d %d: %d -> %d (%d) %d\n",k,i,bef[i],aft[i],app[i],cnt[i]);*/
      }

      mx = cnt[0], k = 0;
      rep(i,n) if(mx < cnt[i]) mx = cnt[i], k = i;
      printf(" %s",dic[k]);
/*      rep(i,n) printf("[%d %d]\n",i,cnt[i]);*/
    }
    
    puts("");
  }

  return 0;
}
