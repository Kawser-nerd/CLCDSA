import java.io.*;
import java.util.*;

public class UpAndDown2 {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];

		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}

		int ans = 0;
		int l = 0, r = n - 1;
		for (int i = 0; i < n; i++) {
			int min = l;
			for (int j = l; j <= r; j++) {
				if (a[j] < a[min]) {
					min = j;
				}
			}

			if (min - l < r - min) {

				for (int t = min - 1; t >= l; t--) {
					int tmp = a[t];
					a[t] = a[t + 1];
					a[t + 1] = tmp;
					ans++;
				}

				l++;
			} else {

				for (int t = min; t < r; t++) {
					int tmp = a[t];
					a[t] = a[t + 1];
					a[t + 1] = tmp;
					ans++;
				}
				r--;
			}
		}
		out.println(ans);
	}

	void run() {
		try {
			in = new FastScanner("input.txt");
			out = new PrintWriter("output.txt");
			int T = in.nextInt();
			for (int i = 1; i <= T; i++) {
				long time = System.currentTimeMillis();
				out.printf("Case #%d: ", i);
				solve();
				System.err.println("Test #" + i + " done in " + (System.currentTimeMillis() - time)
						+ " ms");
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
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

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new UpAndDown2().run();
	}
}
