#include<cstdio>
using namespace std;

int main(){
    int ans=0,s,e;
    for(int i=0;i<3;i++){
        scanf("%d %d",&s,&e);
        s/=10;
        ans+=s*e;
    }
    printf("%d\n",ans);
}