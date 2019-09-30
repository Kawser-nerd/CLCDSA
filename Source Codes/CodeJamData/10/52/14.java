import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "B";
//	 final String filename= problem+"-sample";
//	final String filename = problem + "-small-attempt1";

	// final String filename= problem+"-attempt1";
	 final String filename= problem+"-large";

	public void solve() throws Exception {
		final int inf = 1000000;
		long L = lread();
		int N = iread();
		int[] b = new int[N];
		for (int i = 0; i < N; i++)
			b[i] = iread();
		Arrays.sort(b);
		int mod = b[N - 1];

		int[] queue = new int[mod * 4 + 2], qq = new int[mod * 4 + 2];
		int[] best = new int[mod];
		Arrays.fill(best, inf);
		int ql = 2 * mod, qr = ql;
		queue[qr++] = 0;
		best[0] = 0;
		while (ql < qr) {

			int cur = queue[ql];
			int len = qq[ql];
			ql++;
			if (len > best[cur])
				continue;
			for (int i = 0; i < N - 1; i++) {
				int next = cur + b[i];
				boolean flag = false;
				if (next >= mod) {
					flag = true;
					next -= mod;
				}
				int t = best[cur] + (flag ? 0 : 1);
				if (best[next] <= t)
					continue;
				best[next] = t;
				if (flag) {
					qq[--ql] = t;
					queue[ql] = next;
				} else {
					qq[qr] = t;
					queue[qr++] = next;
				}
			}
		}
		int f = (int) (L % mod);
		if (best[f] == inf) {
			out.write("IMPOSSIBLE");
			return;
		}
		long ans = best[f] + (L - f) / mod;
		out.write(ans + "");
		;
	}

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