#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char init[155][45],flip[45],flipped[45];
int compare(const void *a,const void *b)
{
  char **x=(char**)a;
  char **y=(char**)b;
  if(strcmp(*x,*y)<0)return -1;
  return 1;
}
void xor(char start[],char end[],char flip[],int L)
{
  int i;
  for(i=0;i<L;i++)
    if(start[i]==end[i])
      flip[i]='0';
    else
      flip[i]='1';
  flip[L]='\0';
}
int bSearch(char **arr,char *key,int lo,int hi)
{
  int mid;
  while(lo<=hi)
    {
      mid=(lo+hi)>>1;
      if(strcmp(arr[mid],key)==0)return mid;
      else if(strcmp(arr[mid],key)<0)lo=mid+1;
      else hi=mid-1;
    }
  return -1;
}
int min(int a,int b)
{
  if(a<b)return a;
  return b;
}
int main()
{
  int T,t,N,L,i,answer,j,k,l,x,count;
  char **final;
  scanf("%d",&T);
  final=(char**)malloc(sizeof(char*)*155);
  for(i=0;i<155;i++)
    final[i]=(char*)malloc(sizeof(char)*45);
  for(t=1;t<=T;t++)
    {
      scanf("%d %d",&N,&L);
      for(i=0;i<N;i++)
	scanf("%s",init[i]);
      for(i=0;i<N;i++)
	scanf("%s",final[i]);
      qsort(final,N,sizeof(char*),&compare);
      answer=1e9;
      for(i=0;i<N;i++)
	{
	  for(j=0;j<N;j++)
	    {
	      xor(init[i],final[j],flip,L);
	      for(l=0;l<N;l++)
		{
		  for(k=0;k<L;k++)
		    {
		      if(flip[k]=='1')
			flipped[k]=(init[l][k]=='0')?'1':'0';
		      else
			flipped[k]=init[l][k];
		    }
		  flipped[L]='\0';
		  x=bSearch(final,flipped,0,N-1);
		  if(x==-1)
		    break;
		}
	      if(l>=N)
		{
		  count=0;
		  for(k=0;k<L;k++)
		    if(flip[k]=='1')
		      count++;
		  answer=min(answer,count);
		}
	    }
	}
      printf("Case #%d: ",t);
      if(answer!=1e9)
	printf("%d\n",answer);
      else
	printf("NOT POSSIBLE\n");
    }
}
