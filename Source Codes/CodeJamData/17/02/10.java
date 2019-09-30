import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static void solve() throws Exception {
		String s = next();
		for (int i = 0; i < s.length() - 1; i++) {
			if (s.charAt(i) > s.charAt(i + 1)) {
				while (i > 0 && s.charAt(i - 1) == s.charAt(i)) {
					--i;
				}
				StringBuilder sb = new StringBuilder();
				sb.append(s.substring(0, i));
				sb.append((char) (s.charAt(i) - 1));
				for (++i; i < s.length(); ++i) {
					sb.append('9');
				}
				while (sb.length() > 1 && sb.charAt(0) == '0') {
					sb.deleteCharAt(0);
				}
				s = sb.toString();
				break;
			}
		}
		printCase();
		out.println(s);
	}

	static void printCase() {
		out.print("Case #" + test + ": ");
	}

	static void printlnCase() {
		out.println("Case #" + test + ":");
	}

	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}