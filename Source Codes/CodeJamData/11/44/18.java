import java.io.*;
import java.util.*;

public class SolD implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolD()).start();
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
				st = new StringTokenizer(br.readLine(), ", \n\t");
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

	String FNAME = "D-small-attempt2";
	
	ArrayList<Integer>[] G;
	
	boolean[] good;
	int[][] d;
	int n;
	
	void dfs(int i) {
		good[i] = true;
		for (int j : G[i]) {
			if (!good[j] && d[0][j] == d[0][i] - 1) {
				dfs(j);
			}
		}
	}
	
	int[] cnt;
	boolean[] used;
	
	int bt(int i) {
		if (i == 1) {
			int res = 1;
			for (int j = 0; j < n; j++) {
				if (!used[j] && cnt[j] > 0) {
					res++;
				}
			}
			return res;
		}
		int ret = 0;
		for (int j : G[i]) {
			if (good[j] && d[0][j] == d[0][i] + 1) {
				if (j == 1) {
					int res = 0;
					for (int k = 0; k < n; k++) {
						if (!used[k] && cnt[k] > 0) {
							res++;
						}
					}
					return res;
				}
				used[j] = true;
				for (int k : G[j]) {
					cnt[k]++;
				}
				ret = Math.max(ret, bt(j));
				for (int k : G[j]) {
					cnt[k]--;
				}
				used[j] = false;
			}
		}
		return ret;
	}

	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			System.err.println(test);
			n = nextInt();
			G = new ArrayList[n];
			boolean[][] tab = new boolean[n][n];
			d = new int[n][n];
			for (int i = 0; i < n; i++) {
				G[i] = new ArrayList<Integer>();
				Arrays.fill(d[i], Integer.MAX_VALUE / 2);
				d[i][i] = 0;
			}
			int m = nextInt();
			
			for (int i = 0; i < m; i++) {
				int a = nextInt();
				int b = nextInt();
				G[a].add(b);
				G[b].add(a);
				tab[a][b] = true;
				tab[b][a] = true;
				d[a][b] = 1;
				d[b][a] = 1;
			}
			for (int k = 0; k < n; k++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}
			good = new boolean[n];
			dfs(1);
			cnt = new int[n];
			used = new boolean[n];
			for (int i : G[0]) {
				cnt[i]++;
			}
			used[0] = true;
			int ans = bt(0);
			out.println(d[0][1] - 1 + " " + ans);
		}
	}
}