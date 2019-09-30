#include <stdio.h>
    #include<string.h>
    int main(void) {
      int A,a[1000000],i,j,sam,sam_i;
      char S[100][100];
    scanf("%d",&A);
    for(i=0;i<A;i++){
        scanf("%s",S[i]);
    }
    for(i=0;i<A;i++){
        for(j=i+1;j<A;j++){
            if(strcmp(&S[i],&S[j])==0){
                a[i]++;
            }
        }
    }
    sam=a[0];
    sam_i=0;
    for(i=1;i<A;i++){
        if(sam<a[i]){
            sam=a[i];
            sam_i=i;
        }
    }
    printf("%s\n",S[sam_i]);
      
      return 0;
    } In file included from /usr/include/string.h:635:0,
                 from ./Main.c:2:
./Main.c: In function ‘main’:
./Main.c:12:23: warning: passing argument 1 of ‘__builtin_strlen’ from incompatible pointer type [-Wincompatible-pointer-types]
             if(strcmp(&S[i],&S[j])==0){
                       ^
./Main.c:12:23: note: expected ‘const char *’ but argument is of type ‘char (*)[100]’
./Main.c:12:29: warning: passing argument 1 of ‘__builtin_strlen’ from incompatible pointer type [-Wincompatible-pointer-types]
             if(strcmp(&S[i],&S[j])==0){
                             ^
./Main.c:12:29: note: expected ‘const char *’ but argument is of type ‘char (*)[100]’
./Main.c:12:23: warning: passing argument 1 of ‘__builtin_strcmp’ from incompatible pointer type [-Wincompatible-pointer-types]
             if(strcmp(&S[i],&S[j])==0){
                       ^
./Main.c:12:23: note: expected ‘const char *’ but argument is of type ‘char (*)[100]’
./Main.c:12:29: warning: passing argument 2 of ‘__builtin_st...