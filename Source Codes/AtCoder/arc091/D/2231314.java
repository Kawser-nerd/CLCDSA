import java.util.*;

class Main{
	public static void main(String[] args){
		new Main().run();
	}

	void run(){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long[] A=new long[n];
		long[] K=new long[n];
		long grundy=0;
		for(int i=0;i<n;++i){
			A[i]=sc.nextLong();
			K[i]=sc.nextLong();
			grundy^=f(A[i],K[i]);
		}
		if(grundy==0){
			System.out.println("Aoki");
		}else{
			System.out.println("Takahashi");
		}
	}

	long f(long A,long K){
		if(A%K==0){
			return A/K;
		}else{
			long tmp=(A%K)/(A/K+1);
			if(tmp>1){
				return f(A-(A/K+1)*tmp,K);
			}else{
				return f(A-A/K-1,K);
			}
		}
	}
}