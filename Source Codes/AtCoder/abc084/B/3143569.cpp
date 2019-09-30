#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	char s[20];
	int a,b,len;
	int flag=1;
	cin>>a>>b;
	cin>>s;
	len=strlen(s);
	if(a+b+1!=len) printf("No\n");
	else {
		if(s[a]!='-') printf("No\n");
		else {
			for(int i=0; i<a; i++) {
				if(s[i]<'0'||s[i]>'9') {
					flag=0;
					printf("No\n");
					break;
				}
			}
			if(flag!=0) {
				for(int j=a+1; j<len; j++) {
					if(s[j]<'0'||s[j]>'9') {
						flag=0;
						printf("No\n");
						break;	
					}

				}
			}
			if(flag==1) printf("Yes\n");
		}
	}
	return 0;
}