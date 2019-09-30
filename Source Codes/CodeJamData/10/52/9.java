import java.io.*;
import java.util.*;

public class B {
	private static String fileName = B.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	int m;

	private void solve() {
		long len = in.nextLong();
		int n = in.nextInt();
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			b[i] = in.nextInt();
		}
		Arrays.sort(b);
		m = b[n - 1];
		int a0 = (int) (len % m);
		cost = new long[m];
		val = new long[m];
		Arrays.fill(val, -1);
		val[0] = 0;
		queue = new TreeSet<Entry>();
		queue.add(new Entry(0));
		while (!queue.isEmpty()) {
			int a = queue.pollFirst().rest;
			long v = val[a];
			long c = cost[a];
			if (a == a0) {
				if (val[a] <= len) {
					out.println(cost[a] + (len - v) / m);
				} else {
					throw new Error();
				}
				return;
			}
			for (int i = 0; i < n; i++) {
				int aa = (a + b[i]) % m;
				long v1 = v + b[i];
				long c1 = c + 1;
				long v0 = val[aa];
				long c0 = cost[aa];
				boolean better = false;
				if (v0 == -1) {
					better = true;
				} else {
					better = better(aa, v1, c1, aa, v0, c0);
				}
				if (better) {
					if (queue.contains(new Entry(aa))) {
						queue.remove(new Entry(aa));
					}
					val[aa] = v1;
					cost[aa] = c1;
					queue.add(new Entry(aa));
				}
			}
		}
		out.println("IMPOSSIBLE");
	}
	
	TreeSet<Entry> queue;
	long[] cost;
	long[] val;
	
	class Entry implements Comparable<Entry> {
		int rest;

		public Entry(int rest) {
			this.rest = rest;
		}

		@Override
		public int compareTo(Entry o) {
			if (better(rest, val[rest], cost[rest], o.rest, val[o.rest], cost[o.rest])) {
				return -1;
			} else {
				return 1;
			}
		}
	}

	private boolean better(int a1, long v1, long c1, int a2, long v2, long c2) {
		c1 -= (v1 - a1) / m;
		c2 -= (v2 - a2) / m;
		if (c1 != c2) {
			return c1 < c2;
		}
		return a1 > a2;
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			System.out.print("Case #" + t + ": ");
			new B().solve();
		}
		in.close();
		out.close();
	}
}
