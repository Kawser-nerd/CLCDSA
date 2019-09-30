#include<cstdio>

int main(){
    int N,Sum=0;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int x;
        scanf("%d",&x);
        Sum+=x%2;
    }
    if(Sum%2) puts("NO");
    else puts("YES");
}