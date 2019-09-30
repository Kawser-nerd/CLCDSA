import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {


	static final long mod = 1000*1000*1000 + 7;
	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt(), q = sc.nextInt();
		int a[] = new int[n];
		for (int i = 0 ; i < n ; ++i) {
			a[i] = sc.nextInt();
		}
		long dp[][] = new long[n][m + 1];
		for (int cur = 0 ; cur <= a[0]; ++cur) {
			dp[0][cur] = 1;
		}
		long sum[] = new long[m + 1];
		for (int i = 1 ; i < n ; ++i) {
			Arrays.fill(sum, 0);
			for (int j = 0 ; j <= m ; ++j) {
				sum[j] = dp[i - 1][j];
				if (j > 0) {
					sum[j] += sum[j - 1];
					sum[j] %= mod;

				}
			}
			for (int j = 0  ; j <= m ; ++j) {
				dp[i][j] += sum[j];
				dp[i][j] %= mod;
				if (j - a[i] - 1 >= 0)  {
					dp[i][j] -= sum[j - a[i] - 1];
					dp[i][j] %= mod;
					while (dp[i][j] < 0) {
						dp[i][j] += mod;
					}
					dp[i][j] %= mod;

				}
			}
		}
		long dp2[][] = new long[n][m + 1];
		Arrays.fill(sum, 0);

		for (int i = 0 ; i < n ; ++i) {
			long f[] = new long[m + 1];
			long run = 0;
			for (int j = 0 ; j <= m ; ++j) {
				run += f[j];
				run %= mod;
				dp2[i][j] = dp[n - 1][j] + run;
				dp2[i][j] %= mod;
				if (j + 1 <= m) {
					f[j + 1] -= dp2[i][j];
					f[j + 1] %= mod;
					while (f[j + 1] < 0) f[j + 1] += mod;
					f[j + 1] %= mod;
				}
				if (j + a[i] + 1 <= m) {
					f[j + a[i] + 1] += dp2[i][j];
					f[j + a[i] + 1] %= mod;
				}
				while (dp2[i][j] < 0) {
					dp2[i][j] += mod;
				}
				dp2[i][j] %= mod;
			}
		}

		PrintWriter out = new PrintWriter(System.out);

		while (q-- > 0) {
			int ind = sc.nextInt() - 1, k = sc.nextInt();
			if (k > a[ind]) {
				out.println(0);
			} else {
				out.println(dp2[ind][m - k]);
			}
		}
		out.flush();
		out.close();
	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(String s) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(new File(s)));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}
	}


}