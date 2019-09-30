import java.io.*;
import java.util.*;

public class A {
	FastScanner in;
	PrintWriter out;

	int[] dx = new int[] { -1, 0, 0, 1 };
	int[] dy = new int[] { 0, -1, 1, 0 };
	String dir = "^<>v";

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			int n = in.nextInt();
			int m = in.nextInt();
			char[][] a = new char[n][];
			for (int i = 0; i < n; i++) {
				a[i] = in.next().toCharArray();
			}
			int cost = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (a[i][j] == '.') {
						continue;
					}
					int nowDir = dir.indexOf(a[i][j]);
					boolean ok = false;
					{
						int ni = i, nj = j;
						while (true) {
							ni += dx[nowDir];
							nj += dy[nowDir];
							if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
								break;
							}
							if (a[ni][nj] != '.') {
								ok = true;
								break;
							}
						}
					}
					if (ok) {
						continue;
					}
					cost++;
					for (int d = 0; d < 4; d++) {
						{
							int ni = i, nj = j;
							while (true) {
								ni += dx[d];
								nj += dy[d];
								if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
									break;
								}
								if (a[ni][nj] != '.') {
									ok = true;
									break;
								}
							}
						}
					}
					if (!ok) {
						cost = Integer.MAX_VALUE / 2;
					}
				}
			}
			out.println(cost >= Integer.MAX_VALUE / 2 ? "IMPOSSIBLE" : cost);
			System.err.println((t + 1) + "/" + tc + " done");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("A.in"));
			out = new PrintWriter(new File("A.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new A().run();
	}
}