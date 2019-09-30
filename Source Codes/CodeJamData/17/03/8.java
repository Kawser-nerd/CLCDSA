import java.util.*;

class C {
	static Scanner in = new Scanner(System.in);

	public static void main(String[] args) {
		int T = in.nextInt();
		
		for (int t = 0; t < T; ++t) {
			long[] x = solve();
			System.out.printf("Case #%d: %d %d%n", t + 1, x[0], x[1]);
		}
	}
	
	static long log2(long n) {
		return 63L - Long.numberOfLeadingZeros(n);
	}
	
	static long[] solve(long k, long n) {
		if (k == 1) {
			return new long[] {n / 2, (n - 1) / 2 };
		}
		
		long   m = 1L << log2(k);
		long   x = (k - m) | (m >> 1);
		
		long[] p = solve(x, n);
		
		long v;
		
		if ((k & (m >> 1)) == 0) {
			v = p[0];
		} else {
			v = p[1];
		}
		
		return new long[] {v / 2, (v - 1) / 2 };
	}
	
	static long[] solve() {
		long N = in.nextLong();
		long K = in.nextLong();
		
		return solve(K, N);
	}
}