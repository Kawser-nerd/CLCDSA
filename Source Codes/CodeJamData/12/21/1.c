#include <stdio.h>
#include <iostream>
using namespace std;
int N,total;
int J[201];
int R[201];

int main()
{
	int i,j,k;
	int r;
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> N;
		for(i=0; i<N; i++) cin >> J[i];
		total = 0;
		for(i=0; i<N; i++) total += J[i];

		printf("Case #%d:",cc);
		for(r=0; r<N; r++)
		{
			// bsearch
			double l,h,m;
			l = 0; h = 1;
			while(h-l > 1e-10)
			{
				m = (l+h)/2;
				
				double t = J[r] + m*total;
				double left = 1.0-m;
				for(i=0; i<N; i++)
				{
					if (i == r) continue;
					double minp =  (t-J[i])/total;
					if (minp < 0) continue;
					left -= minp;
				}
				
				if (left < 0) h = m;
				else l = m;
			}
			printf(" %.5lf", m*100);
		}
		printf("\n");
	}	
}
