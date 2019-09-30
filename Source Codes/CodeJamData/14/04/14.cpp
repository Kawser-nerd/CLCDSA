#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test;

	scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		int N,A[1010],B[1010],C[1010];

		scanf ("%d",&N);
		for (int i=0;i<N;i++){
			double t;
			scanf ("%lf",&t);
			A[i] = t * 1000000 + 0.1;
		}
		for (int i=0;i<N;i++){
			double t;
			scanf ("%lf",&t);
			B[i] = t * 1000000 + 0.1;
			C[i] = 0;
		}

		sort(A,A+N);
		sort(B,B+N);

		int y = 0, und=0;
		for (int i=N-1;i>=und;i--){
			bool found = false;
			for (int j=0;j<N;j++) if (!C[j] && A[i] > B[j]){
				found = true;
				break;
			}

			if (found){
				for (int j=N-1;j>=0;j--) if (!C[j] && A[i] > B[j]){
					C[j] = 1;
					y++;
					break;
				}
			}
			else{
				for (int j=N-1;j>=0;j--) if (!C[j] && A[i] < B[j]){
					C[j] = 1;
					break;
				}
			}
		}

		int z = 0;
		for (int i=0;i<N;i++) C[i] = 0;
		for (int i=0;i<N;i++){
			bool found = false;
			for (int j=0;j<N;j++) if (!C[j] && A[i] < B[j]){
				C[j] = 1;
				found = true;
				break;
			}

			if (!found){
				for (int j=0;j<N;j++) if (!C[j]){
					C[j] = 1;
					z++;
				}
			}
		}

		printf ("Case #%d: %d %d\n",Case,y,z);
	}

	return 0;
}