#include<stdio.h>
#include<string.h>

int main(){
	int n,ans=200000,i,j,tmp=0;
	char s[101],ss[101];
	scanf("%s",s);
	for(j=0;j<26;j++){
		strcpy(ss,s);
		while(1){
			int f=0;char t='a'+j;
			for(i=0;ss[i]!=0;i++){
				if(t!=ss[i])f=1;
			}
			if(f==0)break;
			for(i=1;ss[i]!=0;i++){
				if(ss[i]=='a'+j)ss[i-1]=ss[i];
			}ss[i-1]=0;
			tmp++;
		}
		if(tmp<ans)ans=tmp;
		tmp=0;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^