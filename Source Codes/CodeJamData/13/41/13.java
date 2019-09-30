import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Tickets {
	public static void main(String[] args) {
		new Tickets().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(12345);

	private void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
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

	String FNAME = "a";

	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			System.out.println("Case #" + test + ": ");
			int n = nextInt();
			int m = nextInt();
			Event[] a = new Event[2 * m];
			BigInteger fair = BigInteger.ZERO;
			for (int i = 0; i < a.length; i += 2) {
				int o = nextInt();
				int e = nextInt();
				int p = nextInt();
				a[i] = new Event(o, p);
				a[i + 1] = new Event(e, -p);
				long d = e - o;
				fair = fair.add(BigInteger.valueOf(p).multiply(
						BigInteger.valueOf(d * n - d * (d - 1) / 2)));
			}
			System.out.println("fair:\t" + fair);
			Arrays.sort(a);
			BigInteger cheat = BigInteger.ZERO;
			TreeSet<Event> ts = new TreeSet<>();
			for (int i = 0; i < a.length; i++) {
				if (a[i].add > 0) {
					ts.add(a[i]);
				} else {
					long people = -a[i].add;
					while (people > 0) {
						Event e = ts.pollLast();
						long p = Math.min(people, e.add);
						e.add -= p;
						people -= p;
						int d = a[i].x - e.x;
						cheat = cheat.add(BigInteger.valueOf(p).multiply(
								BigInteger.valueOf(d * n - d * (d - 1) / 2)));
						if (e.add > 0) {
							ts.add(e);
						}
					}
				}
			}
			System.out.println("cheat:\t" + cheat);
			out.println(fair.subtract(cheat)
					.mod(BigInteger.valueOf(1000002013)));
		}
	}

	static class Event implements Comparable<Event> {
		int x;
		int add;
		int id;

		public Event(int o, int p) {
			x = o;
			add = p;
			id = ID++;
		}

		static int ID = 0;

		@Override
		public int compareTo(Event o) {
			if (x == o.x) {
				if (o.add == add) {
					return id - o.id;
				}
				return o.add - add;
			}
			return x - o.x;
		}
	}
}
