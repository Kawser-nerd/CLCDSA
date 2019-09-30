import java.util.*;
import java.io.*;

public class D {
	
	char[] init;
	int n;
	double[] prob;
	double[] gain;
	
	private void solve() throws Exception {
		init = nextToken().toCharArray();
		n = init.length;
		prob = new double[1 << n];
		gain = new double[1 << n];
		int initMask = 0;
		for (int i = 0; i < n; ++i) {
			if (init[i] == 'X') {
				initMask |= 1 << i;
			}
		}
		prob[initMask] = 1;
		for (int mask = 0; mask < (1 << n) - 1; ++mask) {
			if (prob[mask] == 0) {
				continue;
			}
			gain[mask] /= prob[mask];
			for (int where = 0; where < n; ++where) {
				int next = where;
				int cost = n;
				while ((mask >> next & 1) == 1) {
					next = (next + 1) % n;
					--cost;
				}
				prob[mask | (1 << next)] += prob[mask] / n;
				gain[mask | (1 << next)] += (double) prob[mask] * (cost + gain[mask]) / n;
			}
		}
		out.printf("%.15f\n", gain[(1 << n) - 1]);
	}

	public void run() {
		try {
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
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

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private D(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		long start = System.currentTimeMillis();
		new D("D").run();
		System.err.println("Done in " + (System.currentTimeMillis() - start) + "ms");
	}
}
