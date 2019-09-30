import java.io.*;
import java.util.*;

/**
 * @author Mikhail Dvorkin
 */
public class B implements Runnable {
	private Scanner in;
	private PrintWriter out;

	class Offer implements Comparable<Offer> {
		int c, from, to;

		public Offer(Scanner in) {
			String col = in.next();
			if (!colors.containsKey(col))
				colors.put(col, colors.size());
			c = colors.get(col);
			from = in.nextInt();
			to = in.nextInt();
		}

		public int compareTo(Offer o) {
			return from - o.from;
		}
	}

	int n;
	HashMap<String, Integer> colors;
	Offer[] offers;
	int[] cols = new int[3];
	boolean[] on = new boolean[1000];
	int ans;

	private void solve(int testCase) {
		n = in.nextInt();
		ans = n + 1;
		colors = new HashMap<String, Integer>();
		offers = new Offer[n];
		for (int i = 0; i < n; i++) {
			offers[i] = new Offer(in);
		}
		Arrays.sort(offers);
		go(Math.max(colors.size(), 3), 0);
		out.println("Case #" + testCase + ": " + ((ans == n + 1) ? "IMPOSSIBLE" : ("" + ans)));
	}

	private void go(int max, int x) {
		if (x == 3) {
			for (int c : cols)
				on[c] = true;
			solve();
			for (int c : cols)
				on[c] = false;
			return;
		}
		for (int i = max; i >= 0; i--) {
			cols[x] = i;
			go(i - 1, x + 1);
		}
	}

	private void solve() {
		int x = 1;
		int besty = -1;
		int took = 0;
		loop:
		for (Offer o : offers) {
			if (!on[o.c])
				continue;
			if (o.from > x) {
				if (besty == -1)
					break loop;
				took++;
				x = besty + 1;
				besty = -1;
				if (o.from > x) {
					break loop;
				}
			}
			if (o.to >= x)
				besty = Math.max(besty, o.to);
		}
		if (besty != -1) {
			took++;
			x = besty + 1;
		}
		if (x == 10001)
			ans = Math.min(ans, took);
	}

//	private void solve() {
//		int x = 1;
//		int t = 0;
//		while (x <= 10000) {
//			int y = -1;
//			for (Offer o : offers) {
//				if (on[o.c] && o.from <= x && o.to >= x)
//					y = Math.max(y, o.to);
//			}
//			if (y == -1)
//				return;
//			x = y + 1;
//			t++;
//		}
//		ans = Math.min(ans, t);
//	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Thread(new B()).start();
	}

	public void run() {
		try {
			in = new Scanner(new FileReader("b.in"));
			out = new PrintWriter("b.out");
			int n = in.nextInt();
			for (int i = 1; i <= n; i++)
				solve(i);
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
