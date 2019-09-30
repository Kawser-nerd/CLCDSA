import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "D-small-attempt1";
	
	char[][] a;
	
	static class Segment {
		int x, y0, y1;

		public Segment(int x, int y0, int y1) {
			this.x = x;
			this.y0 = y0;
			this.y1 = y1;
		}
	}

	public void solve() throws IOException {
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			out.printf("Case #%d: ", test + 1);
			int n = nextInt();
			int m = nextInt();
			a = new char[n][];
			int[] xs = new int[10];
			int[] ys = new int[10];
			int cs = 0;
			for (int i = 0; i < n; ++i) {
				a[i] = next().toCharArray();
				for (int j = 0; j < m; ++j) {
					if (Character.isDigit(a[i][j])) {
						xs[a[i][j] - '0'] = i;
						ys[a[i][j] - '0'] = j;
						cs++;
					}
				}
			}
			out.println();
			for (int i = 0; i < cs; ++i) {
				boolean[][] col = new boolean[n][m];
				int count = dfs1(xs[i], ys[i], col);
				List<Segment> segs = new ArrayList<Segment>();
				int[][] sId = new int[n][m];
				for (int x = 0; x < n; ++x) {
					Arrays.fill(sId[x], -1);
					for (int y = 0; y < m; ++y) {
						if (col[x][y]) {
							int y1 = y;
							while (col[x][y1 + 1]) {
								sId[x][y1++] = segs.size();
							}
							sId[x][y1] = segs.size();
							segs.add(new Segment(x, y, y1));
							y = y1;
						}
					}
				}
				boolean[] mask = new boolean[segs.size()];
				Arrays.fill(mask, true);
				boolean lucky = lucky(segs, mask, sId);
				out.println(i + ": " + count + " " + (lucky ? "Lucky" : "Unlucky"));
			}
		}
	}
	
	int count(boolean[] mask) {
		int count = 0;
		for (int i = 0; i < mask.length; ++i) {
			if (mask[i]) {
				count++;
			}
		}
		return count;
	}
	
	int count2(List<Segment> segs, boolean[] mask) {
		int count = 0;
		for (int i = 0; i < mask.length; ++i) {
			if (mask[i]) {
				count += a.length - segs.get(i).x;
			}
		}
		return count;
	}

	private boolean lucky(List<Segment> segs, boolean[] mask, int[][] sId) {
		if (count(mask) == 1) {
			return true;
		}
		int count = count2(segs, mask);
		loop: for (int dy = 0; dy < a[0].length; ++dy) {
			boolean[] newMask = new boolean[segs.size()];
			for (int u = 0; u < segs.size(); ++u) {
				if (!mask[u]) {
					continue;
				}
				Segment s = segs.get(u);
				int y = Math.min(s.y0 + dy, s.y1);
				if (a[s.x + 1][y] == '#') {
					newMask[u] = true;
				} else {
					if (sId[s.x + 1][y] == -1) {
						continue loop;
					} else {
						newMask[sId[s.x + 1][y]] = true;
					}
				}
			}
			if (count2(segs, newMask) < count) {
				return lucky(segs, newMask, sId);
			}
		}
		loop: for (int dy = 0; dy < a[0].length; ++dy) {
			boolean[] newMask = new boolean[segs.size()];
			for (int u = 0; u < segs.size(); ++u) {
				if (!mask[u]) {
					continue;
				}
				Segment s = segs.get(u);
				int y = Math.max(s.y1 - dy, s.y0);
				if (a[s.x + 1][y] == '#') {
					newMask[u] = true;
				} else {
					if (sId[s.x + 1][y] == -1) {
						continue loop;
					} else {
						newMask[sId[s.x + 1][y]] = true;
					}
				}
			}
			if (count2(segs, newMask) < count) {
				return lucky(segs, newMask, sId);
			}
		}
//		System.err.println(Arrays.toString(mask));
		return false;
	}

	private int dfs1(int i, int j, boolean[][] col) {
		if (col[i][j]) {
			return 0;
		}
		col[i][j] = true;
		int r = 1;
		if (a[i][j - 1] != '#') {
			r += dfs1(i, j - 1, col);
		}
		if (a[i][j + 1] != '#') {
			r += dfs1(i, j + 1, col);
		}
		if (a[i - 1][j] != '#') {
			r += dfs1(i - 1, j, col);
		}
		return r;
	}

	public void run() throws IOException {
		in = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(file + ".out");
		eat("");
		
		solve();
		
		out.close();
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
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}