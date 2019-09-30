#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
 
int main(){
	string s;
	int k;
	cin >> s >> k;
 
	if(k>s.size()){
		cout << 0 << endl;
		return 0;
	}
 
	map<string, bool> cmap;
	for(int i=0; i<=s.size()-k; i++){
		cmap[s.substr(i, k)] = true;
	}
	cout << cmap.size() << endl;
}