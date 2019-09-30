#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>

using namespace std;

char a[11],b[11],c[11];

int main(){
	scanf("%s %s %s",a,b,c);
	int lena = strlen(a),lenb = strlen(b),lenc = strlen(c);
	if(a[lena - 1] == b[0] && b[lenb - 1] == c[0]) printf("YES\n");
	else printf("NO\n");
	}