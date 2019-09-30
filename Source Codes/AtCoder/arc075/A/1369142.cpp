/*
 * test.cpp
 *
 *
 *      Author: Fireworks
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<bitset>
#include<set>
#include<iomanip>
#include<fstream>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<list>
#include<sstream>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,long long> il;
typedef pair<long long,long long> ll;
typedef pair<ll,int> lli;
typedef pair<long long,int> li;
typedef pair<double,double> dd;
typedef pair<ii,int> iii;
typedef pair<double,int> di;
typedef pair<ii,ii> iiii;
long long mod = 1000000007LL;
long long base = 37;
long long large = 1000000000000000000LL;



int main(){
	int n;
	cin>>n;
	vector<int> a(n,0);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	int s = 0;
	int mini = 1000000;
	for(int i=0;i<n;i++){
		s+=a[i];
		if(a[i]%10){
			mini=min(a[i],mini);
		}
	}
	if(s%10==0) s-=mini;
	s=max(s,0);
	cout<<s<<endl;

	/*int totalcase;
	int testcase=0;
	cin>>totalcase;
	ofstream out;
	out.open("result.txt");

	while(totalcase--){
		testcase++;
		out<<"Case #"<<testcase<<": ";
		cout<<testcase<<": "<<endl;

		//GOGOGO


		//END
	}
	out.close();*/

	return 0;
}