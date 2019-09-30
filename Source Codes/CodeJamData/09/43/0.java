import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	private int[] dx;
	private int[] dy;
	private boolean[] col;
	private boolean[][] g;
	
	static final String filename = "C-large";

	public void solve(int test) throws IOException {
		out.print("Case #" + test + ": ");
		int n = nextInt();
		int k = nextInt();
		int[][] a = new int[n][k];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < k; ++j) {
				a[i][j] = nextInt();
			}
		}
		g = new boolean[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				g[i][j] = true;
				for (int t = 0; t < k; ++t) {
					g[i][j] &= a[i][t] < a[j][t];
				}
			}
		}
		dx = new int[n];
		dy = new int[n];
		Arrays.fill(dx, -1);
		Arrays.fill(dy, -1);
		int matching = 0;
		for (int i = 0; i < n; ++i) {
			col = new boolean[n];
			if (dfs(i)) {
				++matching;
			}
		}
		out.println(n - matching);
	}
	
	private boolean dfs(int i) {
		if (i == -1) {
			return true;
		}
		if (col[i]) {
			return false;
		}
		col[i] = true;
		for (int j = 0; j < g.length; ++j) {
			if (g[i][j] && dx[i] != j && dfs(dy[j])) {
				dx[i] = j;
				dy[j] = i;
				return true;
			}
		}
		return false;
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new PrintWriter(filename + ".out");
			eat("");
			
			int tests = nextInt();
			for (int test = 0; test < tests; ++test) {
				solve(test + 1);
			}
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		} catch (OutOfMemoryError er) {
			List<int[]> x = new ArrayList<int[]>();
			while (true) {
				x.add(new int[100000]);
			}
		}
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Thread(new Solution()).start();
	}
	
}
