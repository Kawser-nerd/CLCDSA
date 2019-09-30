//{{{
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <valarray> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <complex> 
#include <memory> 
#include <new> 
#include <iterator> 
#include <limits> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cassert> 
#include <cctype> 
using namespace std;
//}}}

const int inf=1000000000;
char str[100000];
int G[16][16],G2[16][16];
int opt[1<<16][16];
int n,m;
int main(){
	int tests;
	scanf("%d",&tests);
	for(int t=1;t<=tests;t++){
		scanf("%d%s",&m,str);
		n=strlen(str);
		memset(G,0,sizeof(G));
		memset(G2,0,sizeof(G2));
		for(int i=0;i<n;i+=m)
			for(int j=0;j<m;j++)
				for(int k=0;k<m;k++)
					if(str[i+j]==str[i+k])
						G[j][k]++;
		for(int i=m;i<n;i+=m)
			for(int j=0;j<m;j++)
				for(int k=0;k<m;k++)
					if(str[i+j]==str[i-m+k])
						G2[j][k]++;
		int ret=-inf;
		for(int i=0;i<m;i++){
			for(int j=0;j<1<<m;j++)
				for(int k=0;k<m;k++)
					opt[j][k]=-inf;
			opt[1<<i][i]=0;
			for(int j=1;j<1<<m;j++)
				for(int k=0;k<m;k++){
					if(opt[j][k]<0)
						continue;
					for(int l=0;l<m;l++)
						if(1<<l&~j)
							opt[1<<l|j][l]>?=opt[j][k]+G[k][l];
				}
			for(int j=0;j<m;j++)
				ret>?=opt[(1<<m)-1][j]+G2[i][j];
		}
		printf("Case #%d: %d\n",t,n-ret);
	}
scanf("%*s");
	return 0;
}
