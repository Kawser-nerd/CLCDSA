import java.util.*;
import java.io.*;

public class D {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int n = in.nextInt(), l = in.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = in.next();
		}
		String bad = in.next();
		char[] b = bad.toCharArray();
		for (int i = 0; i < n; i++) {
			if (bad.equals(s[i])) {
				out.println("IMPOSSIBLE");
				return;
			}
		}
		for (int i = 0; i < b.length - 1; i++) {
			out.print(1);
		}
		out.print(0);
		out.print(" ");
		for (int i = 0; i < b.length; i++) {
			out.print("0?");
		}
		out.println();
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
		new D().run();
	}
}