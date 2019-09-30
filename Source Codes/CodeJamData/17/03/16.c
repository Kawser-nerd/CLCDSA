#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main()
{
	int cc,ca;
	cin >> ca;
	for(int cc=1; cc<=ca; cc++)
	{
		long long N, K;
		cin >> N >> K;
		map<long long, long long> left;
		left[N] = 1;
		long long y,z;
		while(K > 0)
		{
			map<long long, long long>::iterator p = left.end();
			p--;

			long long a = p->first;
			long long b = p->second;

			if (b >= K)
			{
				if (a%2 == 1)
					y = z = (a-1)/2;
				else
				{
					z = (a-1)/2;
					y = z+1;
				}
				break;
			}
			K -= b;
			left[(a-1)/2]+=b;
			left[a-1-(a-1)/2]+=b;
			left.erase(p);
		}
		printf("Case #%d: %lld %lld\n", cc, y, z);
	}
}

