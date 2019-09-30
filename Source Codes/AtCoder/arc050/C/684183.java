import java.util.Scanner;

import org.omg.Messaging.SyncScopeHelper;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}
	void run() {
		try (Scanner sc = new Scanner(System.in)) {
			long A = sc.nextLong();
			long B = sc.nextLong();
			long M = sc.nextLong();
			long g = gcd(A, B);
			
			long ans = 1;
			ans *= f(A, M);
			ans %= M;
			ans *= g(B / g, g, M);
			ans %= M;
			System.out.println(ans);
		}
	}
	
	long g(long x, long g, long M) {
		if (x == 0) return 0;
		if (x % 2 == 1) return (mod_pow(10, g, M) * g(x - 1, g, M) + 1) % M;
		else return g(x / 2, g, M) * (1 + mod_pow(10, g * x / 2, M)) % M;
	}
	
	long f(long x, long M) {
		if (x == 0) return 0;
		if (x % 2 == 1) return (10L * f(x - 1, M) + 1) % M;
		return f(x / 2, M) * (1 + mod_pow(10, x / 2, M)) % M;
	}
	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	static long mod_pow(long a, long b, long p) {
		long res = 1;
		while (b > 0) {
			if ((b & 1) == 1)
				res = (res * a) % p;
			a = (a * a) % p;
			b >>= 1;
		}
		return res;
	}
}