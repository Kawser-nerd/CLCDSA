#include <stdio.h>
#include <algorithm>
using namespace std;
int dat[100][100];
int R[100], C[100];
int main() {
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T-->0) {
		int N, M;
		scanf("%d %d",&N,&M);
		for (int i=0;i<N;i++) R[i] = 0;
		for (int i=0;i<M;i++) C[i] = 0;
		for (int i=0;i<N;i++) for(int j=0;j<M;j++) {
			scanf("%d",&dat[i][j]);
			R[i] = max(R[i], dat[i][j]);
			C[j] = max(C[j], dat[i][j]);
		}
		bool valid = true;
		for (int i=0;i<N;i++){
			for (int j=0;j<M;j++) {
				if (dat[i][j] != min(R[i],C[j])) valid = false;
			}
		}
		static int cs = 1;
		printf("Case #%d: %s\n", cs ++, valid?"YES":"NO");
	}
	return 0;
}