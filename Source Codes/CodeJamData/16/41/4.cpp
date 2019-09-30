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

string Rs[4444], Ps[4444], Ss[4444];
string nRs[4444], nPs[4444], nSs[4444];

int main(){
  int i, j, k;
  int T, TC = 0;
  int N, R, P, S, dame;
  int nR, nP, nS;
  int RP, PS, SR;
  string res, tmp, t2;

  reader(&T);
  while(T--){
    //fprintf(stderr,"rest %d\n",T);
    printf("Case #%d: ", ++TC);
    reader(&N,&R,&P,&S);

    rep(i,R) Rs[i] = "R";
    rep(i,P) Ps[i] = "P";
    rep(i,S) Ss[i] = "S";

    dame = 0;
    while(R+P+S > 1){
      if(R > P+S){ dame = 1; break; }
      if(P > S+R){ dame = 1; break; }
      if(S > R+P){ dame = 1; break; }

      RP = PS = SR = 0;
      nR = R;
      nP = P;
      nS = S;
      while(nR+nP+nS){
        if(nR >= nS && nP >= nS){
          RP++;
          nR--; nP--;
        } else if(nR >= nP && nS >= nP){
          SR++;
          nS--; nR--;
        } else {
          PS++;
          nP--; nS--;
        }
      }

      sort(Rs, Rs+R); reverse(Rs, Rs+R);
      sort(Ps, Ps+P); reverse(Ps, Ps+P);
      sort(Ss, Ss+S); reverse(Ss, Ss+S);

      while(RP+PS+SR){
        tmp = "ZZZZ";

        if(RP) t2 = Rs[R-1] + Ps[P-1];
        if(RP && t2 < tmp){ k = 0; tmp = t2; }
        if(RP) t2 = Ps[P-1] + Rs[R-1];
        if(RP && t2 < tmp){ k = 0; tmp = t2; }
        if(PS) t2 = Ps[P-1] + Ss[S-1];
        if(PS && t2 < tmp){ k = 1; tmp = t2; }
        if(PS) t2 = Ss[S-1] + Ps[P-1];
        if(PS && t2 < tmp){ k = 1; tmp = t2; }
        if(SR) t2 = Ss[S-1] + Rs[R-1];
        if(SR && t2 < tmp){ k = 2; tmp = t2; }
        if(SR) t2 = Rs[R-1] + Ss[S-1];
        if(SR && t2 < tmp){ k = 2; tmp = t2; }

        if(k==0) nPs[nP++] = tmp, R--, P--, RP--;
        if(k==1) nSs[nS++] = tmp, P--, S--, PS--;
        if(k==2) nRs[nR++] = tmp, S--, R--, SR--;
      }

      R = nR;
      P = nP;
      S = nS;
      rep(i,R) Rs[i] = nRs[i];
      rep(i,P) Ps[i] = nPs[i];
      rep(i,S) Ss[i] = nSs[i];
    }
    if(dame==0){
      if(R) writerLn(Rs[0].c_str());
      if(P) writerLn(Ps[0].c_str());
      if(S) writerLn(Ss[0].c_str());
    } else {
      writerLn("IMPOSSIBLE");
    }
  }

  return 0;
}
