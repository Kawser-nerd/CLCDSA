#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
map<string,char> C;
set<string> D;
string str(char c,char d){
	string ret="";
	ret+=c;
	ret+=d;
	return ret;
}
int main(){
	int tnum;cin>>tnum;
	int tcou;
	while (tnum--){
		++tcou;
		C.clear();
		D.clear();
		int Cnum;cin>>Cnum;
		while (Cnum--){
			string s;cin>>s;
			char o=s[2];
			s=s.substr(0,2);
			C[s]=o;
			swap(s[0],s[1]);
			C[s]=o;
		}
		int Dnum;cin>>Dnum;
		while (Dnum--){
			string s;cin>>s;
			D.insert(s);
			swap(s[0],s[1]);
			D.insert(s);
		}
		int n;cin>>n;
		string out;
		while (n--){
			char c;cin>>c;
			if (out.size()==0){
				out+=c;
				continue;
			}
			string pr=str(out[out.size()-1],c);
			if (C.find(pr)!=C.end()){
				out[out.size()-1]=C[pr];
			}
			else{
				bool bad=true;
				for (int i=0;i<out.size();++i)
					if (D.find(str(out[i],c))!=D.end()){
						out="";
						bad=false;
						break;
					}
				if (bad)
					out+=c;
			}
		}
		cout<<"Case #"<<tcou<<": [";
		for (int i=0;i<out.size();++i){
			if (i>0)
				cout<<", ";
			cout<<out[i];
		}
		cout<<"]"<<endl;
	}
	return 0;
}
