import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class C implements Runnable {
	String fileName = "C-large";
	boolean DEBUG = false;
	int[] LEFT = new int[1 << 20];
	int[] RIGHT = new int[1 << 20];

	private void solution() throws IOException {
		for (int i = 1; i < LEFT.length; ++i) {
			LEFT[i] = searchLeft(i, i / 2, i);
			RIGHT[i] = searchRight(i, i, 2 * i);
		}
		int ts = in.nextInt();
		for (int cas = 1; cas <= ts; ++cas) {
			out.printf("Case #%d: %s\n", cas, solve());
		}
	}

	private String solve() throws IOException {
		int a1 = in.nextInt();
		int a2 = in.nextInt();
		int b1 = in.nextInt();
		int b2 = in.nextInt();
		long res = fast(a1, a2, b1, b2);
		if (DEBUG) {
			if (slow(a1, a2, b1, b2) != res) {
				System.out.println("too bad");
			}
		}
		return toString(res);
	}

	private long fast(int a1, int a2, int b1, int b2) {
		if (a2 - a1 > b2 - b1) {
			int tmp = a1;
			a1 = b1;
			b1 = tmp;
			tmp = a2;
			a2 = b2;
			b2 = tmp;
		}
		long res = 0;
		for (int a = a1; a <= a2; ++a) {
			// int l = searchLeft(a, a / 2, 2 * a);
			// int r = searchRight(a, a, 2 * a);
			int l = LEFT[a];
			int r = RIGHT[a];
			long cur = b2 - b1 + 1 - sum(b1, b2, l, r);
			if (DEBUG) {
				if (cur != slow(a, a, b1, b2)) {
					System.out.println("bad");
				}
			}
			res += cur;
		}
		return res;
	}

	private int searchRight(int a, int l, int r) {
		while (l <= r) {
			int m = (l + r) >> 1;
			if (win(a, m)) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return r;
	}

	private int searchLeft(int a, int l, int r) {
		while (l <= r) {
			int m = (l + r) >> 1;
			if (win(a, m)) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		return l;
	}

	private long sum(int b1, int b2, int l, int r) {
		if (b1 < l) {
			b1 = l;
		} else {
			l = b1;
		}
		if (b2 > r) {
			b2 = r;
		} else {
			r = b2;
		}
		if (b1 > b2) {
			return 0;
		} else {
			return b2 - b1 + 1;
		}
	}

	private long slow(int a1, int a2, int b1, int b2) {
		long res = 0;
		for (int a = a1; a <= a2; ++a) {
			for (int b = b1; b <= b2; ++b) {
				if (win(a, b)) {
					++res;
				}
			}
		}
		return res;
	}

	private boolean win(int a, int b) {
		if (a == b) {
			return false;
		} else {
			if (a < b) {
				int tmp = a;
				a = b;
				b = tmp;
			}
			boolean ok = true;
			while (a > b) {
				if (a < 2 * b) {
					ok ^= true;
					int tmp = a - b;
					a = b;
					b = tmp;
				} else {
					break;
				}
			}
			return ok;
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
		new Thread(null, new C(), "", 1 << 28).start();
	}
	PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	Scanner in = new Scanner(new InputStreamReader(System.in));
}
