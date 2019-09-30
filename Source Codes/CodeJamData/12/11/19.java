import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int numberCases = in.nextInt();
		for (int test = 1; test <= numberCases; test++) {
			int A = in.nextInt();
			int B = in.nextInt();
			double pr[] = new double[A];
			for (int i = 0; i < A; i++) {
				pr[i] = in.nextDouble();
			}
			double ans = 2 + B;
			double right = 1;
			for (int del = A; del >= 0; del--) {
				double newAns = right * (1.0 + B - A + 2 * del)  + (1.0 - right) * (2.0 + 2 * B - A + 2 * del);
				if (newAns < ans) ans = newAns;
				if (del != 0) right *= pr[A - del]; 
			}
			out.print("Case #");
			out.print(test);
			out.print(": ");
			out.println(ans);
		}
	}

	public void run() {
		try {
			in = new FastScanner(new File("A.in"));
			out = new PrintWriter(new File("A.out"));

			//in = new FastScanner(System.in);
			//out = new PrintWriter(System.out);

			solve();

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

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
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

		String nextString() {
			try {
				return br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return null;
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}