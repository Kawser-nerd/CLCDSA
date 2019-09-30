import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution implements Runnable {
	private static final int MOD = 10007;
	int[] di = new int[] {2, 1};
	int[] dj = new int[] {1, 2};
	void solve() throws Exception {
		int tc = nextInt();
		for (int tt = 0; tt < tc; tt++) {
			int h = nextInt();
			int w = nextInt();
			int r = nextInt();
			boolean[][] rock = new boolean[h][w];
			for (int j = 0; j < r; j++) {
				int row = nextInt() - 1;
				int col = nextInt() - 1;
				rock[row][col] = true;
			}
			int[][] cnt = new int[h][w];
			cnt[0][0] = 1;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (rock[i][j]) {
						continue;
					}
					for (int k = 0; k < di.length; k++) {
						int ni = i + di[k];
						int nj = j + dj[k];
						if (ni < h && nj < w && !rock[ni][nj]) {
							cnt[ni][nj] += cnt[i][j];
							cnt[ni][nj] %= MOD;
						}
					}
				}
			}
			out.println("Case #" + (tt + 1) + ": " + cnt[h - 1][w - 1]);
		}
	}
	
	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new Thread(new Solution("d")).start();
	}

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	public Solution(String fname) throws IOException {
		in = new BufferedReader(new FileReader(fname + ".in"));
		st = new StringTokenizer("");
		out = new PrintWriter(new FileWriter(fname + ".out"));
	}
	
	
	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	
	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}
	
	public void run() {
		try {
			solve();
		} catch (Exception e) {
			apstenu(e);
		} finally {
			out.close();
		}
	}

	private void apstenu(Exception e) {
		e.printStackTrace();
		System.exit(1);
	}
	
}
