#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> dis;

int main()
{
	long long i,j,k;
	long long cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		dis.clear();
		long long L, t, N, C;
		cin >> L >> t >> N >> C;
		vector<long long> c;
		for(i=0; i<C; i++)
		{
			long long aa;
			cin >> aa;
			c.push_back(aa);
		}
		long long total = 0;
		for(i=0; i<N; i++)
		{
			dis.push_back(c[i%C]);
			total += c[i%C] * 2;
		}
		reverse(dis.begin(), dis.end());
		long long a = 0;
		while(a < t && dis.size() > 0)
		{
			long long d = dis[dis.size()-1];
			dis.pop_back();
			long long left = a+d*2-t;
			if (left > 0)
				dis.push_back(left/2);
			a = min(a+d*2, t);
		}
		sort(dis.begin(), dis.end());
		reverse(dis.begin(), dis.end());

		long long r = total;
		for(i=0; i<L && i<dis.size(); i++)
			r -= dis[i];
		
		printf("Case #%lld: %lld\n", cc, r);	
	}	
}
