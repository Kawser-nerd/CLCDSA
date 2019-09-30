import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

class Main implements Runnable {

	final static String taskname = "A-large";

	public void solve() throws Exception {
		int tests = iread();
		int inf = 1000000;
		for (int t = 1; t <= tests; t++) {
			int M = iread(), V = iread();
			int[] type = new int[M + 1], change = new int[M + 1];
			int[][] best = new int[2][M + 1];
			for (int i = 1; i <= M; i++) {
				type[i] = iread();
				if (i * 2 < M)
					change[i] = iread();
			}
			for (int i = M; i > 0; i--) {
				best[0][i] = inf;
				best[1][i] = inf;
				if (i * 2 > M) {
					best[type[i]][i] = 0;
					continue;
				}
				for (int left = 0; left < 2; left++)
					for (int right = 0; right < 2; right++) {
						int d = best[left][i*2]+best[right][i*2+1];
						if (d>=inf) continue;
						if (type[i] == 0 || change[i] > 0) {
							int val = left | right;
							if (type[i] == 0)
								best[val][i] = Math.min(best[val][i], d);
							else best[val][i] = Math.min(best[val][i], d+1);
						}
						if (type[i] == 1 || change[i] > 0) {
							int val = left & right;
							if (type[i] == 1)
								best[val][i] = Math.min(best[val][i], d);
							else best[val][i] = Math.min(best[val][i], d+1);
						}
					}
			}
			out.write("Case #"+t+": ");
			if (best[V][1]==inf)
				out.write("IMPOSSIBLE\n");
			else out.write(best[V][1]+"\n");
		}
	}

	public void run() {
		try {
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
