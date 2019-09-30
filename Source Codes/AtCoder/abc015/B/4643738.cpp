#include<cstdio>
using namespace std;
int main(){
    int n,a[100],cnt=0,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]){
            cnt++;
            sum+=a[i];
        }
    }
    if(sum%cnt){
        printf("%d\n",sum/cnt+1);
    }
    else{
        printf("%d\n",sum/cnt);
    }
}