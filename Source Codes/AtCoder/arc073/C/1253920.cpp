#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>

//#define DEBUG 1

#define for0(i,n) for (int i=0; i<n; i++)
#define forr(i,n) for (int i=n-1; i>=0; i--)
#define fori(i,a,b) for (int i=a; i<=b; i++)
#define iter(c,x) for(x::iterator it=c.begin(); it!=c.end(); it++)
#define vec(x) vector< x >
#define pb push_back
#define ms(a,z) memset(a,z,sizeof(a));
#define mp make_pair
#define X first
#define Y second
#define sqr(x) 1LL*(x)*(x)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define all(a) a.begin(),a.end()
#define size(x) (int)(x).size()
#define read(x) int x; scanf("%d",&x);
#ifdef DEBUG
#define nl cout<<"\n";
#define pr(x) cout<<(x)<<" ";
#define prl(x) cout<<#x " = "<<x<<endl;
#define prp(x) cout<<"("<<(x).first<<" "<<(x).second<<") ";
#define printv(v) {for(int _=0; _<size(v); _++) cout<<v[_]<<" "; cout<<"\n";}
#define printa(a,s) {for (int _=0; _<s; _++) cout<<a[_]<<" "; cout<<"\n";}
#define print2D(a,m,n) {for (int _=0; _<m; _++) {for (int __=0; __<n; __++) cout<<a[_][__]<<" "; cout<<"\n";} cout<<"\n";}
#define debug cout<<"ok at line "<<__LINE__<<endl;
#else
#define nl
#define pr(x)
#define prl(x)
#define prp(x)
#define printv(v)
#define printa(a,s)
#define print2D(a,m,n)
#define debug
#endif

using namespace std;

typedef long long ll;

const int INF = 2147483647;
const long long INFL = 9223372036854775807LL;
const double EPSILON = 0.00000001;
const long long MOD = 1000000007;

//int min_max[200005], max_min[200005];

int main()
{
    #ifdef DEBUG
    freopen("C.txt","r",stdin);
    //freopen("","w",stdout);
    #endif

    read(n);
    vector< pair<int,int> > balls;
    for0(i,n){
        read(x); read(y);
        if (x > y)
            swap(x,y);
        balls.pb(mp(y,x));
    }
    sort(all(balls));

    /*if (n == 1){
        cout<<0<<endl;
        return 0;
    }
    else if (n == 2) {
        ll d1 = fabs(balls[0].second)
        ll ans = balls[0].first-ba
    }*/

    int m = INF;
    int min_pos=0;
    for0(i,n) {
        if (balls[i].second < m) {
            m = balls[i].second;
            min_pos = i;
        }
    }
    prl(min_pos);

    vector<int> R, B;
    R.pb(balls[min_pos].second);
    B.pb(balls[min_pos].first);
    balls.erase(balls.begin()+min_pos);
    n = size(balls);

    int min_max = INF;
    int max_min = 0;
    for (int i=0; i<n-1; i++) {
        min_max = min(min_max, balls[i].first);
        max_min = max(max_min, balls[i].second);
    }
    prl(min_max);
    prl(max_min);
    //printa(min_max,n-1)
    //printa(max_min,n-1)

    int Rmin, Rmax, Bmin, Bmax;
    ll ans1=INFL, ans2=INFL;
    Rmin = R[0];

    //case 1: put max in R
    pr("case 1") nl
    Rmax = max(R[0], balls[n-1].first);
    Bmin = min(B[0], balls[n-1].second);
    //Bmin = min(Bmin, min_max[0]);
    Bmax = max(B[0], balls[n-1].second);
    //Bmax = max(Bmax, max_min[0]);
    for (int i=n-2; i>=0; i--) {
        pr("ball") prp(balls[i]) nl
        //take first ball = maximum of all remaining balls
        //this Bmax2 and Bmin2 will be final optimal max & min
        int Bmax2 = max(Bmax, balls[i].first);
        int Bmin2 = min(Bmin, balls[0].first);
        pr(Rmin) pr(Rmax) pr(Bmin2) pr(Bmax2) nl
        ll ans1_i = (long long)(Rmax-Rmin)*(long long)(Bmax2-Bmin2);
        prl(ans1_i)
        ans1 = min(ans1,ans1_i);

        //take second ball. Don't know yet what final min & max will be
        Bmax = max(Bmax, balls[i].second);
        Bmin = min(Bmin, balls[i].second);
    }
    pr(Rmin) pr(Rmax) pr(Bmin) pr(Bmax) nl
    ll ans1_i = (long long)(Rmax-Rmin)*(long long)(Bmax-Bmin);
    prl(ans1_i)
    ans1 = min(ans1,ans1_i);

    /*for (int i=0; i<size(balls)-1; i++) {
        int cur = Bmax-Bmin;
        int Bmax2 = max(Bmax,balls[i].first);
        int Bmin2 = min(Bmin,balls[i].second);
        if (Bmax2-Bmin < Bmax-Bmin2) {
            Bmax = Bmax2;
        }
        else {
            Bmin = Bmin2;
        }
    }
    pr("case 1") nl
    pr(Rmin) pr(Rmax) pr(Bmin) pr(Bmax) nl
    ans1 = (long long)(Rmax-Rmin)*(long long)(Bmax-Bmin);
    prl(ans1)*/

    /*bool flag = false;
    for (int i=0; i<size(balls)-1; i++) {
        if (balls[i].first == min_max && balls[i].second == max_min) {
            pr("corner case") nl
            int Bmin2 = min(Bmin,balls[i].second);
            ans1 = (long long)(Rmax-Rmin)*(long long)(Bmax-Bmin2);
            pr(Rmin) pr(Rmax) pr(Bmin2) pr(Bmax) nl
            prl(ans1)
            int Bmax2 = max(Bmax,balls[i].first);
            pr(Rmin) pr(Rmax) pr(Bmin) pr(Bmax2) nl
            ans1 = min(ans1,(long long)(Rmax-Rmin)*(long long)(Bmax2-Bmin));
            prl(ans1)
            flag = true;
            break;
        }
    }
    if (!flag) {
        pr("case 1") nl
        pr(Rmin) pr(Rmax) pr(Bmin) pr(Bmax) nl
        ans1 = (long long)(Rmax-Rmin)*(long long)(Bmax-Bmin);
    }
    prl(ans1)*/

    //case 2: put max in B
    Bmax = max(B[0], balls[n-1].first);
    Rmax = max(R[0], balls[n-1].second);
    Rmax = max(Rmax, max_min);
    Bmin = min(B[0], balls[n-1].first);
    Bmin = min(Bmin, min_max);
    pr("case 2") nl
    pr(Rmin) pr(Rmax) pr(Bmin) pr(Bmax) nl
    ans2 = (long long)(Rmax-Rmin)*(long long)(Bmax-Bmin);
    prl(ans2)

    cout<<min(ans1,ans2)<<endl;
    return 0;
}