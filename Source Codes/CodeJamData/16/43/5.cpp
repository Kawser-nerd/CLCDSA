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

struct unionFind{
  int *d, N, M;
  inline void malloc(int n){d=(int*)std::malloc(n*sizeof(int));M=n;}
  inline void *malloc(int n, void *mem){d=(int*)mem;M=n;return d+n;}
  inline void init(int n){int i;N=n;rep(i,n)d[i]=-1;}
  inline void init(void){init(M);}
  inline int get(int a){int t=a,k;while(d[t]>=0)t=d[t];while(d[a]>=0)k=d[a],d[a]=t,a=k;return a;}
  inline int connect(int a, int b){if(d[a]>=0)a=get(a);if(d[b]>=0)b=get(b);if(a==b)return 0;if(d[a]<d[b])d[a]+=d[b],d[b]=a;else d[b]+=d[a],d[a]=b;return 1;}
  inline int operator()(int a){return get(a);}
  inline int operator()(int a, int b){return connect(a,b);}
  inline int& operator[](int a){return d[a];}
  inline int sizeList(int res[]){int i,s=0;rep(i,N)if(d[i]<0)res[s++]=-d[i];return s;}
};

int R, C, RC;
char mp[111][111];
int in[11111];

int gt(int a){
  if(a < C) return a;

  a -= C;
  if(a < R){
    if(mp[a][C-1]=='/') return RC + a*C+C-1;
    return a*C+C-1;
  }

  a -= R;
  if(a < C) return RC + (R-1)*C + (C-1-a);

  a -= C;
  a = R-1-a;
  if(mp[a][0]=='/') return a*C;
  return RC + a*C;
}

int main(){
  int i, j, k, mask;
  int a, b;
  int T, TC = 0;
  int ok;
  unionFind uf;

  uf.malloc(10000);

  reader(&T);
  while(T--){
    //fprintf(stderr,"rest %d\n",T);
    printf("Case #%d:\n", ++TC);

    reader(&R,&C);
    RC = R*C;
    rep(i,2*(R+C)) reader(in+i), in[i]--;

    ok = 0;
    rep(i,R) mp[i][C] = '\0';
    rep(mask,1<<RC){
      rep(i,RC){
        if(mask&1<<i) mp[i/C][i%C] = '/';
        else          mp[i/C][i%C] = '\\';
      }

      uf.init(2*RC);
      rep(i,R) rep(j,C){
        if(i){
          uf(RC+(i-1)*C+j, i*C+j);
        }
        if(j){
          a = b = 0;
          if(mp[i][j-1]=='/') a=RC;
          if(mp[i][j]!='/') b=RC;
          uf(a+i*C+j-1, b+i*C+j);
        }
      }

      rep(i,R+C){
        a = gt(in[2*i]);
        b = gt(in[2*i+1]);
        if(uf(a)!=uf(b)) break;
      }
      if(i==R+C){
        ok = 1;
        rep(i,R) writerLn(mp[i]);
        break;
      }
    }

    if(!ok) writerLn("IMPOSSIBLE");
  }

  return 0;
}
