import java.util.*;
import java.io.*;

public class Solution {

	final String filename = "E-small-attempt0";
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	private HashMap<String, Integer> map;
	private ArrayList<Integer> ts;
	private boolean[] col;
	private boolean[][] g;
	private boolean[][] g2;

	private void solve(int test) throws IOException {
		System.out.println("Test: " + test);
		out.print("Case #" + test + ": ");
		int n = nextInt();
		map = new HashMap<String, Integer>();
		int[] a = new int[2 * n];
		for (int i = 0; i < 2 * n; ++i) {
			a[i] = name(next());
		}
		int[] u = new int[n];
		int[] v = new int[n];
		Arrays.fill(u, -1);
		for (int i = 0; i < 2 * n; ++i) {
			if (u[a[i]] == -1) {
				u[a[i]] = i;
			} else {
				v[a[i]] = i;
			}
		}
		g = new boolean[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (u[i] < u[j] && v[j] < v[i]) {
					g[i][j] = true;
				}
			}
		}
		ts = new ArrayList<Integer>();
		col = new boolean[n];
		for (int i = 0; i < n; ++i) {
			tsdfs(i);
		}
		g2 = new boolean[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!(v[i] < u[j] || v[j] < u[i]) && !g[i][j] && !g[j][i]) {
					g2[i][j] = g2[j][i] = true;
				}
			}
		}
//		System.out.println(Arrays.deepToString(g));
//		System.out.println(Arrays.deepToString(g2));
		int ans1 = n + 1;
		loop: for (int mask = 0; mask < 1 << n; ++mask) {
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					if (get(mask, i) == get(mask, j) && g2[i][j]) {
						continue loop;
					}
				}
			}
			int[] count0s = new int[n];
			int[] count1s = new int[n];
			int cur0 = 0;
			int cur1 = 0;
			for (int it = 0; it < n; ++it) {
				int i = ts.get(it);
				for (int jt = 0; jt < i; ++jt) {
					int j = ts.get(jt);
					if (g[j][i]) {
						count0s[i] = Math.max(count0s[i], count0s[j]);
						count1s[i] = Math.max(count1s[i], count1s[j]);
					}
				}
				if (get(mask, i)) {
					count1s[i]++;
				} else {
					count0s[i]++;
				}
				cur0 = Math.max(cur0, count0s[i]);
				cur1 = Math.max(cur1, count1s[i]);
			}
//			System.out.println(cur0 + " " + cur1);
			ans1 = Math.min(ans1, cur0 + cur1);
		}
		out.println(ans1 == n + 1 ? -1 : ans1);
	}
	
	private boolean get(int mask, int i) {
		return (mask & (1 << i)) != 0;
	}

	private void tsdfs(int i) {
		if (col[i]) {
			return;
		}
		col[i] = true;
		for (int j = 0; j < g.length; ++j) {
			if (g[j][i]) {
				tsdfs(j);
			}
		}
		ts.add(i);
	}

	private int name(String next) {
		if (!map.containsKey(next)) {
			map.put(next, map.size());
		}
		return map.get(next);
	}

	Solution() {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new PrintWriter(filename + ".out");
			eat("");
			
			int tests = nextInt();
			for (int test = 1; test <= tests; ++test) {
				solve(test);
			}
			
			in.close();
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
			System.exit(-1);
		}
	}
	
	private void eat(String string) {
		st = new StringTokenizer(string);
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
		new Solution();
	}
	
}
