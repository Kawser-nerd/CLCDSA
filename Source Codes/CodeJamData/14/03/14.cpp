#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

bool can[55][55][2505];
int viaj[55][55][2505],viak[55][55][2505];
char ans[55][55];

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test;

	scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		int R,C,M;

		scanf ("%d %d %d",&R,&C,&M);
		printf ("Case #%d:\n",Case);
		if (R == 1){
			for (int i=0;i<C;i++){
				if (i == 0) printf ("c");
				else if (i < C-M) printf (".");
				else printf ("*");
			}
			puts("");
		}
		else if (C == 1){
			for (int i=0;i<R;i++){
				if (i == 0) printf ("c");
				else if (i < R-M) printf (".");
				else printf ("*");
				puts("");
			}
		}
		else{
			for (int i=0;i<R;i++){
				for (int j=0;j<C;j++) ans[i][j] = '*';
				ans[i][C] = 0;
			}

			memset(can,0,sizeof(can));
			for (int i=1;i<C;i++) can[1][i][2*i+2] = 1;
			for (int i=2;i<R;i++){
				for (int j=1;j<C;j++) for (int k=0;k<=R*C;k++) if (can[i-1][j][k]){
					for (int jj=1;jj<=j;jj++){
						can[i][jj][k+jj+1] = 1;
						viaj[i][jj][k+jj+1] = j;
						viak[i][jj][k+jj+1] = k;
					}
				}
			}

			bool found = false;
			for (int i=1;i<R;i++){
				for (int j=1;j<C;j++) if (can[i][j][R*C-M]){
					int k = R * C - M;
					while (i >= 1){
						for (int l=0;l<=j;l++){
							ans[i-1][l] = ans[i][l] = '.';
						}
						int nj = viaj[i][j][k];
						int nk = viak[i][j][k];
						i--; j = nj; k = nk;
					}
					found = true;
					break;
				}
				if (found) break;
			}
			if (found || R*C-M == 1){
				ans[0][0] = 'c';
				for (int i=0;i<R;i++) puts(ans[i]);
			}
			else puts("Impossible");
		}
	}

	return 0;
}