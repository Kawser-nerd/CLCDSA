import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	private boolean[][] g;
	private int[] p;
	
	static final String filename = "C-large";

	public void solve(int test) throws IOException {
		System.out.println("Case #" + test + ": ");
		out.print("Case #" + test + ": ");
		int n = nextInt();
		if (n == 0) {
			throw new AssertionError();
		}
		final int[] x = new int[n];
		int[] y = new int[n];
		Integer[] inds = new Integer[n];
		for (int i = 0; i < n; ++i) {
			x[i] = nextInt();
			y[i] = nextInt();
			inds[i] = i;
		}
		Arrays.sort(inds, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				if (o1 != o2 && x[o1] == x[o2]) {
					throw new AssertionError();
				}
				return x[o2] - x[o1];
			}
		});
		g = new boolean[n][n];
		int[] yId = new int[32];
		Arrays.fill(yId, -1);
		boolean oneColorable = true;
		for (int i : inds) {
			for (int yy = y[i] - 1; yy <= y[i] + 1; ++yy) {
				if (yId[yy] != -1) {
					g[i][yId[yy]] = g[yId[yy]][i] = true;
					oneColorable = false;
				}
			}
			yId[y[i]] = i;
		}
		if (oneColorable) {
			out.println(1);
			return;
		}
		boolean twoColorable = true;
		boolean[] col = new boolean[n], set = new boolean[n];
		for (int i = 0; i < n; ++i) {
			if (!set[i] && !dfs(i, col, set, false)) {
				twoColorable = false;
				break;
			}
		}
		if (twoColorable) {
			out.println(2);
			return;
		}
		boolean threeColorable = true;
		boolean[][] col2 = new boolean[n][n];
		p = new int[n];
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
		loop: for (int i = 0; i < n; ++i) {
			if (g[i][i]) {
				throw new AssertionError();
			}
			for (int j = 0; j < n; ++j) {
				if (g[i][j] && !col2[i][j]) {
					int[] color = new int[n];
					Arrays.fill(color, -1);
					color[i] = 0;
					color[j] = 1;
					if (!dfs2(i, j, color, col2)) {
						threeColorable = false;
						break loop;
					}
//					System.out.println(Arrays.toString(color));
					int last = -1;
					for (int t = 0; t < n; ++t) {
						if (color[t] != -1) {
							if (last == -1) {
								last = t;
							} else {
								if (get(t) == get(last)) {
									throw new AssertionError();
								}
								unite(t, last);
							}
						}
					}
				}
			}
		}
		out.println(threeColorable ? 3 : 4);
	}
	
	private int get(int i) {
		if (p[i] != i) {
			p[i] = get(p[i]);
		}
		return p[i];
	}
	
	void unite(int i, int j) {
		p[get(i)] = get(j);
	}

	private boolean dfs2(int i, int j, int[] color, boolean[][] col2) {
		if (col2[i][j]) {
			return true;
		}
		if (color[i] == -1 || color[j] == -1) {
			throw new AssertionError();
		}
		if (color[i] == color[j]) {
			return false;
		}
		col2[i][j] = col2[j][i] = true;
		for (int t = 0; t < g.length; ++t) {
			if (g[i][t] && color[i] == color[t]) {
				return false;
			}
			if (g[j][t] && color[j] == color[t]) {
				return false;
			}
			if (g[i][t] && g[j][t]) {
				if (color[t] == -1) {
					color[t] = 3 - color[i] - color[j];
				}
				if (color[t] != 3 - color[i] - color[j]) {
					return false;
				}
				if (!dfs2(i, t, color, col2) || !dfs2(j, t, color, col2)) {
					return false;
				}
			}
		}
		return true;
	}

	private boolean dfs(int i, boolean[] col, boolean[] set, boolean cur) {
		if (set[i]) {
			return col[i] == cur;
		}
		set[i] = true;
		col[i] = cur;
		for (int j = 0; j < g.length; ++j) {
			if (g[i][j] && !dfs(j, col, set, !cur)) {
				return false;
			}
		}
		return true;
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new PrintWriter(filename + ".out");
			eat("");
			
//			Random rnd = new Random();
//			while (rnd != null) {
//				StringBuilder sb = new StringBuilder();
//				int n = 6;
//				sb.append(n).append("\n");
//				for (int i = 0; i < n; ++i) {
//					sb.append(i + " " + (rnd.nextInt(5) + 1)).append("\n");
//				}
//				eat(sb.toString());
//				try {
//					solve(0);
//				} catch (AssertionError e) {
//					System.out.println(sb);
//					break;
//				}
//			}
			
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
