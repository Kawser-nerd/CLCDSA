#include<stdio.h>
inline int max(int a,int b){return a>b?a:b;}
int gcd (int a, int b)
{
    int t;
    while (!(b == 0))
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int iswin(int a,int b){
	int i,t;
	int g;
	if(a==b)return 0;
	g=gcd(a,b);
	if(g>1){
		a=a/g;
		b=b/g;
	}
	if(a<b){t=a,a=b,b=t;}
	if(a>=2*b)return 1;
	else return 1-iswin(a-b,b);
}
int main(){
	int t,n,i,j,k,c,a1,a2,b1,b2;
	FILE *fp1=fopen("A-small.in","r");
	FILE *fp2=fopen("A-small.out","w");
	fscanf(fp1,"%d",&t);
	for(i=1;i<=t;i++){
		fscanf(fp1,"%d%d%d%d",&a1,&a2,&b1,&b2);
		c=0;
		for(j=a1;j<=a2;j++){
			for(k=b1;k<=b2;k++){
				if(iswin(j,k))c++;
			}
		}
		fprintf(fp2,"Case #%d: %d\n",i,c);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
