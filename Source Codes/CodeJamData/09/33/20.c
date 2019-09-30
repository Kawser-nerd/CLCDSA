#include<stdio.h>
#include<math.h>
#include<string.h>
//#include<conio.h>

FILE *fp,*fo;

int prison[100001];

int solve(int a, int b)
{
                         

int i;
int sum1,sum2,bribe,temp;

if(a>=b)return 0;
bribe=100000000;
int flag=0;


for(i=a;i<=b;i++)
{
	if(prison[i]==1)
	{
		flag=1;
		sum1=solve(a,i-1);
		sum2=solve(i+1,b);
		temp=sum1+sum2+b-a;
		if(temp<bribe)bribe=temp;
	}
}
if(flag==0)return 0;
return bribe;

}

int main()
{
	int i,T,j;
	int P,Q,temp1;

	int  ans;
//	char temp;
	

	fp=fopen("C-small-attempt0.in","r");
	fo=fopen("out.txt","w");	

	fscanf(fp,"%d",&T);
//	fscanf(fp,"%c",&temp);
	for(i=0;i<T;i++)
	{
		
		for(j=0;j<100001;j++)prison[j]=0;
		
		fscanf(fp,"%d",&P);	
		fscanf(fp,"%d",&Q);	
		//fscanf(fp,"%c",&temp);	
			//	printf("P=%d Q=%d ",P,Q);
			for(j=0;j<Q;j++)
			{
				fscanf(fp,"%d",&temp1);	
				prison[temp1-1]=1;
			//	printf("%d ",temp1);
			}
		ans=solve(0,P-1);	
		
		
		fprintf(fo,"Case #%d: %d\n",i+1,ans);
		printf("Case #%d: %d\n",i+1,ans);
		
	}
	
	fclose(fp);
	fclose(fo);
	printf("over");
	return 0;
}