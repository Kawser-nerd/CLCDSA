import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution implements Runnable {
	
	private static final String YES = "Yes";
	private static final String NO = "No";
	
	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private String solve(int[][] g) {
		int n = g.length;
		int m = (g.length + 31) / 32;
		int[][] a = new int[n][m];
		boolean[] was = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (go(i, g, was, a)) {
				return YES;
			}
		}
		return NO;
	}

	private boolean go(int u, int[][] g, boolean[] was, int[][] a) {
		if (was[u]) {
			return false;
		}
		for (int i = 0; i < g[u].length; i++) {
			int v = g[u][i];
			if (go(v, g, was, a)) {
				return true;
			}
			for (int j = 0; j < a[u].length; j++) {
				if ((a[u][j] & a[v][j]) != 0) {
					return true;
				}
				a[u][j] |= a[v][j];
			}
		}
		int dd = u / 32;
		int rr = u % 32;
		a[u][dd] |= (1 << rr);
		was[u] = true;
		return false;
	}

	private void solve() throws IOException {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			int n = nextInt();
			int[][] g = new int[n][];
			for (int i = 0; i < n; i++) {
				int m = nextInt();
				g[i] = new int[m];
				for (int j = 0; j < m; j++) {
					g[i][j] = nextInt() - 1;
				}
			}
			String answer = solve(g);
			out.println("Case #" + test + ": " + answer);
		}
	}
	
	

	@Override
	public void run() {
		try {
			solve();
		} catch (Throwable e) {
			apstenu(e);
		} finally {
			out.close();
		}
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	private void apstenu(Throwable e) {
		e.printStackTrace();
		System.exit(1);
	}
	
	public Solution(String filename) {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(filename + ".out"));
		} catch (IOException e) {
			apstenu(e);
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Solution("data").run();
	}
	
}
