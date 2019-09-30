#include <stdio.h>
#include <string.h>

int CHECK(char S[],int num);

int main(void){
   
   char S[20];
   
   scanf("%s",S);
   
   int moji = 0;
   while(1){
      if(S[moji] == '\0'){
         break;
      }
      moji++;
   }
   
   int i,j;
   char Temp[20];
   int temp = 0;
   int ans = 0;
   
   for(i = 0;i < moji;i++){
      for(j = 0;j < moji;j++){
         if(moji > i+j){
            strncpy(Temp,S+i,moji - i - j);
            Temp[moji - i - j] = '\0';
            //printf("%s\n",Temp);
            temp = CHECK(Temp,moji - i - j);
            if(temp > ans){
               ans = temp;
            }
         }
      }
   }
   
   printf("%d\n",ans);
   
   return 0;
}

int CHECK(char S[],int num){
   
   int i;
   int flag = 0;
   for(i = 0;i < num;i++){
      if(S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T'){
         flag = 0;
      }
      else {
         flag = 1;
         break;
      }
   }
   
   if(flag == 0){
      return num;
   }
   else {
      return 0;
   }
   
   
} ./Main.c: In function ‘main’:
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",S);
    ^