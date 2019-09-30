import java.io.*;
import java.util.*;

public class B implements Runnable {

	public static void main(String[] args) {
		new Thread(new B()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public final boolean large = true;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			String FN = "B-" + (large ? "large" : "small");
			br = new BufferedReader(new FileReader(FN + ".in"));
			out = new PrintWriter(FN + ".out");
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

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	long l;
	int n;
	int[] a;

	class Pair implements Comparable<Pair> {
		long first;
		int second;

		public Pair(long first, int second) {
			this.first = first;
			this.second = second;
		}

		@Override
		public int compareTo(Pair o) {
			if (first != o.first)
				return Long.signum(first - o.first);
			return second - o.second;
		}

	}

	int test = 0;

	private void solve() throws IOException {
		l = nextLong();
		n = nextInt();
		a = new int[n];
		System.err.println("TEST: " + (++test));
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < a.length; i++) {
			a[i] = nextInt();
			max = Math.max(max, a[i]);
		}

		System.err.println(n + " " + l);
		System.err.println(Arrays.toString(a));
		long[] d = new long[max];
		Arrays.fill(d, Long.MAX_VALUE);
		d[0] = 0;
		TreeSet<Pair> q = new TreeSet<Pair>();
		q.add(new Pair(0, 0));
		while (!q.isEmpty()) {
			int u = q.pollFirst().second;

			for (int i = 0; i < n; i++) {
				int v = (u + a[i]) % max;
				int add = (u + a[i]) >= max ? 1 : 0;
				
				if (d[v] > d[u] + 1 - add) {
					q.remove(new Pair(d[v], v));
					d[v] = d[u] + 1 - add;
					q.add(new Pair(d[v], v));
				}
			}
		}

		int m = (int) (l % max);
		if (d[m] == Long.MAX_VALUE) {
			out.println("IMPOSSIBLE");
		} else {
			out.println(d[m] + (l / max));
		}

	}
}