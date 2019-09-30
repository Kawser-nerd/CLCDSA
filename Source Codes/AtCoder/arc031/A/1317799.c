#include <stdio.h>
#include <string.h>


int main(void)
{
	int i,lon,count=0;
	char name[101];
	scanf("%s",name);
	
	lon=strlen(name);
	
	if(lon%2==0){
		for(i=0;i<lon/2;i++){
			if(name[i]!=name[lon-1-i]){
				count++;
			}
		}
	} else{
		for(i=0;i<lon/2;i++){
			if(name[i]!=name[lon-1-i]){
				count++;
			}
		}
	}
	
	if(count==0){
		printf("YES\n");
	} else{
		printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",name);
  ^