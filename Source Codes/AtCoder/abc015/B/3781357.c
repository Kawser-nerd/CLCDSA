#include <stdio.h>
int main(void){int i,n,m=0,ans=0;scanf("%d",&n);int a[n];for(i=0;i<n;i++)scanf("%d",&a[i]);for(i=0;i<n;i++)if(a[i]>0){ans+=a[i];m++;}if(ans%m==0)printf("%d\n",ans/m);else printf("%d\n",ans/m+1);return 0;} ./Main.c: In function ‘main’:
./Main.c:2:34: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int main(void){int i,n,m=0,ans=0;scanf("%d",&n);int a[n];for(i=0;i<n;i++)scanf("%d",&a[i]);for(i=0;i<n;i++)if(a[i]>0){ans+=a[i];m++;}if(ans%m==0)printf("%d\n",ans/m);else printf("%d\n",ans/m+1);return 0;}
                                  ^
./Main.c:2:74: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int main(void){int i,n,m=0,ans=0;scanf("%d",&n);int a[n];for(i=0;i<n;i++)scanf("%d",&a[i]);for(i=0;i<n;i++)if(a[i]>0){ans+=a[i];m++;}if(ans%m==0)printf("%d\n",ans/m);else printf("%d\n",ans/m+1);return 0;}
                                                                          ^