M=1e9+7,w,a[1<<20],c[1<<20],r=0,p=0;f(int v){int u[4]={1,-1},s,t,d=0,*z=c+v,x=v%w,y=v/w;if(*z<0){*z=1;for(;d<4;){s=x+u[d];t=y+u[4-++d];~s&~t&s-w&t-*a&&a[t*w+s+2]>a[v+2]?*z=(*z+f(t*w+s))%M:0;}}return*z;}main(){for(;~scanf("%d",a+p);)c[p++]=-1;w=a[1];for(p-=2;p;)r=(r+f(--p))%M;printf("%d",r);} ./Main.c:1:1: warning: data definition has no type or storage class
 M=1e9+7,w,a[1<<20],c[1<<20],r=0,p=0;f(int v){int u[4]={1,-1},s,t,d=0,*z=c+v,x=v%w,y=v/w;if(*z<0){*z=1;for(;d<4;){s=x+u[d];t=y+u[4-++d];~s&~t&s-w&t-*a&&a[t*w+s+2]>a[v+2]?*z=(*z+f(t*w+s))%M:0;}}return*z;}main(){for(;~scanf("%d",a+p);)c[p++]=-1;w=a[1];for(p-=2;p;)r=(r+f(--p))%M;printf("%d",r);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
./Main.c:1:9: warning: type defaults to ‘int’ in declaration of ‘w’ [-Wimplicit-int]
 M=1e9+7,w,a[1<<20],c[1<<20],r=0,p=0;f(int v){int u[4]={1,-1},s,t,d=0,*z=c+v,x=v%w,y=v/w;if(*z<0){*z=1;for(;d<4;){s=x+u[d];t=y+u[4-++d];~s&~t&s-w&t-*a&&a[t*w+s+2]>a[v+2]?*z=(*z+f(t*w+s))%M:0;}}return*z;}main(){for(;~scanf("%d",a+p);)c[p++]=-1;w=a[1];for(p-=2;p;)r=(r+f(--p))%M;printf("%d",r);}
         ^
./Main.c:1:11: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 M=1e9+7,w,a[1<<20],c[1<<20],r=0,p=0;f(int v){int u[4]={1,-1},s,t,d=0,*z=c+v,x=v%w,y=v/w;if(*z<0){...