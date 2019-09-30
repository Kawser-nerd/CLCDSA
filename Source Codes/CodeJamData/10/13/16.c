#include<stdio.h>
int Win(int A,int B)
{ if(A<B) return Win(B,A);
  if(A==0||B==0) return 0;
  if(A==B) return 0;
  if(A%B==0&&A>=2*B) return 1;
  if(A%B!=0&&A/B==1) return !Win(A%B,B);
  if(A%B!=0&&A/B>=2) return 1;

}


int main()
{
  int T;
  scanf("%d",&T);
  int A1,A2,B1,B2;
  int i=0;
  for(i=0;i<T;++i)
    {
      scanf("%d %d %d %d",&A1,&A2,&B1,&B2);
      int k=A1;
      int m=B1;
      int R=0;
      for(k=A1;k<=A2;++k)
	for(m=B1;m<=B2;++m)
	  { if(Win(k,m)) R++;}
      printf("Case #%d: %d\n",i+1,R);



    }













  return 0;


}
