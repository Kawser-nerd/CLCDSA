import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A implements Runnable {

	public static void main(String[] args) {
		new Thread(new A()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public final boolean large = true;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			String FN = "A-" + (large ? "large" : "small");
			br = new BufferedReader(new FileReader(FN + ".in"));
			out = new PrintWriter(FN + ".out");
			getPrimeNumbers();
			int T = nextInt();
			for (int i = 1; i <= T; i++) {
				out.print("Case #" + i + ": ");
				solve();
			}
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

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

	void getPrimeNumbers() {
		boolean[] bad = new boolean[MAX];
		for (int i = 2; i * i < MAX; i++) {
			if (!bad[i]) {
				for (int j = i * i; j < MAX; j += i) {
					bad[j] = true;
				}
			}
		}
		int cnt = 0;
		for (int i = 2; i < MAX; i++) {
			if (!bad[i])
				cnt++;
		}
		allp = new int[cnt];
		cnt = 0;
		for (int i = 2; i < MAX; i++) {
			if (!bad[i])
				allp[cnt++] = i;
		}
	}

	int modInverse(int a, int mod) {
		return BigInteger.valueOf(a).modInverse(BigInteger.valueOf(mod))
				.intValue();
	}

	int MAX = 1000000;
	int[] allp;
	int[] tend = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

	private void stupid() throws IOException {
		int d = nextInt(), k = nextInt();
		int ten = tend[d];
		int[] v = new int[k];
		for (int i = 0; i < v.length; i++) {
			v[i] = nextInt();
		}
		int nextNumber = -1;
		if (d <= 2) {
			pp: for (int it = 0; it < allp.length && allp[it] < ten; it++) {
				int p = allp[it];
				for (int i = 0; i < k; i++) {
					if (v[i] >= p)
						continue pp;
				}
				for (int a = 0; a < p; a++) {
					bb: for (int b = 0; b < p; b++) {

						int s = v[0];
						for (int j = 1; j < k; j++) {
							s = (s * a + b) % p;
							if (s != v[j])
								continue bb;
						}

						s = (s * a + b) % p;
						if (nextNumber != -1 && nextNumber != s) {
							out.println("I don't know.");
							return;
						}
						nextNumber = s;
					}
				}
			}
			assert nextNumber != -1;
			out.println(nextNumber);
			return;
		}

		if (k == 1) {
			out.println("I don't know.");
			return;
		}

		nextNumber = -1;
		System.err.println("TEST");

		pp: for (int it = 0; it < allp.length && allp[it] < ten; it++) {
			int p = allp[it];
			for (int i = 0; i < k; i++) {
				if (v[i] >= p)
					continue pp;
			}

			aa: for (int a = 0; a < p; a++) {

				int as = (int) ((long) a * v[0] % p);

				int b = (v[1] - as + p) % p;
				// System.err.println(a+" "+b+" "+v[0]+" "+v[1]);
				int s = v[0];
				for (int i = 0; i < k; i++) {
					if (s != v[i]) {
						if (i <= 1) {
							throw new AssertionError();
						}
						continue aa;
					}
					s = (int) (((long) a * s + b) % p);
				}

				if (nextNumber != -1 && nextNumber != s) {
					out.println("I don't know.");
					return;
				}
				nextNumber = s;
			}
		}

		out.println(nextNumber);

	}

	int test;

	private void solve() throws IOException {
		int d = nextInt(), k = nextInt();
		int ten = tend[d];
		++test;
		int[] v = new int[k];
		for (int i = 0; i < v.length; i++) {
			v[i] = nextInt();
		}
		System.err.println("TEST # " + test);
		System.err.println(Arrays.toString(v));
		int nextNumber = -1;
		if (d <= 2) {
			pp: for (int it = 0; it < allp.length && allp[it] < ten; it++) {
				int p = allp[it];
				for (int i = 0; i < k; i++) {
					if (v[i] >= p)
						continue pp;
				}
				for (int a = 0; a < p; a++) {
					bb: for (int b = 0; b < p; b++) {

						int s = v[0];
						for (int j = 1; j < k; j++) {
							s = (s * a + b) % p;
							if (s != v[j])
								continue bb;
						}

						s = (s * a + b) % p;
						if (nextNumber != -1 && nextNumber != s) {
							out.println("I don't know.");
							return;
						}
						nextNumber = s;
					}
				}
			}
			assert nextNumber != -1;
			out.println(nextNumber);
			return;
		}

		if (k == 1) {
			out.println("I don't know.");
			return;
		}

		if (v[0] == v[1]) {
			out.println(v[0]);
			return;
		}

		if (k < 3) {
			out.println("I don't know.");
			return;
		}

		boolean zeroes = true;
		for (int i = 1; i < k; i++) {
			if (v[i] != 0)
				zeroes = false;
		}
		if (zeroes) {
			out.println(0);
			return;
		}

		int x = v[0], y = v[1], z = v[2];

		assert nextNumber == -1;

		pp: for (int it = 0; it < allp.length && allp[it] < ten; it++) {
			int p = allp[it];
			for (int i = 0; i < k; i++) {
				if (v[i] >= p)
					continue pp;
			}
			// System.err.println(p);

			int a = 0, b = 0;

			if (x == 0) {
				b = y;
				a = (int) ((long) ((z - b + p) % p) * modInverse(y, p) % p);
			} else {
				int q = (z - y + p) % p; // a ((a-1)s + b)

				int r1 = (int) ((long) y * y % p);
				int r2 = (int) ((long) x * z % p);

				int r = (r1 - r2 + p) % p; // b((a-1)s + b)

				if (q == 0 && r == 0) {

					int t = modInverse(x, p);
					t = (p - t) % p;
					// a = bt + 1

					int l = (int) (((long) x * t + 1) % p);
					if (l == 0) {
						a = 1;
						b = 0;
					} else {
						int dd = (y - x + p) % p;
						b = (int) ((long) dd * modInverse(l, p) % p);
						a = (int) (((long) b * t + 1) % p);
					}
					System.err.println("BAD CASE");
					throw new AssertionError();
				} else {
					if (r == 0) {
						b = 0;
						a = (int) ((long) v[1] * modInverse(v[0], p) % p);
					}
					if (q == 0) {
						a = 0;
						b = v[1];
						// System.err.println("THJASIS");
					}
					if (q != 0 && r != 0) {
						int rr = modInverse(r, p);
						int t = (int) ((long) q * rr % p); // a / b
						if (y != 0) {
							int tt = (int) (((long) t * x + 1) % p);
							assert tt != 0;
							b = (int) ((long) y * modInverse(tt, p) % p);
							a = (int) ((long) b * t % p);
						} else {
							assert z != 0;
							int tt = (int) (((long) t * y + 1) % p);
							b = (int) ((long) z * modInverse(tt, p) % p);
							a = (int) ((long) b * t % p);
						}
						// System.err.println("THJIS");
					}
				}
			}

			int s = x;
			// System.err.println(a + " " + b + " " + s);
			for (int i = 0; i < k; i++) {
				if (s != v[i]) {
					if (i <= 2) {
						System.err.println(p + " " + a + " " + b + " " + x);
						throw new AssertionError();
					}
					continue pp;
				}
				s = (int) (((long) a * s + b) % p);
			}
			if (nextNumber != -1 && nextNumber != s) {
				out.println("I don't know.");
				return;
			}
			nextNumber = s;
		}

		out.println(nextNumber);

	}
}