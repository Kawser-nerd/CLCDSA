import java.io.*;
import java.util.*;

public class Prizes {
	public static void main(String[] args) {
		new Prizes().run();
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

	String FNAME = "b";

	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			System.out.println("Case #" + test + ": ");
			int n = nextInt();
			long p = nextLong();
//			countStup(n, p);
			if (p == (1L << n)) {
				out.println(p - 1 + " " + (p - 1));
				System.out.println(p - 1 + " " + (p - 1));
				continue;
			}
			int min = Integer.MAX_VALUE / 2;
			int zero = n - Long.bitCount(p);
			for (int i = 0; i < n; i++) {
				if ((p & (1L << i)) == 0) {
					zero--;
				} else {
					min = Math.min(min, zero + 1);
				}
			}
			long looser = 0;
			while (min-- > 0) {
				looser = 2 * looser + 1;
			}
			p--;
			int best = Integer.MAX_VALUE / 2;
			int cnt = Long.bitCount(p);
			for (int i = 0; i < n; i++) {
				if ((p & (1L << i)) == 0) {
					best = Math.min(best, cnt + 1);
				} else {
					cnt--;
				}
			}
			long winner = 0;
			while (best-- > 0) {
				winner = 2 * winner + 1;
			}
			out.println((winner - 1) + " " + ((1L << n) - looser - 1));
			System.out.println((winner - 1) + " " + ((1L << n) - looser - 1));
		}
	}

	private void countStup(int n, long p) {
		int[] a = new int[1 << n];
		for (int i = 0; i < a.length; i++) {
			a[i] = i;
		}
		int max = Integer.MIN_VALUE / 2;
		boolean[] good = new boolean[a.length];
		Arrays.fill(good, true);
		do {
			Item[] b = new Item[a.length];
			for (int i = 0; i < b.length; i++) {
				b[i] = new Item(a[i]);
			}
			for (int i = n - 1; i >= 0; i--) {
				for (int j = 0; j < b.length; j += 2) {
					if (b[j].id < b[j + 1].id) {
						b[j + 1].prof |= 1 << i;
					} else {
						b[j].prof |= 1 << i;
					}
				}
				Arrays.sort(b);
			}
			for (int i = 0; i < p; i++) {
				max = Math.max(max, b[i].id);
			}
			for (int i = (int) p; i < b.length; i++) {
				good[b[i].id] = false;
			}
		} while (next(a));

		int min = 0;
		while (min + 1 < good.length && good[min + 1]) {
			min++;
		}
		System.out.println(min + " " + max);
	}

	class Item implements Comparable<Item> {
		int prof;
		int id;

		@Override
		public String toString() {
			return "" + id;
		}

		public Item(int i) {
			id = i;
			prof = 0;
		}

		@Override
		public int compareTo(Item o) {
			return prof - o.prof;
		}

	}

	private boolean next(int[] a) {
		boolean[] q = new boolean[a.length];
		int i = a.length - 1;
		while (i > 0 && a[i - 1] > a[i]) {
			q[a[i]] = true;
			i--;
		}
		if (i == 0) {
			return false;
		}
		q[a[i]] = true;
		q[a[i - 1]] = true;
		a[i - 1]++;
		while (!q[a[i - 1]]) {
			a[i - 1]++;
		}
		q[a[i - 1]] = false;
		int j = 0;
		while (i < a.length) {
			while (!q[j]) {
				j++;
			}
			q[j] = false;
			a[i] = j;
			i++;
		}
		return true;
	}
}
