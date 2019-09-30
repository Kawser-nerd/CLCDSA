import java.io.*;
import java.util.*;

public class GCJ17QualD {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.LARGE;
	static final int ATTEMPT_NUMBER = 1;

	boolean dfs(int v, int[] pair, boolean[][] g, boolean[] vis) {
		vis[v] = true;
		for (int u = 0; u < g[v].length; u++) {
			if (g[v][u]) {
				if (pair[u] == -1
						|| (!vis[pair[u]] && dfs(pair[u], pair, g, vis))) {
					pair[u] = v;
					return true;
				}
			}
		}
		return false;
	}

	int[] getMatching(boolean[][] g) {
		int n = g.length;
		int m = g[0].length;
		int[] pair = new int[m];

		Arrays.fill(pair, -1);

		boolean[] vis = new boolean[n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(vis, false);
			dfs(i, pair, g, vis);
		}
		return pair;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		
		HashSet<Integer> freeRow = new HashSet<>();
		HashSet<Integer> freeCol = new HashSet<>();
		
		for (int i = 0; i < n; i++) {
			freeRow.add(i);
			freeCol.add(i);
		}
		
		boolean[][] can = new boolean[2 * n - 1][2 * n - 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				can[i + j][i - j + n - 1] = true;
			}
		}
		
		int[][] was = new int[n][n];
		for (int i = 0; i < m; i++) {
			int type = "x+o".indexOf(nextToken().charAt(0)) + 1;
			int r = nextInt() - 1;
			int c = nextInt() - 1;
			was[r][c] = type;
			if ((type & 1) != 0) {
				freeRow.remove(r);
				freeCol.remove(c);
			}
			if ((type & 2) != 0) {
//				can[r + c][r - c + n - 1] = false;
				for (int j = 0; j < 2 * n - 1; j++) {
					can[r + c][j] = can[j][r - c + n - 1] = false;
				}
			}
		}
		
		int[][] ans = new int[n][];
		for (int i = 0; i < n; i++) {
			ans[i] = was[i].clone();
		}
		List<Integer> rs = new ArrayList(freeRow);
		List<Integer> cs = new ArrayList(freeCol);
		for (int i = 0; i < rs.size(); i++) {
			ans[rs.get(i)][cs.get(i)] |= 1;
		}
		
		int[] pair = getMatching(can);
		for (int i = 0; i < pair.length; i++) {
			if (pair[i] != -1) {
				int sum = pair[i];
				int diff = i - n + 1;
				
				int fst = (sum + diff) / 2;
				int snd = (sum - diff) / 2;
				
				ans[fst][snd] |= 2;
			}
		}
		
		int pts = 0;
		int changes = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				pts += Integer.bitCount(ans[i][j]);
				if (ans[i][j] != was[i][j]) {
					changes++;
				}
			}
		}
		
		out.println(pts + " " + changes);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ans[i][j] != was[i][j]) {
					out.println("!x+o".charAt(ans[i][j]) + " " + (i + 1) + " " + (j + 1));
				}
			}
		}
	}

	GCJ17QualD() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("GCJ17QualD-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("GCJ17QualD-small-attempt" + ATTEMPT_NUMBER
					+ ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("GCJ17QualD-large.in"));
			out = new PrintWriter("GCJ17QualD-large.out");
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
		new GCJ17QualD();
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