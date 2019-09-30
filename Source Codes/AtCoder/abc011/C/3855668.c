#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{	
	int num,ng1,ng2,ng3,flag;
	int count=0;
	scanf("%d",&num);
	scanf("%d",&ng1);
	scanf("%d",&ng2);	
	scanf("%d",&ng3);

	if(num==ng1||num==ng2||num==ng3){
		flag=0;
	}
	else{
		while(num>0&&count<100){
			if(num-3!=ng1 && num-3!=ng2 && num-3!=ng3 && num-3>=0){
				num=num-3;
				count++;
			}
			else if(num-2!=ng1 && num-2!=ng2 && num-2!=ng3 && num-2>=0){
				num=num-2;
				count++;
			}
			else if(num-1!=ng1 && num-1!=ng2 && num-1!=ng3 && num-1>=0){
				num=num-1;
				count++;
			}
			else{
				break;
			}
		}
	}
	
	if(num==0){
		flag=1;
	}
	else{
		flag=0;
	}

	if(flag==0){
		printf("NO\n");
	}
	if(flag==1){
		printf("YES\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&num);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&ng1);
  ^
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&ng2); 
  ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&ng3);
  ^