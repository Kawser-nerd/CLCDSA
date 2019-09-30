import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		C_DifferByOneBit solver = new C_DifferByOneBit();
		solver.solve(1, in, out);
		out.close();
	}

	static class C_DifferByOneBit {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			int a = in.nextInt();
			int b = in.nextInt();
			int[] path = build(n, a, b);
			if (path == null) {
				out.println("NO");
				return;
			}
			out.println("YES");
			for (int i = 0; i < path.length; i++) {
				if (i > 0) {
					out.print(" ");
				}
				out.print(path[i]);
			}
			out.println();
		}

		private int[] build(int n, int a, int b) {
			int diff = Integer.bitCount(a ^ b);
			if (diff % 2 == 0) {
				return null;
			}
			if (n == 1) {
				return new int[]{a, b};
			}

			int[] differentBitPositions = new int[n];
			int[] differentBitValuesA = new int[n];
			int[] differentBitValuesB = new int[n];
			int numDifferentBits = 0;
			for (int i = 0; i < n; i++) {
				int bitA = (a >> i) & 1;
				int bitB = (b >> i) & 1;
				if (bitA != bitB) {
					differentBitPositions[numDifferentBits] = i;
					differentBitValuesA[numDifferentBits] = bitA;
					differentBitValuesB[numDifferentBits] = bitB;
					++numDifferentBits;
				}
			}

			if (diff == 1) {
				int[] g = gray(n - 1);
				g = insert(n - 1, g, differentBitPositions[0], differentBitValuesA[0]);
				g = rotate(g, a);
				g = remove(n, g, differentBitPositions[0]);
				int[] path = new int[2 * g.length];
				for (int i = 0; i < g.length; i++) {
					path[i] = insert(n - 1, g[i], differentBitPositions[0], differentBitValuesA[0]);
					path[i + g.length] = insert(n - 1, g[g.length - i - 1], differentBitPositions[0], differentBitValuesB[0]);
				}
				return path;
			}

			int a00 = remove(n, a, differentBitPositions[numDifferentBits - 1]);
			int a01 = a00 ^ (1 << differentBitPositions[numDifferentBits - 2]);
			int[] p1 = build(n - 1, a00, a01);
			if (p1 == null) {
				throw new AssertionError();
			}
			p1 = insert(n - 1, p1, differentBitPositions[numDifferentBits - 1], differentBitValuesA[numDifferentBits - 1]);

			int b01 = a01;
			int b11 = remove(n, b, differentBitPositions[numDifferentBits - 1]);

			int[] p2 = build(n - 1, b01, b11);
			if (p2 == null) {
				throw new AssertionError();
			}
			p2 = insert(n - 1, p2, differentBitPositions[numDifferentBits - 1], differentBitValuesB[numDifferentBits - 1]);

			int[] p3 = Arrays.copyOf(p1, 2 * p1.length);
			System.arraycopy(p2, 0, p3, p1.length, p1.length);
			return p3;
		}

		private int[] insert(int n, int[] g, int pos, int val) {
			int[] ng = new int[g.length];
			for (int i = 0; i < g.length; i++) {
				ng[i] = insert(n, g[i], pos, val);
			}
			return ng;
		}

		private int[] remove(int n, int[] g, int pos) {
			int[] ng = new int[g.length];
			for (int i = 0; i < g.length; i++) {
				ng[i] = remove(n, g[i], pos);
			}
			return ng;
		}

		private int insert(int n, int x, int pos, int val) {
			int full = (1 << n) - 1;
			int low = (1 << pos) - 1;
			int high = full ^ low;
			int valLow = x & low;
			int valHigh = (x & high) >> pos;
			return (valHigh << (pos + 1)) | (val << pos) | valLow;
		}

		private int remove(int n, int x, int pos) {
			int full = (1 << n) - 1;
			int low = (1 << pos) - 1;
			int high = full ^ low;
			int valLow = x & low;
			int valHigh = (x & high) >> pos;
			return ((valHigh >> 1) << pos) | valLow;
		}

		private int[] rotate(int[] g, int first) {
			int s = -1;
			for (int i = 0; i < g.length; i++) {
				if (g[i] == first) {
					s = i;
					break;
				}
			}
			if (s < 0) {
				throw new AssertionError();
			}
			int[] ng = new int[g.length];
			for (int i = 0; i < g.length; i++) {
				ng[i] = g[(i + s) % g.length];
			}
			return ng;
		}

		private int[] gray(int n) {
			int[] g = new int[1 << n];
			for (int i = 0; i < g.length; i++) {
				g[i] = i ^ (i >> 1);
//			String s = Integer.toBinaryString(g[i]);
//			while (s.length() < n) {
//				s = "0" + s;
//			}
//			System.out.println(s);
			}
			return g;
		}

	}

	static class FastScanner {
		private BufferedReader in;
		private StringTokenizer st;

		public FastScanner(InputStream stream) {
			in = new BufferedReader(new InputStreamReader(stream));
		}

		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String rl = in.readLine();
					if (rl == null) {
						return null;
					}
					st = new StringTokenizer(rl);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
}