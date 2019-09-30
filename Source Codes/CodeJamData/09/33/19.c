#include<stdio.h>
#include<stdlib.h>
int p,q,*a1,*a2,val=0,fval,f=0,pos=0;
int list(int n) {
  int i,temp=0;
  for(i=n-1;i>=0;i--) if(a2[i]) break;
  if(i>=0) i=a1[i];
  else i=0;
  temp+=a1[n]-i-1;
  for(i=n+1;i<q;i++) if(a2[i]) break;
  if(i<q) i=a1[i];
  else i=p+1;
  temp+=i-a1[n]-1;
  printf("%d\n",temp);
  return temp;
}
void func() {
  int i,j;
  int temp;
  for(i=0;i<q;i++) printf("%d ",a2[i]);
  printf("\n");
  if(pos==q) {
    if(f) {
      if(fval>val) fval=val;
    }
    else {fval=val;f=1;}
    return;
  }
  for(i=0;i<q;i++) {
    if(a2[i]==0) {
      a2[i]=1;
      pos++;
      temp=list(i);
      val+=temp;
      func();
      val-=temp;
      pos--;
      a2[i]=0;
    }
  }
}
main() {
  FILE *fp,*op;
  int i,t,j;
  fp=fopen("C-small.in","r");
  op=fopen("C-small.out","w");
  fscanf(fp,"%d",&t);
  for(i=0;i<t;i++) {
    fscanf(fp,"%d %d",&p,&q);
    a1=(int*)malloc(q*sizeof(int));
    a2=(int*)malloc(q*sizeof(int));
    for(j=0;j<q;j++) {fscanf(fp,"%d",a1+j);a2[j]=0;}
    func();
    fprintf(op,"Case #%d: %d\n",i+1,fval);
    f=0;
    val=0;
    pos=0;
    free(a1);
    free(a2);
  }
  fclose(fp);
  fclose(op);
}
