import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out; 
	
	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; ++test) {
			int n = nextInt();
			double[] x = new double[n];
			double[] y = new double[n];
			double[] z = new double[n];
			double[] p = new double[n];
			for (int i = 0; i < n; ++i) {
				x[i] = nextDouble();
				y[i] = nextDouble();
				z[i] = nextDouble();
				p[i] = nextDouble();
			}
			double l = 0.0;
			double r = 1e9;
			loop: for (int it = 0; it < 100; ++it) {
				double xx = (l + r) / 2.0;
				double[] d = new double[8];
				for (int i = 0; i < 8; ++i) {
					d[i] = Double.POSITIVE_INFINITY;
				}
				for (int i = 0; i < n; ++i) {
					double rad = xx * p[i];
					for (int j = 0; j < 8; ++j) {
						double tmp = rad;
						if ((j & 1) == 0) {
							tmp += x[i];
						} else {
							tmp -= x[i];
						}
						if ((j & 2) == 0) {
							tmp += y[i];
						} else {
							tmp -= y[i];
						}
						if ((j & 4) == 0) {
							tmp += z[i];
						} else {
							tmp -= z[i];
						}
						d[j] = Math.min(d[j], tmp);
					}
				}
//				System.out.println(Arrays.toString(d));
				for (int i = 0; i < 8; ++i) {
					if (-d[i] > d[i ^ 7]) {
						l = xx;
						continue loop;
					}
				}
				r = xx;
			}
			out.println("Case #" + test + ": " + r);
		}
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			st = new StringTokenizer("");
			out = new PrintWriter(System.out);
			
			solve();
			
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
			System.exit(-1);
		}
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	public static void main(String[] args) {
		new Thread(new Solution()).start();
	}

	private void ass(boolean b) {
		if (!b) {
			throw new RuntimeException("Assertion failed");
		}
	}
	
	static final boolean Ъ = true;
}