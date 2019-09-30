#include <iostream>
using namespace std;
int main() {
    int tt = 0;
    int T; scanf("%d",&T); while (T--) {tt++;
        int N; scanf("%d",&N);
        int posO = 1, timeO = 0;
        int posB = 1, timeB = 0;
        char type[2]; int M;
        for (int i=0; i<N; i++) {
            scanf("%s %d",type,&M);
            if (type[0]=='O') {
                timeO += abs(M-posO);
                timeO >?= timeB;
                timeO++;
                posO = M;
            } else {
                timeB += abs(M-posB);
                timeB >?= timeO;
                timeB++;
                posB = M;                
            }
        }
        printf("Case #%d: %d\n",tt,max(timeO,timeB));
    }
}
