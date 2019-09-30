import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		SAMPLE, SMALL, LARGE;
	}

	static final InputType currentInputType = InputType.LARGE;
	static final int attemptNumber = 0; // for small inputs only

	static final String DIRS = "^>v<";
	static final int[] DX = { -1, 0, 1, 0 };
	static final int[] DY = { 0, 1, 0, -1 };
	
	boolean outside(char[][] f, int x, int y, int dir) {
		int dx = DX[dir];
		int dy = DY[dir];
		int r = f.length;
		int c = f[0].length;
		x += dx;
		y += dy;
		while (x >= 0 && x < r && y >= 0 && y < c && f[x][y] == '.') {
			x += dx;
			y += dy;
		}
		if (x >= 0 && x < r && y >= 0 && y < c) {
			return false;
		}
		return true;
	}

	void solve() throws IOException {
		int r = nextInt();
		int c = nextInt();
		char[][] f = new char[r][];
		for (int i = 0; i < r; i++) {
			f[i] = nextToken().toCharArray();
		}
		
		int ans = 0;
		
		for (int i = 0; i < r; i++)
			outer: for (int j = 0; j < c; j++) {
				int d = DIRS.indexOf(f[i][j]);
				if (d == -1) {
					continue;
				}
				if (outside(f, i, j, d)) {
					ans++;
					for (d = 0; d < 4; d++) {
						if (!outside(f, i, j, d)) {
							continue outer;
						}
					}
					out.println("IMPOSSIBLE");
					return;
				}
			}
		out.println(ans);
	}

	void inp() throws IOException {
		switch (currentInputType) {
		case SAMPLE:
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		case SMALL:
			String fileName = "A-small-attempt" + attemptNumber;
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			break;
		case LARGE:
			fileName = "A-large";
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			break;
		}
		int test = nextInt();
		for (int i = 1; i <= test; i++) {
			System.err.println("Running test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A().inp();
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
		} catch (Exception e) {
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
}
