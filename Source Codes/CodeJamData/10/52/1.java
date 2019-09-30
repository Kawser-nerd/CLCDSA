import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static class DistRequest implements Comparable<DistRequest> {
		
		final int id, dist;

		public DistRequest(int id, int dist) {
			this.id = id;
			this.dist = dist;
		}

		public int compareTo(DistRequest o) {
			return dist < o.dist ? -1 : dist > o.dist ? 1 : 0;
		}
	}
	
	static void solveTest() throws Exception {
		long l = nextLong();
		int n = nextInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		sort(a);
		int cnt = a[n - 1];
		int dist[] = new int[cnt];
		fill(dist, Integer.MAX_VALUE);
		dist[0] = 0;
		PriorityQueue<DistRequest> reqs = new PriorityQueue<DistRequest>();
		reqs.add(new DistRequest(0, 0));
		while (!reqs.isEmpty()) {
			DistRequest req = reqs.remove();
			int v = req.id;
			int d = dist[v];
			if (d != req.dist) {
				continue;
			}
			for (int i = 0; i < n - 1; i++) {
				int nv = (v + a[i]) % cnt;
				int nd = d + 1 - (v + a[i]) / cnt;
				if (nd < dist[nv]) {
					dist[nv] = nd;
					reqs.add(new DistRequest(nv, nd));
				}
			}
		}
		int id = (int) (l % cnt);
		if (dist[id] == Integer.MAX_VALUE) {
			out.println("IMPOSSIBLE");
		} else {
			out.println(dist[id] + (l / cnt));
		}
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
		}
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		System.out.print("Enter filename: ");
		System.out.flush();
		String filename = new BufferedReader(new InputStreamReader(System.in)).readLine();
		in = new BufferedReader(new InputStreamReader(
			new FileInputStream(new File(filename + ".in"))));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
			new FileOutputStream(new File(filename + ".out")))));
		solve();
		in.close();
		out.close();
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}
	
	static long nextLong() throws IOException {
		return parseLong(next());
	}
	
	static double nextDouble() throws IOException {
		return parseDouble(next());
	}
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}
}