import java.io.*;
import java.util.*;

public class D2 {
	FastScanner in;
	PrintWriter out;

	int n;
	long ans;
	final static int MOD = (int) 1e9 + 7;
	final static int MAX = 1001;
	static long[][] c = new long[MAX][MAX];

	static {
		for (int i = 0; i < MAX; i++) {
			c[i][0] = 1;
			if (i != 0)
				for (int j = 1; j < MAX; j++)
					c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}

	class V {
		V[] next;
		boolean endHere;
		int cnt;

		V() {
			next = new V[26];
		}

		void add(String s, int from) {
			cnt++;
			if (s.length() == from) {
				endHere = true;
				return;
			}
			char c = s.charAt(from);
			if (next[c - 'A'] == null) {
				next[c - 'A'] = new V();
			}
			next[c - 'A'].add(s, from + 1);
		}

		long go() {
			int curCnt = Math.min(n, cnt);
			ans += curCnt;
			int[] cnt1 = new int[curCnt + 1];
			int[] cnt2 = new int[curCnt + 1];
			if (endHere) {
				cnt1[1] = cnt1.length - 1;
			} else {
				cnt1[0] = 1;
			}
			long res = 1;
			for (int i = 0; i < 26; i++) {
				V ne = next[i];
				if (ne == null)
					continue;
				res = (res * ne.go()) % MOD;
				Arrays.fill(cnt2, 0);
				int there = Math.min(n, ne.cnt);
				for (int was = 0; was < cnt1.length; was++)
					if (cnt1[was] != 0)
						for (int inWas = 0; inWas <= Math.min(was, there); inWas++) {
							int outThere = there - inWas;
							if (outThere <= cnt1.length - was - 1) {
								long add = (c[was][inWas] * c[cnt1.length - 1
										- was][outThere])
										% MOD;
								add = (add * cnt1[was]) % MOD;
								cnt2[was + outThere] += add;
								if (cnt2[was + outThere] >= MOD)
									cnt2[was + outThere] -= MOD;
							}
						}
				int[] tmp = cnt1;
				cnt1 = cnt2;
				cnt2 = tmp;
			}
			return (res * cnt1[cnt1.length - 1]) % MOD;
		}
	}

	void solveTestCase() {
		int m = in.nextInt();
		n = in.nextInt();
		String[] s = new String[m];
		for (int i = 0; i < m; i++) {
			s[i] = "A" + in.next();
		}
		V root = new V();
		for (int i = 0; i < m; i++) {
			root.add(s[i], 0);
		}
		root.cnt = n;
		ans = 0L;
		long cnt = root.go();
		ans -= Math.min(n, root.cnt);
		out.println(ans + " " + cnt);
	}

	void solve() {
		int testNumber = in.nextInt();
		for (int test = 1; test <= testNumber; test++) {
			System.err.println(test);
			out.print("Case #" + test + ": ");
			solveTestCase();
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("D.in"));
			out = new PrintWriter(new File("D2.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new D2().run();
	}
}
