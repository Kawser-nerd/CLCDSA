#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<string>
//#include<string>
//#include<sstream>
#include<iomanip>
using namespace std;
int main() {
	int a[2],b[2];
	scanf("%d%d%d%d",&a[0],&a[1],&b[0],&b[1]);
	int i,j;
	for(i=0;i<b[1]-a[1];i++){
		printf("U");
	}
	for(i=0;i<b[0]-a[0];i++){
		printf("R");
	}
	for(i=0;i<b[1]-a[1];i++){
		printf("D");
	}
	for(i=0;i<b[0]-a[0];i++){
		printf("L");
	}
	
	printf("L");
	for(i=0;i<b[1]-a[1]+1;i++){
		printf("U");
	}
	for(i=0;i<b[0]-a[0]+1;i++){
		printf("R");
	}
	printf("DR");
	for(i=0;i<b[1]-a[1]+1;i++){
		printf("D");
	}
	for(i=0;i<b[0]-a[0]+1;i++){
		printf("L");
	}
	printf("U\n");
}