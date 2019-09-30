import java.io.*;
import java.util.*;

public class TicketSwapping {

	FastScanner in;
	PrintWriter out;

	final int mod = 1000002013;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] from = new int[m], to = new int[m], count = new int[m];

		long initAns = 0;
		List<Event> events = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			from[i] = in.nextInt() - 1;
			to[i] = in.nextInt() - 1;
			count[i] = in.nextInt();

			long dist = to[i] - from[i];
			long cost = (dist * (dist + 1) / 2) % mod;
			initAns += cost * count[i];
			initAns %= mod;

			events.add(new Event(from[i], count[i], 1));
			events.add(new Event(to[i], count[i], -1));
		}
		Collections.sort(events);
		long newAns = 0;
		List<Event> stack = new ArrayList<>();
		for (Event e : events) {
			if (e.type == 1) {
				stack.add(e);
			} else {
				while (e.count > 0) {
					Event top = stack.get(stack.size() - 1);
					long cnt = Math.min(top.count, e.count);
					top.count -= cnt;
					e.count -= cnt;
					if (top.count == 0) {
						stack.remove(stack.size() - 1);
					}
					System.err.println(e.x + " " + top.x + " " + cnt);
					long dist = e.x - top.x;
					long cost = (dist * (dist + 1) / 2) % mod;
					newAns += cnt * cost;
					newAns %= mod;
				}
			}
		}
		if (stack.size() != 0) {
			throw new AssertionError();
		}

		out.println((newAns - initAns + mod) % mod);
	}

	class Event implements Comparable<Event> {
		int x, count, type;

		public Event(int x, int count, int type) {
			super();
			this.x = x;
			this.count = count;
			this.type = type;
		}

		@Override
		public int compareTo(Event o) {
			int t1 = Integer.compare(x, o.x);
			int t2 = -Integer.compare(type, o.type);
			if (t1 != 0) {
				return t1;
			} else {
				return t2;
			}
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("input.txt"));
			out = new PrintWriter("output.txt");

			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				long time = System.currentTimeMillis();
				out.printf("Case #%d: ", (i + 1));
				solve();
				System.err.println("Test #" + (i + 1) + " done in "
						+ (System.currentTimeMillis() - time) + "ms");
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File file) {
			try {
				br = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new TicketSwapping().run();
	}
}
