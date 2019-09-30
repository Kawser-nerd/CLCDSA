#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    char a[51],b[51];
    scanf("%s",a);
    scanf("%s",b);
    if(strlen(a)>strlen(b)){
        printf("%s\n",a);
    }
    else{
        printf("%s\n",b);
    }
}