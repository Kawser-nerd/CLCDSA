#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char s[100];

int main(){
	int d;
	scanf("%d",&d);
	for(int tno=1;tno<=d;tno++){
		scanf("%s",s);
		int z = strlen(s);
		printf("Case #%d: ",tno);
		if(!next_permutation(s,s+z)){
			int a = 0;
			while(s[a] == '0'){
				++a;
			}
			printf("%c",s[a]);
			for(int i=0;i<=a;i++) printf("0");
			printf("%s\n",s+a+1);
		}else printf("%s\n",s);
	}
}
