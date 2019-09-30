#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define LL long long

using namespace std;

int T,N;
LL L,H,A[10005],P[10005];
int main(){
    freopen("C.in","r",stdin);
    freopen("C2.out","w",stdout);
    cin>>T;
    for (int t=1;t<=T;++t) {
        cout<<"Case #"<<t<<": ";
        cin>>N>>L>>H;
        for (int i=1;i<=N;++i) scanf("%I64d",&A[i]);
        sort(A+1,A+N+1);
        P[N]=A[N];
        for (int i=N-1;i>=1;--i) P[i]=__gcd(A[i],P[i+1]);
        LL ans=H+1;
        if (P[1]>=L) 
           for (int i=1;(LL)i*i<=P[1];++i) if (P[1]%i==0) {
               if (i>=L && i<=H) {ans<?=i;break;}
               if (P[1]/i>=L && P[1]/i<=H) ans<?=P[1]/i;
           }
        LL lcm=1;
        for (int i=1;i<=N;++i) {
            LL g=__gcd(lcm,A[i]);
            if (A[i]/g>H*1.0/lcm+1e-6) break;
            lcm=lcm/g*A[i];
            if (i==N || P[i+1]%lcm==0)
               if (i==N)
                  if (lcm<=H)
                     if (lcm>=L) ans<?=lcm;
                     else if (L%lcm==0) ans<?=L;
                          else ans<?=(L/lcm+1)*lcm;
                  else ;
               else {
                    LL d=P[i+1]/lcm;
                    for (int i=1;(LL)i*i<=d;++i) if (d%i==0) {
                        if (lcm*i>=L && lcm*i<=H) {ans<?=lcm*i;break;}
                        if (lcm*(d/i)>=L && lcm*(d/i)<=H) ans<?=lcm*(d/i);
                    }
               }
        } 
        if (ans<L || ans>H) cout<<"NO\n";
        else cout<<ans<<"\n";
    }
    return 0;
}
