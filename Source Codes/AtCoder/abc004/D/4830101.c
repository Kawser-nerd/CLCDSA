m=1e9;i=999;D;f(int C,int x){D=C+x;return x>0|D<1?~-C*C/2+(x>0?x:-~-D)*C:~-x*x/2+~-D*D/2;}main(R,G,B){for(scanf("%d%d%d",&R,&G,&B);i+999;)m=fmin(m,f(R,-fmin(i+99,~-R/2))+f(B,fmax(G+i-100,-~-B/2))+f(G,i--));printf("%d\n",m);} ./Main.c:1:1: warning: data definition has no type or storage class
 m=1e9;i=999;D;f(int C,int x){D=C+x;return x>0|D<1?~-C*C/2+(x>0?x:-~-D)*C:~-x*x/2+~-D*D/2;}main(R,G,B){for(scanf("%d%d%d",&R,&G,&B);i+999;)m=fmin(m,f(R,-fmin(i+99,~-R/2))+f(B,fmax(G+i-100,-~-B/2))+f(G,i--));printf("%d\n",m);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
./Main.c:1:7: warning: data definition has no type or storage class
 m=1e9;i=999;D;f(int C,int x){D=C+x;return x>0|D<1?~-C*C/2+(x>0?x:-~-D)*C:~-x*x/2+~-D*D/2;}main(R,G,B){for(scanf("%d%d%d",&R,&G,&B);i+999;)m=fmin(m,f(R,-fmin(i+99,~-R/2))+f(B,fmax(G+i-100,-~-B/2))+f(G,i--));printf("%d\n",m);}
       ^
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:13: warning: data definition has no type or storage class
 m=1e9;i=999;D;f(int C,int x){D=C+x;return x>0|D<1?~-C*C/2+(x>0?x:-~-D)*C:~-x*x/2+~-D*D/2;}main(R,G,B){for(scanf("%d%d%d",&R,&G,&B);i+999;)m=fmin(m,f(R,-fmin(i+99,~-R/2))+f(B,fmax(G+i-1...