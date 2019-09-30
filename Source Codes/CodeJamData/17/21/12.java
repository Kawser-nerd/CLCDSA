import java.util.*;
import java.io.*;

public class A {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		long d = in.nextLong();
		int n = in.nextInt();
		double maxNeed = 0;
		for (int i = 0; i < n; i++) {
			double start = in.nextLong();
			double speed = in.nextLong();
			double need = (d - start) / speed;
			maxNeed = Math.max(maxNeed, need);
		}
		double ans = d / maxNeed;
		out.println(ans);
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));

			int tn = in.nextInt();
			for (int i = 0; i < tn; i++) {
				System.err.println(i);
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
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

	public static void main(String[] arg) {
		new A().run();
	}
}