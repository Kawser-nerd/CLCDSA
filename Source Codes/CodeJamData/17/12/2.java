import java.io.*;
import java.util.*;
import java.math.*;

public class Food implements Runnable {

	public static void main(String[] args) {
		new Thread(new Food()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	@Override
	public void run() {
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(255);
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

	long nextLond() {
		return Long.parseLong(nextToken());
	}

	String FNAME = "b";

	private void solve() {
		int tests = nextInt();
		nextTest: for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			System.out.println(test);
			int n = nextInt();
			int p = nextInt();
			int[] c = new int[n];
			for (int i = 0; i < c.length; i++) {
				c[i] = nextInt();
			}
			int[][] a = new int[n][p];
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					a[i][j] = nextInt();
				}
				Arrays.sort(a[i]);
			}
			int[] pointer = new int[n];
			int ans = 0;
			loop: while (true) {
				for (int i = 0; i < pointer.length; i++) {
					if (pointer[i] >= a[i].length) {
						break loop;
					}
				}
				int low = 0;
				int high = Integer.MAX_VALUE / 2;
				for (int i = 0; i < pointer.length; i++) {
					int lowi = (a[i][pointer[i]] * 100 + 110 * c[i] - 1) / (110 * c[i]);
					int highi = (a[i][pointer[i]] * 100) / (90 * c[i]);
					low = Math.max(low, lowi);
					high = Math.min(high, highi);
				}
				if (low <= high) {
					ans++;
					for (int i = 0; i < pointer.length; i++) {
						pointer[i]++;
					}
				} else {
					for (int i = 0; i < pointer.length; i++) {
						int lowi = (a[i][pointer[i]] * 100 + 110 * c[i] - 1) / (110 * c[i]);
						int highi = (a[i][pointer[i]] * 100) / (90 * c[i]);
						if (highi < low) {
							pointer[i]++;
						}
					}
				}
			}
			out.println(ans);
		}
	}

}
