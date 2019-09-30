#include<iostream>

using namespace std;
int xs[2000];
int ys[2000];
int main(){
	int cas;
	cin>>cas;
	for(int ca=1;ca<=cas; ++ca){
		int n;
		cin>>n;
		for(int i=0; i<n; ++i){
			cin>>xs[i]>>ys[i];	
		}
		int rtn=0;
		for(int i=0; i<n; ++i){
			for(int j=i+1; j<n; ++j){
				if((xs[i]-xs[j])*(ys[i]-ys[j])<0) ++rtn;
			}
		}
		cout<<"Case #"<<ca<<": "<<rtn<<endl;
	}
}
