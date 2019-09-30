x[111],y[111];a,b,c,d;i,t;s(a,b,c,d){return a*d-b*c>0;}f(e,f,g,h){return s(c-a,d-b,e-a,f-b)^s(c-a,d-b,g-a,h-b)&&s(g-e,h-f,a-e,b-f)^s(g-e,h-f,c-e,d-f);}main(n){for(scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);i<=n;i++)scanf("%d%d",x+i,y+i),t+=i&&f(x[i%n],y[i%n],x[i-1],y[i-1]);printf("%d\n",t/2+1);} ./Main.c:1:1: warning: data definition has no type or storage class
 x[111],y[111];a,b,c,d;i,t;s(a,b,c,d){return a*d-b*c>0;}f(e,f,g,h){return s(c-a,d-b,e-a,f-b)^s(c-a,d-b,g-a,h-b)&&s(g-e,h-f,a-e,b-f)^s(g-e,h-f,c-e,d-f);}main(n){for(scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);i<=n;i++)scanf("%d%d",x+i,y+i),t+=i&&f(x[i%n],y[i%n],x[i-1],y[i-1]);printf("%d\n",t/2+1);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
./Main.c:1:8: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
 x[111],y[111];a,b,c,d;i,t;s(a,b,c,d){return a*d-b*c>0;}f(e,f,g,h){return s(c-a,d-b,e-a,f-b)^s(c-a,d-b,g-a,h-b)&&s(g-e,h-f,a-e,b-f)^s(g-e,h-f,c-e,d-f);}main(n){for(scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);i<=n;i++)scanf("%d%d",x+i,y+i),t+=i&&f(x[i%n],y[i%n],x[i-1],y[i-1]);printf("%d\n",t/2+1);}
        ^
./Main.c:1:15: warning: data definition has no type or storage class
 x[111],y[111];a,b,c,d;i,t;s(a,b,c,d){return a*d-b*c>0;}f(e,f,g,h){return s(c-a,d-b,e-a,f-b)^s(c-a,d-b,g-a,h-b)&&s(g-e,h-f,a...