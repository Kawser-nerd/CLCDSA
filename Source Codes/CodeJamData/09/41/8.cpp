#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;



int main(int argc,char **argv)
{
	int CASES;
	cin >> CASES;
	for(int cn=1;cn<=CASES;++cn)
	{
		int N;
		cin >> N;
		vector<string> v(N,string());
		for(int i=0;i<N;++i)
		{
			cin >> v[i];
		}
		int out = 0;
		for(int i=0;i<N;++i)
		{
			int j = i;
			for(;j<N;++j)
			{
				bool yay = true;
				for(int k=i+1;k<N;++k)
				{if(v[j][k]=='1'){yay = false;break;}}
				if(yay)break;
			}
			out += j-i;
			for(;j>i;--j)
			{
				swap(v[j],v[j-1]);
			}
		}
		printf("Case #%d: %d\n",cn,out);
	}
	return 0;
};
