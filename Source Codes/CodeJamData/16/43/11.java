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

	static final InputType INPUT_TYPE = InputType.SMALL;
	static final int ATTEMPT_NUMBER = 0;

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	static final int[] DX = { -1, 0, 1, 0 };
	static final int[] DY = { 0, -1, 0, 1 };

	int[] trace(int r, int c, int x, int y, boolean[][] f, int dir) {
		while (x >= 0 && x < r && y >= 0 && y < c) {
			if (f[x][y]) {
				dir ^= 1;
			} else {
				dir ^= 3;
			}
			x += DX[dir];
			y += DY[dir];
		}
		return new int[] { x, y };
	}
	
	int decode(int x, int y, int r, int c) {
		if (x == -1) {
			return y;
		}
		if (y == c) {
			return x + c;
		}
		if (x == r) {
			return r + c + (c - 1 - y);
		}
		if (y == -1) {
			return r + 2 * c + (r - 1 - x);
		}
		throw new AssertionError();
	}

	int[] go(int mask, int r, int c) {

		int[] ret = new int[2 * (r + c)];
		boolean[][] f = new boolean[r][c];
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				f[i][j] = test(mask, i * c + j);
			}

		for (int i = 0; i < c; i++) {
			int x = 0;
			int y = i;

			int[] tmp = trace(r, c, x, y, f, 2);

			ret[i] = decode(tmp[0], tmp[1], r, c);
		}
		
		for (int i = c; i < c + r; i++) {
			int x = i - c;
			int y = c - 1;
			int[] tmp = trace(r, c, x, y, f, 1);
			
			ret[i] = decode(tmp[0], tmp[1], r, c);
		}
		
		for (int i = c + r; i < 2 * c + r; i++) {
			int x = r - 1;
			int y = c - 1 - (i - c - r);
			
			int[] tmp = trace(r, c, x, y, f, 0);
			
			ret[i] = decode(tmp[0], tmp[1], r, c);
		}
		
		for (int i = 2 * c + r; i < 2 * c + 2 * r; i++) {
			int x = r - 1 - (i - 2 * c - r);
			int y = 0;
			
			int[] tmp = trace(r, c, x, y, f, 3);
			
			ret[i] = decode(tmp[0], tmp[1], r, c);
		}
		
		for (int i = 0; i < 2 * (r + c); i++) {
			if (ret[ret[i]] != i) {
				throw new AssertionError();
			}
		}
		
		return ret;

	}

	void solve() throws IOException {
		int r = nextInt();
		int c = nextInt();
		int[] a = new int[2 * (r + c)];
		for (int i = 0; i < a.length; i++) {
			a[i] = nextInt() - 1;
		}
		
		int[] b = new int[2 * (r + c)];
		for (int i = 0; i < a.length; i += 2) {
			b[a[i]] = a[i + 1];
			b[a[i + 1]] = a[i];
		}
		

		for (int i = 0; i < 1 << (r * c); i++) {
			if (Arrays.equals(go(i, r, c), b)) {
				for (int x = 0; x < r; x++) {
					for (int y = 0; y < c; y++) {
						out.print(test(i, x * c + y) ? "\\" : "/");
					}
					out.println();
				}
				return;
			}
		}

		out.println("IMPOSSIBLE");
	}

	C() throws IOException {
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
			out.println("Case #" + i + ":");
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
}