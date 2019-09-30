import java.util.ArrayList;
import java.util.Scanner;

class Main{
	static final long MOD = 1000000007;


	static long pow=1000000007;




	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		long N = sc.nextLong();
		long M = sc.nextLong();

		ArrayList<Integer> sosu = new ArrayList<Integer>();
		long ans = 1;

		for(int i = 2;i*i <= M;i++){
			if(M%i == 0){
				int scount = 0;		
				while(M%i==0){
					scount++;
					M /= i;
				}
				if(scount!=0){
					ans *=comb(scount+N-1,scount);
					ans %= pow;
				}


			}
		}
		if(M!=1){
			ans *= comb(1+N-1,1);
			ans %= pow;

		}

		//		
		//		ArrayList<Integer> numdata = new ArrayList<Integer>();			//???????????
		//		int c = 0;
		//		while(M!=1){
		//			int scount = 0;		
		//			while(M%sosu.get(c) == 0){
		//				scount++;
		//				M /= sosu.get(c);
		//			}
		//			if(scount!=0){
		//				numdata.add(scount);
		//			}
		//			c++;
		//		}
		//		
		//		for(int i = 0;i <numdata.size();i++){
		//			ans *=comb(numdata.get(i)+N-1,numdata.get(i));
		//			ans %= pow;
		//		}
		System.out.println(ans);




	}

	static long comb(long x,Integer y){
		long ue = 1;
		long sita = 1;
		for(int i= 0;i < y;i++){
			ue *= x-i;
			ue %= pow;
			sita *= i+1;
			sita %=pow;

		}


		long ans = ue*modpow(sita,pow-2)%pow;
		return ans;
	}
	static long modpow(long a,long p){
		if(p == 0){
			return 1;
		}
		if(p % 2 == 0){
			long halfp = p/2;
			long half = modpow(a, halfp);
			return half*half%pow;
		}else{
			return a*modpow(a, p-1)%pow;
		}
	}
}







class Pair implements Comparable{
	int from;		//p
	int end;		//y
	int num;
	int bango;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}