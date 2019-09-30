#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int N,K,T[1010];

long long cnt(long long t)
{
	long long r = 0;
	for (int i=0;i<N;i++){
		r += t / T[i] + 1;
	}
	return r;
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		scanf ("%d %d",&N,&K);
		for (int i=0;i<N;i++) scanf ("%d",&T[i]);

		long long l = 0, r = 1000000000000000000ll, m, a;
		while (l <= r){
			m = (l + r) / 2;
			if (cnt(m) >= K){
				a = m;
				r = m - 1;
			}
			else l = m + 1;
		}

		int all = K;
		for (int i=0;i<N;i++){
			all -= a / T[i] + 1;
			if (a % T[i] == 0) all++;
		}
		for (int i=0;i<N;i++){
			if (a % T[i] == 0){
				if (all == 1){
					printf ("%d\n",i+1);
					break;
				}

				all--;
			}
		}
	}
	return 0;
}