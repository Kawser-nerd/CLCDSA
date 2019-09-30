import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			boolean[][] wx = new boolean[201][201];
			boolean[][] wy = new boolean[201][201];
			int x = 100;
			int y = 100;
			int dx = 1;
			int dy = 0;
			int n = nextInt();
			for (int i = 0; i < n; ++i) {
				String s = next();
				int rs = nextInt();
				for (int r = 0; r < rs; ++r) {
					for (char c : s.toCharArray()) {
						if (c == 'F') {
							if (dx != 0) {
								wx[(2 * x + dx) / 2][y] = true;
//								System.out.println("x: " + (2 * x + dx) / 2 + " " + y);
							} else {
								wy[x][(2 * y + dy) / 2] = true;
//								System.out.println("y: " + x + " " + (2 * y + dy) / 2);
							}
							x += dx;
							y += dy;
						}
						if (c == 'L') {
							int tmp = dx;
							dx = dy;
							dy = -tmp;
						}
						if (c == 'R') {
							int tmp = dy;
							dy = dx;
							dx = -tmp;
						}
					}
//					System.out.println(dx + " " + dy);
				}
			}
//			System.out.println(x + " " + y);
			boolean[][] s1 = new boolean[200][200];
			
			boolean[][] s2 = new boolean[200][200];
			for (int u = 0; u < 200; ++u) {
				boolean isdown = false;
				boolean inside = false;
				for (int v = 0; v < 200; ++v) {
					isdown |= wx[u][v];
					inside ^= wx[u][v];
					s2[u][v] = !inside & isdown;
				}
				boolean isup = false;
				inside = false;
				for (int v = 199; v >= 0; --v) {
					isup |= wx[u][v + 1];
					inside ^= wx[u][v + 1];
					s2[u][v] &= !inside & isup;
				}
			}
			for (int u = 0; u < 200; ++u) {
				for (int v = 0; v < 200; ++v) {
					s1[u][v] |= s2[u][v];
				}
			}
			
			s2 = new boolean[200][200];
			for (int v = 0; v < 200; ++v) {
				boolean isleft = false;
				boolean inside = false;
				for (int u = 0; u < 200; ++u) {
					isleft |= wy[u][v];
					inside ^= wy[u][v];
//					if (u == 101 && v == 1) {
//						System.out.println(isleft + " " + inside);
//					}
					s2[u][v] = !inside & isleft;
				}
				boolean isright = false;
				inside = false;
				for (int u = 199; u >= 0; --u) {
					isright |= wy[u + 1][v];
					inside ^= wy[u + 1][v];
					s2[u][v] &= !inside & isright;
				}
			}
			for (int u = 0; u < 200; ++u) {
				for (int v = 0; v < 200; ++v) {
					s1[u][v] |= s2[u][v];
				}
			}
			
			int ans = 0;
			for (int u = 0; u < 200; ++u) {
				for (int v = 0; v < 200; ++v) {
//					if (s1[u][v]) {
//						System.out.println((u - 100) + " " + (v - 100));
//					}
					ans += s1[u][v] ? 1 : 0;
				}
			}
			out.println("Case #" + (test + 1) + ": " + ans);
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