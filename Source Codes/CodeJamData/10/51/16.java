import java.io.*;
import java.util.*;
import java.math.*;

public class SolA implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolA()).start();
	}

	@Override
	public void run() {
		try {
			Locale.setDefault(Locale.US);
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof;
	Random random = new Random(43965743875L);

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBigInteger() {
		return new BigInteger(nextToken());
	}

//	String FNAME = "A-small-attempt0";
//	String FNAME = "A-small";
	String FNAME = "A-large";

	ArrayList<Integer> primes = new ArrayList<Integer>();	
	
	void solve() {
		boolean[] isp = new boolean[1000001];
		isp[0] = true;
		isp[1] = true;
		for (int i = 2; i < 1000000; i++) {
			if (!isp[i]) {
				int j = 2 * i;
				while (j < isp.length) {
					isp[j] = true;
					j += i;
				}
			}
		}
		int tests = nextInt();
		test:for (int test = 1; test <= tests; test++) {
			System.out.println(test);
			out.print("Case #" + test + ": ");

			int d = nextInt();
			int maxp = 1;
			while (d-- > 0) {
				maxp *= 10;
			}
			int k = nextInt();
			int[] x = new int[k];
			int maxa = 0;
			for (int i = 0; i < k; i++) {
				x[i] = nextInt();
				maxa = Math.max(maxa, x[i]);
			}
			for (int i = 0; i < k - 1; i++) {
				if (x[i] == x[k - 1]) {
					out.println(x[i + 1]);
					continue test;
				}
			}
			if (k <= 2) {
				out.println("I don't know.");
				continue;
			}
			long ans = -1;
			BigInteger dx = BigInteger.valueOf(x[1] - x[0]);
			for (long p = maxa + 1; p <= maxp; p++) {
				if (isp[(int)p]) continue;
//				if (!BigInteger.valueOf(p).isProbablePrime(100)) continue;
				int cnt = 0;
				long a = (((x[2] - x[1]) % p + p) % p) * dx.modInverse(BigInteger.valueOf(p)).longValue();
//				for (int a = 1; a <= p; a++) {
					long b = (((x[1] - a * x[0]) % p) + p) % p;
					boolean good = true;
					for (int i = 1; i + 1 < k; i++) {
						if ((a * x[i] + b) % p != x[i + 1]) {
							if (i > 1) cnt++;
							good = false;
							break;
						}
					}
//					cnt++;
					if (good) {
						long tans = (a * x[k - 1] + b) % p;
						if (ans != -1 && tans != ans) {
							out.println("I don't know.");
							continue test;
						} else {
							ans = tans;
						}
					}
//				}
				if (cnt > 1) {
					System.out.println(test + " " + cnt);
				}
			}
			if (ans == -1) {
				out.println("I don't know.");
			} else {
				if (k == 2) {
					System.out.println("ff" + test);
				}
				out.println(ans);
			}
		}
	}
}
