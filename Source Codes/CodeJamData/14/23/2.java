import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.LARGE;
	static final int ATTEMPT_NUMBER = 0;

	static class City implements Comparable<City>{
		int code;
		int id;
		
		public City(int code, int id) {
			this.code = code;
			this.id = id;
		}

		@Override
		public int compareTo(City o) {
			return Integer.compare(code, o.code);
		}
		
	}
	
	boolean[][] g;
	boolean[] vis;
	int n;
	
	int dfs(int v, Set<Integer> bad) {
		vis[v] = true;
		int ret = 1;
		for (int to = 0; to < n; to++) {
			if (g[v][to] && !vis[to] && !bad.contains(to)) {
				ret += dfs(to, bad);
			}
		}
		return ret;
	}
	
	boolean can(int[] seq, int size) {
		Set<Integer> bad = new HashSet<>();
		List<Integer> stack = new ArrayList<>();
		stack.add(seq[0]);
		outer: for (int i = 1; i < size; i++) {
			int next = seq[i];
			while (!stack.isEmpty()) {
				int v = stack.get(stack.size() - 1);
				if (g[v][next]) {
					stack.add(next);
					continue outer;
				}
				bad.add(stack.remove(stack.size() - 1));
			}
			if (stack.isEmpty()) {
				return false;
			}
		}
		
		Arrays.fill(vis, false);
		int reach = dfs(seq[0], bad);
		return reach == n - bad.size();
	}

	void solve() throws IOException {
		n = nextInt();
		int m = nextInt();
		
		City[] a = new City[n];
		for (int i = 0; i < n; i++) {
			a[i] = new City(nextInt(), i);
		}
		
		Arrays.sort(a);
		int[] newId = new int[n];
		for (int i = 0; i < n; i++) {
			newId[a[i].id] = i;
		}
		
		g = new boolean[n][n];
		for (int i = 0; i < m; i++) {
			int v1 = newId[nextInt() - 1];
			int v2 = newId[nextInt() - 1];
			// System.err.println(v1 + " " + v2);
			g[v1][v2] = g[v2][v1] = true;
		}
		
		vis = new boolean[n];
		int[] ans = new int[n];
		boolean[] used = new boolean[n];
		outer: for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!used[j]) {
					used[j] = true;
					ans[i] = j;
					if (can(ans, i + 1)) {
						continue outer;
					}
					used[j] = false;
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			out.print(a[ans[i]].code);
		}
		out.println();
		
	}

	C() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("C-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("C-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("C-large.in"));
			out = new PrintWriter("C-large.out");
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
		new C();
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