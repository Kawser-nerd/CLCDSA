import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "B-large";

	public void solve() throws IOException {
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			out.printf("Case #%d: ", test + 1);
			int n = nextInt();
			int w = nextInt();
			int h = nextInt();
			System.err.println(test + " " + n);
			final double[] r = new double[n];
			for (int i = 0; i < n; ++i) {
				r[i] = nextDouble();
			}
			Integer[] order = new Integer[n];
			for (int i = 0; i < n; ++i) {
				order[i] = i;
			}
			Arrays.sort(order, new Comparator<Integer>() {
				@Override
				public int compare(Integer o1, Integer o2) {
					return -Double.compare(r[o1], r[o2]);
				}
			});
			double[] x = new double[n];
			double[] y = new double[n];
			Random rnd = new Random();
			for (int it = 0; it < n; ++it) {
				System.err.print(it + " ");
				int i = order[it];
				loop: while (true) {
					x[i] = rnd.nextDouble() * w;
					y[i] = rnd.nextDouble() * h;
					x[i] = Math.round(x[i] * 1000) / 1000.;
					y[i] = Math.round(y[i] * 1000) / 1000.;
					for (int jt = 0; jt < it; ++jt) {
						int j = order[jt];
						double d2 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
						if (d2 < (r[i] + r[j]) * (r[j] + r[i])) {
							continue loop;
						}
					}
					break;
				}
			}
			for (int i = 0; i < n; ++i) {
				out.print(x[i] + " " + y[i] + " ");
			}
			out.println();
		}
	}

	public void run() throws IOException {
		in = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(file + ".out");
		eat("");
		
		solve();
		
		out.close();
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
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}