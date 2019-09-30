import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "B-large";
	
	int[] dx = {-1, 1, 0, 0};
	int[] dy = {0, 0, -1, 1};

	public void solve(int test) throws IOException {
		System.err.println(test);
		out.print("Case #" + (test + 1) + ": ");
		int h = nextInt();
		int n = nextInt();
		int m = nextInt();
		int[][] a = new int[n][m];
		int[][] b = new int[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				b[i][j] = nextInt();
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				a[i][j] = nextInt();
			}
		}
		int[][] mint = new int[n][m];
		for (int[] ar : mint) {
			Arrays.fill(ar, 2000000000);
		}
		mint[0][0] = 0;
		boolean[][] col = new boolean[n][m];
		while (true) {
			int i0 = -1, j0 = -1;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (!col[i][j] && (i0 == -1 || mint[i][j] < mint[i0][j0])) {
						i0 = i;
						j0 = j;
					}
				}
			}
			if (i0 == n - 1 && j0 == m - 1) {
				break;
			}
			col[i0][j0] = true;
			for (int d = 0; d < 4; ++d) {
				int i1 = i0 + dx[d];
				int j1 = j0 + dy[d];
				if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && Math.max(a[i0][j0], a[i1][j1]) + 50 <= b[i1][j1] && a[i1][j1] + 50 <= b[i0][j0] && 50 <= b[i1][j1]) {
					int dt = Math.max(mint[i0][j0], h - (b[i1][j1] - 50));
					if (dt > 0) {
						dt += Math.max(0, h - dt) >= a[i0][j0] + 20 ? 10 : 100;
					}
					mint[i1][j1] = Math.min(mint[i1][j1], dt);
				}
			}
		}
		out.println(mint[n - 1][m - 1] / 10.);
	}

	public void run() throws IOException {
		in = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(file + ".out");
		eat("");
		
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			solve(test);
		}
		
		out.close();
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
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}
