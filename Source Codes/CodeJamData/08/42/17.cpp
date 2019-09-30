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

int main(){
	int tests;
	scanf("%d",&tests);
	for(int t=1;t<=tests;t++){
		int n,m,a;
		cin>>n>>m>>a;
		bool found=false;
		printf("Case #%d:",t);
		try{
			for(int x1=0;x1<=n;x1++)
				for(int y1=x1==0?1:0;y1<=m;y1++)
					for(int x2=0;x2<=n;x2++)
						for(int y2=x2==0?1:0;y2<=m;y2++)
							if((long long)x1*y2-(long long)x2*y1==a){
								found=true;
								printf(" 0 0 %d %d %d %d\n",x2,y2,x1,y1);
								throw 1;
							}
		}catch(...){}
		if(!found)
			printf(" IMPOSSIBLE\n");
	}
scanf("%*s");
	return 0;
}
