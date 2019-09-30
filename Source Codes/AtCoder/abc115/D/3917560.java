import java.util.Scanner;

class Main{
	static final long MOD = 1000000007;

	static int H, W, K;
	static long[][] dp = new long[110][10];
	static int ans = 0;
	static int n = 0;
	static long x = 0;
	static long[] X;
	static long[] P;




	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);			//?????
		n = sc.nextInt();
		x = sc.nextLong();

		X = new long[51];
		P = new long[51];
		X[0] = 1;
		P[0] = 1;
		for(int i = 1;i <= 50;i++){
			X[i] = 2*X[i-1] + 3;
			P[i] = 2*P[i-1] + 1;
		}
		long ans = sum(n, x);
		System.out.println(ans);






	}

	static long sum(int n,long l){				//l???????????
		
		if(n == 1){
			if(l == 1){
				return 0;
				
			}else if(l <= 4){
				return l -1;
			}else{
				return 3;
			}
			
			
		}
		
		if(l <= 1){
			return 0;
		}else  if(l <= 1 + X[n-1]){
			return sum(n-1, l-1);

		}
		else  if(l == 2 + X[n-1]){
			return P[n-1] + 1;
		}

		else  if( l <= 2 + 2*X[n-1]){
			return  P[n-1] + 1 + sum(n-1, l-(2+X[n-1]));
		}
		else {
			return 2*P[n-1] + 1;
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