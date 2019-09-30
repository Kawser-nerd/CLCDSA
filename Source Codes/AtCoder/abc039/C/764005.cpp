#define rep(i,n) FOR(i,0,n)
#define FOR(i,s,n) for(int (i)=(s);(i)<(s)+(n);(i)++)
#define PI 3.14159265359
#define inf 1000000000
#define TIMEd 2000000
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <math.h>
#include<algorithm>
#include<stdio.h>
#include <set>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<int,ll> Pill;
 
 
int main(){
	char s[]="WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW",str[20];
	cin>>str;
	int t=strstr(s,str)-s;
	switch(t){
		case 0:
			cout<<"Do"<<endl;break;
		case 2:
			cout<<"Re"<<endl;break;
		case 4:
			cout<<"Mi"<<endl;break;
		case 5:
			cout<<"Fa"<<endl;break;
		case 7:
			cout<<"So"<<endl;break;
		case 9:
			cout<<"La"<<endl;break;
		case 11:
			cout<<"Si"<<endl;break;
	}
	return 0;
}