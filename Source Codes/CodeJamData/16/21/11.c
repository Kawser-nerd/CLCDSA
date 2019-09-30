#include<stdio.h>
#include<string.h>

void solve(char *input);

int main(void){
  int cases,T;
  char str[2001];
  scanf("%d%*c",&T);
  for(cases=1;cases<=T;cases++){
    scanf("%s%*c",str);
    printf("Case #%d: ",cases);
    solve(str);
  }
  return 0;
}

void solve(char *input){
  int nums[10]={0};
  int alpha[26]={0};
  int i,j,k,l;
  
  l=strlen(input);
  
  for(i=0;i<l;i++) alpha[input[i]-'A']++;

  nums[0]=alpha[25];
  nums[2]=alpha[22];
  nums[4]=alpha[20];
  nums[6]=alpha[23];
  nums[8]=alpha[6];
  
  alpha[4]-=nums[0]+nums[8];
  alpha[17]-=nums[0]+nums[4];
  alpha[14]-=nums[0]+nums[2]+nums[4];
  alpha[19]-=nums[2]+nums[8];
  alpha[5]-=nums[4];
  alpha[18]-=nums[6];
  alpha[8]-=nums[6]+nums[8];
  alpha[7]-=nums[8];

  nums[1]=alpha[14];
  nums[3]=alpha[19];
  nums[5]=alpha[5];
  nums[7]=alpha[18];
  nums[9]=alpha[8]-nums[5];

  for(i=0;i<10;i++) for(j=0;j<nums[i];j++) putchar(i+'0');
  putchar('\n');
}
