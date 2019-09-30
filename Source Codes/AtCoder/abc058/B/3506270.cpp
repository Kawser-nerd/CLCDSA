#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 int main (){
char a[50],b[50];
while(cin >> a >> b){
int la,lb,f;
la=strlen(a);
lb=strlen(b);
f=max(la,lb);
int i=0;
while(a[i]!='\0'&&b[i]!='\0'){
printf("%c%c",a[i],b[i]); i++; }
int j;
 for(j=i;j<f;j++){
if(la>lb)
printf("%c",a[j]);
else
printf("%c",b[j]);
}
}
 printf("\n");
return 0;
 }