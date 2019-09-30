import java.io.*;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class C {
	BufferedReader in;
	StringTokenizer str;
	PrintWriter out;
	String SK;

	String next() throws IOException {
		while ((str == null) || (!str.hasMoreTokens())) {
			SK = in.readLine();
			if (SK == null)
				return null;
			str = new StringTokenizer(SK);
		}
		return str.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	class Eat implements Comparable<Eat> {
		int cost;
		int time;

		public Eat(int a, int b) {
			cost = a;
			time = b;
		}

		@Override
		public int compareTo(Eat o) {
			return time - o.time;
		}
	}

	void solve() throws IOException {
		int m = nextInt();
		int f = nextInt();
		int n = nextInt();
		Eat[] a = new Eat[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Eat(nextInt(), nextInt() + 1);
		}
		Arrays.sort(a);
		Eat[] b = new Eat[n];
		int t = 1;
		b[0] = a[0];
		for (int i = 1; i < n; i++) {
			b[t++] = a[i];
			while (t > 1 && b[t - 1].cost <= b[t - 2].cost) {
				b[t - 2] = b[t - 1];
				t--;
			}
		}
		long[] cost = new long[n];
		n = t;
		cost[0] = b[0].time * b[0].cost;
		for (int i = 1; i < n; i++) {
			cost[i] = cost[i - 1] + (b[i].time - b[i - 1].time) * b[i].cost;
		}
		int l = 0;
		int r = 2000002;
		while (l < r - 1) {
			int nn = (l + r) / 2;
			long[] rs = new long[nn + 1];
			rs[0] = 0;
			for (int i = 1; i <= nn; i++) {
				rs[i] = Long.MAX_VALUE;
				for (int j = 0; j < n; j++) {
					if (b[j].time <= i) {
						rs[i] = Math
								.min(rs[i], rs[i - b[j].time] + cost[j] + f);
					} else {
						long stcost;
						if (j == 0) {
							stcost = i * b[j].cost;
						} else {
							stcost = cost[j - 1] + b[j].cost
									* (i - b[j - 1].time);
						}
						rs[i] = Math.min(rs[i], stcost + f);
						break;
					}
				}
			}
			if (rs[nn] <= m) {
				l = nn;
			} else {
				r = nn;
			}
		}
		out.println(" " + l);
	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			System.err.println(i);
			out.print("Case #" + (i + 1) + ":");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().run();
	}

}