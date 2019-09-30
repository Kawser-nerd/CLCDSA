import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	static class Pos {
		int x, y, rx, ry, rd, bx, by, bd;
		
		Pos(int x, int y, int rx, int ry, int rd, int bx, int by, int bd) {
			this.x = x;
			this.y = y;
			this.rx = rx;
			this.bx = bx;
			this.ry = ry;
			this.by = by;
			this.rd = rd;
			this.bd = bd;
		}
		
		public int hashCode() {
			return Arrays.hashCode(ar());
		}

		private int[] ar() {
			return new int[] {x, y, rx, ry, rd, bx, by, bd};
		}
		
		public boolean equals(Object obj) {
			return Arrays.equals(ar(), ((Pos)obj).ar());
		}
	}
	
	static class Pair implements Comparable<Pair> {
		Pos p;
		int dist;
		
		Pair(Pos p, int dist) {
			this.p = p;
			this.dist = dist;
		}

		public int compareTo(Pair o) {
			return dist - o.dist;
		}
	}
	
	int[] dx = {-1, 1, 0, 0};
	int[] dy = {0, 0, -1, 1};
	
	private void solve() throws IOException {
		int tests = nextInt();
		loop: for (int test = 0; test < tests; ++test) {
			int n = nextInt();
			int m = nextInt();
			int sx = -1, sy = -1;
			int tx = -1, ty = -1;
			boolean[][] f = new boolean[n][m];
			for (int i = 0; i < n; ++i) {
				char[] tmp = next().toCharArray();
				for (int j = 0; j < m; ++j) {
					f[i][j] = tmp[j] == '#';
					if (tmp[j] == 'O') {
						sx = i;
						sy = j;
					}
					if (tmp[j] == 'X') {
						tx = i;
						ty = j;
					}
				}
			}
			PriorityQueue<Pair> q = new PriorityQueue<Pair>();
			HashSet<Pos> col = new HashSet<Pos>();
			q.add(new Pair(new Pos(sx, sy, -1, -1, -1, -1, -1, -1), 0));
			while (!q.isEmpty()) {
				Pair x = q.remove();
				if (col.contains(x.p)) {
					continue;
				}
				if (x.p.x == tx && x.p.y == ty) {
					out.println("Case #" + (test + 1) + ": " + x.dist);
					continue loop;
				}
				col.add(x.p);
				for (int d = 0; d < 4; ++d) {
					int xx = x.p.x + dx[d];
					int yy = x.p.y + dy[d];
					if (xx < 0 || xx >= n || yy < 0 || yy >= m || f[xx][yy]) {
						if (x.p.bd == d && xx == x.p.bx && yy == x.p.by && x.p.rd != -1) {
							q.add(new Pair(new Pos(x.p.rx - dx[x.p.rd], x.p.ry - dy[x.p.rd], x.p.rx, x.p.ry, x.p.rd, x.p.bx, x.p.by, x.p.bd), x.dist + 1));
						}
						if (x.p.rd == d && xx == x.p.rx && yy == x.p.ry && x.p.bd != -1) {
							q.add(new Pair(new Pos(x.p.bx - dx[x.p.bd], x.p.by - dy[x.p.bd], x.p.rx, x.p.ry, x.p.rd, x.p.bx, x.p.by, x.p.bd), x.dist + 1));
						}
					} else {
						q.add(new Pair(new Pos(xx, yy, x.p.rx, x.p.ry, x.p.rd, x.p.bx, x.p.by, x.p.bd), x.dist + 1));
					}
					while (xx >= 0 && xx < n && yy >= 0 && yy < m && !f[xx][yy]) {
						xx += dx[d];
						yy += dy[d];
					}
					q.add(new Pair(new Pos(x.p.x, x.p.y, xx, yy, d, x.p.bx, x.p.by, x.p.bd), x.dist));
					q.add(new Pair(new Pos(x.p.x, x.p.y, x.p.rx, x.p.ry, x.p.rd, xx, yy, d), x.dist));
				}
			}
			out.println("Case #" + (test + 1) + ": THE CAKE IS A LIE");
		}
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			st = new StringTokenizer("");
			out = new PrintWriter(System.out);
			
			solve();
			
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
			System.exit(-1);
		}
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	public static void main(String[] args) {
		new Thread(new Solution()).start();
	}

	private void ass(boolean b) {
		if (!b) {
			throw new RuntimeException("Assertion failed");
		}
	}
	
	static final boolean Ъ = true;
}