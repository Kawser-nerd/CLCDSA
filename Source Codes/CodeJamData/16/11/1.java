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
//		FS sc = new FS(new File("A-small-attempt0.in"));
		// FS sc = new FS(System.in);
		// PrintWriter out = new PrintWriter(new BufferedWriter(
		// new OutputStreamWriter(System.out)));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				new File("a.out"))));
		int cc = 0;
		int t = sc.nextInt();
		while (t-- > 0) {
			out.printf("Case #%d: ", ++cc);

			String s = sc.next();
			out.printf("%s", foo(s));
			out.println("");
		}
		out.close();
	}

	public static String foo(String s) throws Exception {
		if (s.length() == 0)
			return "";
		int last = 'A';
		for (int i = 0; i < s.length(); i++) {
			last = Math.max(last, s.charAt(i));
		}

		for (int i = s.length() - 1; i >= 0; i--) {

			if (s.charAt(i) == last) {
				return (char) (last) + foo(s.substring(0, i))
						+ s.substring(i + 1);
			}
		}

		throw new Exception("BANANAS");
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
