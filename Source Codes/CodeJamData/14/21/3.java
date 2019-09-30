import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static void solve() throws Exception {
		int n = nextInt();
		String s[] = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = next();
		}
		String sig = null;
		int counts[][] = null;
		for (int i = 0; i < n; i++) {
			String cur = s[i];
			char curSig[] = new char[cur.length()];
			int curSigN = 0;
			for (int j = 0; j < cur.length(); j++) {
				if (j == 0 || cur.charAt(j) != cur.charAt(j - 1)) {
					curSig[curSigN++] = cur.charAt(j);
				}
			}
			String curSigS = new String(curSig, 0, curSigN);
			if (i == 0) {
				sig = curSigS;
				counts = new int[sig.length()][n];
			} else if (!sig.equals(curSigS)) {
				printCase();
				out.println("Fegla Won");
				return;
			}
			for (int j = 0, k = 0; j < cur.length(); j++) {
				if (j > 0 && cur.charAt(j) != cur.charAt(j - 1)) {
					k++;
				}
				counts[k][i]++;
			}
		}
		int ans = 0;
		for (int i = 0; i < sig.length(); i++) {
			sort(counts[i]);
			for (int j = 0; j < n; j++) {
				ans += abs(counts[i][j] - counts[i][n / 2]);
			}
		}
		printCase();
		out.println(ans);
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