#include<stdio.h>
#include<string.h>

int main(){
	int n,i,j;
	char s[100][21]={0},scp[100][21]={0},l;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%s",s[i]);
	for(i=0;i<n;i++){
		for(j=20;j>=0;j--){
			if(s[i][j+1]==0&&s[i][j]!=0)l=j;
			if(s[i][j]!=0){
				scp[i][l-j]=s[i][j];
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(strcmp(&scp[i][0],&scp[j][0])<0){
				char tmp[21]={0},zero[21]={0};
				strcpy(tmp,scp[i]);
				for(int k=0;k<=20;k++)scp[i][k]=0;
				strcpy(scp[i],scp[j]);
				for(int k=0;k<=20;k++)scp[j][k]=0;
				strcpy(scp[j],tmp);
			}
		}
	}
//	for(i=0;i<n;i++)printf("%c\n",scp[i][0]);
	for(i=0;i<n;i++){
		for(j=20;j>=0;j--){
			if('a'<=scp[i][j]&&scp[i][j]<='z')printf("%c",scp[i][j]);
		}puts("");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:8:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%s",s[i]);
                  ^