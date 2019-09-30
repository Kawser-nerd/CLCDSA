import java.io.*;
import java.util.*;

public class DataPacking {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), s = in.nextInt();

		int[] x = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
		}
		Arrays.sort(x);
		
		int cnt = 0;
		int i = 0, j = x.length - 1;
		while (i < j) {
			while (i < j && x[i] + x[j] > s) {
				j--;
			}
			if (i < j) {
				cnt++;
				i++;
				j--;
			}
		}
		out.println(n - cnt);
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
		new DataPacking().run();
	}
}
