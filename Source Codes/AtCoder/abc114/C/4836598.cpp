#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
using namespace std;

int GetDigit(int num){
	int digit=0;
	while(num!=0){
		num/=10;
		digit++;
	}
	return digit;
}

int main(){
	long N;
	cin>>N;
	int keta=GetDigit(N);
	stack<vector<int> >S;
	vector<int>status;
	for(int i=0;i<keta;++i){
		status.push_back(0);
	}
	S.push(status);
	int ans=0;
	while(!S.empty()){
		vector<int>now=S.top();
		status=S.top();
		S.pop();
		/*
		for(int i=0;i<status.size();++i){
			cout<<status[i]<<" ";
		}
		cout<<endl;
		*/
		for(int i=0;i<keta;++i){
			if(status[i]==0){
				status[i]=3;
				S.push(status);
				status[i]=5;
				S.push(status);
				status[i]=7;
				S.push(status);
				break;
			}
		}
		while(now[now.size()-1]==0 && now.size()>0)now.pop_back();
		/*
		for(int i=0;i<now.size();++i){
			cout<<now[i]<<" ";
		}
		cout<<endl;
		*/
		int tmp=0;
		int judge3=0;
		int judge5=0;
		int judge7=0;
		for(int i=0;i<now.size();++i){
			if(now[i]==3)judge3=1;
			if(now[i]==5)judge5=1;
			if(now[i]==7)judge7=1;
			//cout<<pow(10,now.size()-i-1)<<endl;
			tmp+=now[i]*pow(10,now.size()-i-1);
		}
		if(judge3==1 && judge5==1 && judge7==1 && tmp<=N)ans++;
	}
	cout<<ans<<endl;
}