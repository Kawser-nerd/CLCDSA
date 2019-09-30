#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<list>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int csK, csN;
int N, K;

int main()
{
	int i, j, k, m, t;
	scanf("%d", &csN);
	for(csK = 1; csK <= csN; ++csK)
	{
		scanf("%d %d", &N, &K);
		if(((K+1)&((1<<N)-1)) == 0)
			printf("Case #%d: ON\n", csK);
		else
			printf("Case #%d: OFF\n", csK);
	}
}


