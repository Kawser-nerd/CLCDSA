import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.LARGE;
	static final int ATTEMPT_NUMBER = 0;

	int[] gen(int s0, int as, int cs, int rs, int n) {
		int[] ret = new int[n];
		ret[0] = s0;
		for (int i = 1; i < n; i++) {
			long tmp = ((long) ret[i - 1] * as + cs) % rs;
			ret[i] = (int) tmp;
		}
		return ret;
	}

	List<Integer>[] g;

	boolean[] active;
	boolean[] reachable;
	int[] p;

	int reach;

	int dfs(int v) {
		reachable[v] = true;
		int ret = 1;
		for (int to : g[v]) {
			if (active[to]) {
				ret += dfs(to);
			}
		}
		return ret;
	}

	void add(int v) {
		active[v] = true;
		if (v == 0 || reachable[p[v]]) {
			reach += dfs(v);
		}
	}
	
	int dfs2(int v) {
		int ret = 1;
		reachable[v] = false;
		for (int to : g[v]) {
			if (reachable[to]) {
				ret += dfs2(to);
			}
		}
		return ret;
	}

	void remove(int v) {
		active[v] = false;
		if (reachable[v]) {
			reach -= dfs2(v);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int d = nextInt();
		int s0 = nextInt();
		int as = nextInt();
		int cs = nextInt();
		int rs = nextInt();

		int m0 = nextInt();
		int am = nextInt();
		int cm = nextInt();
		int rm = nextInt();

		final int[] s = gen(s0, as, cs, rs, n);
		p = gen(m0, am, cm, rm, n);

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(1);
		}

		for (int i = 1; i < n; i++) {
			p[i] %= i;
			g[p[i]].add(i);
		}

		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}
		Arrays.sort(order,
				(Integer a, Integer b) -> Integer.compare(s[a], s[b]));

		reach = 0;
		active = new boolean[n];
		reachable = new boolean[n];
		
		int ans = 0;

		for (int i = 0, j = 0; i < n; i++) {
			while (j < n && s[order[j]] - s[order[i]] <= d) {
				add(order[j]);
				j++;
			}
			ans = Math.max(ans, reach);
			remove(order[i]);
		}

		out.println(ans);
	}

	A() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("A-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("A-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("A-large.in"));
			out = new PrintWriter("A-large.out");
			break;
		}
		}
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println("Test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}