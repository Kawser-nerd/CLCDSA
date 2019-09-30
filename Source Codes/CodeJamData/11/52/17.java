import java.io.*;
import java.util.*;
import java.math.*;

public class Blarge implements Runnable {

	void solve() {
		int t = nextInt();
		for (int test = 0; test < t; test++) {
			int n = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			out.println("Case #" + (test + 1) + ": " + solve(a));
		}
	}

	static int solve(int[] a) {
		if (a.length == 0) {
			return 0;
		}
		int n = a.length;
		int l = 1;
		int r = n + 1;
		while (l < r - 1) {
			int m = (l + r) >> 1;
			if (check(a, m)) {
				l = m;
			} else {
				r = m;
			}
		}
		return l;
	}

	static void add(Map<Integer, Integer> map, int x) {
		if (!map.containsKey(x)) {
			map.put(x, 1);
		} else {
			map.put(x, map.get(x) + 1);
		}
	}

	static void remove(Map<Integer, Integer> map, int x) {
		if (map.get(x) == 1) {
			map.remove(x);
		} else {
			map.put(x, map.get(x) - 1);
		}
	}

	static boolean check(int[] a, int k) {
		TreeMap<Integer, Integer> all = new TreeMap<Integer, Integer>();
		for (int i : a) {
			add(all, i);
		}
		HashMap<Integer, Integer> end = new HashMap<Integer, Integer>();
		while (!all.isEmpty()) {
			int x = all.firstKey();
			if (end.containsKey(x - 1)) {
				remove(end, x - 1);
				add(end, x);
				remove(all, x);
			} else {
				for (int i = 0; i < k; i++) {
					if (!all.containsKey(i + x)) {
						return false;
					}
					remove(all, i + x);
				}
				add(end, x + k - 1);
			}
		}
		return true;
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		try {
			sc = new FastScanner("blarge.in");
			out = new PrintWriter("blarge.out");
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new Blarge().run();
	}
}