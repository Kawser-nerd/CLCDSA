#include<iostream>
#include<string>
using namespace std;

int main(){
	int N,Q;
	cin>>N>>Q;
	int t[N];
	for(int i=0;i<N-1;++i)t[i]=0;
	string S;
	cin>>S;
	for(int i=0;i<N;++i){
		if((S[i]=='A') && (S[i+1]=='C')){
			t[i+1]=t[i]+1;
		}
		else{
			t[i+1]=t[i];
		}
	}
	int l[Q],r[Q];
	for(int i=0;i<Q;++i)cin>>l[i]>>r[i];
	for(int i=0;i<Q;++i){
		cout<<t[r[i]-1]-t[l[i]-1]<<endl;
	}
}