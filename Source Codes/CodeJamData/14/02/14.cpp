#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test;

	scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		double ans = 1e100, C, F, X;
		scanf ("%lf %lf %lf",&C,&F,&X);

		double time = 0, rate = 2;
		for (int i=0;i<=10000000;i++){
			ans = min(ans,time+X/rate);
			time += C/rate; rate += F;
		}
		printf ("Case #%d: %.7lf\n",Case,ans);
	}

	return 0;
}