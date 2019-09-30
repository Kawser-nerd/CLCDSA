#include <iostream>
using namespace std;
int pows[10];
long long cts[2000001];
int main() {
    pows[0] = 1;
    for (int i=1; i<10; i++) pows[i] = 10*pows[i-1];
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        memset(cts,0,2000001*sizeof(long long));
        int A,B; scanf("%d %d",&A,&B);
        int numdigs = 0;
        int tA = A;
        while (tA) {
            numdigs++;
            tA/=10;
        }
        for (int i=A; i<=B; i++) {
            int best = i, ti = i;
            for (int i=0; i<numdigs; i++) {
                int firstdig = ti/pows[numdigs-1];
                ti = (ti%pows[numdigs-1])*10+firstdig;
                best<?=ti;
            }
            cts[best]++;
        }
        long long ans = 0;
        for (int i=0; i<=B; i++) {
            ans += cts[i]*(cts[i]-1)/2;
        }
        printf("Case #%d: %I64d\n",t,ans);
    }
}
