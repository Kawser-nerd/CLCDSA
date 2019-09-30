#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int A[1024],B[1024];
int N;

void solve(int cas){
    int i,j;
    scanf("%d",&N);
    for (i=0;i<N;i++) scanf("%d",A+i);
    for (i=0;i<N;i++){
        B[i]=0;
        for (j=0;j<N;j++) if (A[j]<A[i]) B[i]++;
    }
    int c = 0;
    for (i=0;i<N;i++) if (B[i]!=i) c++;
    printf("Case #%d: %.6lf\n",cas,c*1.0);
}

int main(){
    int t,cas;
    scanf("%d",&t);
    for (cas=1;cas<=t;cas++)
        solve(cas);
    return 0;
}

