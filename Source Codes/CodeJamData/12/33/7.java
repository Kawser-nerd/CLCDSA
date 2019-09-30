import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class C {
	BufferedReader in;
	StringTokenizer str;
	PrintWriter out;
	String SK;

	String next() throws IOException {
		while ((str == null) || (!str.hasMoreTokens())) {
			SK = in.readLine();
			if (SK == null)
				return null;
			str = new StringTokenizer(SK);
		}
		return str.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		long[] a = new long[n];
		int[] A = new int[n];
		long[] b = new long[m];
		int[] B = new int[m];
		for (int i = 0; i < n; i++) {
			a[n - i - 1] = nextLong();
			A[n - i - 1] = nextInt();
		}
		for (int i = 0; i < m; i++) {
			b[m - i - 1] = nextLong();
			B[m - i - 1] = nextInt();
		}
		long[][] res = new long[n + 1][m + 1];

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				res[i][j] = Math.max(res[i - 1][j],res[i][j-1]);
				long[] c1 = a.clone();
				long[] c2 = b.clone();
				long et = A[i - 1];
				int x = i;
				int y = j;
				long resul = 0;
				while (x > 0 && y > 0) {
					while (x > 0 && A[x - 1] != et) {
						x--;
					}
					while (y > 0 && B[y - 1] != et) {
						y--;
					}
					if (x * y == 0) {
						break;
					}
					resul = resul + Math.min(c1[x - 1], c2[y - 1]);
					res[i][j] = Math.max(res[i][j], res[x - 1][y - 1] + resul);
					long t1=c1[x-1];
					long t2=c2[y-1];
					c1[x - 1] = c1[x - 1] - Math.min(t1, t2);
					c2[y - 1] = c2[y - 1] - Math.min(t1, t2);
					if (c1[x - 1] == 0) {
						x--;
					}
					if (c2[y - 1] == 0) {
						y--;
					}
				}
				c1 = a.clone();
				c2 = b.clone();
				et = B[j - 1];
				x = i;
				y = j;
				resul = 0;
				while (x > 0 && y > 0) {
					while (x > 0 && A[x - 1] != et) {
						x--;
					}
					while (y > 0 && B[y - 1] != et) {
						y--;
					}
					if (x * y == 0) {
						break;
					}
					resul = resul + Math.min(c1[x - 1], c2[y - 1]);
					res[i][j] = Math.max(res[i][j], res[x - 1][y - 1] + resul);
					long t1=c1[x-1];
					long t2=c2[y-1];
					c1[x - 1] = c1[x - 1] - Math.min(t1, t2);
					c2[y - 1] = c2[y - 1] - Math.min(t1, t2);
					if (c1[x - 1] == 0) {
						x--;
					}
					if (c2[y - 1] == 0) {
						y--;
					}
				}
			}
		}
		out.println(" " + res[n][m]);
	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			out.print("Case #" + (i + 1) + ":");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().run();
	}

}