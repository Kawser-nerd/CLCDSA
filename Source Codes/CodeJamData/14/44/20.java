import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "D";
//	final String filename = problem + "-sample";
//	 final String filename = problem + "-small-attempt0";
//	 final String filename = problem + "-small-attempt2";
	 final String filename= problem+"-large";

	String[] s;
	int N;

	public int lcm(int num1, int num2) {
		if (num1 < 0 || num2 < 0)
			return 0;
		if (cache[num1][num2] >= 0) {
			return cache[num1][num2];
		}
		int j;
		for (j = 0; j < s[num1].length() && j < s[num2].length(); j++)
			if (s[num1].charAt(j) != s[num2].charAt(j)) {
				break;
			}
		cache[num1][num2] = j;
		return j;
	}

	long MOD = 1000000007;

	int[][] cache;
	long[][] C;
	long[] fact, rev;

	public void solve() throws Exception {
		int M = iread();
		N = iread();
		s = new String[M];
		for (int i = 0; i < M; i++)
			s[i] = readword();
		cache = new int[M][M];
		for (int i = 0; i < M; i++)
			Arrays.fill(cache[i], -1);
		Arrays.sort(s);

		root = new Trie();
		for (int i = 0; i < M; i++) {
			Trie cur = root;
			cur.leafs++;
			for (int j = 0; j < s[i].length(); j++) {
				int d = s[i].charAt(j) - 'A';
				if (cur.next[d] == null) {
					cur.next[d] = new Trie();
				}
				cur = cur.next[d];
				cur.leafs++;
			}
			cur.leaf = true;
		}

		fact = new long[N + 1];
		rev = new long[N + 1];
		fact[0] = rev[0] = 1;
		for (int i = 1; i <= N; i++) {
			fact[i] = (fact[i - 1] * i) % MOD;
			rev[i] = inv(fact[i]);
		}

		Table table = dfs(root);

		int ans = table.ans[N];
		long res = table.res[N];
//		dummy();
//		if (dummy_ans != ans || dummy_res != res) {
//			System.out.println("BUG");
//		}

		out.write(ans + " " + res);
		// out.write(dummy_ans + " " + dummy_res);
	}

	long inv(long x) {
		long k = MOD - 2;
		long ans = 1;
		while (k > 0) {
			if (k % 2 == 1)
				ans = (ans * x) % MOD;
			k /= 2;
			x = (x * x) % MOD;
		}
		return ans;
	}

	public Table dfs(Trie t) {
		int n1 = t.leaf ? 1 : 0;
		Table table = new Table(n1);
		table.res[n1] = 1;
		for (int d = 0; d < 26; d++) {
			Trie nxt = t.next[d];
			if (nxt == null)
				continue;
			int n2 = Math.min(nxt.leafs, N);
			Table table2 = dfs(nxt);
			int n3 = Math.min(n1 + n2, N);
			Table table3 = new Table(n3);
			for (int i1 = 0; i1 <= n1; i1++)
				if (table.res[i1] != 0)
					for (int i2 = 0; i2 <= n2; i2++)
						if (table2.res[i2] != 0) {
							for (int j = 0; j <= i1 && j <= i2; j++) {
								int ans3 = table.ans[i1] + table2.ans[i2];
								int i3 = i1 + i2 - j;
								if (i3 > N || ans3 < table3.ans[i3])
									continue;
								long r1 = (table.res[i1] * table2.res[i2])
										% MOD;
								
								r1 = (r1*rev[i2])%MOD;
								
								r1 = (r1 * fact[i1]) % MOD;
								r1 = (r1 * rev[j]) % MOD;
								r1 = (r1 * rev[i1-j]) % MOD;
								
								r1 = (r1 * fact[i2]) % MOD;
//								r1 = (r1 * rev[j]) % MOD;
								r1 = (r1 * rev[i2-j]) % MOD;
								
								r1 = (r1 * fact[i3] % MOD);
								r1 = (r1 * rev[i1] % MOD);

								if (ans3 > table3.ans[i3]) {
									table3.res[i3] = r1;
									table3.ans[i3] = ans3;
								} else
									table3.res[i3] = (table3.res[i3] + r1)
											% MOD;
							}
						}
			table = table3;
			n1 = n3;
		}
		for (int i = 0; i <= n1; i++)
			table.ans[i] += i;
		return table;
	}

	class Table {
		int[] ans;
		long[] res;

		public Table(int N) {
			ans = new int[N + 1];
			res = new long[N + 1];
		}
	}

	public void dummy() {
		test = new int[s.length];
		dummy_ans = dummy_res = 0;
		rec(0);
	}

	Trie root;

	int[] test;
	int dummy_ans;
	int dummy_res;

	public void rec(int m) {
		if (m < s.length) {
			for (int i = 0; i < N; i++) {
				test[m] = i;
				rec(m + 1);
			}
			return;
		}
		cycle: for (int i = 0; i < N; i++) {
			for (int j = 0; j < s.length; j++)
				if (test[j] == i) {
					continue cycle;
				}
			return;
		}
		int ans = N;
		int[] test2 = new int[N];
		Arrays.fill(test2, -1);
		for (int i = 0; i < s.length; i++) {
			int k = test[i];
			ans += s[i].length() - lcm(i, test2[k]);
			test2[k] = i;
		}
		if (ans > dummy_ans) {
			dummy_ans = ans;
			dummy_res = 1;
		} else if (ans == dummy_ans)
			dummy_res++;
	}

	class Trie {
		Trie[] next = new Trie[26];
		int leafs;
		boolean leaf;
	}

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			solve();
			out.write("\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new BufferedWriter(new FileWriter(filename + ".out"));
			solve_gcj();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {

		}
		new Thread(new Main()).start();
		// new Thread(null, new Main(), "1", 1<<25).start();
	}
}