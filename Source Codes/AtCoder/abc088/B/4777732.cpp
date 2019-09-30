#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v;
	int va = 0, vb = 0;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) va += v[i];
		else vb += v[i];
	}

	cout << va - vb << endl;
}