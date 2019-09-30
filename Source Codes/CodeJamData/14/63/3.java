import java.io.*;
import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "C";
//	final String filename = problem + "-sample";

	 final String filename= problem+"-small-attempt0";
	// final String filename= problem+"-small-attempt1";
	// final String filename= problem+"-large";

	public void solve() throws Exception {
		int N = iread();
		sym = new char[N];
		for (int i = 0; i < N; i++)
			sym[i] = readword().charAt(0);
		first = new Edge[N];
		Edge[] all = new Edge[N - 1];
		for (int i = 0; i + 1 < N; i++) {
			int x = iread(), y = iread();
			x--;
			y--;
			all[i] = new Edge(x, y);
			new Edge(y, x);
		}
		if (N % 2 == 0) {
			// EDGE
			int c1 = -1, c2 = -1;
			for (int i = 0; i + 1 < N; i++) {
				int x = all[i].from, y = all[i].to;
				if (dfs1(x, y) == dfs1(y, x) && sym[x] == sym[y]) {
					c1 = x;
					c2 = y;
					break;
				}
			}
			if (c1 >= 0) {
				if (dfs(c1, c2).compareTo(dfs(c2, c1)) == 0) {
					out.write("SYMMETRIC");
					return;
				}
			}
		}
		// VERTEX
		int center = -1;
		for (int i = 0; i < N; i++) {
			int best = 0;
			for (Edge e = first[i]; e != null; e = e.next)
				best = Math.max(best, dfs1(e.to, i));
			if (best <= (N + 1) / 2) {
				center = i;
				break;
			}
		}
		if (center == -1) {
			out.write("NOT SYMMETRIC");
			return;
		}
		if (dfs(center, -1).bad <= 2) {
			out.write("SYMMETRIC");
		} else
			out.write("NOT SYMMETRIC");
	}

	char[] sym;

	int dfs1(int x, int par) {
		int cnt = 1;
		for (Edge e = first[x]; e != null; e = e.next)
			if (e.to != par)
				cnt += dfs1(e.to, x);
		return cnt;
	}

	SubTree dfs(int x, int par) {
		ArrayList<SubTree> list = new ArrayList<SubTree>();
		list.clear();
		for (Edge e = first[x]; e != null; e = e.next) {
			if (e.to == par)
				continue;
			list.add(dfs(e.to, x).wrap(sym[e.to]));
		}
		Collections.sort(list);
		if (list.size() == 0)
			return new SubTree();
		int bad = 0;
		{
			int i = 0;
			while (i < list.size()) {
				if (i + 1 < list.size()
						&& list.get(i).compareTo(list.get(i + 1)) == 0) {
					i += 2;
				} else {
					int b = list.get(i).bad;
					if (b >= 2) {
						bad = 3;
						break;
					}
					bad++;
					if (bad > 2)
						break;
					i++;
				}
			}
		}
		for (int i = 1; i < list.size(); i++)
			list.get(0).merge(list.get(i));
		if (bad > 2)
			bad = 3;
		list.get(0).bad = bad;
		return list.get(0);
	}

	class SubTree implements Comparable<SubTree> {
		int N;
		char[] d = new char[0];
		int bad = 0;

		public int compareTo(SubTree o) {
			if (N != o.N)
				return o.N - N;
			for (int i = 0; i < d.length; i++) {
				if (d[i] < o.d[i])
					return 1;
				else if (d[i] > o.d[i])
					return -1;
			}
			return 0;
		}

		SubTree merge(SubTree y) {
			int N1 = N + y.N;
			char[] mask1 = Arrays.copyOf(d, N1);
			System.arraycopy(y.d, 0, mask1, N, y.N);
			d = mask1;
			N = N1;
			return this;
		}

		SubTree wrap(char c) {
			int N1 = N + 2;
			char[] mask1 = Arrays.copyOf(d, N1);
			System.arraycopy(d, 0, mask1, 1, N);
			mask1[0] = c;
			mask1[N1 - 1] = '0';
			d = mask1;
			N = N1;
			return this;
		}
	}

	Edge[] first;

	class Edge {
		int from, to;
		Edge next;

		public Edge(int from, int to) {
			this.from = from;
			this.to = to;
			next = first[from];
			first[from] = this;
		}
	}

	DecimalFormat df = new DecimalFormat("0.0000000000");

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			solve();
			out.write("\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new BufferedWriter(new FileWriter(filename + ".out"));
			solve_gcj();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {

		}
		new Thread(new Main()).start();
		// new Thread(null, new Main(), "1", 1<<25).start();
	}
}