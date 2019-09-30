#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#define eps 1e-8
#define PI 3.14159265358979323846
using namespace std;

long long a[1000];


int main(){
	int T,TT;
	scanf("%d",&T);
	for(TT=1;TT<=T;TT++){
		int p,k,l,i;
		scanf("%d%d%d",&p,&k,&l);
		for(i=0;i<l;i++){
			scanf("%I64d",&a[i]);
		}
		if(p*k<l){
			printf("Case #%d: Impossible\n",TT);
		}else{
			sort(a,a+l,greater<long long>());
			long long j=0,cnt=1;
			long long ret=0;
			for(i=0;i<l;i++){
				ret+=a[i]*cnt;
				j++;
				if(j==k){
					j=0;
					cnt++;
				}
			}
			printf("Case #%d: %I64d\n",TT,ret);
		}
		
	}
}

