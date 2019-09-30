#include<cstdio>
using namespace std;
int main(){
    int n,x;
    scanf("%d",&n);
    x=n*(n+1)/2;
    if(n%2==0){
        printf("%d\n",n*(n-2)/2);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i+j!=n+1){
                    printf("%d %d\n",i,j);
                }
            }
        }
    }
    else if(n==3){
        printf("2\n");
        printf("1 3\n");
        printf("2 3\n");
    }
    else if(n==5){
        printf("8\n");
        printf("1 5\n");
        printf("2 5\n");
        printf("3 5\n");
        printf("4 5\n");
        printf("1 2\n");
        printf("1 3\n");
        printf("4 3\n");
        printf("4 2\n");
    }
    else{
        printf("%d\n",(n-1+(n-1)*(n-2))/2);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i+j!=n){
                    printf("%d %d\n",i,j);
                }
            }
        }
    }
}