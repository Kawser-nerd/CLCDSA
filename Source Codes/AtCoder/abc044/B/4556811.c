#include <stdio.h>
int main(void){
  int count;
  char sa[120];
  int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0,n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0,x=0,y=0,z=0;
  scanf("%s",&sa);
for(count=0;sa[count]!='\0';count++){
  if(sa[count]=='a'){a++;}
    if(sa[count]=='b'){b++;}
    if(sa[count]=='c'){c++;}
    if(sa[count]=='d'){d++;}
    if(sa[count]=='e'){e++;}
    if(sa[count]=='f'){f++;}
    if(sa[count]=='g'){g++;}
    if(sa[count]=='h'){h++;}
    if(sa[count]=='i'){i++;}
    if(sa[count]=='j'){j++;}
    if(sa[count]=='k'){k++;}
    if(sa[count]=='l'){l++;}
    if(sa[count]=='m'){m++;}
    if(sa[count]=='n'){n++;}
    if(sa[count]=='o'){o++;}
    if(sa[count]=='p'){p++;}
    if(sa[count]=='q'){q++;}
    if(sa[count]=='r'){r++;}
    if(sa[count]=='s'){s++;}
    if(sa[count]=='t'){t++;}
    if(sa[count]=='u'){u++;}
    if(sa[count]=='v'){v++;}
    if(sa[count]=='w'){w++;}
    if(sa[count]=='x'){x++;}
    if(sa[count]=='y'){y++;}
    if(sa[count]=='z'){z++;}
}
if (count%2==1){printf("No\n"); return 0;}
if(a%2==0&&b%2==0&&c%2==0&&d%2==0&&e%2==0&&f%2==0&&g%2==0&&h%2==0&&i%2==0&&j%2==0&&k%2==0&&l%2==0&&m%2==0&&n%2==0&&o%2==0&&p%2==0&&q%2==0&&r%2==0&&s%2==0&&t%2==0&&u%2==0&&v%2==0&&w%2==0&&x%2==0&&y%2==0&&z%2==0)
{printf("Yes\n"); return 0;}
  else{printf("No\n"); return 0;}
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[120]’ [-Wformat=]
   scanf("%s",&sa);
         ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&sa);
   ^