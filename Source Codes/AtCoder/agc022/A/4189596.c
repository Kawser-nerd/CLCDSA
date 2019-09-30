#include<stdio.h>

int main(){
		char s[28];
		int a[27]={0},i,j;
		scanf("%s",s);
		for(i=0;s[i]!=0;i++){
				a[s[i]-'a']=1;
		}
		//printf("%d\n",i);
		if(i<26){
				printf("%s",s);
				for(i=0;i<26;i++){
						if(a[i]==0){
								putchar('a'+i);
								break;
						}
				}
				puts("");
				return 0;
		}
		int tmp=-1;
		for(i=25;i>=0;i--){
				for(j=s[i]-'a';j<26;j++){
						if(a[j]==2){
								tmp=i;
								break;
						}
				}
				a[s[i]-'a']++;
				if(tmp==i)break;
				
		}
		//printf("%d\n",i);
		if(i==-1){
				puts("-1");
				return 0;
		}
		for(i=0;i<tmp;i++)putchar(s[i]);
		putchar('a'+j);
		puts("");
		//printf("%d\n",j);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^