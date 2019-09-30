#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 
#include <cctype>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <list>
#include <iomanip>
#include <cassert>
 
using namespace std; 

const double PI=3.14159265358979323846264;

long long gcd(long long x,long long y){
	return y==0?x:gcd(y,x%y);
}


int main(){
	
	string s;
	cin>>s;
 
	int res=0,g=0,p=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='g'){
			if(g>p) p++,res++;
			else g++;
		}else{
			if(g>p) p++;
			else g++,res--;
		}
	}
	cout<<res<<endl;

	return 0;
 
}