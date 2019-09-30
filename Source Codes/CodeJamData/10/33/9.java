import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	Random rand = new Random();

	private void solve() throws IOException {
		int T = in.nextInt();
		for (int tn = 1; tn <= T; ++tn) {
			System.out.println(tn);
			int n = in.nextInt();
			int m = in.nextInt();
			int[][] tab = new int[n][m];
			for (int i = 0; i < n; ++i) {
				 String s = in.next();
				for (int j = 0; j < m / 4; ++j) {
					 char c = s.charAt(j);
					 int k = Integer.parseInt(c + "", 16);
					for (int t = 3; t >= 0; --t) {
						 tab[i][j * 4 + 3 - t] = (k & (1 << t)) > 0 ? 1 : 0;
//						tab[i][j * 4 + 3 - t] = rand.nextBoolean() ? 1 : 0;
					}
				}
			}

			int[][] rl = new int[n][m];
			for (int i = 0; i < n; ++i) {
				for (int j = m - 1; j >= 0; --j) {
					if (j + 1 >= m || tab[i][j + 1] + tab[i][j] != 1) {
						rl[i][j] = 1;
					} else {
						rl[i][j] = rl[i][j + 1] + 1;
					}
				}
			}

			int[][] dl = new int[n][m];
			for (int j = 0; j < m; ++j) {
				for (int i = n - 1; i >= 0; --i) {
					if (i + 1 >= n || tab[i + 1][j] + tab[i][j] != 1) {
						dl[i][j] = 1;
					} else {
						dl[i][j] = dl[i + 1][j] + 1;
					}
				}
			}

			int[][] us = new int[n][m];

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					int l = 1;
					int c = tab[i][j];
					for (; i + l - 1 < n && j + l - 1 < m; ++l) {
						if ((tab[i + l - 1][j] + c + l) % 2 != 1
								|| (tab[i][j + l - 1] + c + l) % 2 != 1
								|| rl[i + l - 1][j] < l || dl[i][j + l - 1] < l)
							break;
					}
					us[i][j] = l - 1;
				}
			}

			int[] ans = new int[m + n + 1];

			Fenwick ft = new Fenwick(n, m);

			for (int sz = Math.min(m, n); sz > 1; --sz) {
//				System.out.println(sz);

				for (int i = 0; i + sz - 1 < n; ++i) {
					loop: for (int j = 0; j + sz - 1 < m; ++j) {
						if (us[i][j] >= sz
								&& ft.sum(i, j, i + sz - 1, j + sz - 1) == 0) {
							++ans[sz];
							// System.out.println(i + " " + j + " " + sz);
							for (int ti = i; ti <= i + sz - 1; ++ti) {
								for (int tj = j; tj <= j + sz - 1; ++tj) {
									ft.add(ti, tj, 1);
								}
							}
							continue loop;
						}
					}

				}
			}

			ans[1] = n * m - ft.sum(0, 0, n - 1, m - 1);

			int K = 0;
			for (int i : ans) {
				if (i > 0)
					++K;
			}

			out.println("Case #" + tn + ": " + K);
			for (int i = ans.length - 1; i >= 0; --i) {
				if (ans[i] > 0) {
					out.println(i + " " + ans[i]);
				}
			}
		}
	}

	class Fenwick {

		int[][] tab;

		public Fenwick(int n, int m) {
			tab = new int[n][m];
		}

		int get(int i, int tj) {
			int ans = 0;
			while (i >= 0) {
				int j = tj;
				while (j >= 0) {
					ans += tab[i][j];
					j = (j & (j + 1)) - 1;
				}
				i = (i & (i + 1)) - 1;
			}
			return ans;
		}

		void add(int i, int tj, int val) {
			while (i < tab.length) {
				int j = tj;
				while (j < tab[i].length) {
					tab[i][j] += val;
					j = j | (j + 1);
				}
				i = i | (i + 1);
			}

		}

		int sum(int i1, int j1, int i2, int j2) {
			return get(i1 - 1, j1 - 1) + get(i2, j2) - get(i2, j1 - 1)
					- get(i1 - 1, j2);
		}

	}

	final String FILE_NAME = "C-large";

	SimpleScanner in;
	PrintWriter out;

	@Override
	public void run() {
		try {
			in = new SimpleScanner(new FileReader(FILE_NAME + ".in"));
			out = new PrintWriter(FILE_NAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

	public static void main(String[] args) {
		new Thread(new C()).start();
	}

	void myAssert(boolean e) {
		if (!e) {
			throw new Error("assertion failed");
		}
	}

	int assertBounds(int l, int m, int r) {
		myAssert(l <= m && m <= r);
		return m;
	}

	class SimpleScanner extends BufferedReader {

		private StringTokenizer st;
		private boolean eof;

		public SimpleScanner(Reader a) {
			super(a);
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(readLine());
				} catch (Exception e) {
					eof = true;
					return "";
				}
			}
			return st.nextToken();
		}

		boolean seekEof() {
			String s = next();
			if ("".equals(s) && eof)
				return true;
			st = new StringTokenizer(s + " " + st.toString());
			return false;
		}

		private String cnv(String s) {
			if (s.length() == 0)
				return "0";
			return s;
		}

		int nextInt() {
			return Integer.parseInt(cnv(next()));
		}

		double nextDouble() {
			return Double.parseDouble(cnv(next()));
		}

		long nextLong() {
			return Long.parseLong(cnv(next()));
		}
	}
}