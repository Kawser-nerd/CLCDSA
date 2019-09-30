import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	static long MOD = 1000000007;
	
	static long inv(long a) {
		return eleva(a, (int)MOD - 2);
	}
	
	static long eleva(long b, int e) {
		if (e == 0) return 1;
		long ret = eleva(b, e / 2);
		ret *= ret;
		ret %= MOD;
		if (e % 2 == 1) {
			ret *= b;
			ret %= MOD;
		}
		return ret;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int N = sc.nextInt();
		long[] fact = new long[N], invFact = new long[N];
		fact[0] = invFact[0] = fact[1] = invFact[1] = 1;
		for (int i = 2; i < N; i++) {
			fact[i] = (fact[i-1] * i) % MOD;
		}
		invFact[N-1] = inv(fact[N-1]);
		for (int i = N - 2; i >= 2; i--) {
			invFact[i] = (invFact[i+1] * (i+1)) % MOD;
		}
		
		long ans = fact[N-1] * (N-1) % MOD;
		for (int k = (N + 1)/2; k < N - 1; k++) {
			long tmp = (fact[k-1] * fact[k]) % MOD;
			tmp = (tmp * invFact[2*k - N]) % MOD;
			ans -= tmp;
		}
		ans %= MOD; ans += MOD; ans %= MOD;
		System.out.println(ans);
	}
}