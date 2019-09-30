import java.io.*;
import java.util.*;
import java.math.*;

public class CShit {
	public static void main(String[] args) throws Throwable {
		new CShit().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(this.hashCode());

	private void run() throws Throwable {
		Locale.setDefault(Locale.US);
		br = new BufferedReader(new FileReader(FNAME + ".in"));
		out = new PrintWriter(FNAME + ".out");
		solve();
		out.close();
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

	BigInteger nextBigInteger() {
		return new BigInteger(nextToken());
	}

	String FNAME = "c";

	private void solve() throws IOException {
		for (int test = 1, testn = nextInt(); test <= testn; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			HashMap<Integer, Corner> hm = new HashMap<Integer, Corner>();
			TreeSet<Corner> ts = new TreeSet<Corner>();
			while (n-- > 0) {
				Corner c = new Corner(nextInt(), nextInt());
				hm.put(c.x, c);
				ts.add(c);
			}
			int ans = 0;
			while (ts.first().v > 1) {
				ans++;
				Corner c = ts.pollFirst();
				hm.remove(c.x);
				Corner c1 = hm.get(c.x - 1);
				if (c1 == null) {
					c1 = new Corner(c.x - 1, 0);
				}
				hm.remove(c1.x);
				ts.remove(c1);
				Corner c2 = hm.get(c.x + 1);
				if (c2 == null) {
					c2 = new Corner(c.x + 1, 0);
				}
				hm.remove(c2.x);
				ts.remove(c2);
				c1.v++;
				c2.v++;
				c.v -= 2;
				if (c.v > 0) {
					hm.put(c.x, c);
					ts.add(c);
				}
				hm.put(c1.x, c1);
				ts.add(c1);
				hm.put(c2.x, c2);
				ts.add(c2);
			}
			out.println(ans);
		}
	}

	class Corner implements Comparable<Corner> {
		int x, v;

		public Corner(int nextInt, int nextInt2) {
			x = nextInt;
			v = nextInt2;
		}

		@Override
		public int compareTo(Corner c) {
			if (c.v == v) {
				return x - c.x;
			}
			return c.v - v;
		}

		@Override
		public boolean equals(Object o) {
			return (o instanceof Corner) && this.compareTo((Corner) o) == 0;
		}
	}

}