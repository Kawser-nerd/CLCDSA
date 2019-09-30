#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int cas;
	cin>>cas;
	for(int ca=1; ca<=cas; ++ca){
		long long a,b,c;
		cin>>a>>b>>c;
		int num=0;
		for(long long i=a*c; i<b; i*=c) num++;
		if(num==0) 
			cout<<"Case #"<<ca<<": 0"<<endl;
		else{
			int rtn=(int)floor(log((double)num)/log(2.0))+1;
			cout<<"Case #"<<ca<<": "<<rtn<<endl;
		}
	}
}
