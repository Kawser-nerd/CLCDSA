#include <stdio.h>
#include <stdlib.h>
int main(void){int a,b,ans;scanf("%d%d",&a,&b);if(abs(a-b)<5)ans=abs(a-b);else ans=10-abs(a-b);printf("%d\n",ans);return 0;} ./Main.c: In function ‘main’:
./Main.c:3:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int main(void){int a,b,ans;scanf("%d%d",&a,&b);if(abs(a-b)<5)ans=abs(a-b);else ans=10-abs(a-b);printf("%d\n",ans);return 0;}
                            ^