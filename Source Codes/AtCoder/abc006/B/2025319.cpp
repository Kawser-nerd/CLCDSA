#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	long long nums[num];
	long long x = 10007;
	nums[0] = 0;
	nums[1] = 0;
	nums[2] = 1;

	for (int i = 3; i < num; ++i)
	{
		nums[i] = (nums[i-1] % x) + (nums[i-2] % x) + (nums[i-3] % x);
	}

	
	for (int i = 0; nums[num-1] > x; i++)
	{
		nums[num-1] -= x;
	}


	cout << nums[num-1] << endl;
	// long long ans = nums[num-1] % toAns; 
	// cout << ans<< endl;
}