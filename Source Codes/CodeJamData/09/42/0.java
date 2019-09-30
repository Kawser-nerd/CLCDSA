import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	private int n;
	private int m;
	private int d;
	private char[][] f;
	
	static final String filename = "B-large";

	public void solve(int test) throws IOException {
		System.out.println(test);
		out.print("Case #" + test + ": ");
		n = nextInt();
		m = nextInt();
		d = nextInt();
		f = new char[n][];
		for (int i = 0; i < n; ++i) {
			f[i] = next().toCharArray();
		}
		boolean[][] canFall = new boolean[n][m];
		int[][] fall = new int[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				fall[i][j] = i;
				while (fall[i][j] < n - 1 && f[fall[i][j] + 1][j] == '.') {
					++fall[i][j];
				}
				canFall[i][j] = fall[i][j] - i < d;
			}
		}
		int[][][][] d = new int[n][m][m][m + 1];
		for (int[][][] arrr : d) {
			for (int[][] arr : arrr) {
				for (int[] ar : arr) {
					Arrays.fill(ar, Integer.MAX_VALUE);
				}
			}
		}
		d[0][0][0][0] = 0;
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < m; ++j) {
				for (int l = 0; l <= j; ++l) {
					for (int r = j; r <= m; ++r) {
						if (d[i][j][l][r] == Integer.MAX_VALUE) {
							continue;
						}
						int u = j;
						int v = j;
						while (u > 0 && f[i + 1][u - 1] == '#' && (f[i][u - 1] == '.' || u - 1 >= l && u - 1 < r)) {
							--u;
						}
						while (v < m - 1 && f[i + 1][v + 1] == '#' && (f[i][v + 1] == '.' || v + 1 >= l && v + 1 < r)) {
							++v;
						}
						for (int l1 = u; l1 <= v; ++l1) {
							for (int r1 = l1 + 1; r1 <= v + 1; ++r1) {
								if (l1 == u && r1 == v + 1) {
									continue;
								}
								if (canFall[i + 1][l1]) {
									if (fall[i + 1][l1] == i + 1) {
										d[i + 1][l1][l1][r1] =
											Math.min(d[i + 1][l1][l1][r1], d[i][j][l][r] + (r1 - l1));
									} else {
										d[fall[i + 1][l1]][l1][l1][l1] =
											Math.min(d[fall[i + 1][l1]][l1][l1][l1], d[i][j][l][r] + (r1 - l1));
									}
								}
								if (canFall[i + 1][r1 - 1]) {
									if (fall[i + 1][r1 - 1] == i + 1) {
										d[i + 1][r1 - 1][l1][r1] =
											Math.min(d[i + 1][r1 - 1][l1][r1], d[i][j][l][r] + (r1 - l1));
									} else {
										d[fall[i + 1][r1 - 1]][r1 - 1][r1 - 1][r1 - 1] =
											Math.min(d[fall[i + 1][r1 - 1]][r1 - 1][r1 - 1][r1 - 1], d[i][j][l][r] + (r1 - l1));
									}
								}
							}
						}
						if (u > 0 && (f[i][u - 1] == '.' || u - 1 >= l && u - 1 < r) && canFall[i + 1][u - 1]) {
							d[fall[i + 1][u - 1]][u - 1][u - 1][u - 1] =
								Math.min(d[fall[i + 1][u - 1]][u - 1][u - 1][u - 1], d[i][j][l][r]);
						}
						if (v < m - 1 && (f[i][v + 1] == '.' || v + 1 >= l && v + 1 < r) && canFall[i + 1][v + 1]) {
							d[fall[i + 1][v + 1]][v + 1][v + 1][v + 1] =
								Math.min(d[fall[i + 1][v + 1]][v + 1][v + 1][v + 1], d[i][j][l][r]);
						}
					}
				}
			}
		}
		int ans = Integer.MAX_VALUE;
		for (int j = 0; j < m; ++j) {
			for (int l = 0; l < m; ++l) {
				for (int r = l; r <= m; ++r) {
					ans = Math.min(ans, d[n - 1][j][l][r]);
				}
			}
		}
		out.println(ans == Integer.MAX_VALUE ? "No" : "Yes " + ans);
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
