#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void mergesort(long array[],int top,int end) //??????
{
  int mid;

  if(top >= end)
    {
      return;
    }

  mid = (end+top) / 2;

  mergesort(array,top,mid);

  mergesort(array,mid+1,end);

  long *left,*right,n1,n2,i,j,k;
  n1 = mid - top + 1;
  n2 = end - mid;
  left = (long *)malloc(sizeof(long)*(n1+1));
  right = (long *)malloc(sizeof(long)*(n2+1));
  
  j=0;
  for(i=top;i<=mid;i++)
    {
      left[j] = array[i];
      j++;
    }
  
  j=0;
  for(i=mid+1;i<=end;i++)
    {
      right[j] = array[i];
      j++;
    }
  
  left[n1] = LONG_MAX;
  right[n2] = LONG_MAX;
  
  i=0; j=0;
  for(k=top;k<=end;k++)
    {
      if(left[i] <= right[j])
	{
	  array[k] = left[i];
	  i++;
	}
      else
	{
	  array[k] = right[j];
	  j++;
	}
    }
  
  free(left);
  free(right);
}

int main(void)
{
  int n,m,i,j;
  scanf("%d %d",&n,&m);
  long x[n],y[n],z[n],sort[n];
  long max=0,temp1=0,tmpx,tmpy,tmpz;
  int bx[8]={1,1,1,1,-1,-1,-1,-1},by[8]={1,1,-1,-1,1,1,-1,-1},bz[8]={1,-1,1,-1,1,-1,1,-1};
  for(i=0;i<n;i++)
    {
      scanf("%ld %ld %ld",&x[i],&y[i],&z[i]);
    }
  for(i=0;i<8;i++)
    {
      for(j=0;j<n;j++)
	{
	  tmpx = bx[i]*x[j];
	  tmpy = by[i]*y[j];
	  tmpz = bz[i]*z[j];
	  sort[j] = tmpx+tmpy+tmpz;
	}
      mergesort(sort,0,n-1);

      /*for(j=0;j<n;j++)
	{
	  printf("%lld ",sort[j]);
	}
	printf("\n");*/
      temp1=0;
      for(j=0;j<m;j++)
	{
	  temp1 += sort[n-1-j];
	}
      //printf("%lld %lld\n\n",temp1,temp2);
      if(max < labs(temp1))
	{
	  max = labs(temp1);
	}
      //printf("max:%lld\n\n",max);
    }

  printf("%ld\n",max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:65:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:71:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%ld %ld %ld",&x[i],&y[i],&z[i]);
       ^