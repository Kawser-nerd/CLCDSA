#include<stdio.h>
long a[100000];

int main(int argc, char const *argv[]){
	long sum,bsum,ans=0,n,i,f=0,min=1;
	scanf("%ld",&n);
	scanf("%ld",&a[0]);
	if(a[0]==0){
		ans++;
		sum=1;
		f=1;
	}else sum=a[0];
	for(i=1;i<n;i++){
		scanf("%ld",&a[i]);
		bsum=sum;
		sum+=a[i];
		if(bsum>0){
			if(sum>=0){
				ans+=sum+1;
				sum=-1;
			}
		}else{
			if(sum<=0){
				ans+=1-sum;
				sum=1;
			}
		}
	}
		if(a[0]>=0){
			min=a[0]+1;
			sum=-1;
		}else{
			min=1-a[0];
			sum=1;
		}
		for(i=1;i<n;i++){
			bsum=sum;
			sum+=a[i];
			if(bsum>0){
				if(sum>=0){
					min+=sum+1;
					sum=-1;
				}
			}else{
				if(sum<=0){
					min+=1-sum;
					sum=1;
				}
			}
		}
		if(ans<min) printf("%ld\n",ans);
		else printf("%ld\n",min);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&a[0]);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&a[i]);
   ^