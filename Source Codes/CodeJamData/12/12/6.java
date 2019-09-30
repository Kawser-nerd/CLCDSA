import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(12345);

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

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String FNAME = "b";

	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			Level[] a = new Level[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = new Level(nextInt(), nextInt());
			}
			Arrays.sort(a);
			int ans = 0;
			int sum = 0;
			while (true) {
				int second = -1;
				for (int i = 0; i < a.length; i++) {
					if (a[i].level < 2 && sum >= a[i].b) {
						second = i;
						break;
					}
				}
				if (second >= 0) {
					ans++;
					sum += 2 - a[second].level;
					a[second].level = 2;
					continue;
				}
				int first = -1;
				for (int i = 0; i < a.length; i++) {
					if (a[i].level < 1 && sum >= a[i].a) {
						first = i;
						break;
					}
				}
				if (first >= 0) {
					ans++;
					sum++;
					a[first].level++;
					continue;
				}
				break;
			}
			if (sum == 2 * n) {
				out.println(ans);
			} else {
				out.println("Too Bad");
			}
		}
	}

	class Level implements Comparable<Level> {

		public Level(int x, int y) {
			a = x;
			b = y;
			level = 0;
		}

		int a, b;
		int level;

		@Override
		public int compareTo(Level o) {
			return o.b - b;
		}
	}
}
