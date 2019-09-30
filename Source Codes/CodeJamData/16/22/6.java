import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;

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
		String s1 = next();
		String s2 = next();
		int n = s1.length();
		long diffZero = 0;
		char solZero[] = new char[2 * n];
		long diffMax = Long.MIN_VALUE;
		char solMax[] = new char[2 * n];
		long diffMin = Long.MIN_VALUE;
		char solMin[] = new char[2 * n];
		char newSolZero[] = new char[2 * n];
		char newSolMax[] = new char[2 * n];
		char newSolMin[] = new char[2 * n];
		long p10 = 1;
		for (int i = n - 1; i >= 0; i--, p10 *= 10) {
			long newDiffZero = Long.MIN_VALUE;
			long newDiffMax = Long.MIN_VALUE;
			long newDiffMin = Long.MIN_VALUE;
			for (int d1 = 0; d1 < 10; d1++) {
				if (s1.charAt(i) != '?' && s1.charAt(i) != d1 + '0') {
					continue;
				}
				for (int d2 = 0; d2 < 10; d2++) {
					if (s2.charAt(i) != '?' && s2.charAt(i) != d2 + '0') {
						continue;
					}
					if (diffZero != Long.MIN_VALUE) {
						long newDiff = diffZero + p10 * (d1 - d2);
						char newSol[] = solZero;
						if (newDiffZero == Long.MIN_VALUE || abs(newDiff) < abs(newDiffZero)) {
							newDiffZero = newDiff;
							arraycopy(newSol, 2 * i + 2, newSolZero, 2 * i + 2, 2 * n - 2 * i - 2);
							newSolZero[2 * i] = (char) (d1 + '0');
							newSolZero[2 * i + 1] = (char) (d2 + '0');
						}
						if (newDiffMax == Long.MIN_VALUE || newDiff > newDiffMax) {
							newDiffMax = newDiff;
							arraycopy(newSol, 2 * i + 2, newSolMax, 2 * i + 2, 2 * n - 2 * i - 2);
							newSolMax[2 * i] = (char) (d1 + '0');
							newSolMax[2 * i + 1] = (char) (d2 + '0');
						}
						if (newDiffMin == Long.MIN_VALUE || newDiff < newDiffMin) {
							newDiffMin = newDiff;
							arraycopy(newSol, 2 * i + 2, newSolMin, 2 * i + 2, 2 * n - 2 * i - 2);
							newSolMin[2 * i] = (char) (d1 + '0');
							newSolMin[2 * i + 1] = (char) (d2 + '0');
						}
					}
					if (diffMax != Long.MIN_VALUE) {
						long newDiff = diffMax + p10 * (d1 - d2);
						char newSol[] = solMax;
						if (newDiffZero == Long.MIN_VALUE || abs(newDiff) < abs(newDiffZero)) {
							newDiffZero = newDiff;
							arraycopy(newSol, 2 * i + 2, newSolZero, 2 * i + 2, 2 * n - 2 * i - 2);
							newSolZero[2 * i] = (char) (d1 + '0');
							newSolZero[2 * i + 1] = (char) (d2 + '0');
						}
						if (newDiffMax == Long.MIN_VALUE || newDiff > newDiffMax) {
							newDiffMax = newDiff;
							arraycopy(newSol, 2 * i + 2, newSolMax, 2 * i + 2, 2 * n - 2 * i - 2);
							newSolMax[2 * i] = (char) (d1 + '0');
							newSolMax[2 * i + 1] = (char) (d2 + '0');
						}
						if (newDiffMin == Long.MIN_VALUE || newDiff < newDiffMin) {
							newDiffMin = newDiff;
							arraycopy(newSol, 2 * i + 2, newSolMin, 2 * i + 2, 2 * n - 2 * i - 2);
							newSolMin[2 * i] = (char) (d1 + '0');
							newSolMin[2 * i + 1] = (char) (d2 + '0');
						}
					}
					if (diffMin != Long.MIN_VALUE) {
						long newDiff = diffMin + p10 * (d1 - d2);
						char newSol[] = solMin;
						if (newDiffZero == Long.MIN_VALUE || abs(newDiff) < abs(newDiffZero)) {
							newDiffZero = newDiff;
							arraycopy(newSol, 2 * i + 2, newSolZero, 2 * i + 2, 2 * n - 2 * i - 2);
							newSolZero[2 * i] = (char) (d1 + '0');
							newSolZero[2 * i + 1] = (char) (d2 + '0');
						}
						if (newDiffMax == Long.MIN_VALUE || newDiff > newDiffMax) {
							newDiffMax = newDiff;
							arraycopy(newSol, 2 * i + 2, newSolMax, 2 * i + 2, 2 * n - 2 * i - 2);
							newSolMax[2 * i] = (char) (d1 + '0');
							newSolMax[2 * i + 1] = (char) (d2 + '0');
						}
						if (newDiffMin == Long.MIN_VALUE || newDiff < newDiffMin) {
							newDiffMin = newDiff;
							arraycopy(newSol, 2 * i + 2, newSolMin, 2 * i + 2, 2 * n - 2 * i - 2);
							newSolMin[2 * i] = (char) (d1 + '0');
							newSolMin[2 * i + 1] = (char) (d2 + '0');
						}
					}
				}
			}
			char t[] = solZero;
			diffZero = newDiffZero;
			solZero = newSolZero;
			newSolZero = t;
			t = solMax;
			diffMax = newDiffMax;
			solMax = newSolMax;
			newSolMax = t;
			t = solMin;
			diffMin = newDiffMin;
			solMin = newSolMin;
			newSolMin = t;
		}
		if (diffZero == Long.MIN_VALUE) {
			throw new AssertionError();
		}
//		String dumbAns = solveDumb(s1, s2);
//		for (int i = 0; i < n; i++) {
//			if (solZero[2 * i] != dumbAns.charAt(i) || solZero[2 * i + 1] != dumbAns.charAt(i + n)) {
//				System.err.println(s1);
//				System.err.println(s2);
//				System.err.println(dumbAns);
//				for (int j = 0; j < n; j++) {
//					System.err.print(solZero[2 * j]);
//				}
//				System.err.print(' ');
//				for (int j = 0; j < n; j++) {
//					System.err.print(solZero[2 * j + 1]);
//				}
//				System.err.println();
//				throw new AssertionError();
//			}
//		}
		printCase();
		for (int i = 0; i < n; i++) {
			out.print(solZero[2 * i]);
		}
		out.print(' ');
		for (int i = 0; i < n; i++) {
			out.print(solZero[2 * i + 1]);
		}
		out.println();
	}
	
//	static String solveDumb(String s1, String s2) {
//		int n = s1.length();
//		long p10 = 1;
//		for (int i = 0; i < n; i++) {
//			p10 *= 10;
//		}
//		long bestDiff = Long.MAX_VALUE;
//		String bestAns = null;
//		v1: for (long v1 = 0; v1 < p10; v1++) {
//			String sv1 = Long.toString(v1);
//			for (int i = 0; i < n; i++) {
//				if (s1.charAt(i) != '?' && s1.charAt(i) != (i < n - sv1.length() ? '0' : sv1.charAt(i + sv1.length() - n))) {
//					continue v1;
//				}
//			}
//			v2: for (long v2 = 0; v2 < p10; v2++) {
//				String sv2 = Long.toString(v2);
//				for (int i = 0; i < n; i++) {
//					if (s2.charAt(i) != '?' && s2.charAt(i) != (i < n - sv2.length() ? '0' : sv2.charAt(i + sv2.length() - n))) {
//						continue v2;
//					}
//				}
//				long diff = abs(v1 - v2);
//				if (diff < bestDiff) {
//					bestDiff = diff;
//					StringBuilder sb = new StringBuilder();
//					for (int i = 0; i < n - sv1.length(); i++) {
//						sb.append('0');
//					}
//					sb.append(sv1);
//					for (int i = 0; i < n - sv2.length(); i++) {
//						sb.append('0');
//					}
//					sb.append(sv2);
//					bestAns = sb.toString();
//				}
//			}
//		}
//		return bestAns;
//	}
	
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