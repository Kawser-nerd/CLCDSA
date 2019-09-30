import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "A-large";

	public void solve(int test) throws IOException {
		out.println("Case #" + (test + 1) + ": ");
		int n = nextInt();
		char[][] g = new char[n][n];
		for (int i = 0; i < n; ++i) {
			g[i] = next().toCharArray();
		}
		double[] wp = new double[n];
		double[] owp = new double[n];
		double[] oowp = new double[n];
		for (int i = 0; i < n; ++i) {
			int count = 0;
			for (int j = 0; j < n; ++j) {
				if (g[i][j] == '1') {
					wp[i]++;
				}
				if (g[i][j] != '.') {
					count++;
				}
			}
			wp[i] /= count;
			count = 0;
			for (int j = 0; j < n; ++j) {
				if (g[i][j] == '.') {
					continue;
				}
				double wins = 0.;
				int countj = 0;
				for (int k = 0; k < n; ++k) {
					if (k == i) {
						continue;
					}
					if (g[j][k] == '1') {
						wins++;
					}
					if (g[j][k] != '.') {
						countj++;
					}
				}
				wins /= countj;
				owp[i] += wins;
				count++;
			}
			owp[i] /= count;
		}
		for (int i = 0; i < n; ++i) {
			int count = 0;
			for (int j = 0; j < n; ++j) {
				if (g[i][j] == '.') {
					continue;
				}
				oowp[i] += owp[j];
				count++;
			}
			oowp[i] /= count;
			out.println(wp[i] / 4 + owp[i] / 2 + oowp[i] / 4);
		}
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
