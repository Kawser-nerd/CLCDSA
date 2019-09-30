#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
bool Sort(long long a, long long b)
{
	return a > b;
}
int main()
{
	int num;
	while (cin >> num)
	{
		vector<long long> arr(num);
		for (int i = 0; i < num; i++)
			cin >> arr[i];
		sort(arr.begin(), arr.end(), Sort);

		long long a = 0, b = 0, temp = arr[0];
		for (int i = 1; i < num; i++)
		{
			if (temp == arr[i])
			{
				if (a < arr[i])
				{
					a = arr[i];
				}
				else if (b < arr[i])
				{
					b = arr[i];
				}
				temp = -1;
			}
			else temp = arr[i];
		}
		cout << a*b << endl;
	}
	return 0;
}