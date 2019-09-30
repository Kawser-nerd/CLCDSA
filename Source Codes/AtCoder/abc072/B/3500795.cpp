#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    char a[100000];
    int c;
    while(cin >> a ){
    for(int i=0;i<strlen(a);i+=2){
        printf("%c",a[i]);

    }
    printf("\n");
    }
    return 0;
}