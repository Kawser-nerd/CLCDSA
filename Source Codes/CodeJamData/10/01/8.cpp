#include <iostream>
using namespace std;
int main() {
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        printf("Case #%d: ",t);
        int N,K; scanf("%d %d",&N,&K);
        int lim = (1<<N);
        if (K%lim==lim-1) printf("ON\n");
        else printf("OFF\n");
    }
}
