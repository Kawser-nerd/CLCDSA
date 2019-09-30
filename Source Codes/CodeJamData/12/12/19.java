import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int numberCases = in.nextInt();
		for (int test = 1; test <= numberCases; test++) {
			int N = in.nextInt();
			int[] a = new int[N];
			int[] b = new int[N];
			int[] was = new int[N];
			for (int i = 0; i < N; i++) {
				a[i] = in.nextInt();
				b[i] = in.nextInt();
			}
			int ans = 0;
			int have = 0;
			while (true) {
				boolean all = true; 
				for (int i = 0; i < N; i++) {
					if (was[i] != 2) {
						all = false;
						break;
					}
				}
				if (all) break;
				int pr = -2;
				int use = -1;
				for (int i = 0; i < N; i++) {
					if (was[i] == 2) continue;
					if (have >= b[i]) {
						use = i;
						pr = -1;
					}
					if (have >= a[i] && pr != -1 && was[i] != 1) {
						if (pr < b[i]) {
							use = i;
							pr = b[i];
						}
					}
				}
				if (pr == -2) {
					ans = -1;
					break;
				}
				if (have >= b[use]) {
					ans++;
					have += 2 - was[use];
					was[use] = 2;
				} else {
					ans++;
					have++;
					was[use] = 1;
				}
			}
			out.print("Case #");
			out.print(test);
			out.print(": ");
			if (ans == -1) out.println("Too Bad"); else
				out.println(ans);
		}
	}

	public void run() {
		try {
			in = new FastScanner(new File("B.in"));
			out = new PrintWriter(new File("B.out"));

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