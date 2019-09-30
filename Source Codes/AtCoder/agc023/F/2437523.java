import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	int[] p;
	int[] rank;
	int[] top;
	int[] c0, c1;

	void submit() {
		int n = nextInt();
		int[] par = new int[n];
		par[0] = -1;
		for (int i = 1; i < n; i++) {
			par[i] = nextInt() - 1;
		}
		int[] val = new int[n];
		for (int i = 0; i < n; i++) {
			val[i] = nextInt();
		}
		out.println(solve(par, val));
		// System.err.println(slow(par, val));
	}

	long slow(int[] par, int[] val) {
		int n = par.length;
		ArrayList<Integer> lst = new ArrayList<>();
		lst.add(0);
		ArrayList<Integer> seq = new ArrayList<>();

		return go(lst, seq, par, val);
	}

	long go(ArrayList<Integer> lst, ArrayList<Integer> seq, int[] par, int[] val) {
		if (lst.isEmpty()) {
			int c1 = 0;
			int ret = 0;
			for (int v : seq) {
				if (v == 0) {
					ret += c1;
				} else {
					c1++;
				}
			}
			return ret;
		}
		long ret = Long.MAX_VALUE;
		for (Integer v : lst) {
			ArrayList<Integer> tmp = new ArrayList<>(lst);
			tmp.remove(v);
			for (int i = 0; i < par.length; i++) {
				if (par[i] == v) {
					tmp.add(i);
				}
			}
			seq.add(val[v]);

			ret = Math.min(ret, go(tmp, seq, par, val));
			seq.remove(seq.size() - 1);
		}

		return ret;
	}

	long solve(int[] par, int[] val) {

		int n = par.length;

		p = IntStream.range(0, n).toArray();
		rank = new int[n];
		top = p.clone();
		c0 = new int[n];
		c1 = new int[n];

		for (int i = 0; i < n; i++) {
			(val[i] == 0 ? c0 : c1)[i]++;
		}

		TreeSet<Integer> set = new TreeSet<>((x, y) -> {
			long v0 = (long) c0[x] * c1[y];
			long v1 = (long) c1[x] * c0[y];
			if (v0 != v1) {
				return v0 < v1 ? -1 : 1;
			}
			return x.compareTo(y);
		});

		for (int i = 1; i < n; i++) {
			set.add(i);
		}

		long ans = 0;

		while (!set.isEmpty()) {
			int v = set.pollLast();
			int u = top[get(par[v])];
			ans += (long) c1[u] * c0[v];
			if (u != 0) {
				set.remove(u);
			}
			c0[u] += c0[v];
			c1[u] += c1[v];
			if (u != 0) {
				set.add(u);
			}
			unite(v, u);
		}

		return ans;
	}

	void unite(int v, int u) {
		int newTop = u;
		v = get(v);
		u = get(u);
		if (v == u) {
			throw new AssertionError();
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
		top[v] = newTop;
	}

	int get(int v) {
		return p[v] == v ? v : (p[v] = get(p[v]));
	}

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(1, C);
			int[] par = new int[n];
			par[0] = -1;
			for (int i = 1; i < n; i++) {
				par[i] = rand(0, i - 1);
			}
			int[] val = new int[n];
			for (int i = 0; i < n; i++) {
				val[i] = rand(0, 1);
			}
			if (solve(par, val) != slow(par, val)) {
				System.err.println(Arrays.toString(par));
				System.err.println(Arrays.toString(val));
				System.err.println(solve(par, val));
				System.err.println(slow(par, val));
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