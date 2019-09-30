#include<stdio.h>

#define BASENUMBER 10
#define MAX_PAY_ORDER 5
#define OK 1
#define NO 0

int power(int b, int p){
	int calc=1;
	for(int i=0; i<p; i++) calc*=b;
return calc;
}	

int getmin(int *D){
	for(int i=0; i<BASENUMBER; i++){
		if(D[i]==OK) return i;
	}
return -1;
}

int Num_order(int N){
	int order=0;

	for(order; ; order++){
		if(N/BASENUMBER==0){
			break;
		}else{
			N/=BASENUMBER;
		}
	}
return order;
}

int pay(int *N, int *D, int *min_useful_number){
	int n=*N, ans=0, flag=0;
	int N_order=Num_order(n);
	int payorder=N_order;
	int temp[MAX_PAY_ORDER];
	for(int i=0; i<MAX_PAY_ORDER; i++) temp[i]=*min_useful_number;

	do{
		if(payorder>N_order){
			for(int i=0; i<payorder; i++) temp[i]=*min_useful_number;
			
			if(*min_useful_number==0){
				for(int i=1; i<BASENUMBER; i++){
					if(D[i]==OK) temp[payorder]=i;
				}
			}

			for(int i=0; i<=payorder; i++){
				ans += temp[i] * power(BASENUMBER, i);
			}
			return ans;
		}

		int digit = ((*N)%power(BASENUMBER, payorder+1)) / power(BASENUMBER, payorder);

		if(D[digit]==OK && flag==0){
			temp[payorder]=digit;
			n -= digit * power(BASENUMBER, payorder);
			
			if(n==0){
				flag=1;
			}else{
				payorder--;
				continue;
			}
		
		}else{ 
			for(int i=digit+1; i<BASENUMBER; i++){
				if(D[i]==OK){
					temp[payorder]=i;
					flag=1;
					break;
				}
			}
		}

		payorder++;
		flag = (flag==1) ? 1 : -1;

	}while(flag!=1 && payorder<=MAX_PAY_ORDER);

	for(int i=0; i<=N_order; i++){
		ans += temp[i] * power(BASENUMBER, i);
	}
return ans;
}

int main(void){
	int N=0, K=0, temp=0, D[BASENUMBER], min_useful_number;
	for(int i=0; i<BASENUMBER; i++) D[i]=OK;

	scanf("%d %d", &N, &K);
	for(int i=0; i<K; i++){
		scanf("%d", &temp);
		D[temp]=NO;
	}

	min_useful_number=getmin(D);

	printf("%d\n", pay(&N, D, &min_useful_number));

return 0;
} ./Main.c: In function ‘main’:
./Main.c:95:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &N, &K);
  ^
./Main.c:97:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &temp);
   ^