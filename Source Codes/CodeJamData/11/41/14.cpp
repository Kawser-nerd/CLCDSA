#include <iostream>
#include <vector>
using namespace std;
struct walkway{
	int len,speed;
	walkway(){}
	walkway(int len,int speed):len(len),speed(speed){}
	double T(double S,double R,double& t){
		double runFor=min(len/(R+speed),t);
		t-=runFor;
		return runFor+(len-runFor*(R+speed))/(S+speed);
	}
};
bool operator<(const walkway& w1,const walkway& w2){
	return w1.speed<w2.speed;
}
vector<walkway> w;
int main(){
	int tnum,tcou=0;cin>>tnum;
	cout<<fixed;
	cout.precision(10);
	while (tnum--){
		int X;cin>>X;
		w.clear();
		int S,R;cin>>S>>R;
		double t;cin>>t;
		int N;cin>>N;
		int last=0;
		while (N--){
			int b,e,W;
			cin>>b>>e>>W;
			w.push_back(walkway(b-last,0));
			w.push_back(walkway(e-b,W));
			last=e;
		}
		w.push_back(walkway(X-last,0));
		sort(w.begin(),w.end());
		double ans=0;
		for (int i=0;i<w.size();++i){
			ans+=w[i].T(S,R,t);
		}
		cout<<"Case #"<<++tcou<<": "<<ans<<endl;
	}
	return 0;
}
