import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class A implements Runnable {
	String fileName = "A-large";

	private void solution() throws IOException {
		int ts = in.nextInt();
		for (int cas = 1; cas <= ts; ++cas) {
			out.printf("Case #%d: %s\n", cas, solve());
			// System.out.println(cas + " is done");
		}
	}

	private String solve() throws IOException {
		int d = in.nextInt();
		int k = in.nextInt();
		int[] a = new int[k];
		for (int i = 0; i < a.length; ++i) {
			a[i] = in.nextInt();
		}
		String dont = "I don't know.";
		if (k == 1) {
			return dont;
		} else if (k == 2) {
			if (a[0] == a[1]) {
				return toString(a[0]);
			} else {
				return dont;
			}
		} else {
			int max = (int) (Math.pow(10, d) + 0.5);
			TreeSet<Integer> res = new TreeSet<Integer>();
			for (int i = 2; i <= max; ++i) {
				if (prime[i]) {
					int next = next(a, i);
					if (next != -1) {
						res.add(next);
					}
					if (res.size() >= 2) {
						return dont;
					}
				}
			}
			return toString(res.first());
		}
	}

	private int next(int[] x, int MOD) {
		for (int t : x) {
			if (t >= MOD) {
				return -1;
			}
		}
		long A = ((long) (x[2] - x[1] + MOD) % MOD) * pow((x[1] - x[0] + MOD) % MOD, MOD - 2, MOD) % MOD;
		long B = ((x[1] - x[0] * A) % MOD + MOD) % MOD;
		long cur = x[0];
		for (int i = 0; i < x.length; ++i) {
			if (cur != x[i]) {
				return -1;
			}
			cur = (cur * A + B) % MOD;
		}
		return (int) cur;
	}

	private long pow(long a, int k, int mod) {
		long res = 1;
		while (k > 0) {
			if ((k & 1) != 0) {
				res = res * a % mod;
			}
			k >>= 1;
			a = a * a % mod;
		}
		return res;
	}
	boolean[] prime = new boolean[1000001];
	{
		Arrays.fill(prime, true);
		prime[0] = prime[1] = false;
		for (int i = 2; i * i < prime.length; ++i) {
			if (prime[i]) {
				for (int j = i; j * i < prime.length; ++j) {
					prime[j * i] = false;
				}
			}
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
		new Thread(null, new A(), "", 1 << 28).start();
	}
	PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	Scanner in = new Scanner(new InputStreamReader(System.in));
}
