#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 
#include <cctype>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <list>
#include <iomanip>
#include <cassert>
 
using namespace std; 

const double PI=3.14159265358979323846264;

long long gcd(long long x,long long y){
	return y==0?x:gcd(y,x%y);
}

int main(){
	
	int n;
	cin>>n;

	long long x,y;
	cin>>x>>y;


	for(int i=0;i<n-1;i++){
		
		long long t,a;
		cin>>t>>a;

		if(t<x || a<y){	
			long long l=0,r=max(x/t,y/a)+10;
			while(r-l>1){
				long long mid=(l+r)/2LL;
				if(t*mid>=x && a*mid>=y) r=mid;
				else l=mid;
			}
			x=r*t,y=r*a;
		}else{
			x=t,y=a;
		}
		

	}

	cout<<x+y<<endl;
 
	return 0;
 
}