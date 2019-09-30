#include <stdio.h>

long long int data[3];
long long int seg[2];

long long int gcd(long long int n1,long long int n2){
	if(n2==0)return n1;
	else return gcd(n2,n1%n2);
}

int main(){
	int c,ct,n,i,j;
	long long int point,temp,number_gcd;
	
	scanf("%d",&c);
	for(ct=1;ct<=c;ct++){
		/* input */
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&data[i]);
		
		/* sort */
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(data[i]>data[j]){
					temp=data[i];
					data[i]=data[j];
					data[j]=temp;
				}
		
		for(i=0;i<n-1;i++)
			seg[i]=data[i+1]-data[i];
		
		if(n-1==1)number_gcd=seg[0];
		else number_gcd=gcd(seg[0],seg[1]);
		
		/* compute */
		for(point=data[0];point>0;point-=number_gcd);
		point*=-1;
		
		printf("Case #%d: %lld\n",ct,point);
		
	}
	return 0;
}
