import java.io.*;
import java.util.*;
import java.math.*;

public class fence_small implements Runnable {

	public static void main(String[] args) {
		new Thread(new fence_small()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(this.hashCode());

	@Override
	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
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

	BigInteger nextBigInteger() {
		return new BigInteger(nextToken());
	}

	String FNAME = "fence1";

	class Offer {
		public Offer(String nextInt, int i, int j) {
			c = nextInt;
			a = i;
			b = j;
		}

		String c;
		int a, b;
	}

	private void solve() throws IOException {
		int testn = nextInt();
		for (int test = 0; test < testn; test++) {
			out.print("Case #" + (test + 1) + ": ");
			int n = nextInt();
			Offer[] a = new Offer[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = new Offer(nextToken(), nextInt() - 1, nextInt() - 1);
			}
			int ans = Integer.MAX_VALUE / 2;
			all: for (int i = 0; i < 1 << n; i++) {
				HashSet<String> colors = new HashSet<String>();
				for (int j = 0; j < a.length; j++) {
					if ((i & (1 << j)) != 0) {
						colors.add(a[j].c);
					}
				}
				if (colors.size() > 3) {
					continue;
				}
				boolean[] q = new boolean[10000];
				for (int j = 0; j < a.length; j++) {
					if ((i & (1 << j)) != 0) {
						for (int k = a[j].a; k <= a[j].b; k++) {
							q[k] = true;
						}
					}
				}
				for (int j = 0; j < q.length; j++) {
					if (!q[j]) {
						continue all;
					}
				}
				ans = Math.min(ans, Integer.bitCount(i));
			}
			if (ans >= Integer.MAX_VALUE / 2) {
				out.println("IMPOSSIBLE");
			} else {
				out.println(ans);
			}
		}
	}
}
