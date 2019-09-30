#include<cstdio>
using namespace std;
int main(){
    int n,ng[3],f,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<3;i++){
        scanf("%d",&ng[i]);
        if(n==ng[i]){
            printf("NO\n");
            return 0;
        }
    }
    while(n>0){
        for(int i=3;i>0;i--){
            f=1;
            for(int j=0;j<3;j++){
                if(n-i<0||n-i==ng[j]){
                    f=0;
                }
            }
            if(f){
                n-=i;
                cnt++;
                break;
            }
        }
        if(!f){
            printf("NO\n");
            return 0;
        }
    }
    if(cnt>100){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
}