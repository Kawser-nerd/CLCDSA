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
	long long a,b;
	cin>>a>>b;
	vector<long long> h(n,0);
	for(int i=0;i<n;i++) cin>>h[i];
	long long low = 0;
	long long high = 1000000000LL;
	long long mid;
	long long ans;
	while(low<=high){
		mid = (low+high)/2;
		vector<long long> hh = h;
		long long cnt = 0;
		for(int i=0;i<n;i++){
			hh[i]-=mid*b;
			hh[i]=max(hh[i],0LL);
			if(hh[i]>0){
				cnt+=(hh[i]-1)/(a-b)+1;
			}
		}
		if(cnt<=mid){
			ans=mid;
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	cout<<ans<<endl;

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