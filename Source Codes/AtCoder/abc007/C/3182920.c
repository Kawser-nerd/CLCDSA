s,t,g,h;i,j;b,e;d;
char C[99][99];
Q[9999];
S(p,q){Q[e++]=d+1<<12|p<<6|q;}
main(){
scanf("%*d%*d%d%d%d%d",&s,&t,&g,&h);
for(;~scanf("%s",C[++i]+1););
S(s,t);
while(i-g|j-h){
d=Q[b]>>12;i=Q[b]>>6&63;j=Q[b++]&63;
if(C[i][j]==46)C[i][j]=0,S(i-1,j),S(i+1,j),S(i,j-1),S(i,j+1);
}
printf("%d\n",d-1);
} ./Main.c:1:1: warning: data definition has no type or storage class
 s,t,g,h;i,j;b,e;d;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
 s,t,g,h;i,j;b,e;d;
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘g’ [-Wimplicit-int]
 s,t,g,h;i,j;b,e;d;
     ^
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘h’ [-Wimplicit-int]
 s,t,g,h;i,j;b,e;d;
       ^
./Main.c:1:9: warning: data definition has no type or storage class
 s,t,g,h;i,j;b,e;d;
         ^
./Main.c:1:9: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:11: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 s,t,g,h;i,j;b,e;d;
           ^
./Main.c:1:13: warning: data definition has no type or storage class
 s,t,g,h;i,j;b,e;d;
             ^
./Main.c:1:13: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
./Main.c:1:15: warn...