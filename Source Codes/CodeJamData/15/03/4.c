#include<stdio.h>
int t,T;
int L,X,l,x;
char foo[10000+1];
int c;
int sgn;
char cur;
int level;
int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&L);
scanf("%d",&X);
scanf("%s",foo);
/*if (L*X<3) {printf("Case #%d: NO\n",t); continue;}*/
if (X>8) {X=X%4+8;}

cur='1';
sgn=1;
level=0;
for(x=0;x<X;x++)
for(l=0;l<L;l++){
if (foo[l]=='i')
 {
 switch(cur){
 case '1':
  cur='i';
  break;
 case 'i':
  cur='1';
  sgn=-sgn;
  break;
 case 'j':
  cur='k';
  sgn=-sgn;
  break;
 case 'k':
  cur='j';
  }
 }

if (foo[l]=='j')
 {
 switch(cur){
 case '1':
  cur='j';
  break;
 case 'i':
  cur='k';
  break;
 case 'j':
  cur='1';
  sgn=-sgn;
  break;
 case 'k':
  cur='i';
  sgn=-sgn;
  }
 }

if (foo[l]=='k')
 {
 switch(cur){
 case '1':
  cur='k';
  break;
 case 'i':
  cur='j';
  sgn=-sgn;
  break;
 case 'j':
  cur='i';
  break;
 case 'k':
  cur='1';
  sgn=-sgn;
  }
 }

if ((level==1)&&(sgn==1)&&(cur=='j')) {level++; cur='1';}
if ((level==0)&&(sgn==1)&&(cur=='i')) {level++; cur='1';}
}
if ((level==2)&&(sgn==1)&&(cur=='k')) {printf("Case #%d: YES\n",t);}
else {printf("Case #%d: NO\n",t);}
}
return 0;
}
