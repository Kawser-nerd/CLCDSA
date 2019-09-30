//I Guds namn
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> unq, v;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for(int i = 0;i < n;i++)
	{
		int a; cin >> a;
		unq.push_back(a), v.push_back(a);
	}
	sort(unq.begin(), unq.end()), sort(v.begin(), v.end());
	unq.resize(unique(unq.begin(), unq.end()) - unq.begin());
	if(unq.size() > 2)
	{
		cout << "No" << endl;
		return 0;
	}
	if(unq.size() == 1)
	{
		if(unq[0] == n - 1)
			cout << "Yes";
		else if(unq[0] > n / 2)
			cout << "No";
		else
			cout << "Yes";
		cout << endl;
		return 0;
	}
	if(unq[1] - unq[0] > 1)
	{
		cout << "No" << endl;
		return 0;
	}
	int sz1 = upper_bound(v.begin(), v.end(), v[0]) - v.begin(), sz2 = n - sz1;
	int cl2 = max(1, unq[0] - sz1 + 1);
	if(cl2 > (sz2 / 2) or (cl2 + sz1 != unq[1]))
		cout << "No";
	else
		cout << "Yes";
	cout << endl;
	return 0;
}