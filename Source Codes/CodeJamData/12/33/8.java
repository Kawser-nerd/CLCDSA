import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution implements Runnable {
	
	private static final int MAXT = 100;
	
	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private int n;
	private int m;
	private long[] ac;
	private int[] at;
	private long[] bc;
	private int[] bt;
	
	private long calcAnswer() {
		long[][] asum = new long[n + 1][MAXT];
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < MAXT; j++) {
				asum[i][j] = asum[i - 1][j];
			}
			asum[i][at[i - 1]] += ac[i - 1];
		}
		long[][] bsum = new long[m + 1][MAXT];
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < MAXT; j++) {
				bsum[i][j] = bsum[i - 1][j];
			}
			bsum[i][bt[i - 1]] += bc[i - 1];
		}
		long[][] answer = new long[n + 1][m + 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int ii = i + 1; ii <= n; ii++) {
					for (int jj = j + 1; jj <= m; jj++) {
						if (at[ii - 1] == bt[jj - 1]) {
							int t = at[ii - 1];
							long aval = asum[ii][t] - asum[i][t];
							long bval = bsum[jj][t] - bsum[j][t];
							long val = Math.min(aval, bval);
							answer[ii][jj] = Math.max(answer[ii][jj], answer[i][j] + val);
						}
					}
				}
			}
		}
		long maxAns = 0;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				maxAns = Math.max(maxAns, answer[i][j]);
			}
		}
		return maxAns;
	}
	
	private void solve() throws IOException {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			System.out.println(test);
			n = nextInt();
			m = nextInt();
			ac = new long[n];
			at = new int[n];
			for (int i = 0; i < n; i++) {
				ac[i] = nextLong();
				at[i] = nextInt() - 1;
			}
			bc = new long[m];
			bt = new int[m];
			for (int i = 0; i < m; i++) {
				bc[i] = nextLong();
				bt[i] = nextInt() - 1;
			}
			long answer = calcAnswer();
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
	
	private long nextLong() throws IOException {
		return Long.parseLong(next());
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
