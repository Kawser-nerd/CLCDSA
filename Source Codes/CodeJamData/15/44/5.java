import java.io.*;
import java.util.*;

public class D {
	FastScanner in;
	PrintWriter out;

	void go(int[][] id) {
		int r = id.length, c = id[0].length;
		int ri = -1, rj = -1;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (id[i][j] == -1 && ri == -1) {
					ri = i;
					rj = j;
				}
				if (id[i][j] != -1) {
					int free = 0, now = 0;
					if (i > 0) {
						if (id[i - 1][j] == -1) {
							free++;
						} else {
							if (id[i - 1][j] == id[i][j]) {
								now++;
							}
						}
					}
					if (i + 1 < r) {
						if (id[i + 1][j] == -1) {
							free++;
						} else {
							if (id[i + 1][j] == id[i][j]) {
								now++;
							}
						}
					}
					int aj = j + 1;
					if (aj == c) {
						aj = 0;
					}
					if (id[i][aj] == -1) {
						free++;
					} else {
						if (id[i][aj] == id[i][j]) {
							now++;
						}
					}
					int sj = j - 1;
					if (sj < 0) {
						sj = c - 1;
					}
					if (id[i][sj] == -1) {
						free++;
					} else {
						if (id[i][sj] == id[i][j]) {
							now++;
						}
					}
					if (now > id[i][j]) {
						return;
					}
					if (now + free < id[i][j]) {
						return;
					}
				}
			}
		}
		if (ri == -1) {
			for (int cnt = c; cnt >= 1; cnt--) {
				if (c % cnt == 0) {
					boolean ok = true;
					int diff = c / cnt;
					for (int i = 0; i < r; i++) {
						for (int j = 0; j < c; j++) {
							if (id[i][j] != id[i][(j + diff) % c]) {
								ok = false;
								break;
							}
						}
					}
					if (ok) {
						div[cnt]++;
						return;
					}
				}
			}
		}
		for (int i = 1; i <= 3; i++) {
			id[ri][rj] = i;
			go(id);
		}
		id[ri][rj] = -1;
	}

	long[] div = new long[7];

	long solve(int r, int c) {
		int[][] id = new int[r][c];
		for (int i = 0; i < r; i++) {
			Arrays.fill(id[i], -1);
		}
		Arrays.fill(div, 0);
		long result = 0;
		go(id);
		for (int d = 1; d <= 6; d++) {
			if (c % d != 0) {
				continue;
			}
			int cd = c / d;
			if (div[d] % cd != 0) {
				throw new AssertionError(div[d] + " " + d);
			}
			result += div[d] / cd;
		}
		return result;
	}

	void solve123() {
		for (int r = 2; r <= 6; r++) {
			for (int c = 3; c <= 6; c++) {
				System.err.println(r + " " + c + " " + solve(r, c));
			}
		}
	}

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			out.println(solve(in.nextInt(), in.nextInt()));
			System.err.println((t + 1) + "/" + tc + " done");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("D.in"));
			out = new PrintWriter(new File("D.out"));

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
		new D().run();
	}
}