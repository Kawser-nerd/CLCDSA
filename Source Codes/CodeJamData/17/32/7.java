import static java.lang.Math.*;
import static java.lang.System.currentTimeMillis;
import static java.lang.System.exit;
import static java.lang.System.arraycopy;
import static java.util.Arrays.sort;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;

import java.util.*;
import java.io.*;

@SuppressWarnings("unused")
public class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();		
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");

	private void run() throws IOException {
		if (new File("input.txt").exists())
			in = new BufferedReader(new FileReader("input.txt"));
		else
			in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter("output.txt");
//		out = new PrintWriter(System.out);
		solve();
		in.close();
		out.close();
	}
	
	final int N = 1440;
	final int M = N / 2;
	final int INF = Integer.MAX_VALUE / 2;

	private void solve() throws IOException {
		
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			int n = nextInt();
			int m = nextInt();
			boolean a[] = new boolean[N];
			boolean b[] = new boolean[N];
			for (int i = 0; i < n; i++) {
				int l = nextInt();
				int r = nextInt();
				for (int j = l; j < r; j++)
					a[j] = true;
			}
			for (int i = 0; i < m; i++) {
				int l = nextInt();
				int r = nextInt();
				for (int j = l; j < r; j++)
					b[j] = true;
			}
			int d[][][] = new int[4][N + 1][M + 1];
			for (int i = 1; i <= M; i++) {
				for (int j = 0; j < 4; j++)
					d[j][0][i] = INF;
				d[1][0][0] = d[2][0][0] = INF;
			}
			
			for (int i = 1; i <= N; i++) {
				for (int k = 0; k <= M; k++) {
					for (int j = 0; j < 4; j++) {
						d[j][i][k] = INF;
					}
					if (k > 0 && !a[i - 1]) {
						d[0][i][k] = min(d[0][i][k], d[0][i - 1][k - 1]);
						d[1][i][k] = min(d[1][i][k], d[0][i - 1][k - 1] + 1);
						
						d[2][i][k] = min(d[2][i][k], d[2][i - 1][k - 1]);
						d[3][i][k] = min(d[3][i][k], d[2][i - 1][k - 1] + 1);
					}
					
					if (!b[i - 1]) {
						d[1][i][k] = min(d[1][i][k], d[1][i - 1][k]);
						d[0][i][k] = min(d[0][i][k], d[1][i - 1][k] + 1);
						
						d[3][i][k] = min(d[3][i][k], d[3][i - 1][k]);
						d[2][i][k] = min(d[2][i][k], d[3][i - 1][k] + 1);
					}
				}
			}
			
			int ans = min(d[0][N][M], d[3][N][M]);
//			double ans = 0;
//			ans += PI * a[0].r * a[0].r;
//			for (int i = 0; i < k; i++) {
//				ans += a[i].r * 2. * PI * a[i].h;
//			}
			out.printf(Locale.US, "Case #%d: %d\n", t + 1, ans);
		}
		
	}
	
	class P implements Comparable<P> {

		int r;
		int h;
		P(int r, int h) {
			this.r = r;
			this.h = h;
		}
		
		@Override
		public int compareTo(P o) {
			if (this.r != o.r)
				return o.r - this.r;
			return this.r - o.r;
		}
		
	}
	
	void chk(boolean b) {
		if (b)
			return;
		System.out.println(new Error().getStackTrace()[1]);
		exit(999);
	}
	void deb(String fmt, Object... args) {
		System.out.printf(Locale.US, fmt + "%n", args);
	}
	String nextToken() throws IOException {
		while (!st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}
	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String s = in.readLine();
			if (s == null)
				return true;
			st = new StringTokenizer(s);
		}
		return false;
	}
}
