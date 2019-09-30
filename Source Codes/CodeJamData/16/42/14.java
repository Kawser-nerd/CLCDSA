import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class b {
	public static void main(String[] Args) throws Exception {
		 FS sc = new FS(new File("B-large.in"));
//		FS sc = new FS(new File("B-small-attempt0.in"));
		// FS sc = new FS(System.in);
		// PrintWriter out = new PrintWriter(new BufferedWriter(
		// new OutputStreamWriter(System.out)));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				new File("b.out"))));
		int cc = 0;
		int t = sc.nextInt();
		while (t-- > 0) {
			out.printf("Case #%d: ", ++cc);
			int n = sc.nextInt();
			int k = sc.nextInt();
			double[] vals = new double[n];
			for (int i = 0; i < n; i++) {
				vals[i] = sc.nextDouble();
			}

			Arrays.sort(vals);

			double ans = 0;
			int m = (k / 2) + 1;
			for (int i = 0; i <= k; i++) {
				double[] things = new double[(k / 2) + 1];
				things[0] = 1;
				for (int j = 0; j < i; j++) {
					double[] newThings = new double[m];
					for (int r = 0; r < m; r++) {
						newThings[r] = things[r] * vals[j];
						if (r > 0)
							newThings[r] += things[r - 1] * (1 - vals[j]);
					}
					things = newThings;
				}

				// System.out.println(n+" "+i+" "+k);
				for (int j = n - (k - i); j < n; j++) {
					double[] newThings = new double[m];
					for (int r = 0; r < m; r++) {
						newThings[r] = things[r] * vals[j];
						if (r > 0)
							newThings[r] += things[r - 1] * (1 - vals[j]);
					}
					things = newThings;
				}
				ans = Math.max(ans, things[m - 1]);
			}
			out.println(ans);
		}
		out.close();
	}

	public static class FS {
		BufferedReader br;
		StringTokenizer st;

		FS(InputStream in) throws Exception {
			br = new BufferedReader(new InputStreamReader(in));
			st = new StringTokenizer(br.readLine());
		}

		FS(File in) throws Exception {
			br = new BufferedReader(new FileReader(in));
			st = new StringTokenizer(br.readLine());
		}

		String next() throws Exception {
			if (st.hasMoreTokens())
				return st.nextToken();
			st = new StringTokenizer(br.readLine());
			return next();
		}

		double nextDouble() throws Exception {
			return Double.parseDouble(next());
		}

		int nextInt() throws Exception {
			return Integer.parseInt(next());
		}
	}
}
