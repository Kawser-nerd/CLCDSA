#include<stdio.h>

int main(){
		int n,i,ans=1,f=0,c=0;
		long long a[100002],b[100000];
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%lld",&a[i]);
		b[0]=a[0];f++;
		for(i=1;i<n;i++){
					if(c==0){
							b[f++]=a[i];
							if(f>=2&&b[f-1]>b[f-2])c=1;
							if(f>=2&&b[f-1]<b[f-2])c=-1;
					}
					else if(c==1){
							if(b[f-1]<=a[i])b[f++]=a[i];
							else {
									ans++;
									b[0]=a[i];
									f=1;
									c=0;
						//			printf("%d\n",i);
							}
					}
					else if(c==-1){
							if(b[f-1]>=a[i])b[f++]=a[i];
							else {
									ans++;
									b[0]=a[i];
									f=1;
									c=0;
						//			printf("%d\n",i);
							}
					}
		}
		printf("%d\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%lld",&a[i]);
                   ^