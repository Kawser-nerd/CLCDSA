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

// Combination Table
ll C[51][51]; // C[n][k] -> nCk

void comb_table(int N){
    for(int i=0;i<=N;++i){
        for(int j=0;j<=i;++j){
            if(j==0 or j==i){
                C[i][j]=1LL;
            }else{
                C[i][j]=(C[i-1][j-1]+C[i-1][j]);
            }
            
        }
        
    }
}

ll f(int x, int y){
    ll res=1;
    bool quo[y+1];
    mem(quo,false);
    
    for(int i=0; i<y; i++){
        res *= x--;
        rep1(j,y){
            if(!quo[j] && res%j==0 ){
                quo[j] = true;
                res /= j;
            }
        }
    }
    return res;
}

int main() {
    int N, A, B;
    scnd3(N,A,B);
    
    vector<ll> nums;
    rep(i,N){
        ll x; cin>>x;
        nums.push_back(x);
    }
    
    sort(nums.begin(), nums.end());
    
    ll sum=0, tcnt=0, tgt = nums[N-A];
    rep(i,A) sum += nums[N-1-i];
    rep(i,N) if(nums[i]==tgt) tcnt++;
    
    comb_table(50);
    
    ll ans=0;
    if(nums[N-1]==tgt){
        for(int i=A; i<=B; i++){
            if(tcnt<i) break;
            ans += C[tcnt][i];
        }
    }else{
        int mcnt=0;
        rep(i,N) {
            if(nums[N-1-i]!=tgt) mcnt++;
            else break;
        }
        ans += C[tcnt][A-mcnt];
    }
    cout.precision(20);
    cout << fixed << 1.0*sum/A << endl;
    cout1(ans);
}