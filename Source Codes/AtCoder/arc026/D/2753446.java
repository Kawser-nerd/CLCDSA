import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.NoSuchElementException;

class UnionFind {
	int[] parent;
	int[] rank;
	UnionFindRoot[] root;

	UnionFind(int n) {
		parent = new int[n];
		root = new UnionFindRoot[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = i;
			root[i] = new UnionFindRoot(i);
		}
	}

	int rootIndex(int i) {
		int p = parent[i];
		if (i == p) {
			return i;
		}
		return parent[i] = rootIndex(p);
	}

	UnionFindRoot root(int i) {
		int p = parent[i];
		if (i == p) {
			return root[i];
		}
		return root[parent[i] = rootIndex(p)];
	}

	void union(int i, int j) {
		int root1 = rootIndex(i);
		int root2 = rootIndex(j);

		if (root2 == root1)
			return;

		UnionFindRoot newRoot = root[root1].combine(root[root2]);

		if (rank[root1] > rank[root2]) {
			parent[root2] = root1;
			root[root1] = newRoot;
		} else if (rank[root2] > rank[root1]) {
			parent[root1] = root2;
			root[root2] = newRoot;
		} else {
			parent[root2] = root1;
			root[root1] = newRoot;
			rank[root1]++;
		}
	}

	int size(int x) {
		return root(x).size;
	}

	class UnionFindRoot {
		int size;

		UnionFindRoot(int index) {
			size = 1;
		}

		UnionFindRoot combine(UnionFindRoot another) {
			UnionFindRoot newRoot = new UnionFindRoot(0);
			newRoot.size = size + another.size;
			return newRoot;
		}
	}
}

public class Main {
	private static void solve() {
		int n = nei();
		int m = nei();
		int[][] data = nis2(m, 4);
		double min = 0;
		double max = 1e10;
		for (int i = 0; i < 100; i++) {
			double mid = (min + max) * 0.5;
			if (??OK(n, m, data, mid)) {
				max = mid;
			} else {
				min = mid;
			}
		}
		out(min);
	}

	static boolean ??OK(int n, int m, int[][] es, double target) {
		double[][] cs = new double[m][3];
		for (int i = 0; i < m; i++) {
			cs[i][0] = es[i][0] + 0.5;
			cs[i][1] = es[i][1] + 0.5;
			cs[i][2] = es[i][2] - target * es[i][3];
		}
		Arrays.sort(cs, (a, b) -> Double.compare(a[2], b[2]));

		UnionFind uf = new UnionFind(n);
		double jikyu = 0;
		for (int i = 0; i < m; i++) {
			int a = (int) cs[i][0];
			int b = (int) cs[i][1];
			if (cs[i][2] <= 0) {
				jikyu += cs[i][2];
				uf.union((int) cs[i][0], (int) cs[i][1]);
			} else {
				if (uf.rootIndex(a) != uf.rootIndex(b)) {
					jikyu += cs[i][2];
					if (jikyu > 0)
						return false;
					uf.union((int) cs[i][0], (int) cs[i][1]);
				}
			}
			if (uf.root(0).size == n)
				return true;
		}
		throw new RuntimeException("ha?");
	}

	static void out(String val) {
		IO.out(val);
	}

	static void out(Object val) {
		IO.out(String.valueOf(val));
	}

	static void out(int val) {
		IO.out(String.valueOf(val));
	}

	static void out(long val) {
		IO.out(String.valueOf(val));
	}

	static void out(char val) {
		IO.out(String.valueOf(val));
	}

	static void out(double val) {
		IO.out(BigDecimal.valueOf(val).toPlainString());
	}

	static void out(boolean val) {
		IO.out(String.valueOf(val));
	}

	static void kil(String val) {
		IO.out(val);
		IO.flush();
		System.exit(0);
	}

	static void kil(Object val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(int val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(long val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(char val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(float val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(double val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(boolean val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static String nes() {
		return IO.next();
	}

	static int nei() {
		return IO.nextInt();
	}

	static long nel() {
		return IO.nextLong();
	}

	static double ned() {
		return IO.nextDouble();
	}

	static char nec() {
		return IO.nextChar();
	}

	static String[] nss(int n) {
		String[] as = new String[n];
		for (int i = 0; i < n; i++) {
			as[i] = IO.next();
		}
		return as;
	}

	static int[] nis(int n) {
		int[] as = new int[n];
		for (int i = 0; i < n; i++) {
			as[i] = IO.nextInt();
		}
		return as;
	}

	static long[] nls(int n) {
		long[] as = new long[n];
		for (int i = 0; i < n; i++) {
			as[i] = IO.nextLong();
		}
		return as;
	}

	static double[] nds(int n) {
		double[] as = new double[n];
		for (int i = 0; i < n; i++) {
			as[i] = IO.nextDouble();
		}
		return as;
	}

	static char[] ncs(int n) {
		char[] as = new char[n];
		for (int i = 0; i < n; i++) {
			as[i] = IO.nextChar();
		}
		return as;
	}

	static String[][] nss2(int n, int m) {
		String[][] as = new String[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				as[i][j] = IO.next();
			}
		}
		return as;
	}

	static int[][] nis2(int n, int m) {
		int[][] as = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				as[i][j] = IO.nextInt();
			}
		}
		return as;
	}

	static long[][] nls2(int n, int m) {
		long[][] as = new long[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				as[i][j] = IO.nextLong();
			}
		}
		return as;
	}

	static double[][] nds2(int n, int m) {
		double[][] as = new double[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				as[i][j] = IO.nextDouble();
			}
		}
		return as;
	}

	static char[][] ncs2(int n, int m) {
		char[][] as = new char[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				as[i][j] = IO.nextChar();
			}
		}
		return as;
	}

	static int parseInt(String val) {
		return Integer.parseInt(val);
	}

	static int parseInt(char val) {
		return Integer.parseInt(String.valueOf(val));
	}

	static long parseLong(String val) {
		return Long.parseLong(val);
	}

	public static void main(String[] args) {
		try {
			solve();
			IO.flush();
		} catch (NumberFormatException | NoSuchElementException e) {
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}

final class IO {
	private static final InputStream in = System.in;
	private static final PrintWriter out = new PrintWriter(System.out, false);
	private static final byte[] buffer = new byte[1024];
	private static int ptr = 0;
	private static int len = 0;

	private static boolean hasNextByte() {
		if (ptr < len)
			return true;
		ptr = 0;
		try {
			len = in.read(buffer);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return len > 0;
	}

	private static int readByte() {
		if (hasNextByte())
			return buffer[ptr++];
		else
			return -1;
	}

	static boolean hasNext() {
		byte c;
		while (hasNextByte() && ((c = buffer[ptr]) < '!' || c > '~'))
			ptr++;
		return hasNextByte();
	}

	static String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (b >= '!' && b <= '~') {
			sb.append((char) b);
			b = readByte();
		}
		return sb.toString();
	}

	static char nextChar() {
		if (!hasNext())
			throw new NoSuchElementException();
		return (char) readByte();
	}

	static long nextLong() {
		if (!hasNext())
			throw new NoSuchElementException();
		long n = 0;
		int sign = 1;
		int b = readByte();
		if (b == '-') {
			sign = -1;
			b = readByte();
		}
		if (b < '0' || '9' < b)
			throw new NumberFormatException();
		while (true) {
			if ('0' <= b && b <= '9')
				n = n * 10 + b - '0';
			else if (b == -1 || b < '!' || b > '~')
				return n * sign;
			else
				throw new NumberFormatException();
			b = readByte();
		}
	}

	static int nextInt() {
		if (!hasNext())
			throw new NoSuchElementException();
		int n = 0;
		int sign = 1;
		int b = readByte();
		if (b == '-') {
			sign = -1;
			b = readByte();
		}
		if (b < '0' || '9' < b)
			throw new NumberFormatException();
		while (true) {
			if ('0' <= b && b <= '9')
				n = n * 10 + b - '0';
			else if (b == -1 || b < '!' || b > '~')
				return n * sign;
			else
				throw new NumberFormatException();
			b = readByte();
		}
	}

	static double nextDouble() {
		return Double.parseDouble(next());
	}

	static void out(String val) {
		out.println(val);
	}

	static void flush() {
		out.flush();
	}
}