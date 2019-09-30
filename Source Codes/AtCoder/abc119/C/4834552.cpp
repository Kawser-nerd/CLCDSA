#include<iostream>
#include<stack>
#include<vector>
#include<numeric>
#include<cmath>
using namespace std;

int main(){
	int N,A,B,C;
	cin>>N>>A>>B>>C;
	int sum=A+B+C;
	int l[N];
	for(int i=0;i<N;++i)cin>>l[i];
	int ans=10000;
	vector<int> status;
	for(int i=0;i<N;++i){
		status.push_back(0);
	}
	status.push_back(-1);
	stack<vector<int> >S;
	S.push(status);
	vector<vector<int> >statusarr;
	while(!S.empty()){
		status=S.top();
		/*
		for(int i=0;i<status.size();++i){
			cout<<status[i]<<" ";
		}
		cout<<endl;
		*/
		S.pop();
		if(status[N]==N-1){
			vector<int>a,b,c;
			for(int i=0;i<N;++i){
				if(status[i]==1)a.push_back(l[i]);
				if(status[i]==2)b.push_back(l[i]);
				if(status[i]==3)c.push_back(l[i]);
			}
			if(a.size()>0 && b.size()>0 && c.size()>0){
				int mp=0;
				int tmpa=accumulate(a.begin(),a.end(),0);
				int tmpb=accumulate(b.begin(),b.end(),0);
				int tmpc=accumulate(c.begin(),c.end(),0);
				mp+=abs(tmpa-A)+abs(tmpb-B)+abs(tmpc-C);
				mp+=(a.size()-1)*10+(b.size()-1)*10+(c.size()-1)*10;
				if(ans>mp)ans=mp;
			}
		}
		else{
			status[N]++;
			for(int i=0;i<=3;++i){
				status[status[N]]=i;
				S.push(status);
			}
		}
	}
	cout<<ans<<endl;
}