#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stdio.h>

using namespace std;

#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))


int t,n;

double d,a,t1,t2,x1,x2,f,p;

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>d>>n>>a;
		if(n==2){
			cin>>t1>>x1;
			cin>>t2>>x2;
			if(x1>d){
				f=0;
			}
			else{
				f=(d-x1)/((x2-x1)/t2);
			}
		}
		else{
			cin>>t1>>x1;
			f=0;
		}
				
			cout<<"Case #"<<i<<":"<<endl;
		for(int j=0;j<a;j++){
			cin>>p;
			double u=pow((2*d/p),0.5);
				printf("%.20f\n",maX(u,f));
		}
	}
	return 0;
}
