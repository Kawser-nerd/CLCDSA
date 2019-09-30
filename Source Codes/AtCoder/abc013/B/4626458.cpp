#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a<b){
        a^=b;
        b^=a;
        a^=b;
    }
    printf("%d\n",min(a-b,10+b-a));
}