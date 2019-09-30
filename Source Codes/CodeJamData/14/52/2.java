import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

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
		int p = nextInt();
		int q = nextInt();
		int n = nextInt();
		int h[] = new int[n];
		int g[] = new int[n];
		for (int i = 0; i < n; i++) {
			h[i] = nextInt();
			g[i] = nextInt();
		}
		int prevDyn[][] = new int[][] {{0}, {}};
		int maxHits = 0;
		for (int i = 0; i < n; i++) {
			int towerHits = (h[i] + q - 1) / q;
			maxHits += towerHits;
			int curDyn[][] = new int[2][maxHits + 1];
			fill(curDyn[0], Integer.MIN_VALUE);
			fill(curDyn[1], Integer.MIN_VALUE);
			// Our turn, we kill
			int needTurns = (h[i] - (towerHits - 1) * q + p - 1) / p - (towerHits - 1) - 1;
			for (int j = max(needTurns, 0); j < prevDyn[0].length; j++) {
				if (prevDyn[0][j] != Integer.MIN_VALUE) {
					curDyn[1][j - needTurns] = max(curDyn[1][j - needTurns], prevDyn[0][j] + g[i]);
				}
			}
			// Our turn, tower kills
			for (int j = 0; j < prevDyn[0].length; j++) {
				if (prevDyn[0][j] != Integer.MIN_VALUE) {
					curDyn[0][j + towerHits] = max(curDyn[0][j + towerHits], prevDyn[0][j]);
				}
			}
			// Tower turn, we kill
//			if (towerHits > 1) {
				needTurns = (h[i] - (towerHits - 1) * q + p - 1) / p - (towerHits - 2) - 1;
				for (int j = max(needTurns, 0); j < prevDyn[1].length; j++) {
					if (prevDyn[1][j] != Integer.MIN_VALUE) {
						curDyn[1][j - needTurns] = max(curDyn[1][j - needTurns], prevDyn[1][j] + g[i]);
					}
				}
//			}
			// Tower turn, tower kills
			for (int j = 0; j < prevDyn[1].length; j++) {
				if (prevDyn[1][j] != Integer.MIN_VALUE) {
					curDyn[0][j + towerHits - 1] = max(curDyn[0][j + towerHits - 1], prevDyn[1][j]);
				}
			}
			prevDyn = curDyn;
		}
		int ans = Integer.MIN_VALUE;
		for (int i = 0; i < prevDyn[0].length; i++) {
			ans = max(ans, prevDyn[0][i]);
		}
		for (int i = 0; i < prevDyn[1].length; i++) {
			ans = max(ans, prevDyn[1][i]);
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