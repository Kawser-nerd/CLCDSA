import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.util.*;
import java.io.*;
import java.math.BigInteger;

import static java.math.BigInteger.*;

public class Main {

	static final int MAX_N = 100000 + 10;
	boolean[] isPrime = new boolean[MAX_N];
	int[] primes;
	void makePrimes(){
		if (primes != null) return;
		for (int i = 0; i < isPrime.length; i++) isPrime[i] = true;
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i * i < isPrime.length; i++)
			if (isPrime[i])
				for(int j = i * i; j < isPrime.length; j += i)
					isPrime[j] = false;
		int p = 0;
		for (int i = 2; i < isPrime.length; i++) p += isPrime[i] ? 1 : 0;
		primes = new int[p];
		p = 0;
		for (int i = 2; i < isPrime.length; i++) if (isPrime[i]) primes[p++] = i;
	}
	
	long root(long x) {
		long res = 1;
		for (int p : primes) {
			if ((long) p * p * p > x) break;
			if (x % p == 0) {
				int times = 0;
				do {
					times++;
					x /= p;
				} while (x % p == 0);
				times %= 3;
				for (int i = 0; i < times; i++) res *= p;
			}
		}
		res *= x;
		return res;
	}
	
	static final long BIG = 1000 * 1000 * 1000 * 10;
	long pair(long x) {
		long res = 1;
		for (int p : primes) {
			if ((long) p * p * p > x) break;
			if (x % p == 0) {
				int times = 0;
				do {
					times++;
					x /= p;
				} while (x % p == 0);
				times %= 3;
				times = (3 - times) % 3;
				for (int i = 0; i < times; i++) { res *= p; if (res > BIG) return -1; }
			}
		}
		if (x == 1)
			return res;
		long sq = Math.round(Math.sqrt(x));
		if (sq * sq == x) {
			res *= sq;
		} else {
			res *= x * x;
		}
		return res;
	}
	void solve() {
		makePrimes();
		int N = sc.nextInt();
		HashMap<Long, Integer> count = new HashMap<>(N * 4 / 3 + 10);
		for (int i = 0; i < N; i++) {
			long x = sc.nextLong();
			long r = root(x);
			count.put(r, count.getOrDefault(r, 0) + 1);
		}
//		tr(count);
		long ans = 0;
		for (long x : new ArrayList<>(count.keySet())) {
			if (x == 1) { ans++; continue; }
			int gx = count.get(x);
			if (gx == 0) continue;
			long y = pair(x);
//			tr(x, y);
			ans += Math.max(gx, count.getOrDefault(y, 0));
			if (gx > 0) count.put(x, 0);
			if (count.containsKey(y)) count.put(y, 0);
		}
		out.println(ans);
	}
	static void tr(Object... os) { System.err.println(deepToString(os)); }

	public static void main(String[] args) throws Exception {
		new Main().run();
	}

	MyScanner sc = null;
	PrintWriter out = null;
	public void run() throws Exception {
		sc = new MyScanner(System.in);
		out = new PrintWriter(System.out);
		for (;sc.hasNext();) {
			solve();
			out.flush();
		}
		out.close();
	}

	class MyScanner {
		String line;
		BufferedReader reader;
		StringTokenizer tokenizer;

		public MyScanner(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}
		public void eat() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					line = reader.readLine();
					if (line == null) {
						tokenizer = null;
						return;
					}
					tokenizer = new StringTokenizer(line);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
		}
		public String next() {
			eat();
			return tokenizer.nextToken();
		}
		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		public boolean hasNext() {
			eat();
			return (tokenizer != null && tokenizer.hasMoreElements());
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++) a[i] = nextInt();
			return a;
		}
	}
}