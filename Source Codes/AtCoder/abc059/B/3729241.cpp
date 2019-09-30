#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

int main(){
	char a[100000], b[100000];
	scanf("%s", a);
	scanf("%s", b);
	int lena = strlen(a);
	int lenb = strlen(b);
	if(lena > lenb) printf("GREATER\n");
	else if(lenb > lena) printf("LESS\n");
	else{
		if(strcmp(a,b) > 0) printf("GREATER\n");
		else if(strcmp(a,b) == 0) printf("EQUAL\n");
		else printf("LESS\n");
	}
	return 0;
}