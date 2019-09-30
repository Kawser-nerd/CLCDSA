//???????-std=c++11??????????
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<algorithm>
#include<cstdlib>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<iostream>
//#include<iomanip>
//#include<utility>
//#include<tuple>//make_tuple(a,b,c)??????get<?>(tuple?)?????

using namespace std;

int main(){
	int n;cin>>n;
	vector<string> v;
	for(int i=0;i<n;i++){
		string a;
		cin>>a;
		v.push_back(a);
		}
	sort(v.begin(),v.end());
	int j=0;int num=1;string a=v[0];
	while(j!=v.size()){
		int p=1;
		if(v[j]==v[j+1]){
		while(v[j]==v[j+1]){
			p++;
			j++;
			}
		if(p>num)a=v[j],num=p;
	}else {
			j++;
		}
	}
	cout<<a<<endl;
  return 0;
}