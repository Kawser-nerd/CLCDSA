import java.io.*;
import java.util.*;
import java.util.Map.*;



public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		final int MOD = 1_000_000_007;

		int a = sc.nextInt();
		int b = sc.nextInt();

		Prime prime = new Prime(Math.max(10, (int)Math.sqrt(a)));
		primes = prime.getPrimeList();
		Map<Long, Integer> hm = new HashMap<>();
		for (int x = b + 1; x <= a; x++) {
			Map<Long, Integer> pf = pf(x);
			for (Entry<Long, Integer> e : pf.entrySet()) {
				long key = e.getKey();
				int value = e.getValue();

				if (hm.containsKey(key)) {
					hm.put(key, hm.get(key) + value);
				} else {
					hm.put(key, value);
				}
			}
		}

		long ans = 1;
		for (int e : hm.values()) {
			ans *= (e + 1);
			ans %= MOD;
		}

		pr.println(ans);
	}

	private static Map<Long, Integer> pf(long x) {
		HashMap<Long, Integer> hm = new HashMap<>();
		long n = x;
		for (int p : primes) {
			if ((long)p * p > n) {
				break;
			}
			int cnt = 0;
			while (n % p == 0) {
				cnt++;
				n /= p;
			}
			if (cnt > 0) {
				hm.put((long)p, cnt);
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

	private static List<Integer> primes;

	@SuppressWarnings("unused")
	private static class Prime {
		private int n;
		private List<Integer> primes;
		private BitSet p;

		Prime(int n) {
			this.n = n;

			p = new BitSet(n / 2);
			int m = (int)Math.sqrt(n);

//			for (int i = 1; i <= m; i++) {
			for (int bi = p.nextClearBit(0); 2 * (bi + 1) + 1 <= m; bi = p.nextClearBit(bi + 1)) {
				long i = bi + 1;
//				if (p.get(i - 1)) {
//					continue;
//				}

				for (long j = 2 * i * (i + 1); 2 * j + 1 <= n; j += 2 * i + 1) {
					p.set((int)(j - 1));
				}
			}
		}

		boolean isPrime(int n) {
			if (n == 2) {
				return true;
			}

			if (n == 1 || (n & 0x1) == 0) {
				return false;
			}

			return !p.get(n / 2 - 1);
		}

		List<Integer> getPrimeList() {
			if (primes != null) {
				return primes;
			}

			primes = new ArrayList<>();
			if (n >= 2) {
				primes.add(2);
//				for (int i = 1; 2 * i + 1 <= n; i++) {
				for (int bi = p.nextClearBit(0); 2 * (bi + 1) + 1 <= n; bi = p.nextClearBit(bi + 1)) {
					int i = bi + 1;
//					if (!p.get(i - 1)) {
//						primes.add(2 * i + 1);
//					}
					primes.add(2 * i + 1);
				}
			}

			return primes;
		}

		private static boolean isPrime(long n) {
			if (n == 2) {
				return true;
			}

			if (n == 1 || (n & 0x1) == 0) {
				return false;
			}

			for (long i = 3; i * i <= n; i += 2) {
				if (n % i == 0) {
					return false;
				}
			}

			return true;
		}
	}

	// ---------------------------------------------------
	public static void main(String[] args) {
		sc = new Scanner(INPUT == null ? System.in : new ByteArrayInputStream(INPUT.getBytes()));
		pr = new Printer(System.out);

		solve();

//		pr.close();
		pr.flush();
//		sc.close();
	}

	static String INPUT = null;

	private static class Printer extends PrintWriter {
		Printer(OutputStream out) {
			super(out);
		}
	}
}