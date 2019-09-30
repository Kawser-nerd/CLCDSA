import java.util.*;
import java.io.*;

public class Template implements Runnable {

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private String name = "B-small-attempt0";
	
	static class ITree {
		int[] tree;
		int size;
		
		ITree(int n) {
			size = 1;
			while (size < n) {
				size <<= 1;
			}
			tree = new int[2 * size + 1];
			Arrays.fill(tree, 1000000000);
		}
		
		void set(int x, int v, int L, int R, int node) {
			tree[node] = Math.min(tree[node], v);
			if (L < R) {
				int mid = (L + R) / 2;
				if (x <= mid) {
					set(x, v, L, mid, node * 2 + 1);
				} else {
					set(x, v, mid + 1, R, node * 2 + 2);
				}
			}
		}
		
		int get(int l, int r, int L, int R, int node) {
			if (r < L || R < l) {
				return 1000000000;
			}
			if (l <= L && R <= r) {
				return tree[node];
			}
			int mid = (L + R) / 2;
			return Math.min(get(l, r, L, mid, node * 2 + 1), get(l, r, mid + 1, R, node * 2 + 2));
		}
	}
	
	static class Segment implements Comparable<Segment> {
		int a, b;
		String c;
		
		Segment(String c, int a, int b) {
			this.c = c;
			this.a = a;
			this.b = b;
		}

		public int compareTo(Segment o) {
			return b - o.b;
		}
	}
	
	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; ++test) {
			int n = nextInt();
//			int n = 100;
			Segment[] segs = new Segment[n];
			for (int i = 0; i < n; ++i) {
				segs[i] = new Segment(next(), nextInt(), nextInt());
//				segs[i] = new Segment("vasya", i + 1, i + 2);
			}
			Arrays.sort(segs);
			int ans = 1000000000;
			for (int i = 0; i < n; ++i) {
				for (int j = i; j < n; ++j) {
					for (int k = j; k < n; ++k) {
						ITree tree = new ITree(10001);
						tree.set(0, 0, 0, tree.size - 1, 0);
						for (Segment s : segs) {
							if (!s.c.equals(segs[i].c) && !s.c.equals(segs[j].c) && !s.c.equals(segs[k].c)) {
								continue;
							}
							int val = tree.get(s.a - 1, s.b - 1, 0, tree.size - 1, 0) + 1;
							tree.set(s.b, val, 0, tree.size - 1, 0);
						}
						ans = Math.min(ans, tree.get(10000, 10000, 0, tree.size - 1, 0));
					}
				}
			}
			out.println("Case #" + test + ": " + (ans == 1000000000 ? "IMPOSSIBLE" : ans));
		}
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(name + ".out");
			
			solve();
			
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
			System.exit(-1);
		}
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		new Thread(new Template()).start();
	}

}
