#include <stdio.h>

int main(){
	int T;
	fscanf(stdin,"%d",&T);

	for(int t=1;t<=T;t++){
		long long N,K;
		fscanf(stdin,"%lld %lld",&N,&K);

		long long empty[2][2]={{N,1},{0,0}};
		long long c=1;
		while(c<K){
			long long emp1=0,n_emp1=0,emp2=0,n_emp2=0;
			emp1=empty[0][0]/2;
			emp2=emp1-1;
			n_emp1=empty[0][1];
			
			if(empty[0][0]%2!=0){
				n_emp1*=2;
			}else{
				n_emp2=n_emp1;
			}

			if(empty[1][0]==0 && n_emp2==0){
				emp2=0;
			}else if(empty[1][0]%2==0){
				n_emp1+=empty[1][1];
				n_emp2+=empty[1][1];
			}else{
				n_emp2+=empty[1][1]*2;
			}

			empty[0][0]=emp1;	empty[0][1]=n_emp1;
			empty[1][0]=emp2;	empty[1][1]=n_emp2;
			c+=empty[0][1]+empty[1][1];
		}
		int index;
		if(c-K<empty[1][1])
			index=1;
		else
			index=0;
		printf("Case #%d: %lld %lld\n",t,empty[index][0]/2,(empty[index][0]-1)/2);
	}
}