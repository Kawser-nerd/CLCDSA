#include <stdio.h>
char Res[5000];
char temp[5000];
char Move[3]={'P','R','S'};
int n,Total;
int Num[3];
int Judge(int k)
{
	if(temp[k]==temp[k+1])
		return -1;
	if((temp[k]=='R' && temp[k+1]=='S') || (temp[k]=='S' && temp[k+1]=='P') || (temp[k]=='P' && temp[k+1]=='R'))
		return k;
	else return k+1;
}
int DFS(int step)
{
	int flag;
	int i,j;
	int k;
	int result;
	if(step==Total)
	{
		flag=1;
		for(i=0;i<Total;i++)
			temp[i]=Res[i];
		k=1;
		for(i=0;i<n;i++)
			k*=2;
		for(i=0;i<n;i++)
		{
			for(j=0;j<k;j+=2)
			{
				result=Judge(j);
				if(result==-1)
				{
					flag=0;
					break;
				}
				else temp[j/2]=temp[result];
			}
			if(!flag)
				break;
			k/=2;
		}
		return flag;
	}
	else {
		for(i=0;i<3;i++)
		{
			if(Num[i]==0)
				continue;
			Num[i]--;
			Res[step]=Move[i];
			flag=DFS(step+1);
			Num[i]++;
			if(flag)
				break;
		}
	}
	return flag;
}
int main()
{
	int T;
	int R,P,S;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	int i,j;
	int flag;
	for(i=0;i<T;i++)
	{
		scanf("%d%d%d%d",&n,&Num[1],&Num[0],&Num[2]);
		Total=1;
		for(j=0;j<n;j++)
			Total*=2;
		flag=DFS(0);
		if(!flag)
			printf("Case #%d: IMPOSSIBLE\n",i+1);
		else{
			printf("Case #%d: ",i+1);
			for(j=0;j<Total;j++)
				printf("%c",Res[j]);
			printf("\n");
		}
	}
	return 0;
}
