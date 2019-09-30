import java.io.*;
import java.util.*;

public class SolB2 implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolB2()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof;

	@Override
	public void run() {
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	String FNAME = "B-large";

	double eps = 1e-9;

	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			System.err.println(test);
			int r = nextInt();
			int c = nextInt();
			int d = nextInt();
			int[][] tab = new int[r][c];
			for (int i = 0; i < r; i++) {
				char[] ch = nextToken().toCharArray();
				for (int j = 0; j < c; j++) {
					tab[i][j] = ch[j] - '0';
				}
			}
			int ans = 0;
			for (int k = 3; k <= r && k <= c; k++) {
				int[][] sumd = new int[r][c];
				for (int i = r - 1; i >= 0; i--) {
					for (int j = 0; j < c; j++) {
						sumd[i][j] = tab[i][j];
						if (i < r - 1) {
							sumd[i][j] += sumd[i + 1][j];
						}
						if (i + k < r) {
							sumd[i][j] -= tab[i + k][j];
						}
					}
				}
				int[][] sumr = new int[r][c];
				for (int j = c - 1; j >= 0; j--) {
					for (int i = 0; i < r; i++) {
						sumr[i][j] = tab[i][j];
						if (j < c - 1) {
							sumr[i][j] += sumr[i][j + 1];
						}
						if (j + k < c) {
							sumr[i][j] -= tab[i][j + k];
						}
					}
				}
				boolean[][] bad = new boolean[r][c];
				for (int i = 0; i + k <= r; i++) {
					double dx = 0;
					double sum = 0;
					for (int j = 0; j < k; j++) {
						dx += sumd[i][j] * (j - (k - 1) / 2.0);
						sum += sumd[i][j];
					}
					for (int j = 0; j + k <= c; j++) {
						double ddx = dx
								+ (tab[i][j] + tab[i + k - 1][j])
								* ((k - 1) / 2.0)
								- (tab[i][j + k - 1] + tab[i + k - 1][j + k - 1])
								* ((k - 1) / 2.0);
						if (Math.abs(ddx) > eps) {
							bad[i][j] = true;
						}
						dx += sumd[i][j] * (k - 1) / 2.0;
						sum -= sumd[i][j];
						dx -= sum;
						if (j + k < c) {
							dx += sumd[i][j + k] * (k - 1) / 2.0;
							sum += sumd[i][j + k];
						}
					}
				}
				for (int j = 0; j + k <= c; j++) {
					double dy = 0;
					double sum = 0;
					for (int i = 0; i < k; i++) {
						dy += sumr[i][j] * (i - (k - 1) / 2.0);
						sum += sumr[i][j];
					}
					for (int i = 0; i + k <= r; i++) {
						double ddy = dy
								+ (tab[i][j] + tab[i][j + k - 1])
								* ((k - 1) / 2.0)
								- (tab[i + k - 1][j] + tab[i + k - 1][j + k - 1])
								* ((k - 1) / 2.0);
						if (Math.abs(ddy) > eps) {
							bad[i][j] = true;
						}
						dy += sumr[i][j] * (k - 1) / 2.0;
						sum -= sumr[i][j];
						dy -= sum;
						if (i + k < r) {
							dy += sumr[i + k][j] * (k - 1) / 2.0;
							sum += sumr[i + k][j];
						}
					}
				}
				for (int i = 0; i + k <= r; i++) {
					for (int j = 0; j + k <= c; j++) {
						if (!bad[i][j]) {
							ans = k;
						}
					}
				}
			}
			out.print("Case #" + test + ": ");
			if (ans == 0) {
				out.println("IMPOSSIBLE");
			} else {
				out.println(ans);
			}
		}
	}
}