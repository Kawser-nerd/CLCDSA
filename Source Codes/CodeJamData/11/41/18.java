import java.io.*;
import java.util.*;

public class SolA implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolA()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof;

	@Override
	public void run() {
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
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

	String FNAME = "A-large";
	
	double eps = 1e-9;

	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			double x = nextInt();
			double s = nextInt();
			double r = nextInt();
			double t = nextInt();
			int n = nextInt();
			double[] b = new double[n];
			double[] e = new double[n];
			double[] w = new double[n];
			double sl = x;
			for (int i = 0; i < n; i++) {
				b[i] = nextInt();
				e[i] = nextInt();
				w[i] = nextInt();
				sl -= e[i] - b[i];
			}
			double ans = 0;
			if (sl >= t * r) {
				for (int i = 0; i < n; i++) {
					ans += 1.0 * (e[i] - b[i]) / (s + w[i]);
				}
				ans += t;
				ans += (sl - t * r) / s; 
			} else {
				ans += sl / r;
				t -= sl / r;
				boolean[] u = new boolean[n];
				while (t > eps) {
					int imin = -1;
					for (int i = 0; i < n; i++) {
						if (u[i]) continue;
						if (imin == -1 || (w[i] < w[imin])) {
							imin = i;
						}
					}
					if (imin == -1) break;
					double len = e[imin] - b[imin]; 
					u[imin] = true;
					if (len >= (w[imin] + r) * t) {
						ans += t;
						e[imin] -= (w[imin] + r) * t;
						ans += (e[imin] - b[imin]) / (w[imin] + s);
						t = 0;
					} else {
						ans += (len / (w[imin] + r));
						t -= (len / (w[imin] + r));
						u[imin] = true;
					}
				}
				for (int i = 0; i < n; i++) {
					if (!u[i]) {
						ans += 1.0 * (e[i] - b[i]) / (s + w[i]);
					}
				}
			}
			out.println("Case #" + test + ": " + ans);
		}
	}
}