#include <iostream>
using namespace std;
double exp[41];
long long choose[41][41];
int main() {
    for (int i=0; i<41; i++) {
        choose[i][i]=choose[i][0]=1LL;
        for (int j=1; j<i; j++) choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
    }
    int t=0;
    int T; scanf("%d",&T); while (T--) {t++;
        int C,N; scanf("%d %d",&C,&N);
        exp[0]=0;        
        for (int i=1; i<=C; i++) {
            // need i more types
            double sum = 0;
            for (int j=1; j<=N && j<=i; j++) {
                // choose N cards, what is probability j of them are new ones
                long long here = choose[i][j] * choose[C-i][N-j];
                sum += 1.*here/choose[C][N] * (1+exp[i-j]);
            }
            double zero = 1.*choose[C-i][N]/choose[C][N];
            exp[i] = (sum+zero)/(1-zero);
        }
        printf("Case #%d: %.9f\n",t,exp[C]);
    }
}
