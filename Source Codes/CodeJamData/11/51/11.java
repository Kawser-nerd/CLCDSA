import java.util.*;
import java.io.*;
import java.math.BigInteger;
import static java.lang.Math.*;

public class Sol implements Runnable {

	void solve() throws Exception {
		int w = nextInt();
		int L = nextInt(), U = nextInt();
		int G = nextInt();
		int [] lx = new int[L], ly = new int[L];
		int [] ux = new int[U], uy = new int[U];
		for (int i = 0; i < L; i++) {
			lx[i] = nextInt();
			ly[i] = nextInt();
		}
		for (int i = 0; i < U; i++) {
			ux[i] = nextInt();
			uy[i] = nextInt();
		}
		double [] h = new double[w + 1];
		for (int i = 0, pu = 0, pl = 0; i <= w; i++) {
			double x = i;
			if (i > ux[pu + 1]) pu++;
			if (i > lx[pl + 1]) pl++;
			double lH = (ly[pl] * (lx[pl + 1] - x) + ly[pl + 1] * (x - lx[pl])) / (lx[pl + 1] - lx[pl]);
			double uH = (uy[pu] * (ux[pu + 1] - x) + uy[pu + 1] * (x - ux[pu])) / (ux[pu + 1] - ux[pu]);
			h[i] = uH - lH;
		}
		double [] S = new double [w];
		double tS = 0;
		for (int i = 0; i < w; i++) {
			S[i] = (h[i] + h[i + 1]) / 2;
			tS += S[i];
		}

		double [] ans = new double[G - 1];
		double curS = 0, eps = 1e-9, meps = 1e-19;
		for (int step = 0, i = 0; step < G - 1; step++) {
			double want = (step + 1) * tS / G;
			while (curS + S[i] < want) {
			      curS += S[i];
				i++;
			}
			ans[step] = i;
			if (abs(h[i] - h[i + 1]) < eps) {
				ans[step] += 2 * (want - curS) / (h[i] + h[i + 1]);
			} else {
				double A = h[i + 1] - h[i];
				double B = 2 * h[i];
				double C = 2 * (curS - want);
				double alpha = 1D / (2 * A) * (-B + sqrt(B * B - 4 * A * C + meps));
				ans[step] += alpha;
			}	
		} 
		
		out.printf("Case #%d:\n", testNumber + 1);
		for (int i = 0; i < ans.length; i++) {
			out.printf("%.8f\n", ans[i]);
		}	
	}

	public static void main(String[] args) {
		new Thread(new Sol()).start();
	}

	int testNumber;
	public void run() {
		try {
			Locale.setDefault(Locale.US);
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			sTime();
			int T = nextInt();
			for (testNumber = 0; testNumber < T; testNumber++) {
				solve();
				debug("Test " + testNumber + " finished at time: " + gTime());
			}

			out.close();

		} catch (Exception e) {
			System.err.println("exception at test = " + testNumber);
			e.printStackTrace();
		}
	}

	
	StringTokenizer tokenizer = new StringTokenizer("");
	BufferedReader in;
	PrintWriter out;

	long time;
	void sTime() { time = System.currentTimeMillis(); }
	long gTime() { return System.currentTimeMillis() - time; }
	void gMemory() { debug("Memory: " + (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) / 1000 + " kb"); }
	public void debug(Object o) { System.err.println(o); }

	
	boolean seekForToken() {
		while (!tokenizer.hasMoreTokens()) {
			String s = null;
			try {
				s = in.readLine();
			} catch (Exception e) {
				e.printStackTrace();
			}
			if (s == null)
				return false;
			tokenizer = new StringTokenizer(s);
		}
		return true;
	}

	String nextToken() {
		return seekForToken() ? tokenizer.nextToken() : null;
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

	BigInteger nextBig() {
		return new BigInteger(nextToken());
	}
}
