#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;
bool pat[2000][2000];
int ans[2000];
int ine[2000];
bool flag[2000];
int main()
{
	FILE *fr=fopen("c-large.in","r");
	FILE *fw=fopen("out0.txt","w");
	int data;
	fscanf(fr,"%d",&data);
	for(int p=0;p<data;p++)
	{
		int num;
		fscanf(fr,"%d",&num);
		for(int i=0;i<2000;i++)
		{
			for(int j=0;j<2000;j++)
			{
				pat[i][j]=false;
			}
			ans[i]=-1;
			ine[i]=0;
			flag[i]=false;
		}
		vector<int>lis,lds;
		for(int i=0;i<num;i++)
		{
			int zan;
			fscanf(fr,"%d",&zan);
			lis.push_back(zan);
		}
		for(int i=0;i<num;i++)
		{
			int zan;
			fscanf(fr,"%d",&zan);
			lds.push_back(zan);
		}
		for(int i=0;i<num;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(lis[j]>=lis[i])
				{
					pat[i][j]=true;
				}
			}
			for(int j=i-1;j>=0;j--)
			{
				if(lis[j]+1==lis[i])
				{
					pat[j][i]=true;
					break;
				}
			}
		}
		for(int i=num-1;i>=0;i--)
		{
			for(int j=num-1;j>i;j--)
			{
				if(lds[j]>=lds[i])
				{
					pat[i][j]=true;
				}
			}
			for(int j=i+1;j<num;j++)
			{
				if(lds[j]+1==lds[i])
				{
					pat[j][i]=true;
					break;
				}
			}
		}
		for(int i=0;i<num;i++)
		{
			for(int j=0;j<num;j++)
			{
				if(pat[i][j])
				{
					ine[j]++;
				}
			}
		}
		int pt=1;
		for(int i=0;i<num;i++)
		{/*
			for(int j=0;j<num;j++)
			{
				printf("%d ",ine[j]);
			}
			printf("\n");*/
			for(int j=0;j<num;j++)
			{
				if(ine[j]==0&&(!flag[j]))
				{
					for(int k=0;k<num;k++)
					{
						if(pat[j][k])
						{
							ine[k]--;
						}
					}
					ans[j]=pt++;
					flag[j]=true;
					break;
				}
			}
		}
		fprintf(fw,"Case #%d: ",p+1);
		for(int i=0;i<num;i++)
		{
			if(i!=0)
			{
				fprintf(fw," ");
			}
			fprintf(fw,"%d",ans[i]);
		}
		fprintf(fw,"\n");
	}
}