#include<stdio.h>
#define ROTATE(A,C) ((A)/10+((A)%10)*(C))

int npair(int a,int b){
	int c,d,e,r;
	for(c=1;c*10<=a;c*=10);
	if(!(b>=c&&c*10>b))return 0;

	r=0;
	for(d=a;d<=b;d++){
		for(e=ROTATE(d,c);e!=d;e=ROTATE(e,c)){
			if(e>d&&e<=b)r++;
		}
	}
	return r;
}

int main(int argc,char*argv[]){
	int a,b,d,e;
	scanf("%d",&e);
	for(d=1;d<=e;d++){
		scanf("%d%d",&a,&b);
		printf("Case #%d: %d\n",d,npair(a,b));
	}
	return 0;
}