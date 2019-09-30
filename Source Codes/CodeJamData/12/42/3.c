#include <stdio.h>
#include <stdlib.h>

int arr_[1050];
int sort(const void *x, const void *y) {
  return (arr_[*(int*)y] - arr_[*(int*)x]);
}
int solve() {
    int N,W,L;
    scanf("%d%d%d",&N,&W,&L);
    int arr[1050] = {0};
    int i,j;
    for(i=0;i<N;i++) {
        scanf("%d",&arr_[i]);
        arr[i] = i;
    }
    qsort(arr, N, sizeof(int), sort);
    int ws[1050] = {0};
    int h_[1050] = {0};
    int *hs = h_+1;
    hs[0] = -arr_[arr[0]];
    int maxh = 0;
    int res[2020], *resp = res;
    for(i=0;i<N;i++) {
        int cur = arr_[arr[i]];
        for(j=0;j<maxh;j++) {
            if(ws[j]+cur<W) break;
        }
        int w = ws[j]+cur;
        if(j==maxh) {
            hs[maxh] = hs[maxh]+cur;
            hs[maxh+1] = hs[maxh]+cur;
            maxh++;
            w = 0;
        }
        if(w>W || hs[j]>L) printf("z");
        *resp++ = w;
        *resp++ = hs[j];
        ws[j] = w+cur;
    }
    int* r;
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) if(arr[j]==i) break;
        printf(" %d %d",res[2*j],res[2*j+1]);
    }
    for(r=res;r!=resp;r++)
    return arr[0];
}

int main(void) {
    int T;
    scanf("%d", &T);
    int tc;
    for(tc = 1; tc <= T; tc++) {
        printf("Case #%d:", tc);
        solve();
        puts("");
    }
    return 0;
}

