#include <stdio.h>
#include <stdlib.h>

int saved[] = {1,5,27,143,751,935,607,903,991,335,47,943,471,55,447,463,991,95,607,263,151,855,527,743,351,135,407,903,791,135,647};

int main(){
  int nt,nt0, n;
  scanf(" %d", &nt0);
  
  for(nt=1 ; nt<=nt0 ; nt++){
    scanf(" %d", &n);
    printf("Case #%d: %03d\n", nt, saved[n]);
  }
  
  return 0;
}
