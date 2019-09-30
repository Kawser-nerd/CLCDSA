import java.io.*;
import java.util.*;
import java.math.*;

public class B {
	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(125475452);

	private void run() {
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

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
	
	long nextLong() {
		return Long.parseLong(nextToken());
	}

	String FNAME = "B-large";

	private void solve() throws IOException {
		int T = nextInt();
		for (int test = 1; test <= T; ++test) {
			int L = nextInt();
			long t = nextLong();
			int N = nextInt();
			int C = nextInt();
		
			
			long[] a = new long[N];
			for (int i = 0; i < C; ++i) {
				a[i] = nextLong();
				int j = i + C;
				while (j < a.length) {
					a[j] = a[i];
					j += C;
				}
				
			}
			long ans = 0;
			for (long v : a) {
				ans += 2 * v;
			}
	
			long[] b = new long[N];
			long st = 0;
			for (int i = 0; i < N; ++i) {
				if (st >= t) {
					b[i] = a[i];
				} else if (st + 2 * a[i] > t) {
					b[i] = a[i] - (t - st) / 2;
				}
				st += 2 * a[i];
			}
			Arrays.sort(b);
			for (int i = b.length - 1; i >= 0 && L > 0; --i, --L) {
				ans -= b[i];
			}
			out.println("Case #" + test + ": " + ans);
		}
	}
}