#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int case_num;
  int i,j;
  int p_head,p_tail;
  int times;
  char s[200];
  scanf("%d",&case_num);
  for(i=0;i<case_num;i++){
    scanf("%s",s);
    p_head = 0;
    p_tail = strlen(s) - 1;
    times = 0;
    if (p_head == p_tail){
      if (s[p_head] == '+'){
        times = 0;
      }else{
        times = 1;
      }
    }
    while(p_head < p_tail){
      while((s[p_tail] == '+') && (p_head < p_tail))
        p_tail--;
      if(s[p_tail] == '-'){
        if(s[p_head] == '+'){
          times++;
          while((s[p_head] == '+'))
            p_head++;
        }
        times++;
      }
      if (!(p_head < p_tail))
        break;
      while((s[p_head] == '-') && (p_head < p_tail))
        p_head++;
      if(s[p_head] == '+'){
        if(s[p_tail] == '-'){
          times++;
          while((s[p_tail] == '-'))
            p_tail--;
        }
        times++;
      }
      if (!(p_head < p_tail))
        break;
    }
    printf("Case #%d: %d\n",(i+1),times);
  }
  return 0;
}
