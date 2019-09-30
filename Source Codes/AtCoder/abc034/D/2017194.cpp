#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>

using namespace std;
 
#define MOD (long long int)(1e9+7)
#define ll long long int


int main(void){
	int n,k;
	cin>>n>>k;
	ll w[1000];
	int p[1000];
	for(int i=0;i<n;i++){
		cin>>w[i]>>p[i];
	}

	double mizu[1000];


	double pu=100.0,pd=0.0;
	double check=0;
	while(pu-pd>=0.0000000001){
		for(int i=0;i<n;i++){
			mizu[i]=w[i]*p[i]-w[i]*((pu+pd)/2);
		}
		sort(mizu,mizu+n);
		reverse(mizu,mizu+n);
		check=0;
		for(int i=0;i<k;i++){
			check+=mizu[i];
		}
		if(check>=0){
			pd=(pu+pd)/2;
		}else{
			pu=(pu+pd)/2;
		}
	}
	//cout<<mizu[0]<<" "<<mizu[1]<<" "<<mizu[2]<<endl;
	cout<<fixed<<setprecision(9)<<pu<<endl;
	return 0;	
}