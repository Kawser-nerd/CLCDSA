import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static final long MOD = 1000000007;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int d = sc.nextInt();
		sc.close();

		long[] fact = new long[n];
		long[] ifact = new long[n];
		long mfact = 1;
		long mifact = 1;
		for(int i=1; i<=n; i++){
			mfact *= i;
			mfact %= MOD;
			fact[i-1] = mfact;
			mifact *= inverseElement(i, MOD);
			mifact %= MOD;
			ifact[i-1] = mifact;
		}
		long[][] xfact = new long[n][n];
		for(int i=0; i<n; i++){
			long tfact = 1;
			for(int j=0; j<n; j++){
				tfact *= ifact[i];
				tfact %= MOD;
				xfact[i][j] = tfact;
			}
		}

		// long[][] dp = new long[b-a+2][n+1];
		// for(int i=1; i<b-a+2; i++){
		// 	int mab = i + a - 1;
		// 	for(int j=1; j<n+1; j++){
		// 		dp[i][j] = dp[i-1][j];
		// 		for(int k=c; k<=d; k++){
		// 			int mabcd = mab*k;
		// 			if(mabcd > n) continue;
		// 			long tfact = fact[k-1];
		// 			for(int l=0; l<k; l++){
		// 				tfact *= fact[mab-1];
		// 			}
		// 			if(mabcd == j){
		// 				dp[i][j] += fact[n-1] / tfact;
		// 			}else if(mabcd < j){
		// 				dp[i][j] += dp[i-1][j-mabcd] / tfact;
		// 			}
		// 		}
		// 	}
		// }
		
		long[][] dp = new long[b-a+2][n+1];
		for(int i=1; i<b-a+2; i++){
			int mab = i + a - 1;
			out: for(int j=1; j<n+1; j++){
				dp[i][j] = dp[i-1][j];
				for(int k=c; k<=d; k++){
					int mabcd = mab*k;
					if(mabcd > n) continue out;
					long tfact = ifact[k-1];
					tfact *= xfact[mab-1][k-1];
					tfact %= MOD;
					// for(int l=0; l<k; l++){
					// 	tfact *= ifact[mab-1];
					// 	tfact %= MOD;
					// }
					if(mabcd == j){
						dp[i][j] += fact[n-1] * tfact;
					}else if(mabcd < j){
						dp[i][j] += dp[i-1][j-mabcd] * tfact;
					}
					dp[i][j] %= MOD;
				}
			}
		}

		System.out.println(dp[b-a+1][n]);
	}

	public static long inverseElement(long a, long n){
        long b = n, u=1, v=0;
        while(b > 0) {
            long t = a/b;
            a -= t*b;
            u -= t*v;
            //swap
            t = a;
            a = b;
            b = t;
            t = u;
            u = v;
            v = t;
        }
        u = u % n;
        if(u < 0) u += n;
        return u;
    }

}