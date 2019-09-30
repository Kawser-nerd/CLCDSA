import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	static void solve() throws Exception {
		int n = scanInt(), a = scanInt(), b = scanInt();
		if ((Integer.bitCount(a ^ b) & 1) == 0) {
			out.print("NO");
		} else {
			out.println("YES");
			go((1 << n) - 1, a, b);
		}
	}

	static void go(int mask, int a, int b) {
		if ((mask & (mask - 1)) == 0) {
			out.print(a + " " + b + " ");
		} else {
			int c = Integer.lowestOneBit(a ^ b);
			int d = Integer.lowestOneBit(mask ^ c);
			go(mask ^ c, a, a ^ d);
			go(mask ^ c, a ^ d ^ c, b);
		}
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