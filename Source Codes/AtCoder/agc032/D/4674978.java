import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	long fast(int[] p, int rgh, int lft) {
		int n = p.length;
		long[] dp = new long[n + 1];
		Arrays.fill(dp, LINF);

		dp[0] = 0;

		for (int v : p) {
			v++;
			long[] nxt = new long[n + 1];
			Arrays.fill(nxt, LINF);
			for (int i = 0; i <= n; i++) {
				if (dp[i] == LINF) {
					continue;
				}
				if (v < i) {
					nxt[i] = Math.min(nxt[i], dp[i] + lft);
				} else {
					nxt[v] = Math.min(nxt[v], dp[i]);
					nxt[i] = Math.min(nxt[i], dp[i] + rgh);
				}
			}
			dp = nxt;
		}

		return Arrays.stream(dp).min().getAsLong();
	}

	static class Perm {
		int[] p;

		public Perm(int[] p) {
			this.p = p;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + Arrays.hashCode(p);
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Perm other = (Perm) obj;
			if (!Arrays.equals(p, other.p))
				return false;
			return true;
		}
	}

	static class Dist implements Comparable<Dist> {
		Perm p;
		long dist;

		public Dist(Perm p, long dist) {
			this.p = p;
			this.dist = dist;
		}

		@Override
		public int compareTo(Dist o) {
			return Long.compare(dist, o.dist);
		}
	}

	long slow(int[] p, int rgh, int lft) {
		int n = p.length;
		Perm from = new Perm(p);
		Perm goal = new Perm(IntStream.range(0, n).toArray());

		HashMap<Perm, Long> dist = new HashMap<>();
		PriorityQueue<Dist> pq = new PriorityQueue<>();

		dist.put(from, 0L);
		pq.add(new Dist(from, 0));

		while (!pq.isEmpty()) {
			Dist tmp = pq.poll();
			Perm v = tmp.p;
			if (dist.get(v) != tmp.dist) {
				continue;
			}
			if (v.equals(goal)) {
				return tmp.dist;
			}

			int[] arr = v.p;

			for (int i = 0; i < n; i++) {
				int move = arr[i];
				for (int j = 0; j < i; j++) {
					int[] to = arr.clone();
					for (int k = i; k > j; k--) {
						to[k] = to[k - 1];
					}
					to[j] = move;
					Perm pto = new Perm(to);
					if (dist.getOrDefault(pto, LINF) > tmp.dist + lft) {
						dist.put(pto, tmp.dist + lft);
						pq.add(new Dist(pto, tmp.dist + lft));
					}
				}

				for (int j = i + 1; j < n; j++) {
					int[] to = arr.clone();
					for (int k = i; k < j; k++) {
						to[k] = to[k + 1];
					}
					to[j] = move;
					Perm pto = new Perm(to);
					if (dist.getOrDefault(pto, LINF) > tmp.dist + rgh) {
						dist.put(pto, tmp.dist + rgh);
						pq.add(new Dist(pto, tmp.dist + rgh));
					}
				}
			}
		}

		throw new AssertionError();
	}

	static final long LINF = Long.MAX_VALUE / 10;

	void submit() {
		int n = nextInt();
		int rgh = nextInt();
		int lft = nextInt();

		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
		}

		out.println(fast(p, rgh, lft));
	}

	static final int INF = 1_000_000;

	void test() {
		System.err.println(fast(new int[] { 3, 0, 2, 4, 1 }, 1, 1));
		System.err.println(slow(new int[] { 3, 0, 2, 4, 1 }, 1, 1));
	}

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(1, C);
			int[] p = new int[n];
			for (int i = 0; i < n; i++) {
				int j = rand(0, i);
				p[i] = p[j];
				p[j] = i;
			}
			int rgh = rand(1, 100);
			int lft = rand(1, 100);
			if (fast(p, rgh, lft) != slow(p, rgh, lft)) {
				System.err.println(Arrays.toString(p));
				System.err.println(rgh + " " + lft);
				System.err.println(fast(p, rgh, lft));
				System.err.println(slow(p, rgh, lft));
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
	static final int C = 7;

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