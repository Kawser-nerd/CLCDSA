#include <iostream>
#include <queue>
using namespace std;
priority_queue<int>p;
int n, x, ans;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		p.push(x);
		cin >> x;
		p.push(x);
	}
	for (int i = 1; i <= n; i++)
	{
		p.pop();
		ans += p.top();
		p.pop();
	}
	cout << ans;
}