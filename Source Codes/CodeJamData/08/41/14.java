import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution implements Runnable {

	private static final int INF = (int) 1e9;
	int[][] a;
	boolean[][] have;
	
	int[] type;
	int[] val;
	boolean[] change;
	
	int calc(int node, int value) {
		if (have[node][value]) {
			return a[node][value];
		}
		if (type[node] == 1) {
			if (value == val[node]) {
				return 0;
			} else {
				return INF;
			}
		}
		if (change[node] == false) {
			int ans = INF;
			if (val[node] == 0) { // OR
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						if ((i | j) == value) {
							ans = Math.min(ans, calc(2 * node, i) + calc(2 * node + 1, j));
						}
					}
				}
			} else { // AND
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						if ((i & j) == value) {
							ans = Math.min(ans, calc(2 * node, i) + calc(2 * node + 1, j));
						}
					}
				}
			}
			have[node][value] = true;
			a[node][value] = ans;
			return ans;
		} else {
			int ans = INF;
			{ // OR
				int toAdd = 0;
				if (val[node] == 1) {
					toAdd = 1;
				}
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						if ((i | j) == value) {
							ans = Math.min(ans, calc(2 * node, i) + calc(2 * node + 1, j) + toAdd);
						}
					}
				}
			}
			{ // AND
				int toAdd = 0;
				if (val[node] == 0) {
					toAdd = 1;
				}
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						if ((i & j) == value) {
							ans = Math.min(ans, calc(2 * node, i) + calc(2 * node + 1, j) + toAdd);
						}
					}
				}
			}
			have[node][value] = true;
			a[node][value] = ans;
			return ans;
		}
	}
	
	void solve() throws Exception {
		int tc = nextInt();
		for (int tt = 0; tt < tc; tt++) {
			out.print("Case #" + (tt + 1) + ": ");
			int m = nextInt();
			int v = nextInt();
			
			type = new int[m + 1];
			val = new int[m + 1];
			change = new boolean[m + 1];
			
			int nn = 1;
			for (int i = 0; i < (m - 1) / 2; i++) {
				int g = nextInt();
				int c = nextInt();
				if (c == 1) {
					change[nn] = true;
				}
				val[nn] = g;
				type[nn] = 0;
				nn++;
			}
			
			for (int i = 0; i < (m + 1) / 2; i++) {
				val[nn] = nextInt();
				type[nn] = 1;
				nn++;
			}
			
			a = new int[m + 1][2];
			have = new boolean[m + 1][2];
			int ans = calc(1, v);
			if (ans == INF) {
				out.println("IMPOSSIBLE");
			} else {
				out.println(ans);
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new Thread(new Solution("a")).start();
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
