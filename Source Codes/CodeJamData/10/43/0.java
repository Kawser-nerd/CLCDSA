import java.io.*;
import java.util.*;

public class Solution {
	
	final String f = "C-large";
//	final String f = "C-small-attempt1";
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private int minSum;
	private int maxx;
	private int maxy;
	
	static class Rect implements Comparable<Rect> {
		int x1, y1, x2, y2;

		public Rect(int x1, int y1, int x2, int y2) {
			super();
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
		}

		public int compareTo(Rect o) {
			if (x1 == o.x1) {
				return y1 - o.y1;
			}
			return x1 - o.x1;
		}
		
		boolean isects(Rect o) {
			return !(x2 < o.x1 || o.x2 < x1 || y2 < o.y1 || o.y2 < y1);
		}
		
		boolean sisects(Rect o) {
			return isects(o) && (x2 != o.x1 || y2 != o.y1) && (o.x2 != x1 || o.y2 != y1);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		ArrayList<Rect> rs = new ArrayList<Rect>();
		for (int i = 0; i < n; ++i) {
			rs.add(new Rect(nextInt(), nextInt(), nextInt() + 1, nextInt() + 1));
		}
//		boolean[][] g = new boolean[101][101];
//		for (Rect r : rs) {
//			for (int i = r.x1; i < r.x2; ++i) {
//				for (int j = r.y1; j < r.y2; ++j) {
//					g[i][j] = true;
//				}
//			}
//		}
//		int ans0;
//		for (int t = 0; ; ++t) {
//			boolean empty = true;
//			for (int i = g.length - 1; i > 0; --i) {
//				for (int j = g[0].length - 1; j > 0; --j) {
//					if (g[i][j]) {
//						empty = false;
//						if (!g[i - 1][j] && !g[i][j - 1]) {
//							g[i][j] = false;
//						}
//					}
//					if (g[i - 1][j] && g[i][j - 1]) {
//						g[i][j] = true;
//					}
//				}
//			}
//			if (empty) {
//				System.out.println(t);
//				ans0 = t;
//				break;
//			}
//		}
		int ans = 0;
		boolean[] col = new boolean[rs.size()];
		for (int i = 0; i < rs.size(); ++i) {
			if (!col[i]) {
				minSum = 1000000000;
				maxx = -1000000000;
				maxy = -1000000000;
				dfs(i, rs, col);
				ans = Math.max(ans, maxx + maxy - minSum + 1);
			}
		}
//		if (ans != ans0) {
//			throw new AssertionError(ans + " != " + ans0);
//		}
		out.println(ans);
	}

	private void dfs(int i, ArrayList<Rect> rs, boolean[] col) {
		if (col[i]) {
			return;
		}
		col[i] = true;
		Rect u = rs.get(i);
		minSum = Math.min(minSum, u.x1 + u.y1);
		maxx = Math.max(maxx, u.x2 - 1);
		maxy = Math.max(maxy, u.y2 - 1);
		for (int j = 0; j < rs.size(); ++j) {
			if (u.sisects(rs.get(j))) {
				dfs(j, rs, col);
			}
		}
	}

	Solution() throws IOException {
		in = new BufferedReader(new FileReader(f + ".in"));
		out = new PrintWriter(f + ".out");
		
		eat("");
		
		Random rnd = new Random();
		int tests = nextInt();
//		int tests = 10000;
		for (int test = 0; test < tests; ++test) {
			System.out.println("Test #" + (test + 1));
			out.print("Case #" + (test + 1) + ": ");
			
//			int n = 10;
//			StringBuilder sb = new StringBuilder();
//			sb.append(n + "\n");
//			for (int i = 0; i < n; ++i) {
//				int x1 = rnd.nextInt(25) + 1;
//				int x2 = rnd.nextInt(25) + 1;
//				int y1 = rnd.nextInt(25) + 1;
//				int y2 = rnd.nextInt(25) + 1;
//				if (x1 > x2) {
//					int tmp = x1;
//					x1 = x2;
//					x2 = tmp;
//				}
//				if (y1 > y2) {
//					int tmp = y1;
//					y1 = y2;
//					y2 = tmp;
//				}
//				sb.append(x1 + " "  + y1 + " " + x2 + " " + y2 + "\n");
//			}
//			System.out.println(sb);
//			eat(sb.toString());
			
			solve();
		}
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
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

	public static void main(String[] args) throws IOException {
		new Solution();
	}
}
