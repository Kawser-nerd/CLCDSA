import java.io.*;
import java.util.*;

public class Main {

	boolean dfs(int v, int[] pair, boolean[] vis, boolean[][] g) {
		vis[v] = true;
		for (int u = 0; u < g[v].length; u++) {
			if (!g[v][u]) {
				continue;
			}
			if (pair[u] == -1 || (!vis[pair[u]] && dfs(pair[u], pair, vis, g))) {
				pair[u] = v;
				return true;
			}
		}
		return false;
	}

	void submit() {
		 int n = nextInt();
		 int[] xs = new int[n];
		 for (int i = 0; i < n; i++) {
		 xs[i] = nextInt();
		 }

//		int n = 100;
//		int[] xs = new int[n];
//		for (int i = 0; i < n; i++) {
//			xs[i] = 2 * i + 1;
//		}

		TreeSet<Integer> init = new TreeSet<>();

		for (int i = 0; i < n; i++) {
			if (i == 0 || (xs[i - 1] != xs[i] - 1)) {
				init.add(xs[i] - 1);
			}
			if (i == n - 1 || (xs[i + 1] != xs[i] + 1)) {
				init.add(xs[i]);
			}
		}

		// System.err.println(init);

		boolean[] isPrime = new boolean[10_000_001];
		Arrays.fill(isPrime, true);
		isPrime[0] = isPrime[1] = false;

		for (int i = 2; i * i < isPrime.length; i++) {
			if (isPrime[i]) {
				for (int j = i * i; j < isPrime.length; j += i) {
					isPrime[j] = false;
				}
			}
		}

		List<Integer>[] byPar = new ArrayList[2];
		byPar[0] = new ArrayList<>();
		byPar[1] = new ArrayList<>();

		for (int x : init) {
			byPar[x % 2].add(x);
		}

		boolean[][] g = new boolean[byPar[0].size()][byPar[1].size()];
		for (int i = 0; i < byPar[0].size(); i++) {
			int x = byPar[0].get(i);
			for (int j = 0; j < byPar[1].size(); j++) {
				int y = byPar[1].get(j);

				g[i][j] = isPrime[Math.abs(x - y)];
			}
		}

		int[] pair = new int[byPar[1].size()];
		Arrays.fill(pair, -1);
		boolean[] vis = new boolean[byPar[0].size()];

		int match = 0;
		for (int i = 0; i < g.length; i++) {
			Arrays.fill(vis, false);
			if (dfs(i, pair, vis, g)) {
				match++;
			}
		}

		int part1 = byPar[0].size();
		int part2 = byPar[1].size();

		int ans = match + go(part1 - match, part2 - match);
		if (match > 0) {
			match--;
			ans = Math.min(ans, match + go(part1 - match, part2 - match));
		}

		out.println(ans);
	}

	int go(int x, int y) {
		if ((x % 2) != (y % 2)) {
			throw new AssertionError();
		}
		if (x % 2 == 0) {
			return x + y;
		} else {
			return x + y + 1;
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.