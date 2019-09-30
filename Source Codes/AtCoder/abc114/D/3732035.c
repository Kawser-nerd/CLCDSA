#include<stdio.h>
int main(){
    int collect[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int nums[15]={0};
    int n;
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	int temp=i;
	for(int j=0;j<15;j++){
	    if(collect[j]>temp)
		break;
	    while(temp%collect[j]==0){
		temp/=collect[j];
		nums[j]++;
	    }
	}
    }
    int a=0,b=0,c=0,d=0,e=0;
    for(int i=0;i<15;i++){
	if(nums[i]>=4){
	    a++;
	}
	if(nums[i]>=2)
	    b++;
	if(nums[i]>=14)
	    c++;
	if(nums[i]>=24)
	    d++;
	if(nums[i]>=74)
	    e++;
    }
    if(a<2||b<3)
	printf("0\n");
    else
	printf("%d\n",a*(a-1)/2*(b-2)+c*(a-1)+d*(b-1)+e);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^