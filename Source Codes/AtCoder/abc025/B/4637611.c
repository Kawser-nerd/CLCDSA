a,b,x;main(d,s)char*s;{for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",s,&d);x+=*s<87?d:-d)d=a<d?d<b?d:b:a;printf(x?x>0?"East %d\n":"West %d\n":"%d\n",abs(x));} ./Main.c:1:1: warning: data definition has no type or storage class
 a,b,x;main(d,s)char*s;{for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",s,&d);x+=*s<87?d:-d)d=a<d?d<b?d:b:a;printf(x?x>0?"East %d\n":"West %d\n":"%d\n",abs(x));}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a,b,x;main(d,s)char*s;{for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",s,&d);x+=*s<87?d:-d)d=a<d?d<b?d:b:a;printf(x?x>0?"East %d\n":"West %d\n":"%d\n",abs(x));}
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
 a,b,x;main(d,s)char*s;{for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",s,&d);x+=*s<87?d:-d)d=a<d?d<b?d:b:a;printf(x?x>0?"East %d\n":"West %d\n":"%d\n",abs(x));}
     ^
./Main.c:1:7: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a,b,x;main(d,s)char*s;{for(scanf("%*d%d%d",&a,&b);~scanf("%s%d",s,&d);x+=*s<87?d:-d)d=a<d?d<b?d:b:a;printf(x?x>0?"East %d\n":"West %d\n":"%d\n",abs(x)...