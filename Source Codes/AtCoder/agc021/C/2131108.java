import java.io.*;
import java.util.*;

public class Main {

	void submit() {
		int r = nextInt();
		int c = nextInt();
		int h = nextInt();
		int v = nextInt();
		solve(r, c, h, v);
	}

	void solve(int r, int c, int h, int v) {

		boolean flip = false;
		if (r % 2 == 1 && c % 2 == 0) {
			int tmp = r;
			r = c;
			c = tmp;

			tmp = h;
			h = v;
			v = tmp;
			flip = true;
		}

		char[][] ans = new char[r][c];
		for (char[] row : ans) {
			Arrays.fill(row, '.');
		}

		if (r % 2 == 0) {
			int x = 0;
			int y = 0;
			while (h > 0) {
				if (y + 1 >= c) {
					out.println("NO");
					return;
				}
				ans[x][y] = '<';
				ans[x][y + 1] = '>';
				h--;
				x++;
				if (x == r) {
					x = 0;
					y += 2;
				}
			}
			if (!fillVert(ans, v)) {
				out.println("NO");
				return;
			}
		} else {
			if (h > (long)r * (c / 2)) {
				out.println("NO");
				return;
			}
			for (int y = 0; y + 1 < c && h > 0;) {
				ans[0][y] = '<';
				ans[0][y + 1] = '>';
				h--;
				y += 2;
			}

			if (h == 0) {
				
			} else {
				if (r == 1) {
					out.println("NO");
					return;
				}
				if (h % 2 == 0) {
					int x = 1;
					int y = 0;
					while (h > 0) {
						if (y + 1 >= c) {
							out.println("NO");
							return;
						}
						ans[x][y] = '<';
						ans[x][y + 1] = '>';
						h--;
						x++;
						if (x == r) {
							x = 1;
							y += 2;
						}
					}
				} else {
					
					ans[r - 1][c - 2] = '<';
					ans[r - 1][c - 1] = '>';
					h--;
					for (int i = r - 2; i >= 2 && h > 0; i--) {
						ans[i][c - 2] = '<';
						ans[i][c - 1] = '>';
						h--;
					}
					
					int x = 1;
					int y = 0;
					while (h > 0) {
						ans[x][y] = '<';
						ans[x][y + 1] = '>';
						h--;
						x++;
						if (x == r) {
							x = 1;
							y += 2;
						}
					}
				}
			}
			
			if (!fillVert(ans, v)) {
				out.println("NO");
				return;
			}

		}

		out.println("YES");
		if (flip) {
			char[][] newAns = new char[ans[0].length][ans.length];
			for (int i = 0; i < ans.length; i++) {
				for (int j = 0; j < ans[i].length; j++) {
					char symb = ans[i][j];
					char ns;
					if (symb == '.') {
						ns = '.';
					} else if (symb == '<') {
						ns = '^';
					} else if (symb == '>') {
						ns = 'v';
					} else if (symb == '^') {
						ns = '<';
					} else if (symb == 'v') {
						ns = '>';
					} else {
						throw new AssertionError();
					}
					newAns[j][i] = ns;
				}
			}
			ans = newAns;
		}

		for (char[] row : ans) {
			out.println(row);
		}
	}

	boolean fillVert(char[][] ans, int v) {
		if (v == 0) {
			return true;
		}
		for (int c = 0; c < ans[0].length; c++) {
			for (int r = 0; r < ans.length - 1; r++) {
				if (ans[r][c] == '.' && ans[r + 1][c] == '.') {
					ans[r][c] = '^';
					ans[r + 1][c] = 'v';
					v--;
					if (v == 0) {
						return true;
					}
				}
			}
		}
		return false;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {
//		int r = 3;
//		int c = 4;
//		for (int x = 0; x < 7; x++) {
//			for (int y = 0; y < 7; y++) {
//				out.println(x + " " + y);
//				solve(r, c, x, y);
//			}
//		}
		solve(5, 5, 9, 3);
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		 submit();
		// stress();
//		test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}