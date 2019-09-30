#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(double *x){scanf("%lf",x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(double x, char c){printf("%.15f",x);mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}

char memarr[17000000]; void *mem = memarr;
#define MD 1000000007

template<class T> void sort(int N, T a[], void *mem = NULL){sort(a,a+N);}
template<class T1, class T2> void sort(int N, T1 a[], T2 b[], void *mem){int i;pair<T1,T2> *r=(pair<T1, T2>*)mem;rep(i,N)r[i].first=a[i],r[i].second=b[i];sort(r,r+N);rep(i,N)a[i]=r[i].first,b[i]=r[i].second;}
template<class T1, class T2, class T3> void sort(int N, T1 a[], T2 b[], T3 c[], void *mem){int i;pair<T1,pair<T2,T3> > *r=(pair<T1,pair<T2,T3> >*)mem;rep(i,N)r[i].first=a[i],r[i].second.first=b[i],r[i].second.second=c[i];sort(r,r+N);rep(i,N)a[i]=r[i].first,b[i]=r[i].second.first,c[i]=r[i].second.second;}
template<class T1, class T2, class T3, class T4> void sort(int N, T1 a[], T2 b[], T3 c[], T4 d[], void *mem){int i;pair<pair<T1,T2>,pair<T3,T4> > *r=(pair<pair<T1,T2>,pair<T3,T4> >*)mem;rep(i,N)r[i].first.first=a[i],r[i].first.second=b[i],r[i].second.first=c[i],r[i].second.second=d[i];sort(r,r+N);rep(i,N)a[i]=r[i].first.first,b[i]=r[i].first.second,c[i]=r[i].second.first,d[i]=r[i].second.second;}

template<class T> void unique(T arr[], int &sz, int sorted=0){int i,k=0;if(!sorted)sort(arr,arr+sz);rep(i,sz)if(!k||arr[k-1]!=arr[i])arr[k++]=arr[i];sz=k;}
template<class T, class S> void unique(T arr[], S val[], int &sz, void *mem, int sorted=0){int i,k=0;if(!sorted)sort(sz,arr,val,mem);rep(i,sz)if(!k||arr[k-1]!=arr[i])arr[k]=arr[i],val[k++]=val[i];else val[k-1] += val[i];sz=k;}
template<class T, class S, class V> void unique(T arr[], S v1[], V v2[], int &sz, void *mem, int sorted=0){int i,k=0;if(!sorted)sort(sz,arr,v1,v2,mem);rep(i,sz)if(!k||arr[k-1]!=arr[i])arr[k]=arr[i],v1[k]=v1[i],v2[k++]=v2[i];else v1[k-1] += v1[i],v2[k-1] += v2[i];sz = k;}

int bitcount(int x){
  int res = 0;
  while(x) res += x%2, x /= 2;
  return res;
}

int N;
char S[33][33];

int mask[33], val[33];
int tate[33], yoko[33], sz;

map<ull,int> memo;
int solve(int sz, int tate[], int yoko[]){
  int i, j, k;
  int res = 1000000000, tmp;
  int st[33], sy[33], ss;
  ull hs;

  if(sz==0) return 0;

  sort(sz,tate,yoko,mem);
  hs = 89137491ULL * sz + 109478901ULL;
  rep(i,sz) hs = hs * 18713ULL + tate[i];
  rep(i,sz) hs = hs * 91391ULL + yoko[i];
  if(memo.count(hs)) return memo[hs];

  if(tate[0] < yoko[0]){
    tmp = yoko[0]*yoko[0] - tate[0]*yoko[0];
    rep(i,sz-1) st[i] = tate[i+1], sy[i] = yoko[i+1];
    ss = sz-1;
    tmp += solve(ss, st, sy);
    res = min(res, tmp);
  }

  REP(i,1,sz){
    ss = 0;
    rep(k,sz) if(k!=0 && k!=i){
      st[ss] = tate[k];
      sy[ss] = yoko[k];
      ss++;
    }
    st[ss] = tate[0] + tate[i];
    sy[ss] = yoko[0] + yoko[i];
    tmp = st[ss]*sy[ss] - tate[0]*yoko[0] - tate[i]*yoko[i];
    if(st[ss] != sy[ss]) ss++;
    tmp += solve(ss, st, sy);
    res = min(res, tmp);
  }

  return memo[hs] = res;
}

int main(){
  int i, j, k;
  int fg1, fg2;
  int T, TC = 0;
  int res, add;

  reader(&T);
  while(T--){
    fprintf(stderr,"rest %d\n",T);
    printf("Case #%d: ", ++TC);

    reader(&N);
    rep(i,N) reader(S[i]);
    rep(i,N) rep(j,N) S[i][j] -= '0';

    add = 0;
    for(;;){
      int fg = 0;
      rep(i,N) REP(j,i+1,N){
        fg1 = fg2 = 0;
        rep(k,N){
          if(S[i][k]+S[j][k]==1) fg1++;
          if(S[i][k]+S[j][k]==2) fg2++;
        }
        if(fg1 && fg2){
          fg = 1;
          rep(k,N) if(S[i][k] || S[j][k]){
            if(S[i][k]==0) add++, S[i][k] = 1;
            if(S[j][k]==0) add++, S[j][k] = 1;
          }
        }
      }
      if(!fg) break;
    }

    rep(i,N){
      mask[i] = 0;
      val[i] = 1;
      rep(k,N) if(S[i][k]) mask[i] |= (1<<k);
    }
    unique(mask,val,N,mem);

    sz = 0;
    rep(i,N){
      k = bitcount(mask[i]);
      if(k==val[i]) continue;

      if(k==0){
        while(val[i]){
          tate[sz] = 0;
          yoko[sz] = 1;
          sz++;
          val[i]--;
        }
      } else {
        tate[sz] = k;
        yoko[sz] = val[i];
        sz++;
      }
    }

//    rep(i,sz) printf("[%d %d] ",tate[i],yoko[i]); puts("");

    memo.clear();
    res = solve(sz,tate,yoko);
    writerLn(add+res);
  }

  return 0;
}
