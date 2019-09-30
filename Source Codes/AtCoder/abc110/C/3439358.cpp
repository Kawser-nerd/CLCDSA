#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 2*100000+5
char s1[MAXN],s2[MAXN];
int a[30],b[30];
int main() {
	scanf("%s",s1),scanf("%s",s2);
	for(int i=0;s1[i];i++)
		a[s1[i]-'a']++;
	for(int i=0;s2[i];i++)
		b[s2[i]-'a']++;
	sort(a,a+30), sort(b,b+30);
	for(int i=0;i<30;i++)
		if(a[i]!=b[i]) {
			puts("No");
			return 0;
		}
	puts("Yes");
}