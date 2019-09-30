import java.util.*;
import java.io.*;

public class Solution {

	final String filename = "sample";
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	static class Vector {
		double x, y;
		
		Vector(double x, double y) {
			this.x = x;
			this.y = y;
		}
		
		Vector diff(Vector b) {
			return new Vector(x - b.x, y - b.y);
		}
		
		double len() {
			return Math.sqrt(x * x + y * y);
		}
	}
	
	static double dist(Vector a, Vector b) {
		return a.diff(b).len();
	}
	
	static double per(Vector a, Vector b, Vector c) {
		return dist(a, b) + dist(b, c) + dist(c, a);
	}
	
	private void solve(int test) throws IOException {
		out.print("Case #" + test + ": ");
		int n = nextInt();
		final Vector[] vs = new Vector[n];
		Integer[] xs = new Integer[n];
		Integer[] ys = new Integer[n];
		for (int i = 0; i < n; ++i) {
			vs[i] = new Vector(nextDouble(), nextDouble());
			xs[i] = ys[i] = i;
		}
		Arrays.sort(xs, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return Double.compare(vs[o1].x, vs[o2].x);
			}
		});
		Arrays.sort(ys, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return Double.compare(vs[o1].y, vs[o2].y);
			}
		});
		int[] xid = new int[n];
		for (int i = 0; i < n; ++i) {
			xid[xs[i]] = i;
		}
		double[] lastAns = new double[n];
		Arrays.fill(lastAns, Double.POSITIVE_INFINITY);
		for (int sh = 1; lastAns.length > 1; ++sh) {
			int m = ((n - 1) >> sh) + 1;
			double[] ans = new double[m];
			ArrayList<Vector>[] ls = new ArrayList[m];
			for (int i = 0; i < m; ++i) {
				ls[i] = new ArrayList<Vector>();
				ans[i] = lastAns[2 * i];
				if (2 * i + 1 < lastAns.length) {
					ans[i] = Math.min(ans[i], lastAns[2 * i + 1]);
				}
			}
			for (int it = 0; it < n; ++it) {
				int i = ys[it];
				int j = xid[i] >> sh;
				double xBound = Double.POSITIVE_INFINITY;
				if (2 * j + 1 < lastAns.length) {
					xBound = vs[xs[(2 * j + 1) << (sh - 1)]].x;
				}
				if (Math.abs(vs[i].x - xBound) <= ans[j]) {
					ls[j].add(vs[i]);
				}
			}
			for (int i = 0; i < m; ++i) {
				for (int u = 0; u < ls[i].size(); ++u) {
					for (int v = u + 2; v < ls[i].size() && v < u + 16; ++v) {
						for (int w = u + 1; w < v; ++w) {
							ans[i] = Math.min(ans[i], per(ls[i].get(u), ls[i].get(v), ls[i].get(w)));
						}
					}
				}
			}
			lastAns = ans;
		}
		out.println(lastAns[0]);
	}
	
	Solution() {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new PrintWriter(filename + ".out");
			eat("");
			
			int tests = nextInt();
			for (int test = 1; test <= tests; ++test) {
				solve(test);
			}
			
			in.close();
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
			System.exit(-1);
		}
	}
	
	private void eat(String string) {
		st = new StringTokenizer(string);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
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
		new Solution();
	}
	
}
