import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) {
		new Main();
	}

	public Main() {
		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt(), M = sc.nextInt(), A[] = new int[M], B[] = new int[M];
		for (int i = 0;i < M;++ i) {
			A[i] = sc.nextInt() - 1;
			B[i] = sc.nextInt() - 1;
		}
		UnionFindTree unionFind = new UnionFindTree(N);
		long ans[] = new long[M + 1];
		ans[M] = (long)N * (N - 1) / 2;
		for (int i = M - 1;i > 0;-- i) {
			ans[i] = ans[i + 1];
			if (!unionFind.isUnion(A[i], B[i])) {
				ans[i] -= (long)unionFind.getSize(A[i]) * unionFind.getSize(B[i]);
				unionFind.unite(A[i], B[i]);
			}
		}
		for (int i = 1;i <= M;++ i) out.println(ans[i]);
		out.flush();
	}

	/**
	 * ???????????<br>
	 * ????????????????????????
	 * @author 31536000
	 */
	public class UnionFindTree {
		private int[] parent; // ???????????????index

		/**
		 * size??????????????
		 * @param size ???
		 */
		public UnionFindTree(int size) {
			this.parent = new int[size];
			Arrays.fill(this.parent, -1);
		}

		/**
		 * ???????????????????????????????<br>
		 * ????O(?(N))???
		 * @param n ????????
		 * @return ?????????
		 */
		public int find(int n) {
			while(parent[n] >= 0 && parent[parent[n]] >= 0) n = parent[n] = parent[parent[n]]; // ????
			return parent[n] >= 0 ? parent[n] : n;
		}

		/**
		 * ???????????????<br>
		 * ????O(?(N))???
		 * @param l ???????
		 * @param r ???????
		 * @return ???????????????true??????????false
		 */
		public boolean unite(int l, int r) {
			l = find(l);
			r = find(r);
			if (l == r) return false; // ??????
			if (parent[l] >= parent[r]) { // r??????
				parent[r] += parent[l]; // ???????????????
				parent[l] = r;
			} else {
				parent[l] += parent[r]; // ???????????????
				parent[r] = l;
			}
			return true;
		}

		/**
		 * ????2??????????????<br>
		 * ????O(?(N))???
		 * @param l ???????
		 * @param r ???????
		 * @return l?r??????true
		 */
		public boolean isUnion(int l, int r) {
			return find(l) == find(r);
		}

		/**
		 * ???????????????????????<br>
		 * ????O(?(N))???
		 * @param n ???????????????
		 * @return ??n???????????
		 */
		public int getSize(int n) {
			return -parent[find(n)];
		}

		/**
		 * ?????????????<br>
		 * ????O(N)???
		 * @return ???????
		 */
		public int getUnion() {
			int ret = 0;
			for (int i : parent) if (i < 0) ++ ret;
			return ret;
		}
	}
	public class FastScanner {
		private final InputStream in = System.in;
		private final byte[] buffer = new byte[1024];
		private int read = 0;
		private int length = 0;

		private boolean hasNextByte() {
			if (read < length) return true;
			else {
				try {
					read = 0;
					length = in.read(buffer);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return length > 0;
		}

		private int readByte() {
			return hasNextByte() ? buffer[read++] : -1;
		}

		private boolean isPrintableChar(int c) {
			return 33 <= c && c <= 126;
		}

		private boolean isNumber(int c) {
			return '0' <= c && c <= '9';
		}

		public boolean hasNext() {
			while (hasNextByte() && !isPrintableChar(buffer[read])) read++;
			return hasNextByte();
		}

		public char nextChar() {
			if (!hasNextByte())  throw new NoSuchElementException();
			return (char)readByte();
		}

		public String next() {
			if (!hasNext()) throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b;
			while (isPrintableChar(b = readByte())) sb.appendCodePoint(b);
			return sb.toString();
		}

		public long nextLong() {
			if (!hasNext()) throw new NoSuchElementException();
			long n = 0;
			boolean minus = false;
			int b = readByte();
			if (b == '-') {
				minus = true;
				b = readByte();
			}
			if (!isNumber(b)) throw new NumberFormatException();
			while (true) {
				if (isNumber(b)) {
					n *= 10;
					n += b - '0';
				} else if (b == -1 || !isPrintableChar(b)) return minus ? -n : n;
				else throw new NumberFormatException();
				b = readByte();
			}
		}

		public int nextInt() {
			long nl = nextLong();
			if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
			return (int) nl;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public int[] nextInt(int width) {
			int[] ret = new int[width];
			for (int i = 0;i < width;++ i) ret[i] = nextInt();
			return ret;
		}

		public long[] nextLong(int width) {
			long[] ret = new long[width];
			for (int i = 0;i < width;++ i) ret[i] = nextLong();
			return ret;
		}

		public int[][] nextInt(int width, int height) {
			int[][] ret = new int[height][width];
			for (int i = 0, j;i < height;++ i) for (j = 0;j < width;++ j) ret[j][i] = nextInt();
			return ret;
		}

		public long[][] nextLong(int width, int height) {
			long[][] ret = new long[height][width];
			for (int i = 0, j;i < height;++ i) for (j = 0;j < width;++ j) ret[j][i] = nextLong();
			return ret;
		}
	}
}