import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static boolean debug = false;
	static boolean debug2 = false;

	private final static int mod = 1000000007;

	public static void main(String[] args) throws java.io.IOException {
		debug = 1 <= args.length;
		debug2 = 2 <= args.length;

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String[] ia = in.readLine().split(" ");

		final long N = Long.parseLong(ia[0]);
		final int M = Integer.parseInt(ia[1]);

		final long patterns = patterns(N, M);

		System.out.println(patterns);
	}

	private static long inverse(long x) {
		long y = 1;
		while (0 != y % x) {
			y += mod;
		}
		return y / x;
	}

	private static long nCr(long n, long r) {
		if (n < r) {
			return 0;
		}
		if (n - r < r) {
			r = n - r;
		}

		long ret = 1;
		for (long i = 0; i < r; ++i) {
			ret = ret * n % mod;
			--n;
			ret = ret * inverse(i + 1) % mod;
		}

		return ret;
	}

	private static long nHr(long n, long r) {
		return nCr(n + r - 1, r);
	}

	private static HashMap<Long, Integer> prime_factors(long n) {
		HashMap<Long, Integer> hm = new HashMap<>();

		while (n % 2 == 0) {
			n /= 2;
			if (hm.containsKey(2L)) {
				hm.put(2L, hm.get(2L) + 1);
			} else {
				hm.put(2L, 1);
			}
		}

		for (long i = 3; i <= Math.sqrt(n) + 1 && 1 < n; ) {
			if (n % i == 0) {
				n /= i;
				if (hm.containsKey(i)) {
					hm.put(i, hm.get(i) + 1);
				} else {
					hm.put(i, 1);
				}
			} else {
				i += 2;
			}
		}

		if (n != 1) {
			if (hm.containsKey(n)) {
				hm.put(n, hm.get(n) + 1);
			} else {
				hm.put(n, 1);
			}
		}

		return hm;
	}

	private static long patterns(long n, int m) {
		n = Math.abs(n);

		final HashMap<Long, Integer> hm = prime_factors(n);

		long ret = 1;
		for (Iterator<Long> it = hm.keySet().iterator(); it.hasNext(); ) {
			ret = ret * nHr(m, hm.get(it.next())) % mod;
		}

		for (int i = 0; i < m - 1; ++i) {
			ret = ret * 2 % mod;
		}

		return ret;
	}

}