//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,a,n) for(int i=a; i<n; ++i)
#define rep1(i,a,n) for(int i=n-1; i>=a; --i)
#define sd(a) scanf("%d",&a)
#define sf(a) scanf("%lf",&a)
#define sll(a) scanf("%lld",&a)
#define test(a) cout<<a<<endl
#define test2(a,b) cout<<a<<" "<<b<<endl
#define inf(a) memset(a,0x3f,sizeof(a))
#define While(a) for(;a;)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int N=1e4+10;
const ll  MAXN=1e18;
const int MAX=1e5+10;
//const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-12;



inline void solve(){
    ll x,y;
    int ans=0;
    sll(x); sll(y);
    while(x<=y){
        x<<=1;
        ans++;
    }
    printf("%d\n",ans);
    return ;
}
//int t=1;
int main(){
#ifdef local
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif
    int casen=1;
//    IOS;
//    cin >> casen;
//    sd(casen);
//    init();
    int t=1;
//    init();
    While(casen--){
//        printf("Case %d: ",t++);
//          cout << "Case "<< t++ << ": ";
//        test(qpow(2,10));
        solve();
    }
    fclose(stdin);
//    fclose(stdout);
    return 0;
}