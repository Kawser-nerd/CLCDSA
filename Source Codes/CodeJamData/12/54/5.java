import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) {
		new D().run();
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

	String FNAME = "d";

	char[] chars = new char[] { 'o', 'i', ' ', 'e', 'a', 's', ' ', 't', 'b',
			'g' };

	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			int k = nextInt();
			char[] str = nextToken().toCharArray();
			Set<String> pairs = new HashSet<String>();
			for (int i = 0; i + 1 < str.length; i++) {
				char c11 = str[i];
				char c12 = getPair(str[i]);
				char c21 = str[i + 1];
				char c22 = getPair(str[i + 1]);
				pairs.add(c11 + "" + c21);
				pairs.add(c12 + "" + c21);
				pairs.add(c11 + "" + c22);
				pairs.add(c12 + "" + c22);
			}
			int n = pairs.size();
			char[][] p = new char[n][];
			n = 0;
			for (String s : pairs) {
				p[n++] = s.toCharArray();
			}
			a = new int[n][n];
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					if (i == j) {
						continue;
					}
					a[i][j] = p[i][1] == p[j][0] ? 1 : 0;
				}
			}
			pair = new int[n];
			Arrays.fill(pair, -1);
			u = new boolean[n];
			int ans = 0;
			for (int i = 0; i < u.length; i++) {
				Arrays.fill(u, false);
				if (dfs(i)) {
					ans++;
				}
			}
			if (ans == n) {
				ans--;
			}
			out.println(n * 2 - ans);
		}
	}

	int[][] a;
	int[] pair;
	boolean[] u;

	private boolean dfs(int x) {
		u[x] = true;
		for (int i = 0; i < a[x].length; i++) {
			if (a[x][i] > 0 && (pair[i] < 0 || !u[pair[i]] && dfs(pair[i]))) {
				pair[i] = x;
				return true;
			}
		}
		return false;
	}

	private char getPair(char c) {
		for (int j = 0; j < chars.length; j++) {
			if (chars[j] == c) {
				c = (char) ('0' + j);
			}
		}
		return c;
	}
}
