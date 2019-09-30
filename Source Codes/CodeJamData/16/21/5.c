#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[2048];
int c[32];
char name[][10]={"ZERO", "SIX", "EIGHT", "TWO", "FOUR", "THREE", "SEVEN", "FIVE", "ONE", "NINE"};
char s[]="ZXGWURSVOI";
int d[]={0,6,8,2,4,3,7,5,1,9};
int ret[2048];

int cmp(const void *a,const void *b) {
	return *(int *)a-*(int *)b;
}

int main() {
	int N,cs=0,i,j,k;
	for(scanf("%d",&N);N--;) {
		scanf("%s",str);
		memset(c,0,sizeof(c));
		for(i=0;str[i];i++) c[str[i]-'A']++;
		for(i=k=0;i<10;i++) {
			while(c[s[i]-'A']) {
				ret[k++]=d[i];
				for(j=0;name[i][j];j++) c[name[i][j]-'A']--;
			}
		}
		qsort(ret,k,sizeof(ret[0]),cmp);
		printf("Case #%d: ",++cs);
		for(i=0;i<k;i++) printf("%d",ret[i]);
		puts("");
	}
	return 0;
}
