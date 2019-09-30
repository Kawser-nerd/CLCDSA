#include <stdio.h>
//include <conio.h>

int a,b,c;
int ta,ji,sa;
int ap,bp,cp;

int main(){
	scanf("%d %d %d",&a,&b,&c);
	if(a>b){
		ap++;
	}
	else {
		bp++;
	}
	if(a>c){
		ap++;
	}
	else {
		cp++;
	}
	if(b>c){
		bp++;
	}
	else {
		cp++;
	}
	if(ap==2) ta=1;
	else if(ap==1) ta=2;
	else ta=3;
	if(bp==2) ji=1;
	else if(bp==1) ji=2;
	else ji=3;
	if(cp==2) sa=1;
	else if(cp==1) sa=2;
	else sa=3;
	printf("%d\n%d\n%d\n",ta,ji,sa);
	/*char a[101];
	int n;
	int migi,hidari;
	scanf("%s %d",&a,&n);
	for(int i=0;i<n;i++){
	scanf("%d %d",&hidari,&migi);
	
	}
	printf("%s",&a);*/
	//getch();
	return 0;
}