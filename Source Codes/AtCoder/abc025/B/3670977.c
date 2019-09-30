#include <stdio.h>
int D(a,b,d){
    if(d<a) return a;
    else if(b<d) return b;
    else return d;
}
int main(void){
    // Your code here!
    int n,a,b;
    scanf("%d %d %d\n",&n,&a,&b);
    
    int e=0,w=0,d;
    char s[5];
    for(int i=0;i<n;i++){
        scanf("%s %d\n",&s,&d);
        if(s[0]=='E'){
            e=e+D(a,b,d);
        }
        else{
            w=w+D(a,b,d);
        }
    }
    
    if(e>w) printf("East %d\n",e-w);
    else if(e<w) printf("West %d\n",w-e);
    else printf("0\n");
} ./Main.c: In function ‘D’:
./Main.c:2:5: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
 int D(a,b,d){
     ^
./Main.c:2:5: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:2:5: warning: type of ‘d’ defaults to ‘int’ [-Wimplicit-int]
./Main.c: In function ‘main’:
./Main.c:15:15: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[5]’ [-Wformat=]
         scanf("%s %d\n",&s,&d);
               ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d\n",&n,&a,&b);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s %d\n",&s,&d);
         ^