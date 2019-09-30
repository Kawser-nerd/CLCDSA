#include <stdio.h>
#include <memory.h>
int NumS[500][500];
char ans[]="welcome to code jam";
int lena;
char str[501];
int n;
int len;

int Num(m,q)
{
	int i;
	int sum;
	if (NumS[m][q]!=-1) return NumS[m][q];
	else
	{
		if (str[m]==ans[lena-q])
		{
			if (q==1) return (NumS[m][q]=1);
			else
			{
				sum=0;
				for (i=m+1;i<=len-q+1;i++)
				{
					sum+=Num(i,q-1);
					sum%=10000;
				}
				return (NumS[m][q]=sum);
			}
		}
		else
		{
			return (NumS[m][q]=0);
		}
	}
}


void main()
{
	int i,j,k;
	int sum;

    freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);

	scanf("%d",&n);gets(str);
	lena=strlen(ans);
	for (i=1;i<=n;i++)
	{
		gets(str);
		len=strlen(str);
		for (j=0;j<500;j++)
			for (k=0;k<500;k++)
				NumS[j][k]=-1;
		sum=0;
		for (j=0;j<len;j++)
		{
			sum+=Num(j,lena);
			sum%=10000;
		}
		printf("Case #%d: %04d\n",i,sum);
	}
	
}