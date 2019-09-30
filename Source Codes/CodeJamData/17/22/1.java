import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "B";
	// final String filename = problem + "-sample";

//	final String filename = problem + "-small-attempt0";
	// final String filename= problem+"-small-attempt1";
	 final String filename = problem + "-large";

	char[] chars = new char[] { 'R', 'O', 'Y', 'G', 'B', 'V' };

	public void solve() throws Exception {
		int N = iread();

		int[] a = new int[6];
		for (int i = 0; i < 6; i++) {
			a[i] = iread();
		}
		for (int i = 0; i < 6; i += 2) {
			if (a[i] > 0 && a[i] == a[(i + 3) % 6]) {
				if (a[i] + a[(i + 3) % 6] == N) {
					for (int j = 0; j < N; j += 2) {
						out.write(chars[i]);
						out.write(chars[(i + 3) % 6]);
					}
				} else {
					out.write("IMPOSSIBLE");
				}
				return;
			}
			a[i] -= a[(i + 3) % 6];
			if (a[i] < 0) {
				out.write("IMPOSSIBLE");
				return;
			}
		}
		int[] srt = new int[] { 0, 2, 4 };
		for (int i = 0; i <= 1; i++) {
			for (int j = 1; j >= i; j--) {
				if (a[srt[j]] < a[srt[j + 1]]) {
					int t = srt[j + 1];
					srt[j + 1] = srt[j];
					srt[j] = t;
				}
			}
		}

		if (a[srt[0]] > a[srt[1]] + a[srt[2]]) {
			out.write("IMPOSSIBLE");
			return;
		}

		char[] ans = new char[N];
		int cur = 0;

		for (int a1 = 0; a1 < a[srt[0]]; a1++) {
			int x = srt[0];
			while (a[(x + 3) % 6] > 0) {
				ans[cur++] = chars[x];
				ans[cur++] = chars[(x + 3) % 6];
				a[(x + 3) % 6]--;
			}
			ans[cur++] = chars[x];

			if (a1 < a[srt[1]]) {
				x = srt[1];
				while (a[(x + 3) % 6] > 0) {
					ans[cur++] = chars[x];
					ans[cur++] = chars[(x + 3) % 6];
					a[(x + 3) % 6]--;
				}
				ans[cur++] = chars[x];
			}

			if (a1 >= a[srt[0]] - a[srt[2]]) {
				x = srt[2];
				while (a[(x + 3) % 6] > 0) {
					ans[cur++] = chars[x];
					ans[cur++] = chars[(x + 3) % 6];
					a[(x + 3) % 6]--;
				}
				ans[cur++] = chars[x];
			}
		}
		out.write(new String(ans));
	}

	class Unicorn {
		int color;
		int irregular;

		public Unicorn(int color, int irregular) {
			this.color = color;
			this.irregular = irregular;
		}
	}

	DecimalFormat df = new DecimalFormat("0.00000000");

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			solve();
			out.write("\n");
		}
	}

	public void run() {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			// out = new BufferedWriter(new OutputStreamWriter(System.out));
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new BufferedWriter(new FileWriter(filename + ".out"));
			solve_gcj();
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
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {

		}
		new Thread(new Main()).start();
		// new Thread(null, new Main(), "1", 1<<25).start();
	}
}