#include<stdio.h>
int main()
{
	int test,t=0,num,low,high,i,j;
	long long int ans=0;
	scanf("%d",&test);
	while(test--)	
	{	
		int a[1000]={0};
		ans=0;
		scanf("%d%d%d",&num,&low,&high);
		for(i=0;i<num;i++)
			scanf("%d",&a[i]);
		for(j=low;j<=high;j++)
		{
			int flag=0;	
			for(i=0;i<num;i++)
			{
				if(a[i]%j==0 || j%a[i]==0)
				{}
				else{
					flag=1;
					break;
				}
			}
			if(flag==0){
				ans=j;
				break;
			}
		}
		printf("Case #%d: ",++t);
		if(ans!=0)
			printf("%lld\n",ans);
		else
			printf("NO\n");
	}
	return 0;
}
