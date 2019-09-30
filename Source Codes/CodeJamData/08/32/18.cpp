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

int cnt,len;
int b[100];
char c[100];
void getac(int d){
	if(d==len-1){
		long long a=c[0]-'0';
		long long ret=0;
		int opt=1;
		for(int i=1;i<len;i++){
			if(b[i-1]==0){
				a=a*10+c[i]-'0';
			}else if(b[i-1]==1){
				if(opt==1){
					ret+=a;
				}else{
					ret-=a;
				}
				opt=1;
				a=c[i]-'0';
			}else if(b[i-1]==2){
				if(opt==1){
					ret+=a;
				}else{
					ret-=a;
				}
				opt=2;
				a=c[i]-'0';
			}
		}
		if(opt==1){
			ret+=a;
		}else{
			ret-=a;
		}
		if(ret%2==0 || ret%3==0 || ret%5==0 || ret%7==0)
			cnt++;
	}else{
		b[d]=0;
		getac(d+1);
		b[d]=1;
		getac(d+1);
		b[d]=2;
		getac(d+1);
	}
}

int main(){
	int T,TT;
	scanf("%d",&T);
	for(TT=1;TT<=T;TT++){
		
		scanf("%s",c);
		len=strlen(c);
		cnt=0;
		getac(0);
		printf("Case #%d: %d\n",TT,cnt);
	
	}
}

