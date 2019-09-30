#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
bool flag[100000];
int main()
{
	int num;
	scanf("%d", &num);
	vector<ll>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
	}
	vector<ll>dif;
	for (int i = 0; i < num - 1; i++)dif.push_back(vec[i + 1] - vec[i]);
	int kai;
	ll gen;
	scanf("%d%lld", &kai, &gen);
	vector<int>v;
	for (int i = 0; i < num - 1; i++)v.push_back(i);
	for (int i = 0; i < kai; i++)
	{
		int z;
		scanf("%d", &z);
		swap(v[z - 2], v[z - 1]);
	}
	vector<int>ans;
	ans.resize(num - 1);
	for (int i = 0; i < num - 1; i++)
	{
		if (!flag[i])
		{
			vector<int>z;
			int now = i;
			for (;;)
			{
				if (flag[now])break;
				flag[now] = true;
				z.push_back(now);
				now = v[now];
			}
			for (int i = 0; i < z.size(); i++)
			{
				ans[z[i]] = z[(gen + i) % z.size()];
			}
		}
	}
	printf("%lld\n", vec[0]);
	ll now = vec[0];
	for (int i = 1; i < num; i++)
	{
		now += dif[ans[i - 1]];
		printf("%lld\n", now);
	}
}