#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1234567];
int pre[1234567];
int v[256]={0};
int l;
int main(){
    v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = 1;
    int t,T;
    int i,j,k;
    int len;
    long long int ans;
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%s %d",str,&l);
        len = strlen(str);
        ans = 0;
        memset(pre,0,sizeof(pre));
        pre[0] = !v[str[0]];
        for(i=1;i<len;++i){
            pre[i] = (v[str[i]])?0:pre[i-1]+1;
        }
      //  for(i=0;i<len;++i)printf("%d ",pre[i]);
       // puts("");
        for(i=j=ans=0;j<len;){
            if(pre[j]<l){
                ans += i;
                ++j;
            }else if(pre[j]>=l){
                i=j-l+2;
                ans += i;
                ++j;
            }
//            printf("%d ",i);
        }
        printf("Case #%d: %lld\n",t,ans);
    }
    return 0;
}
