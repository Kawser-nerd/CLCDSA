#include<stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
int main(int argc, char const *argv[]){
	long i,n,a,num[2][2],s=0,p;
	scanf("%ld",&n);
	for(i=0;i<n;i++){
		scanf("%ld",&a);
		if(s==0){
			num[0][0]=a;
			num[0][1]=1;
			s=1;
		}else if(s==1){
			if(a==num[0][0]) num[0][1]++;
			else{
				num[1][0]=a;
				num[1][1]=1;
				s=2;
				if((num[0][0]-num[1][0])!=1 && (num[1][0]-num[0][0])!=1){
					printf("No\n");
					return 0;
				}
			}
		}else{
			if(a==num[0][0]) num[0][1]++;
			else if(a==num[1][0]) num[1][1]++;
			else{
				printf("No\n");
				return 0;
			}
		}
	}
	if(s==1){
		if(n/2<num[0][0] && num[0][0]!=(n-1)){
			printf("No\n");
			return 0;
		}
	}else{
		if(num[0][0]>num[1][0]) p=0;
		else p=1;
		if(!((num[1-p][1]+1)<=num[p][0] && num[p][0]<=(num[1-p][1]+num[p][1]/2))){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&a);
   ^