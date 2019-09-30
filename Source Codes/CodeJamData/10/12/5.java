import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;

public class B implements Runnable {
	String fileName = "B-large";

	private void solution() throws IOException {
		int ts = in.nextInt();
		for (int cas = 1; cas <= ts; ++cas) {
			out.printf("Case #%d: %s\n", cas, solve());
			System.err.println(cas);
		}
	}

	private String solve() throws IOException {
		int D = in.nextInt();
		int I = in.nextInt();
		int diff = in.nextInt();
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = in.nextInt();
		}
		Integer[][] dp = new Integer[n][257];
		int res = doit(0, 256, D, I, diff, a, dp);
		return toString(res);
	}

	private int doit(int at, int prev, int D, int I, int diff, int[] a, Integer[][] dp) {
		if (at == a.length) {
			return 0;
		}
		if (dp[at][prev] != null) {
			return dp[at][prev];
		}
		int res = D + doit(at + 1, prev, D, I, diff, a, dp);
		for (int cur = 0; cur <= 255; ++cur) {
			int sum = Math.abs(cur - a[at]);
			if (prev != 256) {
				if (prev != cur && diff == 0) {
					continue;
				}
				sum += more(prev, cur, diff) * I;
			}
			res = Math.min(res, sum + doit(at + 1, cur, D, I, diff, a, dp));
		}
		return dp[at][prev] = res;
	}

	private int more(int a, int b, int diff) {
		if (a == b) {
			return 0;
		}
		return (Math.abs(a - b) - 1) / diff;
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
		new Thread(null, new B(), "", 1 << 28).start();
	}
	PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	Scanner in = new Scanner(new InputStreamReader(System.in));
}
