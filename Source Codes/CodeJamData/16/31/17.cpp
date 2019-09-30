/* ***********************************************
Author        :axp
Created Time  :2016/5/8 17:07:05
TASK		  :A.cpp
LANG          :C++
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 30;
int T;
int ar[N];
int sum;
int num;
int n;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		scanf("%d",&n);
		num=0;
		sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&ar[i]);
			if(ar[i])num++;
			sum+=ar[i];
		}
		printf("Case #%d:",kase);
		while(sum)
		{
			int se=0;
			putchar(' ');
			if(num<=2)
			{
				for(int i=0;i<n;i++)
					if(ar[i])
					{
						putchar('A'+i);
						ar[i]--;
						sum--;
						if(ar[i]==0)num--;
					}
			}
			else
			{
				for(int i=0;i<n;i++)
					if(ar[i]>ar[se])
						se=i;
				putchar('A'+se);
				ar[se]--;
				sum--;
				if(ar[se]==0)num--;
			}
		}
		putchar(10);
	}
    return 0;
}
