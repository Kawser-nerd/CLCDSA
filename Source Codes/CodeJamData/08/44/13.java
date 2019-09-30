import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution implements Runnable {

	private static final int INF = (int) 1e9;
	
	void solve() throws Exception {
		int tc = nextInt();
		for (int tt = 0; tt < tc; tt++) {
			out.print("Case #" + (tt + 1) + ": ");
			int k = nextInt();
			String t = nextToken();
			int n = t.length();
			char[][] s = new char[n / k][k];
			for (int i = 0; i < n / k; i++) {
				int beg = i * k;
				for (int j = 0; j < k; j++) {
					s[i][j] = t.charAt(beg + j);
				}
			}
			n = n / k;
			
			int[] cnt = new int[1 << k];
			int[][][] a = new int[1 << k][k][k];
			for (int[][] b : a) {
				for (int[] c : b) {
					Arrays.fill(c, INF);
				}
			}
			for (int l = 0; l < k; l++) {
				for (int r = 0; r < k; r++) {
					if (l == r) {
						continue;
					}
					int cur = 0;
					for (int i = 1; i < n; i++) {
						if (s[i - 1][r] != s[i][l]) {
							cur++;
						}
					}
					if (k == 2) {
						for (int i = 0; i < n; i++) {
							if (s[i][l] != s[i][r]) {
								cur++;
							}
						}
					}
					int ss = (1 << l) | (1 << r);
					cnt[ss] = 2;
					a[ss][l][r] = cur;
				}
			}
			
			int[][] sum = new int[k][k];
			for (int i = 0; i < k; i++) {
				for (int j = 0; j < k; j++) {
					for (int l = 0; l < n; l++) {
						if (s[l][i] != s[l][j]) {
							sum[i][j]++;
						}
					}
				}
			}
			
			for (int mask = 0; mask < (1 << k); mask++) {
				for (int l = 0; l < k; l++) {
					for (int r = 0; r < k; r++) {
						if (a[mask][l][r] == INF) {
							continue;
						}
						for (int l1 = 0; l1 < k; l1++) {
							if ((mask & (1 << l1)) != 0) {
								continue;
							}
							for (int r1 = 0; r1 < k; r1++) {
								if ((mask & (1 << r1)) != 0) {
									continue;
								}
								if (l1 == r1 && cnt[mask] != k - 1) {
									continue;
								}
								int nMask = mask | (1 << r1) | (1 << l1);
								if (l1 == r1) {
									cnt[nMask] = cnt[mask] + 1;
								} else {
									cnt[nMask] = cnt[mask] + 2;
								}
								int cur = a[mask][l][r];
								cur += sum[l][l1];
								cur += sum[r][r1];
								if (cnt[mask] == k - 2) {
									cur += sum[l1][r1];
								}
								a[nMask][l1][r1] = Math.min(a[nMask][l1][r1], cur);
							}
						}
					}
				}
			}
			int ans = INF;
			for (int l = 0; l < k; l++) {
				for (int r = 0; r < k; r++) {
					if (l == r && k % 2 == 0) {
						continue;
					}
					ans = Math.min(ans, a[(1 << k) - 1][l][r]);
				}
			}
			System.out.println(tt);
			out.println(ans + 1);
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
