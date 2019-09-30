#include<stdio.h>
int increment(int array[],int n)
{
  if(array[n] ==0){
    array[n]++;
    return n;
  }
  else if(array[n] == 1)
    {
      array[n] = 0;
      return increment(array,n+1);
    }
}

int main()
{
  int point=0,i,s[100],N,max=0,bool[100]={0};
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&s[i]);
    point = 0;
    for(i=0;i<N;i++)
      point += s[i];
    if(!(point % 10)){
      for(i=0;i<N;i++)
        if((point - s[i]) % 10)
          if(max < point - s[i])
            max = point - s[i];
    }else
      max = point;
  printf("%d\n",max);
  return 0;
  
} ./Main.c: In function ‘main’:
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&s[i]);
     ^