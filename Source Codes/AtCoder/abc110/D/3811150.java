import java.util.Scanner;
import java.util.Map.Entry;

public class Main {

	static int MAX_FAC = 510000;
	static int MOD = 1000000007;
	static long[] fac = new long[MAX_FAC];
	static long[] finv = new long[MAX_FAC];
	static long[] inv = new long[MAX_FAC];

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);

		long N = in.nextLong();
		long M = in.nextLong();
		long ans = 1;

		initComb();

		long m = M;
		for (int i = 2; i * i <= m; i++) {
			if (m % i == 0) {
				int count = 0;
				while (m % i == 0) {
					m /= i;
					count++;
				}
				ans = (ans * comb((int)N-1+count, count)) % MOD;
			}
		}
		if(m > 1){
			ans = (ans * N) % MOD;
		}

		System.out.println(ans);
	}
	public static void initComb(){
		fac[0] = finv[0] = inv[0] = fac[1] = finv[1] = inv[1] = 1;
		for (int i = 2; i < MAX_FAC; ++i) {
			fac[i] = fac[i - 1] * i % MOD;
			inv[i] = MOD - (MOD / i) * inv[(int) (MOD % i)] % MOD;
			finv[i] = finv[i - 1] * inv[i] % MOD;
		}
	}
	public static long comb(int n, int k){
		return fac[n] * finv[k] % MOD * finv[n - k] % MOD;
	}
}