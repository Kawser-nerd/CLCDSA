#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

string s;
map<char,int> m;
int n[1000005] = {};
int num = 0,num2 = 0;

int main(){
	cin >> s;

	for(int i =0; i< s.size();i++)m[s[i]]++;

	for(auto im: m){
		if(im.second %2 != 0){
			m[im.first]--;
			num++;
		}
	}
	sort(n,n+num);
	
	for(auto im: m){
		for(int i =im.second; i > 0; i-=2){
			n[0] += 2;
			sort(n,n+num);
		}
	}
	cout << n[0]+(int)(num > 0) <<endl;

	return 0;
}