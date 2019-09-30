#include<stdio.h>

int main()
{
  int t,q=1,x,r,c,p;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d%d",&x,&r,&c);
    p=r*c;
    if(x>p)
      printf("Case #%d: RICHARD\n",q);
    else if(p%x!=0)
      printf("Case #%d: RICHARD\n",q);
    else if((r==x-1 || c==x-1) && p%x==0)
      printf("Case #%d: GABRIEL\n",q);
    else if(p%x==0 && r>=x-1 && c>=x-1)
      printf("Case #%d: GABRIEL\n",q);
    else
      printf("Case #%d: RICHARD\n",q);
    q++;
    }
    return 0;
}
