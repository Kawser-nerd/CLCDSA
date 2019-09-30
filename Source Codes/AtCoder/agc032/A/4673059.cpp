#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void prnt(vector<int> b){
	for(int i=0;i<b.size();i++){
		cout<<b[i]<<endl;
	}
	return;
}
void ok(vector<int>& b,vector<int>& ans,int* bo){
	//prnt(b);
	//cout<<"size="<<b.size()<<endl;
	if(b.size()==1&&b[0]==1){
		//cout<<"hoge\n";
		ans.push_back(1);
		*bo=1;
		return;
	}
	for(int i=b.size()-1;i>=0;i--){
		if(b[i]==i+1){
			//cout<<"ho\n";
			b.erase(b.begin()+i);
			ans.push_back(i+1);
			ok(b,ans,bo);
			if(*bo==1) return;
			ans.pop_back();
			b.insert(b.begin()+i,i+1);
			break;
		}
	}
	return ;
}

int main(){
	int n;
	cin>>n;
	vector<int> b(n,0);
	vector<int> ans;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int bo=0;
	ok(b,ans,&bo);
	//cout<<"bo="<<bo<<endl;
	if(bo==1){
		for(int i=0;i<ans.size();i++){
			cout<<ans[ans.size()-i-1]<<endl;
		}
	}else{
		cout<<-1<<endl;
	}
	return 0;
}