#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

struct point{
	point(){x = y = 0;}
	long long x,y;
	bool operator <(const point t) const{
		return atan2(y,x) < atan2(t.y,t.x);
	}
}P[6030]; int C;

int N,X[3030],Y[3030];

long long ccw(point a, point b, point c)
{
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d:\n",Case);

		scanf ("%d",&N);
		for (int i=0;i<N;i++) scanf ("%d %d",&X[i],&Y[i]);
		for (int i=0;i<N;i++){
			fprintf (stderr,"%d %d\n",Case,i);
			C = 0;
			for (int j=0;j<N;j++) if (i != j){
				P[C].x = X[j] - X[i]; P[C].y = Y[j] - Y[i];
				C++;
			}
			sort(P,P+C);
			for (int j=0;j<C;j++) P[j+C] = P[j];

			int ans = N-1;
			for (int i=0,j=1;i<C;i++){
				while (j < i + C && ccw(P[i],point(),P[j]) <= 0) j++;
				int u = j - i;
				ans = min(ans,N-1-u);
			}
			printf ("%d\n",ans);
		}
	}
	return 0;
}