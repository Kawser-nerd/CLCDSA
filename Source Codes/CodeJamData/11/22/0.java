import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "B-large";
	
	static class Point implements Comparable<Point> {
		int p, count;
		
		Point(int p, int count) {
			this.p = p;
			this.count = count;
		}

		@Override
		public int compareTo(Point o) {
			return p - o.p;
		}
	}

	public void solve(int test) throws IOException {
		out.print("Case #" + (test + 1) + ": ");
		int n = nextInt();
		int d = nextInt();
		Point[] ps = new Point[n];
		for (int i = 0; i < n; ++i) {
			ps[i] = new Point(nextInt(), nextInt());
		}
		Arrays.sort(ps);
		double l = 0., r = 1e15;
		loop: for (int it = 0; it < 200; ++it) {
			double t = (l + r) / 2;
			double last = Double.NEGATIVE_INFINITY;
			for (Point p : ps) {
				for (int i = 0; i < p.count; ++i) {
					double x = Math.max(last + d, p.p - t);
					if (x > p.p + t) {
						l = t;
						continue loop;
					}
					last = x;
				}
			}
			r = t;
		}
		out.println(r);
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(file + ".in"));
			out = new PrintWriter(file + ".out");
			eat("");
			
			int tests = nextInt();
			for (int test = 0; test < tests; ++test) {
				solve(test);
			}
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			failed = true;
		}
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
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
	
	static boolean failed = false;
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Thread th = new Thread(new Solution());
		th.start();
		try {
			th.join();
		} catch (InterruptedException iex) {
		}
		if (failed) {
			throw new RuntimeException();
		}
	}
	
}
