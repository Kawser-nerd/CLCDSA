i,n;char a[100002]="SS",s[999999];f(){for(i=0;++i<=n;)a[i+1]=a[i]==87^a[i-1]==87^s[i]=='o'?83:87;if(!strncmp(a,a+n,2))a[n]=0,puts(a),exit(0);}main(){scanf("%d%s",&n,&s);strncat(s,s,n);f();*a=87;f();a[1]=87;f();*a=83;f();puts("-1");} ./Main.c:1:1: warning: data definition has no type or storage class
 i,n;char a[100002]="SS",s[999999];f(){for(i=0;++i<=n;)a[i+1]=a[i]==87^a[i-1]==87^s[i]=='o'?83:87;if(!strncmp(a,a+n,2))a[n]=0,puts(a),exit(0);}main(){scanf("%d%s",&n,&s);strncat(s,s,n);f();*a=87;f();a[1]=87;f();*a=83;f();puts("-1");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
 i,n;char a[100002]="SS",s[999999];f(){for(i=0;++i<=n;)a[i+1]=a[i]==87^a[i-1]==87^s[i]=='o'?83:87;if(!strncmp(a,a+n,2))a[n]=0,puts(a),exit(0);}main(){scanf("%d%s",&n,&s);strncat(s,s,n);f();*a=87;f();a[1]=87;f();*a=83;f();puts("-1");}
   ^
./Main.c:1:35: warning: return type defaults to ‘int’ [-Wimplicit-int]
 i,n;char a[100002]="SS",s[999999];f(){for(i=0;++i<=n;)a[i+1]=a[i]==87^a[i-1]==87^s[i]=='o'?83:87;if(!strncmp(a,a+n,2))a[n]=0,puts(a),exit(0);}main(){scanf("%d%s",&n,&s);strncat(s,s,n);f();*a=87;f();a[1]=87;f();*a=83;f();puts("-1");}
     ...