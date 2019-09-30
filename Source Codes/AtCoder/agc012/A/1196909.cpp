#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef unsigned long long ull;

int main()
{
	ull n, t, ai;
	cin >> t;
	n = t * 3;
	ull counter = n-2;
	ull msum = 0;

	vector<ull> mems;
	mems.reserve(n);
	while (n > 0)
	{
		cin >> ai;
		mems.push_back(ai);
		--n;
	}

	sort(mems.begin(), mems.end());
	
	while (t > 0)
	{
		msum += mems[counter];
		counter -= 2;
		--t;
	}
	cout << msum << endl;

	return 0;
	
}