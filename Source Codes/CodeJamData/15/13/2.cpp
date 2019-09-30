#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
const double EPS=1e-12;
const double PI=acos(-1);
struct Point{
    LL x,y;
    Point(LL _x=0,LL _y=0){x=_x;y=_y;}
    Point operator-(const Point& b){return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b){return Point(x+b.x,y+b.y);}
    Point operator*(const LL v){return Point(x*v,y*v);}
    LL operator*(const Point& b){return x*b.y-y*b.x;}
    LL operator^(const Point& b){return x*b.x+y*b.y;}
    bool operator<(const Point& b)const{
        return x<b.x||(x==b.x&&y<b.y);
    }
    double angle(){return atan2(y,x);}
    double dis(){return sqrt(x*x+y*y);}
    void scan(){cin>>x>>y;}
    void print(){cout<<x<<" "<<y<<endl;}
}p[SIZE];
double v[SIZE];
int vn;
int main(){
    CASET{
        DRI(n);
        REP(i,n){
            cin>>p[i].x>>p[i].y;
        }
        printf("Case #%d:\n",case_n++);
        REP(i,n){
            vn=0;
            REP(j,n){
                if(i==j)continue;
                v[vn++]=(p[i]-p[j]).angle();
            }
            sort(v,v+vn);
            REP(j,n)v[j+vn]=v[j]+PI*2;
            int ll=0;
            int ma=0;
            REP(j,vn*2){
                while(v[ll]+PI+1e-12<v[j])ll++;
                if(j>=vn)ma=max(ma,j-ll+1);
            }
            printf("%d\n",vn-ma);
        }
    }
    return 0;
}
