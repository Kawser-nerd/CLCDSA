r;p;M=1e9+7;a[1<<20];c[1<<20];u[4]={1,-1};f(v,w){int*z=c+v,x=v%w,y=v/w,s,t,d=4;if(*z<0)for(*z=1;d--;~s&~t&s-w&t-*a&&a[t*w+s+2]>a[v+2]?*z=(*z+f(t*w+s,w))%M:0)s=x+u[d],t=y+u[3-d];return*z;}main(){for(;~scanf("%d",a+p);)--c[p++];for(p-=2;p--;)r=(r+f(p,a[1]))%M;printf("%d",r);} ./Main.c:1:1: warning: data definition has no type or storage class
 r;p;M=1e9+7;a[1<<20];c[1<<20];u[4]={1,-1};f(v,w){int*z=c+v,x=v%w,y=v/w,s,t,d=4;if(*z<0)for(*z=1;d--;~s&~t&s-w&t-*a&&a[t*w+s+2]>a[v+2]?*z=(*z+f(t*w+s,w))%M:0)s=x+u[d],t=y+u[3-d];return*z;}main(){for(;~scanf("%d",a+p);)--c[p++];for(p-=2;p--;)r=(r+f(p,a[1]))%M;printf("%d",r);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘r’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 r;p;M=1e9+7;a[1<<20];c[1<<20];u[4]={1,-1};f(v,w){int*z=c+v,x=v%w,y=v/w,s,t,d=4;if(*z<0)for(*z=1;d--;~s&~t&s-w&t-*a&&a[t*w+s+2]>a[v+2]?*z=(*z+f(t*w+s,w))%M:0)s=x+u[d],t=y+u[3-d];return*z;}main(){for(;~scanf("%d",a+p);)--c[p++];for(p-=2;p--;)r=(r+f(p,a[1]))%M;printf("%d",r);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘p’ [-Wimplicit-int]
./Main.c:1:5: warning: data definition has no type or storage class
 r;p;M=1e9+7;a[1<<20];c[1<<20];u[4]={1,-1};f(v,w){int*z=c+v,x=v%w,y=v/w,s,t,d=4;if(*z<0)fo...