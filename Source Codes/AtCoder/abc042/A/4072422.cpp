#include<iostream>
#include<cstdio>
using namespace std;

int li[3];

int main(){
	for(int i=0;i<3;i++) cin >> li[i];
	sort(li,li+3);
	if(li[0] == 5 && li[1] == 5 && li[2] == 7) printf("YES\n");
	else printf("NO\n");
	return 0;
}