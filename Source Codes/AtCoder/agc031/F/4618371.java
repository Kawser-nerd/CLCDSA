import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int qq = nextInt();
		int mod = nextInt();

		int[] a = new int[3 * m];
		for (int i = 0; i < m; i++) {
			a[3 * i] = nextInt() - 1;
			a[3 * i + 1] = nextInt() - 1;
			a[3 * i + 2] = nextInt();
		}

		int t = 0;
		for (int i = 2; i < a.length; i += 3) {
			t = gcd(t, Math.abs(a[i] - a[2]));
		}

		int q = gcd(t, mod);
		mod = gcd(3 * t, mod);

		int rem = a[2] % q;

		DSU dsu = new DSU(6 * n);

		for (int i = 0; i < a.length; i += 3) {
			int v = a[i];
			int u = a[i + 1];
			int edge = (a[i + 2] - rem) % mod / q;

			for (int zzz = 0; zzz < 2; zzz++) {

				for (int p2 = 0; p2 < 2; p2++) {
					for (int mq = 0; mq < 3; mq++) {

						int toP2 = p2 ^ 1;
						int toMq = (2 * mq + edge) % 3;

						dsu.unite(6 * v + p2 * 3 + mq, 6 * u + toP2 * 3 + toMq);
					}
				}

				int tmp = v;
				v = u;
				u = tmp;
			}
		}
		
		DSU rems = new DSU(mod);
		for (int i = 0; i < mod; i++) {
			rems.unite(i, 4 * i % mod);
		}
		
		outer: while (qq-- > 0) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			int r = nextInt();
			
			// (u, rem) -> (v, rem + r)
			
			int uVal = rem;
			int vVal = (rem + r) % mod;
			
			for (int p2 = 0; p2 < 2; p2++) {
				for (int mq = 0; mq < 3; mq++) {
					if (dsu.get(6 * u) == dsu.get(6 * v + p2 * 3 + mq)) {
						
						int realV = Math.floorMod(vVal - mq * q, mod);
						int realU = p2 == 0 ? uVal : (2 * uVal) % mod;
						
						if (rems.get(realV) == rems.get(realU)) {
							out.println("YES");
							continue outer;
						}
						
					}
				}
			}
			
			out.println("NO");
		}

	}

	static class DSU {
		int[] p;
		int[] rank;

		public DSU(int n) {
			p = IntStream.range(0, n).toArray();
			rank = new int[n];
		}

		int get(int v) {
			return p[v] == v ? v : (p[v] = get(p[v]));
		}

		boolean unite(int v, int u) {
			v = get(v);
			u = get(u);
			if (v == u) {
				return false;
			}

			if (rank[v] < rank[u]) {
				int tmp = v;
				v = u;
				u = tmp;
			}

			if (rank[v] == rank[u]) {
				rank[v]++;
			}

			p[u] = v;
			return true;
		}
	}

	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	Main() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}