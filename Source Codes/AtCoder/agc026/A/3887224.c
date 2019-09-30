#include<stdio.h>
#include<stdlib.h>

int main()
{
  int length=0;
  int* slime;
  char hoge;
  //????????
  scanf("%d",&length);
  slime = calloc(length,sizeof(int));
  for(int i=0;i<length;i++)
  {
  scanf("%d",&slime[i]);
    //printf("?G???%d",slime[i]);
  }
    int count=0;
  
  if(length == 2 && slime[0]==slime[1])
  {
    printf("1\n");
  }
  else
  {
  for(int i=1; i<length;i++)
  {
    //printf("?????G\n");
    //printf("%d????G?%d??G???…",slime[i-1],slime[i]);
    if(slime[i-1] == slime[i])
    {
      //printf("????G\n");
      slime[i]=slime[i-1]+slime[i+1];
      count++;
    }
  }
  
  printf("%d\n",count);
  }
  free(slime);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&length);
   ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&slime[i]);
   ^