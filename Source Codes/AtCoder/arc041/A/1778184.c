int x,y,k;int main(){scanf("%d%d%d",&x,&y,&k);printf("%d",(k>y?x+y*2-k:x+k));puts("");return 0;} ./Main.c: In function ‘main’:
./Main.c:1:22: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 int x,y,k;int main(){scanf("%d%d%d",&x,&y,&k);printf("%d",(k>y?x+y*2-k:x+k));puts("");return 0;}
                      ^
./Main.c:1:22: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:22: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:47: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 int x,y,k;int main(){scanf("%d%d%d",&x,&y,&k);printf("%d",(k>y?x+y*2-k:x+k));puts("");return 0;}
                                               ^
./Main.c:1:47: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:47: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:1:78: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 int x,y,k;int main(){scanf("%d%d%d",&x,&y,&k);printf("%d",(k>y?x+y*2-k:x+k));puts("");return 0;}
...