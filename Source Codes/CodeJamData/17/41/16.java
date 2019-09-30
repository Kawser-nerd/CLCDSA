import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class a {
	public static void main(String[] Args) throws Exception {
		FS sc = new FS(new File("A-large.in"));
		// FS sc = new FS(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(new File("a.out"))));
		// FS sc = new FS(System.in);
		// PrintWriter out = new PrintWriter(new BufferedWriter(new
		// OutputStreamWriter(System.out)));
		int cc = 0;
		int t = sc.nextInt();
		while (t-- > 0) {
			out.printf("Case #%d: ", ++cc);

			int n = sc.nextInt();
			int p = sc.nextInt();
			int[] vs = new int[n];
			for (int i = 0; i < n; i++)
				vs[i] = sc.nextInt() % p;
			int ans = 0;
			boolean[] done = new boolean[n];
			for (int i = 0; i < n; i++) {
				if (vs[i] == 0) {
					done[i] = true;
					ans++;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (!done[i] && !done[j] && vs[i] + vs[j] == p) {
						ans++;
						done[i] = true;
						done[j] = true;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n && !done[i]; j++) {
					for (int k = j + 1; k < n && !done[j]; k++) {
						if (!done[i] && !done[j] && !done[k] && (vs[i] + vs[j] + vs[k]) % p == 0) {
							ans++;
							done[i] = true;
							done[j] = true;
							done[k] = true;
						}
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n && !done[i]; j++) {
					for (int k = j + 1; k < n && !done[j]; k++) {
						for (int ii = k + 1; ii < n && !done[k]; ii++) {
							if (!done[i] && !done[j] && !done[k] && !done[ii]
									&& (vs[i] + vs[j] + vs[k] + vs[ii]) % p == 0) {
								ans++;
								done[i] = true;
								done[j] = true;
								done[k] = true;
								done[ii] = true;
							}
						}
					}
				}
			}
			for (int i = 0; i < n; i++)
				if (!done[i]) {
					ans++;
					break;
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

		int nextInt() throws Exception {
			return Integer.parseInt(next());
		}
	}
}
