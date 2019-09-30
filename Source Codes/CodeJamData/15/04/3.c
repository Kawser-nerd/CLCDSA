#include<stdio.h>
int t,T,X,R,C;
int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&X);
scanf("%d",&R);
scanf("%d",&C);

if (((R*C)%X)!=0) {printf("Case #%d: RICHARD\n",t); continue;}

if (X==1) {printf("Case #%d: GABRIEL\n",t); continue;}
if (X==2) {printf("Case #%d: GABRIEL\n",t); continue;}

if ((R<3)&&(C<3)) {printf("Case #%d: RICHARD\n",t); continue;}
if ((R==1)||(C==1)) {printf("Case #%d: RICHARD\n",t); continue;}
if (X==3) {printf("Case #%d: GABRIEL\n",t); continue;}


if ((R<4)&&(C<4)) {printf("Case #%d: RICHARD\n",t); continue;}
if ((R==2)||(C==2)) {printf("Case #%d: RICHARD\n",t); continue;}
if (X==4) {printf("Case #%d: GABRIEL\n",t); continue;}

if ((R<5)&&(C<5)) {printf("Case #%d: RICHARD\n",t); continue;}
if ((X==5)&&(R==3)&&(C<10)) {printf("Case #%d: RICHARD\n",t); continue;}
if ((X==5)&&(C==3)&&(R<10)) {printf("Case #%d: RICHARD\n",t); continue;}
if (X==5) {printf("Case #%d: GABRIEL\n",t); continue;}

if ((R<6)&&(C<6)) {printf("Case #%d: RICHARD\n",t); continue;}
if ((R==3)||(C==3)) {printf("Case #%d: RICHARD\n",t); continue;}
if (X==6) {printf("Case #%d: GABRIEL\n",t); continue;}

if (X>=7) {printf("Case #%d: RICHARD\n",t); continue;}
}



return 0;
}
