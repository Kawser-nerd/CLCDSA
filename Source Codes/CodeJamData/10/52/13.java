import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;

public class B implements Runnable {
	String fileName = "B-small-attempt0";

	private void solution() throws IOException {
		int ts = in.nextInt();
		for (int cas = 1; cas <= ts; ++cas) {
			out.printf("Case #%d: %s\n", cas, solve());
		}
	}

	private String solve() throws IOException {
		long L = in.nextLong();
		int n = in.nextInt();
		int[] w = new int[n];
		for (int i = 0; i < n; ++i) {
			w[i] = in.nextInt();
		}
		Arrays.sort(w);
		int max = w[n - 1];
		int limit = 0;
		for (int x : w) {
			limit += max * x;
		}
		long res = 0;
		if (L > limit) {
			res += (L - limit) / max;
			L -= max * res;
		}
		int[] dp = new int[(int) (L + 1)];
		for (int i = 1; i < dp.length; ++i) {
			dp[i] = Integer.MAX_VALUE / 2;
			for (int x : w) {
				if (i - x >= 0 && dp[i - x] + 1 < dp[i]) {
					dp[i] = dp[i - x] + 1;
				}
			}
		}
		if (dp[(int) L] == Integer.MAX_VALUE / 2) {
			return toString("IMPOSSIBLE");
		} else {
			return toString(res + dp[(int) L]);
		}
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
		new Thread(null, new B(), "", 1 << 28).start();
	}
	PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	Scanner in = new Scanner(new InputStreamReader(System.in));
}
