import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class b {
	public static void main(String[] Args) throws Exception {
		FS sc = new FS(new File("B-large.in"));
		// FS sc = new FS(new File("B-small-attempt0.in"));
		// FS sc = new FS(System.in);
		// PrintWriter out = new PrintWriter(new BufferedWriter(
		// new OutputStreamWriter(System.out)));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				new File("b.out"))));
		int cc = 0;
		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt();
			boolean[] con = new boolean[2501];
			for (int i = 0; i < (n * 2 - 1) * n; i++) {
				int k = sc.nextInt();
				con[k] = !con[k];
			}
			out.printf("Case #%d:", ++cc);

			for (int i = 0; i < 2501; i++) {
				if (con[i]) {
					out.printf(" %d", i);
				}
			}
			out.println();
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
