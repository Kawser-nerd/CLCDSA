import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		final long MOD = 1000000007;
		int N = sc.nextInt();
		long A = sc.nextLong();
		long B = sc.nextLong();
		if(A>B) {
			long temp = A;
			A = B;
			B = temp;
		}
		long[] S = new long[N+1];
		S[0] = -(B+1);
		for(int i=0; i<N; i++)
			S[i+1] = sc.nextLong();
		
		for(int i=2; i<N+1; i++) {
			if(S[i]-S[i-2]<A) {
				System.out.println(0);
				sc.close();
				return;
			}
		}
		
		long[] dp = new long[N+1];
		dp[0] = 1;
		
		int idxZero = 0;
		int idxB = 0;
		long sum = 0;
		for(int i=1; i<=N; i++) {
			while(S[i] - S[idxB]>=B) {
				sum = (sum + dp[idxB])%MOD;
				idxB++;
			}
			dp[i] = sum;
			if(S[i]-S[i-1]<A) {
				while(idxZero<i-1) {
					if(idxZero<idxB)
						sum = (sum - dp[idxZero] + MOD)%MOD;
					dp[idxZero]=0;
					idxZero++;
				}
			}
		}

		long ans = 0;
		for(int i=0; i<N+1; i++)
			ans = (ans + dp[i])%MOD;
		System.out.println(ans);
		
		sc.close();
	}
}