import java.io.*;
import java.util.*;

public class ErdosSubmit {

	FastScanner in;
	PrintWriter out;

	int[] a, b;
	boolean[] used;
	int[] p, curA, curB;
	int n;

	void go(int k) {
		if (k == n) {
			curB[n - 1] = 1;
			for (int i = n - 2; i >= 0; i--) {
				curB[i] = 1;
				for (int j = i + 1; j < n; j++) {
					if (p[i] > p[j]) {
						curB[i] = Math.max(curB[i], curB[j] + 1);
					}
				}
			}
			for (int i = 0; i < n; i++) {
				if (curB[i] != b[i]) {
					return;
				}
			}
			for (int i = 0; i < n; i++) {
				out.print((p[i] + 1) + " ");
			}
			out.println();
			throw new FoundAnswer();
		}

		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				used[i] = true;
				p[k] = i;
				curA[k] = 1;
				for (int j = 0; j < k; j++) {
					if (p[j] < i) {
						curA[k] = Math.max(curA[k], curA[j] + 1);
					}
				}
				if (curA[k] != a[k]) {
					used[i] = false;
					continue;
				}

				go(k + 1);
				used[i] = false;
			}
		}
	}

	void solve() {
		n = in.nextInt();
		a = new int[n];
		b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = in.nextInt();
		}
		used = new boolean[n];
		p = new int[n];
		curA = new int[n];
		curB = new int[n];
		try {
			go(0);
		} catch (FoundAnswer e) {
		}
	}

	class FoundAnswer extends RuntimeException {
	}

	void run() {
		try {
			in = new FastScanner(new File("input.txt"));
			out = new PrintWriter("output.txt");

			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				long time = System.currentTimeMillis();
				out.printf("Case #%d: ", (i + 1));
				solve();
				System.err.println("Test #" + (i + 1) + " done in "
						+ (System.currentTimeMillis() - time) + "ms");
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File file) {
			try {
				br = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String next() {
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
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new ErdosSubmit().run();
	}
}
