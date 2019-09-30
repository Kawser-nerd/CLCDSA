import java.io.*;
import java.util.*;

public class B {

	static void solveMultiTest() throws IOException {
		int testCases = nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			out.print("Case #" + testCase + ": ");
			solveOneTest();
		}
	}

	static void solveOneTest() throws IOException {
		int n = nextInt();
		long p = nextLong();
		long answer1 = getGuaranteed(n, p);
		long answer2 = getCould(n, p);
		out.println(answer1 + " " + answer2);
	}

	private static long getCould(int n, long p) {
		if (p == (1L << n)) {
			return p - 1;
		}
		int leadingZeros = leadingOnes(n, (1L << n) - p - 1);
		return (1L << n) - (1L << leadingZeros + 1);
	}

	private static long getGuaranteed(int n, long p) {
		if (p == (1L << n)) {
			return p - 1;
		}
		int leadingOnes = leadingOnes(n, p - 1);
		return (1L << (leadingOnes + 1)) - 2;
	}

	private static int leadingOnes(int n, long p) {
		for (int i = n - 1, ret = 0; i >= 0; --i, ++ret) {
			if (((p >>> i) & 1) == 0) {
				return ret;
			}
		}
		return n;
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("b.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream(new File("b.out"));
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solveMultiTest();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
}
