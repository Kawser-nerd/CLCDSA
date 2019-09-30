#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int N;
	long long K;
	cin >> N >> K;
	vector<pair<int,int>> number(N);
	
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		number[i] = make_pair(a,b);
	}
	sort(number.begin(), number.end());
	long long looking = 0;
	for (int i = 0; i < N; i++)
	{
		looking += number[i].second;
		if (K <= looking)
		{
			cout << number[i].first<<endl;
			break;
		}
	}
	return 0;

}