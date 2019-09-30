#include <iostream>
#include <vector>
using namespace std;

int N,L,H;
int o[200];

int main()
{
	int i,j,k;
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> N >> L >> H;
		for(i=0; i<N; i++)
			cin >> o[i];
		for(i=L; i<=H; i++)
		{
			for(j=0; j<N; j++)
				if (!(o[j]%i == 0 || i%o[j] == 0))
					break;
			if (j >= N)
				break;
		}
		printf("Case #%d: ", cc);
		if (i <= H)
			printf("%d\n", i);
		else
			printf("NO\n");
	}
}
