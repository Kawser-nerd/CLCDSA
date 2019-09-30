#include<stdio.h>

struct pair
{
	int key;
	int bi;
};

void quicksort(struct pair data[],int left,int right);

int main()
{
    int n,m,i,j,a,b,flag=0,ans=0;
	struct pair arr[100000];
	int kenarr[100000][2];
	//int ans=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&(arr[i].key),&(arr[i].bi));
	}
	quicksort(arr,0,m-1);
	

	for(i=0;i<m;i++)
	{
		if(ans==(n-2))break;
		a=arr[i].key;
		b=arr[i].bi;
		if(i==0)
		{
			kenarr[0][0]=a;
			kenarr[0][1]=b;
		}
		else
		{
			flag=0;
			for(j=0;j<=ans;j++)
			{
				if((kenarr[j][1]>a)&&(kenarr[j][0]<b))
				{
					flag=1;
					if(kenarr[j][0]<a)kenarr[j][0]=a;
					if(kenarr[j][1]>b)kenarr[j][1]=b;
				}
				if(flag)break;
			}
			if(!flag)
			{
				ans++;
				kenarr[ans][0]=a;
				kenarr[ans][1]=b;
			}
		}
	}
	
	//for(i=0;i<ans+1;i++)printf("%d,%d\n",kenarr[i][0],kenarr[i][1]);
	printf("%d",ans+1);
}


void quicksort(struct pair data[],int left,int right)
{
	int i,j;
	struct pair std,work;
	if(left<right)
	{
		i=left,j=right;
		std=data[(i+j)/2];//??
		do
		{
			while(data[i].key < std.key)i++;
			while(data[j].key > std.key)j--;
			if(i<=j)
			{
				if(i<j)
				{
					work=data[i];
					data[i]=data[j];
					data[j]=work;
				}
				i++; j--;
			}
		}while(i<=j);
		if(left<j)quicksort(data,left,j);
		if(i<right)quicksort(data,i,right);
	}
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&(arr[i].key),&(arr[i].bi));
   ^