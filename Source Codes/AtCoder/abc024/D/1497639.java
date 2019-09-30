import java.util.Scanner;

/**
 * http://abc024.contest.atcoder.jp/tasks/abc024_d
 */
public class Main {
	
	static final int MOD = 1000000007;

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final long A = sc.nextLong();
		final long B = sc.nextLong();
		final long C = sc.nextLong();
		sc.close();
		
		long div = getInverse(getMod(A*(B+C)-B*C));
		long c = getMod(getMod(B*(C-A))*div);
		long r = getMod(getMod(C*(B-A))*div);
		System.out.println(r +" "+ c);	

	}
	
	static long getPower(long a, int n) {
		if(n == 0){
			return 1;
		}else if(n % 2 == 0){
			return getPower(getMod(a*a), n/2);
		}else{
			return getMod(a*getPower(a,n-1));
		}
	}
	
	static long getInverse(long a) {
		return getPower(a, MOD-2);
	}
	
	static long getMod(long a){
		if(a >= 0){
			return a%MOD;
		}
		else{
			return MOD + a%MOD;
		}
	}

}