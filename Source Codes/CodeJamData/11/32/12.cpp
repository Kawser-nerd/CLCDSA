#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <iostream>


using namespace std;


__int64 gcd(__int64 a, __int64 b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

vector<__int64> getDivs(__int64 a)
{
	vector<__int64> res;
	for (__int64 i = 1; i * i <= a; i++)
		if (a % i == 0)
		{
			res.push_back(a / i);
			res.push_back(i);
		}
	return res;
}
__int64 solve(__int64 l, __int64 h, vector<__int64> vin)
{
	__int64 a = vin.back();
	vector<__int64> divs = getDivs(a);

	__int64 ans = -1;
	for (int i =0;i<(int)divs.size();i++)
		if (l <= divs[i] && divs[i] <= h)
		{
			__int64 t = divs[i];
			bool f = false;
			for (int j=0;j<(int)vin.size() && !f;j++)
				if (vin[j] % t != 0 && t % vin[j] != 0)
					f = true;
			if (f)
				continue;

			if (ans == -1 || ans > t)
				ans = t;
		}

	for (int i=0;i<(int)vin.size();i++)
	{
		__int64 cur = vin[i];
		cur /= gcd(cur, a);
		if (a > 1000000000000000000LL / cur)
			return ans;
		a *= cur;
		if (a > h)
			return ans;
	}

	__int64 dv = l / a;
	__int64 md = l % a;
	if (md != 0)
		++dv;
	a *= dv;

	if (l <= a && a <= h)
		if (ans == -1 || ans > a)
			ans = a;

	return ans;
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int t;
	cin>>t;
	for (int aaa = 0; aaa < t; aaa++)
	{
		__int64 l, t;
		int n, c;
		cin>>l>>t>>n>>c;
		vector<__int64> dist1(c);
		vector<__int64> dist(n);

		for (int i=0;i<c;i++)
			cin>>dist1[i];
		for (int i=0;i<n;i++)
			dist[i] = dist1[i%c];

		reverse(dist.begin(),dist.end());
		__int64 tt = 0;
		t /= 2;
		while (dist.size() && t)
		{
			__int64 tc = min(dist.back(), t);
			dist.back() -= tc;
			if (dist.back() == 0)
				dist.pop_back();
			t -= tc;
			tt += 2*tc;
		}

		sort(dist.begin(),dist.end());
		while (dist.size() && l)
		{
			--l;
			tt += dist.back();
			dist.pop_back();
		}
		for (int i=0;i<(int)dist.size();i++)
			tt += dist[i] * 2;
		cout<<"Case #"<<aaa+1<<": ";
		cout<<tt;
		cout<<endl;
	}

	
    return 0;
}