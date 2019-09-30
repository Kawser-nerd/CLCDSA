#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n,m;
struct Obj{
    int type;
    long long int num;
}a[10000],b[10000];
long long int ans;

int main(){
    int Case = 0;
    int t;
    int i,j,k;
    long long int aNum,bNum,cut,sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;++i){
            scanf(" %lld %d",&a[i].num,&a[i].type);
        }
        for(i=0;i<m;++i){
            scanf(" %lld %d",&b[i].num,&b[i].type);
        }
        ans = 0;
        for(i=0;i<m;++i){
            for(j=i;j<m;++j){
                sum = 0;
                aNum = a[0].num;
                for(k=0;k<=i;++k){
                    bNum = b[k].num;
                    if(a[0].type == b[k].type){
                        if(aNum > bNum){
                            cut = bNum;
                        }else {
                            cut = aNum;
                        }
                        aNum-=cut;
                        bNum-=cut;
                        sum +=cut;
                    }
                }
                if(sum > ans)ans = sum;
                if(n ==1 ){
                    continue;
                }
                aNum = a[1].num;
                for(k=i;k<=j;++k){
                    if(k!=i)bNum = b[k].num;
                    if(a[1].type == b[k].type){
                        if(aNum > bNum){
                            cut = bNum;
                        }else {
                            cut = aNum;
                        }
                        aNum-=cut;
                        bNum-=cut;
                        sum +=cut;
                    }
                }
                if(sum > ans)ans = sum;
                if(n ==2 ){
                    continue;
                }
                aNum = a[2].num;
                for(k=j;k<m;++k){
                    if(k!=j)bNum = b[k].num;
                    if(a[2].type == b[k].type){
                        if(aNum > bNum){
                            cut = bNum;
                        }else {
                            cut = aNum;
                        }
                        aNum-=cut;
                        bNum-=cut;
                        sum +=cut;
                    }
                }
                if(sum > ans)ans = sum;
            }
        }
        printf("Case #%d: %lld\n",++Case,ans);
    }
    return 0;
}
