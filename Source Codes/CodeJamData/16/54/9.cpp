#include<stdio.h>
#include<string.h>
int tcn,tc;
int n,m;
char s[110][55];
char b[55];
int main(){
	int i,j;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%s",&s[i]);
		}
		scanf("%s",b);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(s[i][j]!=b[j])break;
			}
			if(j==m){
				break;
			}
		}
		printf("Case #%d: ",tc);
		if(i==n){
			if(m==1){
				printf("%c? %c\n",'1'+'0'-b[0],'1'+'0'-b[0]);
			}
			else{
				for(i=0;i<m;i++){
					printf("%c?",'1'+'0'-b[i]);
				}
				printf(" ");
				for(i=0;i<m-1;i++){
					if(b[i]=='0'&&b[i+1]=='0')printf("0");
					if(b[i]=='1'&&b[i+1]=='1')printf("1");
					if(b[i]=='0'&&b[i+1]=='1')printf("10");
					if(b[i]=='1'&&b[i+1]=='0')printf("01");
				}
				printf("\n");
			}
		}
		else{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}