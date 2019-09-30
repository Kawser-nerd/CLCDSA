#include<stdlib.h>
#include<stdio.h>
struct tmp{
int up;
int down;
int sign;//0:-,1:+
int di;
}a[100000],b[100000],c[100000];
int cmp1( const void * a , const void * b){
return ((struct tmp *)a)->up-((struct tmp *)b)->up;
}
int cmp2( const void * a , const void * b){
return ((struct tmp *)b)->down-((struct tmp *)a)->down;
}
int main(){
long t=0,max=0;
int n,i,q=0,w=0,e=0,d,dd;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d%d",&d,&dd);
if(d-dd<0){
a[q].up=d;
a[q++].down=dd;
}else if(d-dd==0){
b[w].up=d;
b[w++].down=dd;
}else{
c[e].up=d;
c[e++].down=dd;
}
}
qsort(a,q,sizeof(struct tmp),cmp1);
qsort(c,e,sizeof(struct tmp),cmp2);
for(i=0;i<q;i++){
 t+=a[i].up;
 if(max<t)max=t;
 t-=a[i].down;
}
for(i=0;i<w;i++){
 t+=b[i].up;
 if(max<t)max=t;
 t-=b[i].down;
}
for(i=0;i<e;i++){
 t+=c[i].up;
 if(max<t)max=t;
 t-=c[i].down;
}
printf("%ld\n",max);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&n);
 ^
./Main.c:20:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d%d",&d,&dd);
 ^