#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int N,A[1010];

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		scanf ("%d",&N);
		for (int i=0;i<N;i++) scanf ("%d",&A[i]);

		int ans1 = 0;
		for (int i=1;i<N;i++) ans1 += A[i] < A[i-1] ? A[i-1] - A[i] : 0;

		int ans2 = 0x7fffffff;
		for (int d=0;d<=10000;d++){
			int a = 0, u = A[0];
			for (int i=1;i<N;i++){
				if (u < d){
					a += u;
					u = 0;
				}
				else{
					u -= d;
					a += d;
				}
				if (A[i] >= u) u = A[i];
				else{
					a = 2000000000;
					break;
				}
			}
			if (ans2 > a)
				ans2 = a;
		}

		printf ("%d %d\n",ans1,ans2);
	}
	return 0;
}