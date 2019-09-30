import java.awt.geom.Ellipse2D;
import java.awt.geom.Point2D;
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class D implements Runnable {
	String fileName = "D-small-attempt1";

	private void solution() throws IOException {
		int ts = in.nextInt();
		for (int cas = 1; cas <= ts; ++cas) {
			out.printf("Case #%d: %s\n", cas, solve());
		}
	}
	int res = 0;

	private String solve() throws IOException {
		long n = in.nextLong();
		int base = in.nextInt();
		List<Integer> list = new ArrayList<Integer>();
		this.res = 0;
		generate(1, 0, base, n, list);
		return toString(res);
		// int[] rem = new int[cnt(n, base)];
		// for (int i = 0; i < rem.length; ++i) {
		// rem[i] = (int) (n % base);
		// n /= base;
		// }
		// long[][] C = fillC(base, base * base);
		// long res = 0;
		// for (int len = 1; len <= base; ++len) {
		// long[][] dp = new long[rem.length + 1][len * rem.length + 1];
		// dp[0][0] = 1;
		// for (int i = 0; i < rem.length; ++i) {
		// for (int j = 0; j < dp[i].length; ++j) {
		// if (dp[i][j] != 0) {
		// int need = rem[i] - j;
		// if (need < 0) {
		// need += base;
		// }
		// for (int t = need; t < C[len].length; t += base) {
		// if (C[len][t] == 0) {
		// continue;
		// }
		// int add = (j + t) / base;
		// dp[i + 1][j + add] += dp[i][j] * C[len][t];
		// dp[i + 1][j + add] %= MOD;
		// }
		// }
		// }
		// }
		// res = (res + dp[rem.length][0] * pow(fact(len - 1), ) % MOD;
		// }
		// return toString(res);
	}

	private void generate(int val, int sum, int base, long n, List<Integer> list) {
		if (sum == n) {
			++res;
			return;
		}
		for (int i = val;; ++i) {
			if (sum + i > n) {
				break;
			}
			if (can(list, i, base)) {
				list.add(i);
				generate(i + 1, sum + i, base, n, list);
				list.remove(list.size() - 1);
			}
		}
	}

	private boolean can(List<Integer> list, int i, int base) {
		for (int x : list) {
			if (!check(i, x, base)) {
				return false;
			}
		}
		return true;
	}

	private boolean check(int x, int y, int base) {
		String a = get(x, base);
		String b = get(y, base);
		for (int i = 0; i < Math.min(a.length(), b.length()); ++i) {
			if (a.charAt(i) == b.charAt(i)) {
				return false;
			}
		}
		return true;
	}

	private String get(int x, int base) {
		StringBuilder builder = new StringBuilder();
		while (x > 0) {
			builder.append((char) (x % base + '0'));
			x /= base;
		}
		return builder.toString();
	}
	int MOD = 1000000007;

	private long[][] fillC(int n, int max) {
		++max;
		long[][][] res = new long[n + 1][n + 1][max + 1];
		res[1][0][0] = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < res[i].length; ++j) {
				for (int k = 0; k < res[i][j].length; ++k) {
					if (res[i][j][k] != 0) {
						res[i + 1][j][k] += res[i][j][k];
						res[i + 1][j][k] %= MOD;
						if (k + i < res[i + 1][j + 1].length) {
							res[i + 1][j + 1][k + i] += res[i][j][k];
							res[i + 1][j + 1][k + i] %= MOD;
						}
					}
				}
			}
		}
		return res[n];
	}

	private int cnt(long n, int base) {
		int cnt = 0;
		while (n > 0) {
			n /= base;
			++cnt;
		}
		return cnt;
	}

	public void run() {
		try {
			in = new Scanner(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			solution();
			in.reader.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	private String toString(Object ob) {
		StringBuilder builder = new StringBuilder();
		try {
			int size = Array.getLength(ob);
			for (int i = 0; i < size; ++i) {
				if (i != 0) {
					builder.append(" ");
				}
				builder.append(Array.get(ob, i));
			}
		} catch (Exception e) {
			builder.append(ob);
		}
		return builder.toString();
	}

	private class Scanner {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public Scanner(Reader reader) {
			this.reader = new BufferedReader(reader);
			this.tokenizer = new StringTokenizer("");
		}

		public boolean hasNext() throws IOException {
			while (!tokenizer.hasMoreTokens()) {
				String next = reader.readLine();
				if (next == null) {
					return false;
				}
				tokenizer = new StringTokenizer(next);
			}
			return true;
		}

		public String next() throws IOException {
			hasNext();
			return tokenizer.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			tokenizer = new StringTokenizer("");
			return reader.readLine();
		}
	}

	public static void main(String[] args) throws IOException {
		new Thread(null, new D(), "", 1 << 28).start();
	}
	PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	Scanner in = new Scanner(new InputStreamReader(System.in));
}
