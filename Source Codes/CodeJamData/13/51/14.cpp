#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

long long B, X[37];

#define debug(x) cerr<<#x<<" = "<<(x)<<endl

double solve(){
    double best=0;
    for(int i=0; i<37; i++){
        long long h=X[i];
        long long goodbet=0;
        long long totalbet=0;
        for(int j=0; j<=i; j++){
            totalbet+=h-X[j];
            goodbet+=h-X[j];
        }
        if(totalbet>B)
            continue;
        int L=i;
        while(L<37-1 && X[L+1]<=h+1)
        {
            L++;
            totalbet+=h+1-X[L];
        }
        while(totalbet<=B){
            double winnings=36.0*goodbet/(i+1)-totalbet;
            best=max(best, winnings);
            long long nexth=L==37-1 ? 10000000000000000 : X[L+1]-1;
            if((nexth-h)*(L+1)+totalbet>B){
                nexth=h+(B-totalbet)/(L+1);
            }
            if(nexth<=h)
                nexth=h+1;
            goodbet+=(nexth-h)*(i+1);
            totalbet+=(nexth-h)*(L+1);
            h=nexth;
            while(L<37-1 && X[L+1]==h+1)
                L++;
        }
    }
    return best;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int N;
        scanf("%lld %d", &B, &N);
        memset(X, 0, sizeof(X));
        for(int i=0; i<N; i++){
            scanf("%lld", X+i);
        }
        sort(X, X+37);
        printf("Case #%d: %.9f\n", t, solve());
    }
}
