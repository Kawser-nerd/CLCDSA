import java.io.*;
import java.util.*;

public class D {

	static void solveMultiTest() throws IOException {
		int testCases = nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			out.print("Case #" + testCase + ": ");
			solveOneTest();
		}
	}

	static void solveOneTest() throws IOException {
		String s = nextToken();
		int n = s.length();
		int mask = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != '.') {
				mask |= 1 << i;
			}
		}

		double answer = expected(n, mask);
		out.println(answer);
	}

	private static double expected(int n, int mask) {
		double[] totalPay = new double[1 << n];
		double[] pGet = new double[1 << n];
		totalPay[mask] = 0;
		pGet[mask] = 1;
		for (int m = mask; m < (1 << n) - 1; m++) {
			if ((m & mask) != mask) {
				continue;
			}
			for (int man = 0; man < n; man++) {
				int pay = n;
				int dude = man;
				while ((m & (1 << dude)) != 0) {
					--pay;
					++dude;
					if (dude == n) {
						dude = 0;
					}
				}
				int toM = m | (1 << dude);
				totalPay[toM] += totalPay[m] / n + (double)pay * pGet[m]/n;
				pGet[toM] += pGet[m] / n;
			}
		}
		return totalPay[totalPay.length - 1];
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("d.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream(new File("d.out"));
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
