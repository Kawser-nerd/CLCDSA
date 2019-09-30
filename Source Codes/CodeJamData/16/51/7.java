import java.util.*;
import java.io.*;

public class A {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		char[] c = in.next().toCharArray();
		int n = c.length;
		char[] st = new char[n];
		int sp = 0;
		int ans = 0;
		for (int i = 0; i < c.length; i++) {
			if (sp > 0 && c[i] == st[sp - 1]) {
				sp--;
				ans += 10;
			} else {
				st[sp++] = c[i];
			}
		}
		ans += (sp / 2) * 5;
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