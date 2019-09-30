import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "A-large";

	int f(int x, int k) {
		int res = 0;
		while (x > 0) {
			res += (x % k) * (x % k);
			x /= k;
		}
		return res;
	}

	public void solve() throws Exception {
		final int MAX = 1000;
		boolean[][] happy;
		int[][] mark;
		happy = new boolean[11][MAX];
		mark = new int[11][MAX];
		for (int k = 2; k <= 10; k++) {
			happy[k][1] = true;
			mark[k][1] = 2;
			for (int x = 2; x < MAX; x++) {
				int y = x;
				while (mark[k][y] == 0) {
					mark[k][y] = 1;
					y = f(y, k);
				}
				happy[k][x] = happy[k][y];
				y = x;
				while (mark[k][y] == 1) {
					mark[k][y] = 2;
					happy[k][y] = happy[k][x];
					y = f(y, k);
				}
			}
		}

		int[] ans = new int[1 << 9];
		Arrays.fill(ans, Integer.MAX_VALUE);
		for (int x = 2; x <= 12000000; x++) {
			int mask = 0;
			for (int k = 2; k <= 10; k++)
				if (happy[k][f(x, k)])
					mask |= 1 << (k - 2);
			ans[mask] = Math.min(ans[mask], x);
		}
		for (int m = 0; m < 1 << 9; m++) {
			for (int mask = 0; mask < m; mask++)
				if ((mask & m) == mask)
					ans[mask] = Math.min(ans[mask], ans[m]);
		}

		int T = Integer.parseInt(in.readLine());
		for (int ntest = 1; ntest <= T; ntest++) {
			String[] s = in.readLine().split(" +");
			int mask = 0;
			for (int i = 0; i < s.length; i++)
				mask |= 1<<(Integer.parseInt(s[i]) - 2);
			out.write("Case #" + ntest + ": " + ans[mask] + "\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(taskname + ".in"));
			out = new BufferedWriter(new FileWriter(taskname + ".out"));
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		// Locale.setDefault(Locale.US);
		new Thread(new Main()).start();
	}
}