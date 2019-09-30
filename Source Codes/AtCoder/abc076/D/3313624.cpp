#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <iomanip>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define loop3(i,j,k,a) for(int i=0; i<a; i++)for(int j=0; j<a; j++)if(i!=j)for(int k=0; k<a; k++)if(i!=k&&j!=k)
#define loop4(i,j,k,l,a) for(int i=0; i<a; i++)for(int j=0; j<a; j++)if(i!=j)for(int k=0; k<a; k++)if(i!=k&&j!=k)for(int l=0; l<a; l++)if(i!=l&&j!=l&&k!=l)
#define rep1(i,a) for(int i=1; i<=a; i++)

#define scnd1(a) scanf("%d", &a)
#define scnd2(a,b) scanf("%d%d", &a,&b)
#define scnd3(a,b,c) scanf("%d%d%d", &a,&b,&c)
#define scnd4(a,b,c,d) scanf("%d%d%d%d", &a,&b,&c,&d)

#define cin1(a) cin >> a;
#define cin2(a,b) cin >> a >> b;
#define cin3(a,b,c) cin >> a >> b >> c;
#define cin4(a,b,c,d) cin >> a >> b >> c >> d;
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define prtd1(a) printf("%d\n", a)
#define prtd2(a,b) printf("%d %d\n", a,b)
#define prtd3(a,b,c) printf("%d %d %d\n", a,b,c)
#define prtd4(a,b,c,d) printf("%d %d %d %d\n", a,b,c,d)

#define mem(a,n) memset( a, n, sizeof(a))
#define INF 1000000000
typedef long long ll;

vector<int> T, V;
double G[20009];

class section{
    public:
        int begin;
        int end;
        int velocity;
        
        section(){}
        section(int begin, int end) : begin(begin), end(end){}
};

int main() {
    int N;
    cin >> N;
    
    vector<section> ss(N);
    int sum_t = 0;
    rep(i,N){
        int x;
        cin >> x;
        x *= 2;
        
        ss[i].begin = sum_t;
        ss[i].end = sum_t + x;
        sum_t += x;
    }
    
    rep(i,N){
        int x;
        cin >> x;
        ss[i].velocity = x*2;
    }
    
    vector<int> a(sum_t+1,INF);
    a[0] = 0;
    a[sum_t] = 0;
    
    for(const section& s:ss){
        for(int i=s.begin; i<=s.end; i++){
            a[i] = min( a[i], s.velocity );
        }
    }
    
    for(int i=sum_t-1; i>=0; i--){
        a[i] = min( a[i+1]+1, a[i]);
    }
    
    int speed = 0;
    int distance = 0;
    rep(i,sum_t){
        if( speed < a[i+1] ){
            speed++;
            distance += speed+1;
        }else if( speed > a[i+1] ) {
            speed--;
            distance += speed-1;
        }else{
            distance += speed;
        }
    }
    
    cout << std::fixed << std::setprecision(9) << (1.0 * distance / 4) << endl;
}