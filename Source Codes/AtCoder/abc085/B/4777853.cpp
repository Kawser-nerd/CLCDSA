#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int n;
	cin >> n;

	set<int> set;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		set.insert(num);
	}

	//sort(set.begin(), set.end());

	cout <<  set.size() << endl;
}