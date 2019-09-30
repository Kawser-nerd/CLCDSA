import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "E-small-attempt2";

	public void solve(int test) throws IOException {
		out.print("Case #" + (test + 1) + ": ");
		int x = nextInt();
		int m = nextInt();
		int n = nextInt();
//		double[] p = new double[n + 1];
//		for (int i = 1; i <= n; ++i) {
//			p[i] = 1.;
//			double tr = 0.;
//			for (int k = 1; k <= m; k *= 2) {
//				tr = Math.max(tr, (1. - 1. / (2. * k)) / (1. - p[Math.max(0, i - 1 - (2 * k - 1))] / (2. * k)));
//			}
//			for (int j = 0; j < i; ++j) {
//				p[j] *= tr;
//			}
//		}
		double[] p = new double[n + 1];
		p[n] = 1.;
		for (int it = 0; it < 100000; ++it) {
			for (int i = n - 1; i >= 0; --i) {
				for (int bet0 = 1; bet0 <= i && bet0 <= m; ++bet0) {
					double p1 = p[i], pcur = 1.;
					for (int bet = bet0; bet <= m; bet *= 2) {
						int loose = i - (2 * bet - bet0);
						int win = i + bet0;
						pcur /= 2;
						p1 = Math.max(p1, pcur * p[Math.max(0, loose)] + (1. - pcur) * p[Math.min(n, win)]);
					}
					p[i] = p1;
				}
			}
//			System.err.println(Arrays.toString(p));
		}
		int maxBet = 0;
		for (int bet0 = 1; bet0 <= x && bet0 <= m; ++bet0) {
			double p1 = 0., pcur = 1.;
			for (int bet = bet0; bet <= m; bet *= 2) {
				int loose = x - (2 * bet - bet0);
				int win = x + bet0;
				pcur /= 2;
				p1 = Math.max(p1, pcur * p[Math.max(0, loose)] + (1. - pcur) * p[Math.min(n, win)]);
			}
			if (p[x] - p1 < 1e-8) {
				maxBet = bet0;
			}
		}
		out.println(p[x] + " " + maxBet);
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(file + ".in"));
			out = new PrintWriter(file + ".out");
			eat("");
			
			int tests = nextInt();
			for (int test = 0; test < tests; ++test) {
				solve(test);
			}
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			failed = true;
		}
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	static boolean failed = false;
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Thread th = new Thread(new Solution());
		th.start();
		try {
			th.join();
		} catch (InterruptedException iex) {
		}
		if (failed) {
			throw new RuntimeException();
		}
	}
	
}
