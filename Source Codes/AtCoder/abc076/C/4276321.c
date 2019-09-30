#include<stdio.h>
#include<string.h>

int main(){
	int gs=0,gt=0,i,j,f=0;
	char s[51],t[51],ans[51];
	scanf("%s%s",s,t);
	while(s[gs]!=0)gs++;
	while(t[gt]!=0)gt++;
	if(gs<gt){
		puts("UNRESTORABLE");
		return 0;
	}
	for(i=0;i<gs;i++){
		for(j=0;j<gt;j++){
			if(s[i+j]!=t[j]&&s[i+j]!='?')break;
		}
		if(j==gt){
			char tmp[51];
			/*for(j=0;j<gs;j++){
				if(j>=i&&j<i+gt)tmp[j]=t[j-i];
				else if(s[j]=='?')tmp[j]='a';
				else tmp[j]=s[j];
			}*/
			strcpy(tmp,s);
			for(j=0;j<gt;j++)tmp[i+j]=t[j];
			for(j=0;j<gs;j++){
				if(tmp[j]=='?')tmp[j]='a';
			}
			if(f==0){
				strcpy(ans,tmp);
				f=1;
			}else if(strcmp(ans,tmp)>0){
				strcpy(ans,tmp);
			}
		}
	}
	if(f==0)puts("UNRESTORABLE");
	else printf("%s\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",s,t);
  ^