#include<stdio.h>
int main()
{
  char s[11];
  int t,i,k[11],v=0,tmp,j;
  k[0]=0;
  k[1]=0;
  k[2]=0;
  k[3]=0;
  k[4]=0;
  scanf("%s",s);
  for(i=0;s[i]!='\0';i++)
  {
    if(s[i]=='A'||s[i]=='T'||s[i]=='G'||s[i]=='C')
    {
      if(k[v]==0)
      {

        k[v]++;
        t=i;
      }
      else
      {
        if(t==i-k[v])
        {
          k[v]++;
        }
        else
        {
          v++;
          k[v]++;
          t=i;
        }
      }
          
    }
  }
  for(i=0;i<v+1;i++)
  {
    for(j=1;j<v+1;j++)
    {
      if(k[j-1]<k[j])
      {
        tmp=k[j-1];
        k[j-1]=k[j];
        k[j]=tmp;
      }
    }
  }
  printf("%d\n",k[0]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^