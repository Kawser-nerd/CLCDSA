#include <cstdio>
using namespace std;



int main(){
    int x,a,b;
    scanf("%d",&x);
    scanf("%d",&a);
    scanf("%d",&b);
    x-=a;
    printf("%d\n",x%b);
    
}