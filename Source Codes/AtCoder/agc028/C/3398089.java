import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	static class Token implements Comparable<Token> {
		final int value, id;
		final boolean isB;
		boolean isBig;

		Token(int value, int id, boolean isB) {
			this.value = value;
			this.id = id;
			this.isB = isB;
		}

		public int compareTo(Token o) {
			return value - o.value;
		}
	}

	static void solve() throws Exception {
		int n = scanInt();
		Token a[] = new Token[n], b[] = new Token[n];
		Token tokens[] = new Token[2 * n];
		for (int i = 0; i < n; i++) {
			a[i] = tokens[i] = new Token(scanInt(), i, false);
			b[i] = tokens[i + n] = new Token(scanInt(), i, true);
		}
		sort(tokens);
		long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += tokens[i].value;
		}
		for (int i = n; i < 2 * n; i++) {
			tokens[i].isBig = true;
		}
		int c1 = 0, c2 = 0, c3 = 0;
		for (int i = 0; i < n; i++) {
			if (!a[i].isBig && b[i].isBig) {
				++c1;
			} else if (a[i].isBig && !b[i].isBig) {
				++c3;
			} else {
				++c2;
			}
		}
		if (c2 == 0 && c1 != 0 && c3 != 0) {
			if (tokens[n - 1].id != tokens[n].id ||
				(c1 == 1 && tokens[n].isB == tokens[n].isBig) ||
				(c3 == 1 && tokens[n].isB != tokens[n].isBig)) {
				sum += tokens[n].value - tokens[n - 1].value;
			} else {
				sum += min(tokens[n].value - tokens[n - 2].value,
					tokens[n + 1].value - tokens[n - 1].value);
			}
		}
		out.print(sum);
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