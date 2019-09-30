import java.io.*;
import java.util.*;


public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		Prime prime = new Prime(100_000);
		List<Integer> primes = prime.getPrimeList();

//		Set<Long> p = new HashSet<>();
		Map<Long, Integer> sp = new HashMap<>();
//		Map<Long, Integer> cp = new HashMap<>();
		for (int e : primes) {
			long tmp = e;
//			p.add(tmp);
			tmp *= e;
			if (tmp <= 10_000_000_000L) {
				sp.put(tmp, e);
			}
//			tmp *= e;
//			if (tmp <= 10_000_000_000L) {
//				cp.put(tmp, e);
//			}
		}

		int n = sc.nextInt();

		Map<Long, Integer> hmc = new HashMap<>();
		Map<Long, Long> hmp = new HashMap<>();
		int ret = 0;
		for (int i = 0; i < n; i++) {
			long s = sc.nextLong();

			long norm = 1;
			long part = 1;
			for (int p : primes) {
				if (p > 2154) { // 10_000_000_000^1/3
					break;
				}
				int cnt = 0;
				while (s % p == 0) {
					s /= p;
					cnt++;
				}

				if (cnt > 0) {
					cnt %= 3;

					if (cnt == 1) {
						norm *= p;
						part *= p * p;
					} else if (cnt == 2) {
						norm *= p * p;
						part *= p;
					}
				}
			}

			if (sp.containsKey(s)) {
				norm *= s;
				part *= (long)Math.sqrt(s);
			} else {
				if (s > 100_000) {
					ret++;
					norm = 0;
					part = 0;
				} else {
					norm *= s;
					part *= s * s;
				}
			}

			hmp.put(norm, part);
			if (!hmc.containsKey(norm)) {
				hmc.put(norm, 0);
			}
			hmc.put(norm, hmc.get(norm) + 1);
		}

		int ret2 = 0;
		for (long e : hmp.keySet()) {
			if (e == 0) {
			} else if (e == 1) {
				ret++;
			} else {
				Integer nc = hmc.get(e);
				Integer pc = hmc.get(hmp.get(e));

				if (pc != null) {
					ret2 += nc.compareTo(pc) >= 0 ? nc.intValue() : pc.intValue();
				} else {
					ret += nc.intValue();
				}
			}
		}

		pr.println(ret + ret2 / 2);
	}

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
		sc = new Scanner(System.in);
		pr = new Printer(System.out);

		solve();

		pr.close();
		sc.close();
	}

	@SuppressWarnings("unused")
	private static class Scanner {
		BufferedReader br;

		Scanner (InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}

		private boolean isPrintable(int ch) {
			return ch >= '!' && ch <= '~';
		}

		private boolean isCRLF(int ch) {
			return ch == '\n' || ch == '\r' || ch == -1;
		}

		private int nextPrintable() {
			try {
				int ch;
				while (!isPrintable(ch = br.read())) {
					if (ch == -1) {
						throw new NoSuchElementException();
					}
				}

				return ch;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		String next() {
			try {
				int ch = nextPrintable();
				StringBuilder sb = new StringBuilder();
				do {
					sb.appendCodePoint(ch);
				} while (isPrintable(ch = br.read()));

				return sb.toString();
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		int nextInt() {
			try {
				// parseInt from Integer.parseInt()
				boolean negative = false;
				int res = 0;
				int limit = -Integer.MAX_VALUE;
				int radix = 10;

				int fc = nextPrintable();
				if (fc < '0') {
					if (fc == '-') {
						negative = true;
						limit = Integer.MIN_VALUE;
					} else if (fc != '+') {
						throw new NumberFormatException();
					}
					fc = br.read();
				}
				int multmin = limit / radix;

				int ch = fc;
				do {
					int digit = ch - '0';
					if (digit < 0 || digit >= radix) {
						throw new NumberFormatException();
					}
					if (res < multmin) {
						throw new NumberFormatException();
					}
					res *= radix;
					if (res < limit + digit) {
						throw new NumberFormatException();
					}
					res -= digit;

				} while (isPrintable(ch = br.read()));

				return negative ? res : -res;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		long nextLong() {
			try {
				// parseLong from Long.parseLong()
				boolean negative = false;
				long res = 0;
				long limit = -Long.MAX_VALUE;
				int radix = 10;

				int fc = nextPrintable();
				if (fc < '0') {
					if (fc == '-') {
						negative = true;
						limit = Long.MIN_VALUE;
					} else if (fc != '+') {
						throw new NumberFormatException();
					}
					fc = br.read();
				}
				long multmin = limit / radix;

				int ch = fc;
				do {
					int digit = ch - '0';
					if (digit < 0 || digit >= radix) {
						throw new NumberFormatException();
					}
					if (res < multmin) {
						throw new NumberFormatException();
					}
					res *= radix;
					if (res < limit + digit) {
						throw new NumberFormatException();
					}
					res -= digit;

				} while (isPrintable(ch = br.read()));

				return negative ? res : -res;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		float nextFloat() {
			return Float.parseFloat(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			try {
				int ch;
				while (isCRLF(ch = br.read())) {
					if (ch == -1) {
						throw new NoSuchElementException();
					}
				}
				StringBuilder sb = new StringBuilder();
				do {
					sb.appendCodePoint(ch);
				} while (!isCRLF(ch = br.read()));

				return sb.toString();
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		void close() {
			try {
				br.close();
			} catch (IOException e) {
//				throw new NoSuchElementException();
			}
		}
	}

	private static class Printer extends PrintWriter {
		Printer(PrintStream out) {
			super(out);
		}
	}
}