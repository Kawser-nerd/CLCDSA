import java.io.*;
import java.util.*;

public class ManyPrizesSubmit {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		long p = in.nextLong();
		if (p == 1L << n) {
			out.println(((1L << n) - 1) + " " + ((1L << n) - 1));
			return;
		}
		if (p == 1) {
			out.println(0 + " " + 0);
			return;
		}
		
		
		long curAdd = 1L << (n - 1);
		long pp = p;
		int k = 0;
		while (pp > curAdd) {
			pp -= curAdd;
			curAdd /= 2;
			k++;
		}
		
		out.print((1L << (k + 1)) - 2);
		out.print(' ');
		pp = p;
		curAdd = 1;
		k = 0;
		while (pp > curAdd) {
			pp -= curAdd;
			curAdd *= 2;
			k++;
		}
		out.println((1L << n) - (1L << (n - k)));
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
		new ManyPrizesSubmit().run();
	}
}
