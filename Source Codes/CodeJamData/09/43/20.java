import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

public class Program implements Runnable{
	private static BufferedReader br;
	private static PrintWriter out;
	private static StringTokenizer stk;
	
	public static void main(String[] args) throws FileNotFoundException {
		br = new BufferedReader(new FileReader("D:\\C-large.in"));
		out = new PrintWriter(new File("D:\\C-out.txt"));
		(new Thread(new Program())).start();
	}
	
	private void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private String nextLine() {
		try {
			return br.readLine();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	private Integer nextInt() {
		while (stk==null||!stk.hasMoreTokens()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}
	
	private Long nextLong() {
		while (stk==null||!stk.hasMoreTokens()) loadLine();
		return Long.parseLong(stk.nextToken());
	}
	
	private Double nextDouble() {
		while (stk==null||!stk.hasMoreTokens()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}
	
	private String nextWord() {
		while (stk==null||!stk.hasMoreTokens()) loadLine();
		return stk.nextToken();
	}
	
	private boolean dfs(int v) {
		boolean res = false;
		if (v == 2*n+1) {
			return true;
		}
		used[v] = true;
		for (int i = 0; i < 2*n+2; ++i) {
			if (c[v][i] - f[v][i] > 0 && !used[i]) {
				prev[i] = v;
				res |= dfs(i);
			}
		}
		return res;
	}
	
	private int[] prev;
	private boolean[] used;
	int n;
	private int[][] c;
	private int[][] f;
	public void run() {
		int t = nextInt();
		for (int tt = 0; tt < t; ++tt) {
			n = nextInt();
			int k = nextInt();
			
			boolean[][] g = new boolean[n][n];
			int[][] pr = new int[n][k];
			
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < k; ++j) {
					pr[i][j] = nextInt();
				}
			}
			
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					boolean good = true;
					for (int l = 0; l < k; ++l) {
						if (pr[i][l] <= pr[j][l]) {
							good = false;
							break;
						}
					}
					g[i][j] = good;
				}
			}
			
			c = new int[2*(n+1)][2*n+2];
			f = new int[2*(n+1)][2*n+2];
			for (int i = 1; i <= n; ++i) {
				c[0][i] = 1;
				c[i][0] = 0;
				
			}
			
			for (int i = n+1; i < 2*(n+1)-1; ++i) {
				c[i][2*n+1] = 1;
				c[2*n+1][i] = 0;
			}
			
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (g[i][j]) {
						c[i+1][n+1+j] = 1;
					}
				}
			}
			prev = new int[2*n+2];
			Arrays.fill(prev, -1);
			used = new boolean[2*n+2];
			Arrays.fill(used, false);
			int res = 0;
			while (dfs(0)) {
				Arrays.fill(used, false);
				int pos = 2*n+1;
				while (prev[pos] != -1) {
					int p = prev[pos];
					++f[p][pos];
					f[pos][p] = -f[p][pos];
					pos = p;
				}
				++res;
			}
			out.println("Case #" + (tt+1) + ": " + (n-res));
		}
		out.flush();
	}
	
}
