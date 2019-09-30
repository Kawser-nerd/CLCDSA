import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String problem = "C";
	// final String filename = problem + "-sample";

//	final String filename = problem + "-small-attempt0";
	// final String filename= problem+"-small-attempt1";
	 final String filename= problem+"-large";

	HashSet<String> str = new HashSet<String>();

	public void init() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(
				"garbled_email_dictionary.txt"));
		long time = System.currentTimeMillis();
		while (in.ready()) {
			String s = in.readLine();
			str.add(s);
			StringBuilder sb = new StringBuilder(s);
			for (int i = 0; i < s.length(); i++) {
				sb.setCharAt(i, '?');
				str.add(sb.toString());
				for (int j = i + 5; j < s.length(); j++) {
					sb.setCharAt(j, '?');
					str.add(sb.toString());
					sb.setCharAt(j, s.charAt(j));
				}
				sb.setCharAt(i, s.charAt(i));
			}
		}
		System.out.println(str.size() + " words generated in "
				+ (System.currentTimeMillis() - time) + "ms");
		in.close();
	}

	public void solve() throws Exception {
		final int INF = 10000;
		String S = readword();
		int n = S.length();
		int[][] best = new int[5][n + 1];
		for (int i = 0; i < 5; i++)
			Arrays.fill(best[i], INF);
		best[4][0] = 0;
		StringBuilder sb = new StringBuilder();
		for (int pos = 0; pos < n; pos++) {
			for (int len = 1; len <= 10 && pos + len <= n; len++) {
				sb.setLength(len);
				for (int i = 0; i < len; i++)
					sb.setCharAt(i, S.charAt(i + pos));
				if (str.contains(sb.toString())) {
					for (int sh = 0; sh < 5; sh++) {
						int t = best[sh][pos];
						if (t == INF)
							continue;
						int v = Math.min(4, sh + len);
						best[v][pos + len] = Math.min(best[v][pos + len], t);
					}
				}
				for (int i = 0; i < len; i++) {
					int t = INF;
					for (int sh = Math.max(0, 4 - i); sh < 5; sh++) {
						t = Math.min(t, best[sh][pos]);
					}
					sb.setCharAt(i, '?');
					if (str.contains(sb.toString())) {
						int v = Math.min(4, len - i - 1);
						best[v][pos + len] = Math
								.min(best[v][pos + len], t + 1);
					}
					for (int j = i + 5; j < len; j++) {
						sb.setCharAt(j, '?');
						if (str.contains(sb.toString())) {
							int v = Math.min(4, len - j - 1);
							best[v][pos + len] = Math.min(best[v][pos + len],
									t + 2);
						}
						sb.setCharAt(j, S.charAt(j + pos));
					}
					sb.setCharAt(i, S.charAt(i + pos));
				}
			}
		}
		int ans = INF;
		for (int i = 0; i < 5; i++)
			ans = Math.min(ans, best[i][n]);
		out.write(ans + "");
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
			init();
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