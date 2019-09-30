#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

int mt[4][8] = {
	{0,1,2,3,4,5,6,7},
	{1,4,3,6,5,0,7,2},
	{2,7,4,1,6,3,0,5},
	{3,2,5,4,7,6,1,0}	
};

int c2d(char c)
{
	if (c == '1') return 0;
	if (c == 'i') return 1;
	if (c == 'j') return 2;
	if (c == 'k') return 3;
}

int mul(int a, int b)
{
	if (a >= 4 && b >= 4)
	{
		a -= 4;
		b -= 4;
	}
	if (a >= 4 && b < 4)
	{
		a -= 4;
		b += 4;
	}
	return mt[a][b];
}

int main()
{
	int cc,ca;
	long long i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		long long L,X;
		cin >> L >> X;
		string S;
		cin >> S;
		set<pair<long long, long long> > visited;
		int r = 0;
		for(i=0; ;i++)
		{
			long long p = i%S.size();
			r = mul(r, c2d(S[p]));
			if (visited.find(make_pair(p, r)) != visited.end())
				break;
			if (r == 1)
				break;
			visited.insert(make_pair(p,r));
		}
		if (r != 1)
		{
			printf("Case #%d: NO\n", cc);
			continue;
		}
		long long p1 = i+1;

		visited.clear();
		r = 0;
		for(i=0; ; i++)
		{
			long long p = S.size() - i%S.size() -1;
			r = mul(c2d(S[p]), r);
			if (visited.find(make_pair(p, r)) != visited.end())
				break;
			if (r == 3)
				break;
			visited.insert(make_pair(p,r));
		}
		if (r != 3)
		{
			printf("Case #%d: NO\n", cc);
			continue;
		}
		long long p3 = i+1;

		r = 0;
		visited.clear();
		for(i=p1;;i++)
		{
			long long p = i%S.size();
			r = mul(r, c2d(S[p]));
			if (visited.find(make_pair(p,r)) != visited.end())
				break;
			if (r == 2)
				break;
			visited.insert(make_pair(p,r));
		}
		if (r != 2)
		{
			printf("Case #%d: NO\n", cc);
			continue;
		}
		long long p2 = i-p1+1;

		long long left = L*X-p1-p2-p3;
		if (left < 0)
		{
			printf("Case #%d: NO\n", cc);
			continue;
		}
		if (left == 0)
		{
			printf("Case #%d: YES\n", cc);
			continue;
		}

		long long start = p1+p2;
		long long length = L*X - p1 - p2 - p3;
		int t = 0;
		for(i=start; i<S.size() && i < start+length; i++)
		{
			t = mul(t, c2d(S[i]));
			left--;
		}
		if (left > S.size())
		{
			int t2 = 0;
			for(i=0; i<S.size(); i++)
				t2 = mul(t2, c2d(S[i]));
			long long leftcycle = (left/S.size())%4;
			for(i=0; i<leftcycle; i++)
				t = mul(t, t2);
			left = left%S.size();
		}
		for(i=0; i<left; i++)
			t = mul(t, c2d(S[i]));
		
		if (t == 0)
			printf("Case #%d: YES\n", cc);
		else
			printf("Case #%d: NO\n", cc);
					
	}
}
