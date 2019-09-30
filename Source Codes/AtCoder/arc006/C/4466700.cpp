#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=100010;
int main(){
    int n;
    int b[maxn];
    memset(b,0,sizeof(b));
    scanf("%d",&n);
    int count=0,x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        for(int j=0;j<n;j++){
            if(x<=b[j]){
                b[j]=x;
                break;
            }
            if(b[j]==0){
                b[j]=x;
                count++;
                break;
            }
        }
    }printf("%d\n",count);
    return 0;
}