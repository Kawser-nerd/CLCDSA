import java.io.*;
import java.util.*;

public class D {

	static void solve() throws IOException {
		int t = nextInt();
		for (int currentTest = 0; currentTest < t; currentTest++) {
			int m = nextInt();
			int n = nextInt();
			String[] s = new String[m];
			for (int i = 0; i < m; i++) {
				s[i] = nextToken();
			}
			out.println("Case #" + (currentTest + 1) + ": " + solve(s, n));
		}
	}

	static String[] s;
	static int[] inSet;
	static int ans;
	static int count;

	static void go(int x, int sets, int m) {
		if (x == s.length) {
			if (sets != m)
				return;
			Set<String>[] z = new Set[m];
			for (int i = 0; i < m; i++) {
				z[i] = new HashSet<>();
			}
			for (int i = 0; i < s.length; i++) {
				for (int j = 0; j < s[i].length(); j++) {
					z[inSet[i]].add(s[i].substring(0, j + 1));
				}
			}
			int got = 0;
			for (int i = 0; i < m; i++) {
				got += z[i].size() + 1;
			}
			if (got > ans) {
				ans = got;
				count = 1;
			} else if (got == ans) {
				++count;
			}
			return;
		}
		for (int i = 0; i <= sets; i++) {
			if (i >= m)
				continue;
			inSet[x] = i;
			go(x + 1, Math.max(sets, i + 1), m);
		}
	}

	static String solve(String[] s_, int m) {
		s = s_;
		count = 0;
		ans = -1;
		inSet = new int[s.length];
		go(0, 0, m);
		final int MOD = 1000000007;
		for (int i = 1; i <= m; i++) {
			count = (int) ((long) count * i % MOD);
		}
		return ans + " " + count;
	}

	public static void main(String[] args) throws Exception {
		File file = new File("d.in");
		InputStream input = System.in;
		PrintStream output = System.out;
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream("d.out");
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static boolean hasNextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			st = new StringTokenizer(line);
		}
		return true;
	}

	static String nextToken() throws IOException {
		return hasNextToken() ? st.nextToken() : null;
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}
