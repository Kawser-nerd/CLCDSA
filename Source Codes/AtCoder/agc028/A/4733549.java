import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
 
public class Main {
 
	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
 
	static void solve() throws Exception {
		int n = scanInt(), m = scanInt();
		String s = scanString(), t = scanString();
		int g = gcd(n, m);
		int ng = n / g, mg = m / g;
		for (int i = 0; i < g; i++) {
			if (s.charAt(ng * i) != t.charAt(mg * i)) {
				out.print(-1);
				return;
			}
		}
		out.print((long) n * mg);
	}
 
	static int scanInt() throws IOException {
		return parseInt(scanString());
	}
 
	static long scanLong() throws IOException {
		return parseLong(scanString());
	}
 
	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
 
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
 
	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}