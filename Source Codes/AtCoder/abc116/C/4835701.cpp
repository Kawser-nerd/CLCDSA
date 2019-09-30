#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int h[N];
	for(int i=0;i<N;++i)cin>>h[i];
	int ans=0;
	while(true){
		/*
		for(int i=0;i<N;++i){
			cout<<h[i]<<" ";
		}
		cout<<endl;
		*/
		int r=-1;
		int l=-1;
		for(int i=0;i<N;++i){
			if(h[i]>0 && r==-1)r=i;
			if(h[i]==0 && r!=-1 && l==-1)l=i-1;
		}
		if(r!=-1 && l==-1)l=N-1;
		//cout<<r<<" "<<l<<endl;
		for(int i=r;i<=l;++i)h[i]--;
		if(r==-1)break;
		ans++;
	}
	cout<<ans<<endl;
}