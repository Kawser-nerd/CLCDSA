import java.io.*;
import java.util.*;

public class AirportWalkways {

	class Segm implements Comparable<Segm> {
		int x, y;
		int v;

		public Segm(int x, int y, int v) {
			this.x = x;
			this.y = y;
			this.v = v;
		}

		@Override
		public int compareTo(Segm o) {
			if (this.v != o.v)
				return this.v - o.v;
			else
				return (this.y - this.x) - (o.y - o.x);
		}
	}

	void solve() throws Exception {
		int x = nextInt();
		int s = nextInt();
		int r = nextInt() - s;
		double t = nextInt();
		int n = nextInt();
		Segm[] a = new Segm[n + 1];
		int len = 0;
		for (int i = 0; i < n; i++) {
			a[i] = new Segm(nextInt(), nextInt(), nextInt() + s);
			len += (a[i].y - a[i].x);
		}
		a[n] = new Segm(0, x - len, s);
		Arrays.sort(a);
		double ans = 0;
		for (int i = 0; i < n + 1; i++) {
			int l = a[i].y - a[i].x;
			if ((a[i].v + r) * t >= l) {
				t -= ((double) l) / (a[i].v + r);
				ans += ((double) l) / (a[i].v + r);
			} else {
				double rmn = l - (a[i].v + r) * t;
				ans += t;
				t = 0;
				ans += rmn / (a[i].v);

			}
		}
		out.println(ans);
	}

	void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			int tests = nextInt();
			for (int i = 0; i < tests; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;
	final String filename = new String("AirportWalkways").toLowerCase();

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new AirportWalkways().run();
	}

}
