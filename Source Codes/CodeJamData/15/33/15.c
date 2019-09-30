#include<stdio.h>
#include<malloc.h>
int arr[30];
int length;
int sum;
int answer;
int c,d,v;
int flag;
int main()
{
	int cases;
	scanf("%d",&cases);
	int countcase=0;
	while(countcase<cases)
	{
		answer = 0;
		countcase++;
		printf("Case #%d: ",countcase);
		scanf("%d%d%d",&c,&d,&v);
		length = d;
		int i,j,k;
		for(i=0;i<d;i++)
			scanf("%d",&arr[i]);

A:		for(i=1;i<=v;i++)
		{
			sum = i;
			flag = 0;
			for(k=0;k<length;k++)
			{
				if(i==arr[k])
				{flag=1;break;}
			}
			if(flag)
			{flag = 0;continue;}
			for(j=0;j<length-1;j++)
			{
				for(k=j+1;k<length;k++)
				{
					if(find(arr[j],arr[k],k+1)==1)
					{
						flag=1;break;
					}
				}
				if(flag)
				{break;}
			}
			if(flag)
			{flag = 0;continue;}
			else
			{
			
				//printf("counldnt do it for %d\n",sum);
				answer++;arr[length]=sum;length++;
				int t,u,temp;
			    for (t = 0; t <length; ++t)
			    {
				for (u = t + 1; u < length; ++u)
				{
				    if (arr[t] > arr[u])
				    {
					temp =  arr[u];
					arr[u] = arr[t];
					arr[t] = temp;
				    }
				}
			    }
			    goto A;
			}
		}
		printf("%d\n",answer);

	}
}
int find(int x,int y,int index)
{
	if(x+y==sum)
	{
		return 1;
	}
	if(index>=length)
	{
		return -1;
	}
	int z=index;
	int flag=0;
	for(;z<length;z++)
	{
		if(find((x+y),arr[z],z+1)==1)
		{
			flag=1;break;
		}
	}
	if(flag)
		return 1;
		
	return -1;
}
