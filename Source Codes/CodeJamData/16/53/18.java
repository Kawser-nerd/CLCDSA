
import java.io.*;
import java.util.*;

import javafx.util.Pair;

public class C {
	FastScanner in = new FastScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);

	class UnionFindTree {
		int[] count;
		int[] parent;
		
		public UnionFindTree(int n) {
			count = new int[n];
			parent = new int[n];
			for (int i = 0; i < parent.length; i++) {
				parent[i] = i;
				count[i] = 1;
			}
		}
		
		public int cntUpdate(int x) {
			if (parent[x] == x) return count[x];
			return count[x] = cntUpdate(parent[x]);
		}
		
		public int find(int x) {
			if (parent[x] == x) return x;
			return parent[x] = find(parent[x]);
		}
		
		public boolean same(int x, int y) {
			return find(x) == find(y);
		}
		
		public void unite(int x, int y) {
			int xx = find(x), yy = find(y);
			if (xx == yy) return;
			parent[xx] = yy;
			int tmp = count[xx];
			count[xx] += count[yy];
			count[yy] += tmp;
		}

		public String toString() {
			return Arrays.toString(parent);
		}
	}

	class Pair implements Comparable<Pair> {
		int a;
		int b;
		double dist;
		
		Pair (int a, int b, double dist) {
			this.a = a;
			this.b = b;
			this.dist = dist;
		}
		
		public int compareTo(Pair s) {
			return Double.compare(dist, s.dist);	
		}
		
		public String toString() {
			return a + " " + b + " " + dist;
		}
	}
	
	double calcDist(double x1, double y1, double z1, double x2, double y2, double z2) {
		double dx = x1 - x2;
		double dy = y1 - y2;
		double dz = z1 - z2;
		return Math.sqrt(dx * dx + dy * dy + dz * dz);
	}
	
	public void run() {
		int T = in.nextInt();
		for (int caseN = 1; caseN <= T; caseN++) {
			int N = in.nextInt(), S = in.nextInt();
			int[] xs = new int[N], ys = new int[N], zs = new int[N];
			int[] vxs = new int[N], vys = new int[N], vzs = new int[N];
			for (int i = 0; i < N; i++) {
				xs[i] = in.nextInt();
				ys[i] = in.nextInt();
				zs[i] = in.nextInt();
				vxs[i] = in.nextInt();
				vys[i] = in.nextInt();
				vzs[i] = in.nextInt();
			}
			
			UnionFindTree uft = new UnionFindTree(N);
			PriorityQueue<Pair> pq = new PriorityQueue<>();
			for (int i = 0; i < N; i++) {
				for (int j = i + 1; j < N; j++) {
					pq.add(new Pair(i, j, calcDist(xs[i], ys[i], zs[i], xs[j], ys[j], zs[j])));
				}
			}
			
			double res = 0;
			while (!pq.isEmpty() && !uft.same(0, 1)) {
				Pair p = pq.poll();
				res = p.dist;
				uft.unite(p.a, p.b);				
			}
			
			out.println("Case #" + caseN + ": " + res);
		}
		out.close();
	}

	public static void main(String[] args) {
		new C().run();
	}

	public void mapDebug(int[][] a) {
		System.out.println("--------map display---------");

		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				System.out.printf("%3d ", a[i][j]);
			}
			System.out.println();
		}

		System.out.println("----------------------------");
		System.out.println();
	}

	public void debug(Object... obj) {
		System.out.println(Arrays.deepToString(obj));
	}

	class FastScanner {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public FastScanner(InputStream stream) {
			this.stream = stream;
			//stream = new FileInputStream(new File("dec.in"));

		}

		int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		boolean isEndline(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] nextIntArray(int n) {
			return nextIntArray(n, 0);
		}

		int[] nextIntArray(int n, int margin) {
			int[] array = new int[n + margin];
			for (int i = 0; i < n; i++)
				array[i + margin] = nextInt();

			return array;
		}

		int[][] nextIntMap(int n, int m) {
			int[][] map = new int[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextIntArray(m);
			}
			return map;
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		long[] nextLongArray(int n) {
			return nextLongArray(n, 0);
		}

		long[] nextLongArray(int n, int margin) {
			long[] array = new long[n + margin];
			for (int i = 0; i < n; i++)
				array[i + margin] = nextLong();

			return array;
		}

		long[][] nextLongMap(int n, int m) {
			long[][] map = new long[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextLongArray(m);
			}
			return map;
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		double[] nextDoubleArray(int n) {
			return nextDoubleArray(n, 0);
		}

		double[] nextDoubleArray(int n, int margin) {
			double[] array = new double[n + margin];
			for (int i = 0; i < n; i++)
				array[i + margin] = nextDouble();

			return array;
		}

		double[][] nextDoubleMap(int n, int m) {
			double[][] map = new double[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextDoubleArray(m);
			}
			return map;
		}

		String next() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		String[] nextStringArray(int n) {
			String[] array = new String[n];
			for (int i = 0; i < n; i++)
				array[i] = next();

			return array;
		}

		String nextLine() {
			int c = read();
			while (isEndline(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndline(c));
			return res.toString();
		}
	}
}

