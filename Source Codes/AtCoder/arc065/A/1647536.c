#include<stdio.h>
int main(){
  char s[100010],ss[100020]={};
  char a[][10]={"eraser","erase","dreamer","dream"};
  char b[5][10]={};
  int i,j,k,l;
  scanf("%s",s);
  for(l=0;s[l];l++);
  for(i=0;i<l;i++)ss[i]=s[l-i-1];
  for(i=0;i<4;i++){
    for(l=0;a[i][l];l++);
    for(j=0;j<l;j++)b[i][j]=a[i][l-j-1];
  }
  //printf("%s\n",ss);
  //for(i=0;i<4;i++)printf("%s\n",b[i]);
  for(i=0;ss[i];i+=k){//printf("%d\n",i);return 0;
    for(j=0;j<4;j++){
      for(k=0;b[j][k];k++){
	if(ss[i+k]-b[j][k])break;
      }
      if(b[j][k]==0)break;
    }
    if(j==4){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^