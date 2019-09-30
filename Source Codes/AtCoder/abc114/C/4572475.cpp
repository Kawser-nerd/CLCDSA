#include<iostream>
#include<cstdio>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int countnum = 0;
int T, N;
string bign;
void DFS(int index, int flag1,int flag2,int flag3,string str)
{
	if (index == bign.size())
	{
		if (flag1&&flag2&&flag3&&str <= bign)
			countnum++;
		return;
	}
	else
	{
		if (flag1&&flag2&&flag3)
			countnum++;
	}
	DFS(index + 1, 1, flag2, flag3, str + '3');
	DFS(index + 1, flag1 , 1, flag3, str + '5');
	DFS(index + 1, flag1, flag2, 1, str + '7');
}
int main()
{
	cin >> bign;
	DFS(0, 0, 0, 0, "");
	printf("%d\n", countnum);
	system("pause");
	return 0;
}