import java.io.*;
import java.util.*;

public class Mountain {

	final int MAX = 1000000000 + 1;
	final int MAX_IT = 100000000;

	void solve() throws Exception {
		int n = nextInt();
		int[] x = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			x[i] = nextInt() - 1;
		}
		int[] h = new int[n];
		Random rnd = new Random();
		for (int IT = 0; IT < MAX_IT; IT++) {
			for (int i = 0; i < n; i++) {
				h[i] = rnd.nextInt(MAX);
			}
			boolean ok = true;
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					long left = (long) (h[j] - h[i]) * (x[i] - i);
					long right = (long) (h[x[i]] - h[i]) * (j - i);
					if (j < x[i]) {
						if (left >= right) {
							ok = false;
							break;
						}
					}
					if (j > x[i]) {
						if (left > right) {
							ok = false;
							break;
						}
					}
				}
				if (ok == false) {
					break;
				}
			}
			if (ok) {
				for (int i = 0; i < n; i++) {
					out.print(h[i] + " ");
				}
				out.println();
				return;
			}
		}
		out.println("Impossible");
	}

	void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			int tests = nextInt();

			for (int i = 0; i < tests; i++) {
				long time = System.currentTimeMillis();
				out.print("Case #" + (i + 1) + ": ");
				solve();
				System.err.println("Solved case #" + (i + 1) + " in "
						+ (System.currentTimeMillis() - time) + " ms");
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;
	final String filename = new String("Mountain").toLowerCase();

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new Mountain().run();
	}

}
