#include <stdio.h>
int main(){
	int T,i,ii,i1,i2,i3,i4,n,R,N,M,K;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		
		scanf("%d %d %d %d",&R,&N,&M,&K);
		n=0;
		int k[K];
		for(ii=0;ii<R;ii++){
			
			for(i1=0;i1<K;i1++){
				scanf("%d",&k[i1]);
				
			}
			n=1;
			for(i1=2;i1<=5;i1++)
            if(n)
			for(i2=2;i2<=5;i2++)
			if(n)
			for(i3=2;i3<=5;i3++){
				n=0;
			int nums[125]={0};
				nums[1]=1;
				nums[i1]=1;
				nums[i2]=1;
				nums[i3]=1;
				nums[i1*i2]=1;
				nums[i2*i3]=1;
				nums[i1*i3]=1;
				nums[i1*i2*i3]=1;
				for(i4=0;i4<K;i4++){
					if(nums[k[i4]]==0){
						n=1;
						break;
					}
					
				}
				if(n==0){
					printf("%d%d%d\n",i1,i2,i3);
					break;
				}
			}
		}
		
	}
	return 0;
}
