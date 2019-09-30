import static java.lang.Math.max;
import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class B {

	static void solveMultiTest() throws IOException {
		int testCases = nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			out.println("Case #" + testCase + ": "+solveOneTest());
		}
	}

	static String solveOneTest() throws IOException {
		int r = nextInt(), c = nextInt();
		int[][] a =new int[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				a[i][j] = nextInt();
			}
		}
		int[] maxRow = new int[r];
		int[] maxCol = new int[c];
		fill(maxRow, Integer.MIN_VALUE);
		fill(maxCol, Integer.MIN_VALUE);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				maxRow[i] = max(maxRow[i], a[i][j]);
				maxCol[j] = max(maxCol[j], a[i][j]);
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (a[i][j] < maxRow[i] && a[i][j] < maxCol[j]) {
					return "NO";
				}
			}
		}
		return "YES";
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
