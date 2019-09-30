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
int A[10010],B[10010];
int opt[10010][2];
int main(){
	int tests;
	scanf("%d",&tests);
	for(int t=1;t<=tests;t++){
		int n,v;
		scanf("%d%d",&n,&v);
		for(int i=1;i<=(n-1)/2;i++)
			scanf("%d%d",A+i,B+i);
		for(int i=1;i<=n;i++){
			opt[i][0]=inf;
			opt[i][1]=inf;
		}
		for(int i=(n-1)/2+1;i<=n;i++){
			int tmp;
			scanf("%d",&tmp);
			opt[i][tmp]=0;
		}
		for(int i=(n-1)/2;i>=1;i--){
			int l=i*2,r=i*2+1;
			for(int a=0;a<2;a++)
				for(int b=0;b<2;b++){
					opt[i][A[i]==1?a&b:a|b]<?=opt[l][a]+opt[r][b];
					if(B[i])
						opt[i][A[i]!=1?a&b:a|b]<?=opt[l][a]+opt[r][b]+1;
				}
		}
		printf("Case #%d: ",t);
		if(opt[1][v]==inf)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",opt[1][v]);
	}
scanf("%*s");
	return 0;
}
