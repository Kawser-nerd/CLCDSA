#include<stdio.h>//???????? 
//struct bigint{
//	int digit[1000];
//	int size;
//	void init(){
//		for(int i=0;i<1000;i++){
//			digit[i]=0;
//		}
//		size=0;
//	}
//	void set(long long x){
//		init();
//		do{
//			digit[size++]=x%10000;
//			x=x/10000;
//		}while(x!=0);
//	}
//	bigint operator * (const bigint &a) const{
//		bigint ret;int tmp;int carry=0;
//		ret.init();
//		for(int i=0;i<size||i<)
//	}
//};
int main(){
	long long N,A,B;
	scanf("%lld%lld%lld",&N,&A,&B);
	if(N==0){
		printf("0\n");
	} 
	else if(N==1){
		if(A==B)
			printf("1\n");
		else
			printf("0\n");
	}
	else if(N==2){
		if(A<=B)
			printf("1\n");
		else
			printf("0\n");
	}
	else{
		if(A>B)
			printf("0\n");
		else if(A==B){
			printf("1\n");
		}
		else{
			long long ans=(N-2)*(B-A)+1;
			printf("%lld\n",ans);
		}
	}
	return 0;
}