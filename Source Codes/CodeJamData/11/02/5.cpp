#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

string com[200];
string op[200];
char s[1000];
vector<char> a;

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int i,j,k,l,t,n,m,nn,b1;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%s",s);
			com[i]=s;
		}
		scanf("%d",&m);
		for (i=0;i<m;i++)
		{
			scanf("%s",s);
			op[i]=s;
		}
		scanf("%d",&nn);
		scanf("%s",s);
		a.clear();
		for (i=0;i<nn;i++)
		{
			a.push_back(s[i]);
			b1=1;
			while ((a.size()>=2)&&(b1==1))
			{
				b1=0;
				for (j=0;j<n;j++)
					if (((a[a.size()-1]==com[j][0])&&(a[a.size()-2]==com[j][1]))||
						((a[a.size()-1]==com[j][1])&&(a[a.size()-2]==com[j][0])))
					{
						b1=1;
						a.pop_back();
						a.pop_back();
						a.push_back(com[j][2]);
						break;
					}
			}
			if (a.size()>=2)
			{
				for (j=a.size()-2;j>=0;j--)
				{
					for (k=0;k<m;k++)
						if (((a[a.size()-1]==op[k][0])&&(a[j]==op[k][1]))||
							((a[a.size()-1]==op[k][1])&&(a[j]==op[k][0])))
						{
							a.clear();
							break;
						}
					if (a.size()==0) break;
				}
			}
		}
		printf("Case #%d: [",l+1);
		for (i=0;i<a.size();i++)
		{
			if (i!=0) printf(", ");
			printf("%c",a[i]);
		}
		printf("]\n");
	}
	return 0;
}

