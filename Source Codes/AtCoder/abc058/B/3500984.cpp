#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main (){
    char a[50],b[50];
    while(cin >> a >> b){
            int c,d,f;
            c=strlen(a);
            d=strlen(b);
            f=max(c,d);
            int i=0;
            while(a[i]!='\0'&&b[i]!='\0'){
                printf("%c%c",a[i],b[i]);
                i++;
            }
            int j;
            for(j=i;j<f;j++){
            if(c>d)
            printf("%c",a[j]);
            else
            printf("%c",b[j]);

            }

    }
    printf("\n");
return 0;
}