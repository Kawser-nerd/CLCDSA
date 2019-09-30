#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

string li[105];
int n,l;

int main(){
	cin >> n >> l;
	for(int i=0;i<n;i++) cin >> li[i];
	sort(li,li+n);
	for(int i=0;i<n;i++) cout << li[i];
	cout << endl;
	return 0;
}