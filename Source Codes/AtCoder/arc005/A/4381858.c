#include<stdio.h>
#include<string.h>

int main(){
	int n,i,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		char s[101];
		scanf("%s",s);
		if(strcmp(s,"TAKAHASHIKUN")==0)ans++;
		if(strcmp(s,"Takahashikun")==0)ans++;
		if(strcmp(s,"takahashikun")==0)ans++;
		if(strcmp(s,"TAKAHASHIKUN.")==0)ans++;
		if(strcmp(s,"Takahashikun.")==0)ans++;
		if(strcmp(s,"takahashikun.")==0)ans++;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^