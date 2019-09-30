i,j,c,d;
char a[9],b[9],p[9],q[9];
main(){
  int n = atoi(gets(&n));
  while(j++<n){
    scanf("%s%s",a,b);
    for(d=0;d<1000;d++){
      for(c=0;c<1000;c++){
        sprintf(p,"%0*d",strlen(a),c);
        if(strlen(a)!=strlen(p))break;
        for(i=0;i<strlen(a);i++){
          if(a[i]!='?'&&a[i]!=p[i])goto out;
        }
        if(c-d<0)goto out2;
        sprintf(q,"%0*d",strlen(b),c-d);
        for(i=0;i<strlen(b);i++){
          if(b[i]!='?'&&b[i]!=q[i])goto out2;
        }
        goto ok;
out2:;
        if(c+d>=1000)goto out;
        sprintf(q,"%0*d",strlen(b),c+d);
        if(strlen(b)!=strlen(q))break;
        for(i=0;i<strlen(b);i++){
          if(b[i]!='?'&&b[i]!=q[i])goto out;
        }
        goto ok;
out:;
      }
    }
ok:
    printf("Case #%d: %s %s\n", j, p, q);
  }
  return 0;
}

