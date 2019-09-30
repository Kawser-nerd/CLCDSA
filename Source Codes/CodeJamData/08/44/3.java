import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "D-large";

	public void solve() throws Exception {
		int tests = iread();
		main: for (int t = 1; t <= tests; t++) {
			int k = iread();
			String s = readword();
			if (k == 1) {
				int ans = 1;
				for (int i = 0; i < s.length() - 1; i++)
					if (s.charAt(i) != s.charAt(i + 1))
						ans++;
				out.write("Case #" + t + ": " + ans + "\n");
				continue main;
			}
			if (k == 2) {
				int ans1 = 1;
				for (int i = 0; i < s.length() - 1; i++)
					if (s.charAt(i) != s.charAt(i + 1))
						ans1++;
				int ans2 = 1;
				for (int i = 0; i < s.length() - 1; i++)
					if (s.charAt(i ^ 1) != s.charAt((i + 1) ^ 1))
						ans2++;
				int ans = Math.min(ans1, ans2);
				out.write("Case #" + t + ": " + ans + "\n");
				continue main;
			}

			int[][] bonus = new int[k][k];
			int[][] bonus2 = new int[k][k];
			for (int d = 0; d < s.length(); d += k) {
				for (int i = 0; i < k; i++)
					for (int j = 0; j < k; j++) {
						if (s.charAt(d + i) == s.charAt(d + j))
							bonus[i][j]++;
						if (d + k < s.length()
								&& s.charAt(d + i) == s.charAt(d + k + j))
							bonus2[i][j]++;
					}
			}
			int ans = 0;
			for (int j = 0; j < k; j++) {
				int[][] d = new int[k][1 << k];
				for (int i = 0; i < k; i++) {
					Arrays.fill(d[i], -1);
					if (i == j)
						continue;
					int p = (1 << i) + (1 << j);
					d[i][p] = bonus2[j][i];
				}
				for (int p = 1 << j; p < 1 << k; p++)
					for (int u = 0; u < k; u++) {
						if (d[u][p] < 0)
							continue;
						for (int v = 0; v < k; v++) {
							if (((1 << v) & p) > 0)
								continue;
							int q = p | (1 << v);
							int d1 = d[u][p] + bonus[u][v];
							if (q + 1 == 1 << k) {
								ans = Math.max(ans, d1 + bonus[v][j]);
								continue;
							}
							if (d[v][q] < 0 || d[v][q] < d1)
								d[v][q] = d1;
						}
					}
			}
			ans = s.length() - ans;
			out.write("Case #" + t + ": " + ans + "\n");
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
