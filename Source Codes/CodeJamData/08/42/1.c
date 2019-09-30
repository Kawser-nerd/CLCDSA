#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

long long N,M,A;

int main()
{
	int i,j,k;
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> N >> M >> A;
		int a,b,c,d;
		int flag = 0;
		for(a=0; a<=N; a++) for(b=0; b<=N; b++) for(c=0; c<=M; c++) for(d=0; d<=M; d++)
		{
//			printf("%d %d %d %d %d\n", a,b,c,d,a*d-b*c);
			if (a*d-b*c == A)
			{
//				printf("found\n");
				if (!(a == 0 && c == 0) && !(b == 0 && d == 0) && !(a == b && c == d))
				{
//					printf("%d %d %d %d\n", a,b,c,d);
					flag = 1;
					goto done;
				}
			}
		}
done:
		if (flag == 1)
			printf("Case #%d: %d %d %d %d %d %d\n", cc, 0, 0, a, c, b, d);
		else
			printf("Case #%d: IMPOSSIBLE\n", cc);
	}
}
