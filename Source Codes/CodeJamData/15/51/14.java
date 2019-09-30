import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

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
		int d = nextInt();
		int sCur = nextInt();
		int as = nextInt();
		int cs = nextInt();
		int rs = nextInt();
		int mCur = nextInt();
		int am = nextInt();
		int cm = nextInt();
		int rm = nextInt();
		int min[] = new int[n];
		int max[] = new int[n];
		min[0] = sCur - d;
		max[0] = sCur + 1;
		for (int i = 1; i < n; i++) {
			sCur = (int) (((long) sCur * as + cs) % rs);
			mCur = (int) (((long) mCur * am + cm) % rm);
			min[i] = max(min[mCur % i], sCur - d);
			max[i] = min(max[mCur % i], sCur + 1);
//			System.err.println(i + " " + sCur + " " + (mCur % i));
		}
		int change[] = new int[rs + 1];
		for (int i = 0; i < n; i++) {
			if (min[i] < max[i]) {
				++change[max(min[i], 0)];
				--change[max[i]];
			}
		}
		int ans = 0;
		int cans = 0;
		for (int i = 0; i <= rs; i++) {
			cans += change[i];
			ans = max(ans, cans);
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