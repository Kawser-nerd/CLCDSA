#include<cstdio>
#include<string.h>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<iomanip>
#include<map>
#include<deque>
using namespace std;
//int limit=2147483647;//deque<int>deq;deq.push_front(a);deq.push_back(a);cout<<deq[i]<<endl;
//long long limit =9223372036854775807;//string(num,"hello");num???hello???v.
//string?????.length()?string????????????????????????????.
//.length()?(int)????????error?????.
//to_string()?????????????//set<string>s//map<string,int>salary;salary["ore"]=1400;salary["kimi"]=5000;
//????M_PI;//setprecison(??)???????????.#include<iomanip>
//cout<<"HIT"<<endl;cout<<setprecision(100)<<ans<<endl;
int main(){
	while(1){
		int n,q;cin>>n>>q;
		int a[n+1];memset(a,0,sizeof(a));
		for(int i=0;i<q;i++){
			int l,r;
			cin>>l>>r;
			l--;r--;
			a[l]+=1;
			a[r+1]-=1;
		}
		for(int i=0;i<n;i++){
			a[i+1]+=a[i];
			cout<<a[i]%2;
		}
		cout<<endl;return 0;
	}}//mainwhile