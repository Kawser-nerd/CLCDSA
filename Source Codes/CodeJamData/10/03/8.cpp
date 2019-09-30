#include <iostream>
using namespace std;
long long sizes[1000];
long long moneyhit[1000];
int cyclecount[1000];
int main() {
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        printf("Case #%d: ",t);
        long long R,k;
        int N;
        scanf("%I64d %I64d %d",&R,&k,&N);
        
        long long totpeople = 0;
        for (int i=0; i<N; i++) {
            scanf("%I64d",&sizes[i]);
            totpeople += sizes[i];
            moneyhit[i]=-1;
        }
        
        int curpos = 0;
        moneyhit[0]=0;        
        cyclecount[0]=0;
        long long curmoney = 0;
        int cyclect = 0;
        
        bool foundcycle = false;
        while (R--) {
            cyclect++;
            // find the next group
            long long cursize = 0;
            for (int j=0; j<N; j++) {
                long long next = sizes[curpos];
                if (cursize + next > k) break;
                cursize += next;
                curpos = (curpos+1)%N;
            }
            curmoney += cursize;
            if (!foundcycle) {
                if (moneyhit[curpos]==-1) {
//                    printf("At %d, money is %I64d\n",curpos,curmoney);
                    moneyhit[curpos] = curmoney;
                    cyclecount[curpos] = cyclect;
                } else {
//                    printf("Found a cycle; last time we were at %d we had %I64d, this time we have %I64d\n",curpos,moneyhit[curpos],curmoney);
                    
                    int cyclelen = cyclect-cyclecount[curpos];
//                    printf("Number of rides in between: %d - %d\n",cyclect,cyclecount[curpos]);
                    
                    long long numcycles = R/cyclelen;
//                    printf("Want to add on %I64d more cycles\n",numcycles);
                    
                    curmoney += numcycles * (curmoney-moneyhit[curpos]);
                    R%=cyclelen;
                    foundcycle = true;
                }
            }
        }
        printf("%I64d\n",curmoney);
    }
}
