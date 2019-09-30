#include<iostream>
using namespace std;
int dist(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}
int main()
{
	int N;
	scanf("%d", &N);
	int t, x, y;
	int nowt = 0, nowx = 0, nowy = 0;
	bool flag = true;
	for (int i = 1;i <= N;i++)
	{
		scanf("%d %d %d", &t, &x, &y);
		int dis = dist(nowx, nowy, x, y);
		if (dis > t - nowt || ((t - nowt) - dis) % 2)
			flag = false;
	}
	if (flag)puts("Yes");
	else puts("No");


}