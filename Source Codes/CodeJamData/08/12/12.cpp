#include <iostream>
#include <cmath>

using namespace std;
bool like[2000][2000];
int numlike[2000];
int malt[2000];
bool ans[2000];
bool done[2000];
int main() {
    int T;scanf("%d",&T);for (int t=1; t<=T; t++) {
        int N,M;scanf("%d %d",&N,&M);
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) like[i][j]=false;
            malt[i]=-1;
        }
        for (int i=0; i<M; i++) {
            scanf("%d",&numlike[i]);
            int tmp = numlike[i];
            for (int j=0; j<tmp; j++) {
                int a,b;scanf("%d %d",&a,&b);a--;
                if (b==1) {
                    numlike[i]--;
                    malt[i]=a;
                } else like[i][a]=true;
            }
        }
        for (int i=0; i<N; i++) ans[i]=false;
        for (int i=0; i<M; i++) done[i]=false;

        while (true) {

            bool found=false;
            // loop through all customers to find one which doesn't have any likes
            for (int i=0; i<M; i++) {
                if (done[i] || numlike[i]>0) continue;

                // if they have no malts, we lose
                if (malt[i]==-1) goto nope;

                // must make that one malt
                done[i]=true;
                ans[malt[i]]=true;
                for (int j=0; j<M; j++) {
                    if (done[j] || !like[j][malt[i]]) continue;

                    like[j][malt[i]]=false;
                    numlike[j]--;
                }
                found=true;
                break;
            }
            if (!found) break;
        }
        printf("Case #%d:",t);
        for (int i=0; i<N; i++) printf(" %d",ans[i]?1:0);
        printf("\n");
        continue;
        nope:;
        printf("Case #%d: IMPOSSIBLE\n",t);
    }
}
