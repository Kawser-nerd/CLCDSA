import java.io.*;
import java.util.*;

public class KingdomRush {

	class Pair {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "Pair [x=" + x + ", y=" + y + "]";
		}
	}

	void solve() throws Exception {
		int n = nextInt();
		Pair[] a = new Pair[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Pair(nextInt(), nextInt());
		}
		Arrays.sort(a, new Comparator<Pair>() {
			@Override
			public int compare(Pair o1, Pair o2) {
				if (o1.x != o2.x) {
					return o1.x - o2.x;
				} else {
					return o1.y - o2.y;
				}
			}
		});

		int[] done = new int[n];
		int curStars = 0;
		int steps = 0;
		mainCycle: while (true) {
			steps++;
			for (int i = 0; i < n; i++) {
				if (done[i] != 2 && a[i].y <= curStars) {
					curStars += 2 - done[i];
					done[i] = 2;
					continue mainCycle;
				}
			}
			int max = Integer.MIN_VALUE;
			int maxPos = -1;
			for (int i = 0; i < n; i++) {
				if (done[i] == 0 && a[i].x <= curStars) {
					if (a[i].y > max) {
						max = a[i].y;
						maxPos = i;
					}
				}
			}
			if (maxPos != -1) {
				done[maxPos] = 1;
				curStars++;
				continue mainCycle;
			}
			break;
		}
		for (int i : done) {
			if (i != 2) {
				out.println("Too Bad");
				return;
			}
		}
		out.println(steps - 1);
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
	final String filename = new String("KingdomRush").toLowerCase();

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
		new KingdomRush().run();
	}

}
