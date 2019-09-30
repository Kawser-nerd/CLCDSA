#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    long long n,m;string s;
    while(cin>>n>>m>>s){
    	int a[200000],v=0;memset(a,0,sizeof(a));
    	for(int i=0;i<s.length();i++){
    		a[i]=v;
    		if(s[i]=='A'&&s[i+1]=='C'){
    			a[i+1]=v+1;i++;v++;
			}
		}
		cout<<endl;
		for(int i=0;i<m;i++){
			int x,y;cin>>x>>y;
			cout<<a[y-1]-a[x-1]<<endl;
		}
	}
    return 0;
}