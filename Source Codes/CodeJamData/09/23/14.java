import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	static final String filename = "C-small-attempt0";

	int[] dx = {-1, 1, 0, 0};
	int[] dy = {0, 0, -1, 1};
	
	static Comparator<String> cmp = new Comparator<String>() {
		public int compare(String o1, String o2) {
			if (o1.length() != o2.length()) {
				return o1.length() - o2.length();
			}
			return o1.compareTo(o2);
		}
	};
	
	static class Node implements Comparable<Node> {
		int x, y, val;
		String s;
		
		Node(int x, int y, int val, String s) {
			this.x = x;
			this.y = y;
			this.val = val;
			this.s = s;
		}

		public int compareTo(Node o) {
			return cmp.compare(s, o.s);
		}
	}
	
	public void solve(int test) throws IOException {
		out.println("Case #" + test + ": ");
		int n = nextInt();
		int m = nextInt();
		char[][] f = new char[n][];
		for (int i = 0; i < n; ++i) {
			f[i] = next().toCharArray();
		}
		String[][][] d = new String[n][n][501];
		PriorityQueue<Node> pq = new PriorityQueue<Node>();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (Character.isDigit(f[i][j])) {
					d[i][j][f[i][j] - '0' + 250] = "" + f[i][j];
					pq.add(new Node(i, j, f[i][j] - '0' + 250, "" + f[i][j]));
				}
			}
		}
		while (!pq.isEmpty()) {
			Node no = pq.poll();
			if (!d[no.x][no.y][no.val].equals(no.s)) {
				continue;
			}
			for (int d1 = 0; d1 < 4; ++d1) {
				int xs = no.x + dx[d1];
				int ys = no.y + dy[d1];
				if (xs < 0 || xs >= n || ys < 0 || ys >= n) {
					continue;
				}
				for (int d2 = 0; d2 < 4; ++d2) {
					int xd = xs + dx[d2];
					int yd = ys + dy[d2];
					if (xd < 0 || xd >= n || yd < 0 || yd >= n) {
						continue;
					}
					int v2 = no.val + (f[xd][yd] - '0') * (f[xs][ys] == '+' ? 1 : -1);
					if (v2 < 0 || v2 > 500) {
						continue;
					}
					String ss = no.s + f[xs][ys] + f[xd][yd];
					if (d[xd][yd][v2] == null || cmp.compare(d[xd][yd][v2], ss) > 0) {
						d[xd][yd][v2] = ss;
						pq.add(new Node(xd, yd, v2, ss));
					}
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			int q = nextInt() + 250;
			String best = null;
			for (int u = 0; u < n; ++u) {
				for (int v = 0; v < n; ++v) {
					if (d[u][v][q] != null && (best == null || cmp.compare(best, d[u][v][q]) > 0)) {
						best = d[u][v][q];
					}
				}
			}
			out.println(best);
		}
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
