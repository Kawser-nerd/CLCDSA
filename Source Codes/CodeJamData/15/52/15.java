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
import java.util.Random;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
//	static final Random rng = new Random(42);
	
	static void solve() throws Exception {
		int n = nextInt();
		int k = nextInt();
//		int n = rng.nextInt(50) + 1;
//		int k = rng.nextInt(n) + 1;
//		long xxx[] = new long[n];
//		long xxxMin = Long.MAX_VALUE, xxxMax = Long.MIN_VALUE;
//		long add = rng.nextLong() % 100;
//		for (int i = 0; i < n; i++) {
//			xxx[i] = rng.nextLong() % 50 + add;
//			xxxMin = min(xxxMin, xxx[i]);
//			xxxMax = max(xxxMax, xxx[i]);
//		}
//		long xxxDiff = xxxMax - xxxMin;
		long sum[] = new long[n - k + 1];
		for (int i = 0; i < n - k + 1; i++) {
			sum[i] = nextLong();
//			for (int j = i; j < i + k; j++) {
//				sum[i] += xxx[j];
//			}
		}
		long classMin[] = new long[k];
		long classMax[] = new long[k];
		long classDiff[] = new long[k];
		long initSum = sum[0];
		long maxDiff = 0;
		for (int i = 0; i < k; i++) {
			long classCur = 0;
			for (int j = i; j < n - k; j += k) {
				classCur += sum[j + 1] - sum[j];
				classMin[i] = min(classMin[i], classCur);
				classMax[i] = max(classMax[i], classCur);
			}
			classDiff[i] = classMax[i] - classMin[i];
			initSum += classMin[i];
			maxDiff = max(maxDiff, classDiff[i]);
		}
		long slack = 0;
		for (int i = 0; i < k; i++) {
			slack += maxDiff - classDiff[i];
		}
		printCase();
		out.println(slack >= ((initSum % k + k) % k) ? maxDiff : maxDiff + 1);
//		if ((slack >= (initSum % k + k % k) ? maxDiff : maxDiff + 1) > xxxDiff) {
//			throw new AssertionError();
//		}
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