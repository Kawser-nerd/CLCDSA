#include <stdio.h>
#include <stdlib.h>

#define SET(a) a=1
#define CLEAR(a) a=0
#define MAX_LEN 10

int main()
{
  char ori_num[MAX_LEN],orp_num[MAX_LEN];
  char carry_flag;
  int case_num,catched_signal;
  int i,j;
  int original,ori_len,orp_len;
  scanf("%d",&case_num);
  for(i=0;i<case_num;i++){
    scanf("%d",&original);
    //initial work start
    for(j=0;j<MAX_LEN;j++){
      ori_num[j]=0;
      orp_num[j]=0;
    }
    catched_signal = 0x3FF;
    ori_len = 0;
    orp_len = 0;
    //where the n'th bit is 1 stand for the n is not catched
    //initial work end

    if(original == 0){
      printf("Case #%d: INSOMNIA\n",(i+1));
    }else{
      j = 0;
      while(original != 0){
        ori_num[j] = original % 10;
        original = original / 10;
        j++;
      }
      ori_len = j;
      orp_len = j;

      while(catched_signal){
        //high precision add
        CLEAR(carry_flag);
        for(j=0;j<orp_len;j++){
          orp_num[j] = orp_num[j] + ori_num[j] + carry_flag;
          if (orp_num[j] > 9){
            orp_num[j] -= 10;
            SET(carry_flag);
          }else{
            CLEAR(carry_flag);
          }
        }
        if(carry_flag){
          orp_num[j] = 1;
          orp_len++;
        }
        //high precision add

        //examine each bit
        for(j=0;j<orp_len;j++){
          catched_signal = (catched_signal & ~(0x1 << orp_num[j]));
        }
      }
      printf("Case #%d: ",(i+1));
      for(j=0;j<orp_len;j++){
        printf("%d",orp_num[orp_len-j-1]);
      }
      printf("\n");
    }
  }
  //printf("Hello world!\n");
  return 0;
}
