import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.LARGE;
	static final int ATTEMPT_NUMBER = 0;

	static final int[] DX = { -1, 0, 1, 0 };
	static final int[] DY = { 0, -1, 0, 1 };

	int r, c;
	char[][] f;

	int getNewDir(int wasDir, char c) {
		if (c == '/') {
			return wasDir ^ 3;
		}
		if (c == '\\') {
			return wasDir ^ 1;
		}
		return wasDir;
	}

	int[][] trace(int x0, int y0, int dirType) {
		int[][] ret = new int[r][c];
		for (int d0 = dirType; d0 < 4; d0 += 2) {

			int x = x0;
			int y = y0;
			int dir = d0;

			boolean isFirst = true;

			while (true) {
				if (f[x][y] == '#') {
					break;
				}
				int bit = dir & 1;
				if (!isFirst && test(ret[x][y], bit)) {
					break;
				}
				if (f[x][y] == '.' || f[x][y] == '*') {
					ret[x][y] |= 1 << bit;
				}
				isFirst = false;
				dir = getNewDir(dir, f[x][y]);
				x += DX[dir];
				y += DY[dir];
			}
		}
		return ret;
	}

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}
	
	void solve() throws IOException {
		r = nextInt();
		c = nextInt();

		f = new char[r + 2][c + 2];
		for (int i = 0; i < r + 2; i++) {
			Arrays.fill(f[i], '#');
		}
		
		for (int i = 1; i <= r; i++) {
			String tmp = nextToken();
			for (int j = 1; j <= c; j++) {
				f[i][j] = tmp.charAt(j - 1);
				if (f[i][j] == '-' || f[i][j] == '|') {
					f[i][j] = '*';
				}
			}
		}
		
		realSolve(r + 2, c + 2, f);
	}

	void realSolve(int r, int c, char[][] f) throws IOException {
		this.r = r;
		this.c = c;
		this.f = f;
		int[][] varId = new int[r][c];
		for (int i = 0; i < r; i++) {
			Arrays.fill(varId[i], -1);
		}
		int vars = 0;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (f[i][j] == '*') {
					varId[i][j] = vars++;
				}
			}
		}

		TwoSAT sat = new TwoSAT(vars);

		boolean[][] seen = new boolean[2][vars];

		int[][][] whoEmpty = new int[2][r][c];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < r; j++) {
				Arrays.fill(whoEmpty[i][j], -1);
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {

				if (f[i][j] == '*') {
					int var = varId[i][j];
					for (int type = 0; type < 2; type++) {
						if (seen[type][var]) {
							continue;
						}
						int[][] vis = trace(i, j, type);
						
//						System.err.println(type + " " + i + " " + j);
//						for (int x = 0; x < r; x++) {
//							System.err.println(Arrays.toString(vis[x]));
//						}
//						System.err.println();

						int[] now = new int[vars];
						int ptr = 0;

						for (int x = 0; x < r; x++) {
							for (int y = 0; y < c; y++) {
								if (f[x][y] == '*' && vis[x][y] == 3) {
									out.println("IMPOSSIBLE");
									return;
								}
								if (varId[x][y] != -1 && vis[x][y] != 0) {
									seen[vis[x][y] - 1][varId[x][y]] = true;
									now[ptr++] = 2 * varId[x][y]
											+ (vis[x][y] - 1);
								}
							}
						}

						if (ptr == 0) {
							throw new AssertionError();
						}

						if (ptr > 1) {
							for (int ii = 0; ii < ptr; ii++) {
								sat.add(now[ii] ^ 1, now[ii] ^ 1);
							}
						} else {
							for (int x = 0; x < r; x++) {
								for (int y = 0; y < c; y++) {
									if (f[x][y] == '.' && vis[x][y] != 0) {
										
										if (test(vis[x][y], 0)) {
											if (whoEmpty[0][x][y] != -1) {
												throw new AssertionError();
											}
											whoEmpty[0][x][y] = now[0];
										}
										
										if (test(vis[x][y], 1)) {
											if (whoEmpty[1][x][y] != -1) {
												throw new AssertionError();
											}
											whoEmpty[1][x][y] = now[0];
										}
										
									}
								}
							}

						}

					}

				}

			}
		}
		
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (f[i][j] == '.') {
					
					int who0 = whoEmpty[0][i][j];
					int who1 = whoEmpty[1][i][j];
					
					if (who0 == -1 && who1 == -1) {
						out.println("IMPOSSIBLE");
						return;
					}
					
					if (who0 == -1) {
						sat.add(who1, who1);
					} else if (who1 == -1) {
						sat.add(who0, who0);
					} else {
						sat.add(who0, who1);
					}
					
				}
			}
		}

		boolean[] ans = sat.solve();
		if (ans == null) {
			out.println("IMPOSSIBLE");
		} else {
			out.println("POSSIBLE");
			
//			out.println("input");
//			for (int i = 1; i < r - 1; i++) {
//				for (int j = 1; j < c - 1; j++) {
//					out.print(f[i][j]);
//				}
//				out.println();
//			}
			
//			out.println("output");
			for (int i = 1; i < r - 1; i++) {
				for (int j = 1; j < c - 1; j++) {
					if (f[i][j] != '*') {
						out.print(f[i][j]);
					} else {
						out.print(ans[varId[i][j]] ? '|' : '-');
					}
				}
				out.println();
//				out.flush();
			}
		}

	}
	
	static final Random rng = new Random();
	static final int B = 6;
	
	void test() {
		for (int tst = 0;;tst++) {
			int r = 3 + rng.nextInt(B);
			int c = 3 + rng.nextInt(B);
			char[][] f = new char[r][c];
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
						f[i][j] = '#';
					} else {
						String tmp = "/\\*.";
						f[i][j] = tmp.charAt(rng.nextInt(tmp.length()));
					}
				}
			}
			try {
				realSolve(r, c, f);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	C() throws IOException {
		
//		out = new PrintWriter(System.out);
//		test();
		
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("C-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("C-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("C-large.in"));
			out = new PrintWriter("C-large.out");
			break;
		}
		}
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println("Test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static class TwoSAT {
		int n;

		List<Integer>[] g;
		List<Integer>[] gRev;

		/**
		 * 
		 * @param n
		 *            - numbers of variables
		 */
		public TwoSAT(int n) {
			this.n = n;
			g = new List[2 * n];
			gRev = new List[2 * n];
			for (int i = 0; i < 2 * n; i++) {
				g[i] = new ArrayList<>();
				gRev[i] = new ArrayList<>();
			}
			order = new int[2 * n];
			color = new int[2 * n];
			ptr = 2 * n;
		}

		/**
		 * 2x - x-th variable 2x + 1 - negation of x-th variable
		 */
		void add(int v, int u) {
			g[v ^ 1].add(u);
			gRev[u].add(v ^ 1);
			g[u ^ 1].add(v);
			gRev[v].add(u ^ 1);
		}

		private int[] order;
		private int ptr;
		private int[] color;

		private void dfs1(int v) {
			color[v] = -1;
			for (int u : g[v]) {
				if (color[u] == 0) {
					dfs1(u);
				}
			}
			order[--ptr] = v;
		}

		private void dfs2(int v) {
			color[v] = ptr;
			for (int u : gRev[v]) {
				if (color[u] == -1) {
					dfs2(u);
				}
			}
		}

		boolean[] solve() {
			for (int i = 0; i < 2 * n; i++) {
				if (color[i] == 0) {
					dfs1(i);
				}
			}
			ptr = 0;
			for (int v : order) {
				if (color[v] == -1) {
					dfs2(v);
					ptr++;
				}
			}

			boolean[] ret = new boolean[n];

			for (int i = 0; i < 2 * n; i += 2) {
				if (color[i] == color[i ^ 1]) {
					return null;
				}
				ret[i >> 1] = color[i] > color[i ^ 1];
			}

			return ret;
		}

	}

}