#include<cstdio>
#include<cstring>
using namespace std;
int jud;
char s[200005],x[200005],ch[150],sh[150];
int main(){
	scanf("%s",s);	scanf("%s",x);
	for(int i = 0; i < strlen(s); i++){
		if(ch[s[i]] == '\0'){
			ch[s[i]] = x[i];
		}
		if(sh[x[i]] == '\0'){
			sh[x[i]] = s[i];
		}
		if(ch[s[i]] != x[i] || sh[x[i]] != s[i]){
			printf("No");
			jud = 1;
			break;
		}
	}
	if(!jud) printf("Yes");
}