#include<cstdio>
using namespace std;
int main(){
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cnt+=i*j;
        }
    }
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(cnt==n+i*j){
                printf("%d x %d\n",i,j);
            }
        }
    }
}