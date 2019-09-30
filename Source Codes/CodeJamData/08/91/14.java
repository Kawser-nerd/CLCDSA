import java.io.*;
import java.util.*;
import java.math.*;

public class Juice_simp implements Runnable {

	public static void main(String[] args) {
		new Thread(new Juice_simp()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(this.hashCode());

	@Override
	public void run() {
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

	String FNAME = "juice";

	private void solve() throws IOException {
		int testn = nextInt();
		for (int test = 0; test < testn; test++) {
			out.print("Case #" + (test + 1) + ": ");
			int n = nextInt();
			int[][] a = new int[n][3];
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					a[i][j] = nextInt();
				}
			}
			int max = 0;
			int[] b = new int[3];
			for (b[0] = 0; b[0] <= 10000; b[0]++) {
				for (b[1] = 0; b[0] + b[1] <= 10000; b[1]++) {
					b[2] = 10000 - b[0] - b[1];
					int m = 0;
					for (int i = 0; i < a.length; i++) {
						boolean good = true;
						for (int j = 0; j < b.length; j++) {
							good &= b[j] >= a[i][j];
						}
						if (good) {
							m++;
						}
					}
					max = Math.max(m, max);
				}
			}
			out.println(max);
		}
	}

}
