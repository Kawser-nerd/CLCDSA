import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";

	public static void main(String[] args) throws Exception {
		new Main().run();
	}

	void solver() {
		int n = ni();
		int m = ni();
		ArrayList<Edge>[] g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int c = ni();
			int a = ni();
			int b = ni();
			g[a].add(new Edge(a, b, c));
			g[b].add(new Edge(b, a, c));
		}
		long[] dist = new long[n];
		Arrays.fill(dist, 1L << 60);
		PriorityQueue<State> que = new PriorityQueue<>();
		que.add(new State(0, 0, 0));

		dist[0] = 0;
		while (!que.isEmpty()) {
			State s = que.poll();
			if (dist[s.cur] < s.dist)
				continue;
			dist[s.cur] = s.dist;
			for (Edge e : g[s.cur]) {
				int ndist = s.dist;
				if (e.type == 0) {
					ndist += 1;
					if (ndist < dist[e.dst]) {
						que.add(new State(e.dst, s.mcnt, ndist));
					}
				} else {
					ndist += s.mcnt + 1;
					if (ndist < dist[e.dst]) {
						que.add(new State(e.dst, s.mcnt + 1, ndist));
					}
				}
			}
		}
		for (int v = 0; v < n; v++) {
			out.println(dist[v]);
		}
	}

	class State implements Comparable<State> {
		int cur;
		int mcnt;
		int dist;

		State(int cur, int mcnt, int dist) {
			this.cur = cur;
			this.mcnt = mcnt;
			this.dist = dist;
		}

		@Override
		public int compareTo(State o) {
			if (this.mcnt != o.mcnt)
				return Integer.compare(this.mcnt, o.mcnt);
			else
				return Integer.compare(this.dist, o.dist);
		}
	}

	class Edge {
		int src;
		int dst;
		int type;

		Edge(int src, int dst, int type) {
			this.src = src;
			this.dst = dst;
			this.type = type;
		}
	}

	void run() {
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		solver();
		out.flush();

	}

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

	static void tr(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.