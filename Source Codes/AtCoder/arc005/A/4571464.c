#include <stdio.h>
#include <string.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	char a[100][100];
	
	for(int i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	
	int count=0;
	
	char b[6][14]={"TAKAHASHIKUN","Takahashikun","takahashikun","TAKAHASHIKUN.","Takahashikun.","takahashikun."};
	
	for(int i=0;i<n;i++){
		for(int j=0;j<6;j++){
			if(strcmp(a[i],b[j])==0){
				count++;
			}
		}
	}
	
	printf("%d\n",count);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",a[i]);
   ^