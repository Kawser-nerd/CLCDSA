s,t,g,h;i,j;b,e;d;
char C[99][99];
P[9999];Q[9999];R[9999];
S(p,q,r){P[e]=p;Q[e]=q;R[e]=r;e++;}
main(){
scanf("%*d%*d%d%d%d%d",&s,&t,&g,&h);
s--;t--;g--;h--;
for(;~scanf("%s",C[i++]););
S(s,t,0);
while(b<e){
i=P[b];j=Q[b];d=R[b];b++;
if(i==g&&j==h)break;
if(C[i][j]=='.'){
C[i][j]='#';
S(i-1,j,d+1);
S(i+1,j,d+1);
S(i,j-1,d+1);
S(i,j+1,d+1);
}
}
printf("%d\n",d);
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