import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "A-large";
	
	static class Segment implements Comparable<Segment> {
		double l, w;
		
		Segment(double l, double w) {
			this.l = l;
			this.w = w;
		}

		@Override
		public int compareTo(Segment o) {
			return Double.compare(w, o.w);
		}
	}

	public void solve(int test) throws IOException {
		out.print("Case #" + (test + 1) + ": ");
		double l = nextInt();
		double s = nextInt();
		double r = nextInt();
		double t = nextInt();
		int n = nextInt();
		PriorityQueue<Segment> q = new PriorityQueue<Segment>();
		for (int i = 0; i < n; ++i) {
			double u = nextInt();
			double v = nextInt();
			double w = nextInt();
			q.add(new Segment(v -u, w));
			l -= v - u;
		}
		q.add(new Segment(l, 0));
		double ans = 0.;
		while (!q.isEmpty()) {
			Segment seg = q.poll();
			double t0 = seg.l / (seg.w + r);
			if (t0 <= t) {
				t -= t0;
				ans += t0;
			} else {
				double x = (seg.w + r) * t;
				ans += t + (seg.l - x) / (seg.w + s);
				t = 0.;
			}
		}
		out.println(ans);
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
