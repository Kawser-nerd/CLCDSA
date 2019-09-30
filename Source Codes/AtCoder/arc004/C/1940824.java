public class Main {

	private static void solve() {
		String s = next();
		String[] elem = s.split("/");
		long x = Long.parseLong(elem[0]);
		long y = Long.parseLong(elem[1]);
		
		long n1 = 2 * x / y;
		long n2 = (2 * x + y) / y;
		
		if (n1 > n2) {
			long tmp  = n1;
			n1 = n2;
			n2 = tmp;
		}

		long m1 = f(x, y, n1);
		long m2 = f(x, y, n2);
		
		
		boolean flg = false;
		if (m1 >= 0) {
			System.out.println(n1 + " " + m1);
			flg = true;
		}
		if (m2 >= 0) {
			System.out.println(n2 + " " + m2);
			flg = true;
		}
		if (!flg) {
			System.out.println("Impossible");
		}
	}
	
	static long f (long x, long y, long n) {
		if (n <= 0) {
			return -1;
		}
		long p = n * (y * (n + 1) - 2 * x);
		long q = 2 * y;
		
		
		if (p % q == 0) {
			return p / q;
		} else {
			return -1;
		}
	}

	public static void main(String[] args) {
		new Thread(null, new Runnable() {
			@Override
			public void run() {
				long start = System.currentTimeMillis();
				String debug = args.length > 0 ? args[0] : null;
				if (debug != null) {
					try {
						is = java.nio.file.Files.newInputStream(java.nio.file.Paths.get(debug));
					} catch (Exception e) {
						throw new RuntimeException(e);
					}
				}
				reader = new java.io.BufferedReader(new java.io.InputStreamReader(is), 32768);
				solve();
				out.flush();
				tr((System.currentTimeMillis() - start) + "ms");
			}
		}, "", 64000000).start();
	}

	private static java.io.InputStream is = System.in;
	private static java.io.PrintWriter out = new java.io.PrintWriter(System.out);
	private static java.util.StringTokenizer tokenizer = null;
	private static java.io.BufferedReader reader;

	public static String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new java.util.StringTokenizer(reader.readLine());
			} catch (Exception e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	private static double nd() {
		return Double.parseDouble(next());
	}

	private static long nl() {
		return Long.parseLong(next());
	}

	private static int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = ni();
		return a;
	}

	private static char[] ns() {
		return next().toCharArray();
	}

	private static long[] nal(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nl();
		return a;
	}

	private static int[][] ntable(int n, int m) {
		int[][] table = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				table[i][j] = ni();
			}
		}
		return table;
	}

	private static int[][] nlist(int n, int m) {
		int[][] table = new int[m][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				table[j][i] = ni();
			}
		}
		return table;
	}

	private static int ni() {
		return Integer.parseInt(next());
	}

	private static void tr(Object... o) {
		if (is != System.in)
			System.out.println(java.util.Arrays.deepToString(o));
	}
}