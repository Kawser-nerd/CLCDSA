import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.StringTokenizer;

public class C {
	String fn = "C-large";
	// String fn = "helper";
	// String fn = "C-small";
	Random rand = new Random(1);
	int MAXN = (int) 1e6;

	void solve2() throws IOException {
		// int a1 = nextInt();
		// int a2 = nextInt();
		// int b1 = nextInt();
		// int b2 = nextInt();
		// int a = rand.nextInt(MAXN) + 1;
		// tm = new HashMap<Long, Boolean>();
		// if (!play(a / 2, a)) {
		// throw new AssertionError();
		// }

		// int a1 = rand.nextInt(MAXN);
		// int a2 = a1 + rand.nextInt(MAXN);
		// int b1 = rand.nextInt(MAXN);
		// int b2 = b1 + rand.nextInt(MAXN);

		// int a1 = 1;
		// int a2 = 1000000;
		// int b1 = 1;
		// int b2 = 1000000;
		tm = new HashMap<Long, Boolean>();

		int a1 = nextInt();
		int a2 = nextInt();
		int b1 = nextInt();
		int b2 = nextInt();
		System.err.println(a1 + " " + a2 + " " + b1 + " " + b2);
		long time = System.currentTimeMillis();
		// solve(a1, a2, b1, b2);
		out.println(solve(a1, a2, b1, b2));
		System.err.println("time = " + (System.currentTimeMillis() - time));
		// System.err.println(naive(a1, a2, b1, b2));
		// out.flush();
	}

	long solve(int a1, int a2, int b1, int b2) {
		long res = 0;
		for (int a = a1; a <= a2; a++) {
			// if (a % 10000 == 0) {
			// System.err.println(a + " " + tm.size());
			// tm.clear();
			// }
			res += solve(a, b1, b2);
		}
		return res;
	}

	long solve(int a, int b1, int b2) {
		int L = LL[a];
		if (false) {
			int l = a / 2;
			int r = a;
			while (l < r - 1) {
				int m = (l + r) / 2;
				if (can(a, m)) {
					l = m;
				} else {
					r = m;
				}
			}
			L = l;
		}
		int R = RR[a];
		if (false) {
			int l = a;
			int r = 2 * a;
			while (l < r - 1) {
				int m = (l + r) / 2;
				if (!can(a, m)) {
					l = m;
				} else {
					r = m;
				}
			}
			R = r;
		}
		// helper file was generated here
		// out.println(L + " " + R);
		// out.flush();
		return cross(1, L, b1, b2) + cross(R, MAXN, b1, b2);
	}

	int cross(int a1, int a2, int b1, int b2) {
		int l = Math.max(a1, b1);
		int r = Math.min(a2, b2);
		if (l <= r) {
			return r - l + 1;
		} else {
			return 0;
		}
	}

	long naive(int a1, int a2, int b1, int b2) {
		long res = 0;
		for (int a = a1; a <= a2; a++) {
			boolean found = false;
			for (int b = b1; b <= b2; b++) {
				tm = new HashMap<Long, Boolean>();
				System.err.println(a + " " + b);
				if (play(a, b)) {
					// out.print("+");
					res++;
				} else {
					if (!found) {
						System.err.println(a + " " + b);
						found = true;
					}
					// out.print(".");
				}
			}
			// out.println();
		}
		return res;
	}

	long MUL = (long) 1e7;

	boolean can(int a, int b) {
		return play(a, b);
	}

	boolean play(int a, int b) {
		// System.err.println(a + " " + b);
		if (a <= 0 || b <= 0) {
			return true;
		}
		if (a == b)
			return false;
		long p = MUL * a + b;
		if (tm.containsKey(p)) {
			return tm.get(p);
		}
		boolean win = false;
		// for (int i = 1; a - b * i > 0; i++) {
		for (int i : new int[] { a / b, a / b - 1 }) {
			if (i <= 0)
				continue;
			if (!play(a - b * i, b)) {
				win = true;
				tm.put(p, win);
				return win;
			}
		}
		// for (int i = 1; b - a * i > 0; i++) {
		for (int i : new int[] { b / a, b / a - 1 }) {
			if (i <= 0)
				continue;
			if (!play(a, b - a * i)) {
				win = true;
				tm.put(p, win);
				return win;
			}
		}
		tm.put(p, win);
		return win;
	}

	Map<Long, Boolean> tm;

	void solve() throws IOException {
		// solve2();
		//		
		// // naive(1, 100, 1, 100);
		// if (true)
		// return;
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			System.err.println(i);
			out.print("Case #" + (i + 1) + ": ");
			solve2();
		}

	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	int[] LL, RR;

	public void run() {
		try {
			br = new BufferedReader(new FileReader("helper.out"));
			LL = new int[MAXN + 1];
			RR = new int[MAXN + 1];
			for (int i = 1; i < LL.length; i++) {
				LL[i] = nextInt();
				RR[i] = nextInt();
			}
			br.close();
			br = new BufferedReader(new FileReader(fn + ".in"));
			out = new PrintWriter(fn + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(123);
		}
	}

	String nextToken() {
		try {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
			}
		} catch (Exception e) {
			e.printStackTrace();
			throw new AssertionError();
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	public static void main(String[] args) {
		new C().run();
	}
}