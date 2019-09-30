#include <iostream>
#include<cstring>
using namespace std;
#define mems(a) (memset(a,0,sizeof(a)))
int grid[102][102];
int height, width, sum, colors, counts;
int main()
{
	cin >> height >> width >> sum;
	mems(grid);
	counts = -1;
	for (int i = 1; i <= sum; i++)
		{
			cin>>colors;
			while (colors--)
			{
				counts++;
				grid[(counts / height) & 1 ? (height - 1 - (counts%height)) : counts % height][counts / height] = i;
			}
		}
		for (int i = 0; i<height; i++)
		{
			for (int j = 0; j<width; j++)
			{
				if (j!=0) cout<<" ";
				cout<<grid[i][j];
			}
			cout << endl;
		}
	
	return 0;
}