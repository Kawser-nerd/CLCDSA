#include<stdio.h>

int main(void){
  int num, i, count=0, count_M=0;
  char Word[11];
  scanf("%s", &Word);
  for(num=0; Word[num]!=NULL; num++) {
      if(Word[num] == 'A' ||Word[num] == 'C' || 
         Word[num] == 'G' ||Word[num] == 'T') count++;
      else {
        if(count_M < count) { 
	    	count_M = count;
        }        
      	count = 0;
      }
  }
  if(count_M < count){
    count_M = count;
  }
  printf("%d",count_M);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[11]’ [-Wformat=]
   scanf("%s", &Word);
         ^
./Main.c:7:23: warning: comparison between pointer and integer
   for(num=0; Word[num]!=NULL; num++) {
                       ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", &Word);
   ^