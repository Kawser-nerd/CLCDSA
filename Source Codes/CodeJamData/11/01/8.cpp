#include <iostream>
using namespace std;
int main(){
	int tnum;cin>>tnum;int tcou=0;
	while (tnum--){
		int n;cin>>n;
		int pos[2]={1,1};
		int tim[2]={0,0};
		int ans=0;
		while (n--){
			char c;int p;
			cin>>c>>p;
			int num=((c=='O')?0:1);
			int T=abs(pos[num]-p)+1;
			pos[num]=p;
			int TT=max(1,T-tim[num]);
			ans+=TT;
			tim[1-num]+=TT;
			tim[num]=0;
		}
		cout<<"Case #"<<++tcou<<": "<<ans<<endl;
	}
	return 0;
}
