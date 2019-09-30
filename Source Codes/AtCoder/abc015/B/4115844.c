#include <stdio.h>
int main(void){int n,m=0,ans=0;scanf("%d",&n);int a[n];for(int i=0;i<n;i++){scanf("%d",&a[i]);ans+=a[i];if(a[i]!=0)m++;}if(ans%m==0)printf("%d\n",ans/m);else printf("%d\n",ans/m+1);return 0;} ./Main.c: In function ‘main’:
./Main.c:2:32: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int main(void){int n,m=0,ans=0;scanf("%d",&n);int a[n];for(int i=0;i<n;i++){scanf("%d",&a[i]);ans+=a[i];if(a[i]!=0)m++;}if(ans%m==0)printf("%d\n",ans/m);else printf("%d\n",ans/m+1);return 0;}
                                ^
./Main.c:2:77: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int main(void){int n,m=0,ans=0;scanf("%d",&n);int a[n];for(int i=0;i<n;i++){scanf("%d",&a[i]);ans+=a[i];if(a[i]!=0)m++;}if(ans%m==0)printf("%d\n",ans/m);else printf("%d\n",ans/m+1);return 0;}
                                                                             ^