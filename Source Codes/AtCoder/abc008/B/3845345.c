#include<stdio.h>
#include <string.h>
int main()
{
	int num=0;
	int i,j;
	int k=0;
	int max=0;
	char str[51][51];
	char count[51]={};

	//printf("Please enter the number of people to vote for.\n");
	scanf("%d",&num);

	for(i=0;i<num;i++){
		//printf("Please enter the name of the person who wants to be a leader.\n");
		scanf("%s",&str[i]);
		}

	for(i=0;i<num-1;i++){
    	for(j=i+1;j<num;j++){
    		if(strcmp(str[i],str[j])==0){
   				 count[i]++;
    		}
    	}
    }

	for(i=0;i<num;i++){
		if(k<count[i]){
			k=count[i];
   			max=i;
		}
	}

	printf("%s\n",str[max]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[51]’ [-Wformat=]
   scanf("%s",&str[i]);
         ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&num);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&str[i]);
   ^