import java.io.*;
import java.util.*;

public class A {

	static class Segment implements Comparable<Segment> {
		int len;
		int w;

		public Segment(int len, int w) {
			this.len = len;
			this.w = w;
		}

		@Override
		public int compareTo(Segment o) {
			return w - o.w;
		}
	}

	private void solve() throws IOException {
		int x = nextInt();
		int s = nextInt(), r = nextInt();
		int t = nextInt();
		int n = nextInt();
		Segment[] segments = new Segment[n + 1];
		for (int i = 0; i < n; i++) {
			segments[i] = new Segment(-nextInt() + nextInt(), nextInt());
			x -= segments[i].len;
		}
		segments[n] = new Segment(x, 0);
		Arrays.sort(segments);
		double run = t;
		double time = 0;
		for (Segment segm : segments) {
			double freeDist = Math.min(run * (r + segm.w), segm.len);
			double t1 = freeDist / (r + segm.w);
			run -= t1;
			double t2 = (segm.len - freeDist) / (s + segm.w);
			time += t1;
			time += t2;
		}
		out.println(time);
	}

	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	static final boolean large = true;

	public void run() {
		try {
			String fileName = "A-" + (large ? "large" : "small");
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			st = new StringTokenizer("");
			int T = nextInt();
			for (int i = 1; i <= T; i++) {
				out.print("Case #" + i + ": ");
				solve();
			}
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}