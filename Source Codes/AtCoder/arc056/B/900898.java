import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.PriorityQueue;

public class Main{
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);

		solver2();
		out.flush();
	}

	void solver() {
		int N = ni();// the number of people and vertices
		int M = ni();// the number of edges
		int S = ni() - 1;// start
		ArrayList<Integer>[] e = new ArrayList[N];
		for (int i = 0; i < N; i++) {
			e[i] = new ArrayList<>();
		}
		for (int i = 0; i < M; i++) {
			int u = ni() - 1;
			int v = ni() - 1;
			e[u].add(v);
			e[v].add(u);
		}
		int[] mx = new int[N];
		Arrays.fill(mx, -1);
		mx[S] = S;
		PriorityQueue<Pair> q = new PriorityQueue<Pair>(new Comparator<Pair>() {
			@Override
			public int compare(Pair o1, Pair o2) {
				return -Integer.compare(o1.max, o2.max);
			}
		});
		q.add(new Pair(S, S));
		while (!q.isEmpty()) {
			Pair v = q.poll();
			if (mx[v.num] == -1)
				throw new AssertionError();
			for (int i = 0; i < e[v.num].size(); i++) {
				int u = e[v.num].get(i);
				if (mx[u] >= mx[v.num])
					continue;
				mx[u] = Math.min(u, mx[v.num]);
				q.add(new Pair(u, mx[u]));
			}
		}
		for (int i = 0; i < N; i++) {
			if (mx[i] == i) {
				out.println((i + 1));
			} else if (mx[i] > i) {
				throw new AssertionError();
			}
		}
	}

	class Pair {
		int num;
		int max;// ??????????????????????(0-origin)

		Pair(int num, int max) {
			this.num = num;
			this.max = max;
		}
	}

	void solver2() {
		int n = ni();
		int m = ni();
		int s = ni() - 1;
		ArrayList<Integer>[] e = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			e[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int u = ni() - 1;
			int v = ni() - 1;
			e[u].add(v);
			e[v].add(u);
		}
		boolean[] d = new boolean[n];
		DJSet ds = new DJSet(n);
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < e[i].size(); j++) {
				int u = e[i].get(j);
				if (u > i) {
					ds.setUnion(u, i);
				}
			}
			if (ds.equiv(i, s)) {
				d[i] = true;
			}
		}
		for (int i = 0; i < n; i++) {
			if (d[i]) {
				out.println(i + 1);
			}
		}
	}

	class DJSet {
		int n;// the number of vertices
		int[] d;

		DJSet(int n) {
			this.n = n;
			d = new int[n];
			Arrays.fill(d, -1);
		}

		int root(int x) {
			return d[x] < 0 ? x : (d[x] = root(d[x]));
		}

		boolean setUnion(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (x < y) {
					int d = x;
					x = y;
					y = d;
				}
				// x>y
				d[y] += d[x];
				d[x] = y;
			}
			return x != y;
		}

		boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		// x?????Node??
		int size(int x) {
			return d[root(x)] * (-1);
		}

		// ???????
		int count() {
			int ct = 0;
			for (int u : d) {
				if (u < 0)
					ct++;
			}
			return ct;
		}
	}

	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";

	static long nl() {
		try {
			long num = 0;
			boolean minus = false;
			while ((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'))
				;
			if (num == '-') {
				num = 0;
				minus = true;
			} else {
				num -= '0';
			}

			while (true) {
				int b = is.read();
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}

	static char nc() {
		try {
			int b = skip();
			if (b == -1)
				return 0;
			return (char) b;
		} catch (IOException e) {
		}
		return 0;
	}

	static double nd() {
		try {
			return Double.parseDouble(ns());
		} catch (Exception e) {
		}
		return 0;
	}

	static String ns() {
		try {
			int b = skip();
			StringBuilder sb = new StringBuilder();
			if (b == -1)
				return "";
			sb.append((char) b);
			while (true) {
				b = is.read();
				if (b == -1)
					return sb.toString();
				if (b <= ' ')
					return sb.toString();
				sb.append((char) b);
			}
		} catch (IOException e) {
		}
		return "";
	}

	public static char[] ns(int n) {
		char[] buf = new char[n];
		try {
			int b = skip(), p = 0;
			if (b == -1)
				return null;
			buf[p++] = (char) b;
			while (p < n) {
				b = is.read();
				if (b == -1 || b <= ' ')
					break;
				buf[p++] = (char) b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}

	public static byte[] nse(int n) {
		byte[] buf = new byte[n];
		try {
			int b = skip();
			if (b == -1)
				return null;
			is.read(buf);
			return buf;
		} catch (IOException e) {
		}
		return null;
	}

	static int skip() throws IOException {
		int b;
		while ((b = is.read()) != -1 && !(b >= 33 && b <= 126))
			;
		return b;
	}

	static boolean eof() {
		try {
			is.mark(1000);
			int b = skip();
			is.reset();
			return b == -1;
		} catch (IOException e) {
			return true;
		}
	}

	static int ni() {
		try {
			int num = 0;
			boolean minus = false;
			while ((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'))
				;
			if (num == '-') {
				num = 0;
				minus = true;
			} else {
				num -= '0';
			}

			while (true) {
				int b = is.read();
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.