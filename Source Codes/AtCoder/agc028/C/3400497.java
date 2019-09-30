import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class Main {

	static class Event implements Comparable<Event> {
		int x, type, id;

		@Override
		public int compareTo(Event o) {
			return Integer.compare(x, o.x);
		}

		public Event(int x, int type, int id) {
			this.x = x;
			this.type = type;
			this.id = id;
		}
	}

	static boolean nextPermutation(int[] a) {
		int n = a.length;
		int ptr = n - 1;
		while (ptr > 0 && a[ptr - 1] >= a[ptr]) {
			ptr--;
		}

		for (int i = ptr, j = n - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}

		if (ptr <= 0) {
			return false;
		}

		for (int i = ptr;; i++) {
			if (a[ptr - 1] < a[i]) {
				int tmp = a[ptr - 1];
				a[ptr - 1] = a[i];
				a[i] = tmp;
				return true;
			}
		}
	}

	long slow(int[] a, int[] b) {
		int n = a.length;

		long ret = Long.MAX_VALUE;

		int[] p = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			p[i] = i + 1;
		}
		do {
			long here = 0;
			here += Math.min(a[0], b[p[0]]);
			for (int i = 0; i < n - 2; i++) {
				here += Math.min(a[p[i]], b[p[i + 1]]);
			}
			here += Math.min(a[p[n - 2]], b[0]);
			ret = Math.min(ret, here);
		} while (nextPermutation(p));

		return ret;
	}

	long go(int[] a, int[] b) {
		int n = a.length;

		Event[] c = new Event[2 * n];
		for (int i = 0; i < n; i++) {
			c[2 * i] = new Event(a[i], 0, i);
			c[2 * i + 1] = new Event(b[i], 1, i);
		}

		Arrays.sort(c);

		int[][] cnt = new int[2][n];

		for (int i = 0; i < n; i++) {
			cnt[c[i].type][c[i].id]++;
		}

		long ret = 0;

		boolean all0 = true, all1 = true, all = true;
		for (int i = 0; i < n; i++) {
			all0 &= cnt[0][i] == 1;
			all1 &= cnt[1][i] == 1;
			all &= cnt[0][i] + cnt[1][i] == 1;
			ret += c[i].x;
		}

		if (all0 || all1) {
			return ret;
		}

		if (!all) {
			return ret;
		}

		{
			cnt = new int[2][n];

			for (int i = 0; i < n - 1; i++) {
				cnt[c[i].type][c[i].id]++;
			}
			cnt[c[n].type][c[n].id]++;

			ret += c[n].x - c[n - 1].x;

			all0 = true;
			all1 = true;
			all = true;
			for (int i = 0; i < n; i++) {
				all0 &= cnt[0][i] == 1;
				all1 &= cnt[1][i] == 1;
				all &= cnt[0][i] + cnt[1][i] == 1;
			}

			if (all0 || all1) {
				return ret;
			}

			if (!all) {
				return ret;
			}
		}

		long ret1 = Long.MAX_VALUE;
		long ret2 = Long.MAX_VALUE;

		{
			cnt = new int[2][n];

			for (int i = 0; i < n - 2; i++) {
				cnt[c[i].type][c[i].id]++;
			}
			cnt[c[n - 1].type][c[n - 1].id]++;
			cnt[c[n].type][c[n].id]++;

			ret1 = ret + c[n - 1].x - c[n - 2].x;

			all0 = true;
			all1 = true;
			all = true;
			for (int i = 0; i < n; i++) {
				all0 &= cnt[0][i] == 1;
				all1 &= cnt[1][i] == 1;
				all &= cnt[0][i] + cnt[1][i] == 1;
			}

			if (!(all0 || all1) && all) {
				ret1 = Long.MAX_VALUE;
			}
		}

		{
			cnt = new int[2][n];

			for (int i = 0; i < n - 1; i++) {
				cnt[c[i].type][c[i].id]++;
			}
			cnt[c[n + 1].type][c[n + 1].id]++;

			ret2 = ret + c[n + 1].x - c[n].x;

			all0 = true;
			all1 = true;
			all = true;
			for (int i = 0; i < n; i++) {
				all0 &= cnt[0][i] == 1;
				all1 &= cnt[1][i] == 1;
				all &= cnt[0][i] + cnt[1][i] == 1;
			}

			if (!(all0 || all1) && all) {
				ret2 = Long.MAX_VALUE;
			}
		}

		return Math.min(ret1, ret2);
	}

	void submit() {
		int n = nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			b[i] = nextInt();
		}

		// out.println(slow(a, b));
		out.println(go(a, b));
		// out.println((sum - go(a, b)) / 2);
		// out.println((sum - slow(a, b)) / 2);
	}

	void test() {
		System.err.println(go(new int[] { 3, 5, 1 }, new int[] { 4, 1, 4 }));
		System.err.println(slow(new int[] { 3, 5, 1 }, new int[] { 4, 1, 4 }));
	}

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(2, C);
			int[] a = new int[n];
			int[] b = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = rand(1, C);
				b[i] = rand(1, C);
			}
			if (go(a, b) != slow(a, b)) {
				System.err.println(Arrays.toString(a));
				System.err.println(Arrays.toString(b));
				System.err.println(go(a, b));
				System.err.println(slow(a, b));
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