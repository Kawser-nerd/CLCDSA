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
	public static int[][] winning;

	public static void main(String[] Args) throws Exception {
		 FS sc = new FS(new File("A-large.in"));
//		 FS sc = new FS(new File("A-small-attempt2.in"));
//		FS sc = new FS(System.in);
		// PrintWriter out = new PrintWriter(new BufferedWriter(
		// new OutputStreamWriter(System.out)));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				new File("a.out"))));
		int cc = 0;
		int t = sc.nextInt();
		int[][] winning = new int[13][3];
		winning[0][0] = 1;
		winning[0][1] = 0;
		winning[0][2] = 0;
		for (int i = 1; i < 13; i++) {
			winning[i][0] = winning[i - 1][0] + winning[i - 1][1];
			winning[i][2] = winning[i - 1][2] + winning[i - 1][0];
			winning[i][1] = winning[i - 1][1] + winning[i - 1][2];
		}
		while (t-- > 0) {
			out.printf("Case #%d: ", ++cc);
			int n = sc.nextInt();

			int[] cur = new int[3];
			for (int i = 0; i < 3; i++) {
				cur[i] = sc.nextInt();
			}
			boolean can = false;
			for (int i = 0; i < 3; i++) {
				boolean good = true;
				for (int j = 0; j < 3; j++) {
					if (winning[n][j % 3] != cur[(j + i) % 3]) {
						good = false;
					}
				}
				if (good) {
					can = true;
					out.println(make(n, i));
				}
			}
			if (!can)
				out.println("IMPOSSIBLE");
		}
		out.close();
	}

	public static String make(int count, int win) {
		if (count == 0)
			return (win == 0 ? "R" : (win == 1 ? "P" : "S"));

		String a = make(count - 1, win);
		String b = make(count - 1, (win + 2) % 3);
		if (a.compareTo(b) < 0)
			return a + b;
		return b + a;
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
