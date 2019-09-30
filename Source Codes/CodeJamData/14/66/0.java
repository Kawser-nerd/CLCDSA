import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static void solve() throws Exception {
		int n = nextInt();
		int r = nextInt();
		int g = nextInt();
		double p[] = new double[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextDouble();
		}
		sort(p);
		double value[] = new double[r * g + 1];
		double nvalue[] = new double[r * g + 1];
		double matrix[][] = new double[r * g + 1][r * g + 1];
		double vector[] = new double[r * g + 1];
		for (int it = 0; it < 1000; it++) {
			for (int i = 0; i <= r * g; i++) {
				double ans = 0;
				fill(matrix[i], 0);
				vector[i] = 0;
				for (int j = 0; j < n; j++) {
					double cans = p[j] + value[min(i + 1, r * g)];
					if (i >= g && nvalue[i - g] > cans) {
						cans = nvalue[i - g];
						for (int k = 0; k <= r * g; k++) {
							matrix[i][k] += matrix[i - g][k];
						}
						vector[i] += vector[i - g];
					} else {
						matrix[i][min(i + 1, r * g)] += 1;
						vector[i] += p[j];
					}
					ans += cans;
				}
				for (int j = 0; j <= r * g; j++) {
					matrix[i][j] /= n;
				}
				vector[i] /= n;
				nvalue[i] = ans / n;
			}
//			for (int i = r * g; i >= 0; i--) {
//				nvalue[i] -= nvalue[0];
//			}
//			double t[] = value;
//			value = nvalue;
//			nvalue = t;
//			System.err.println(Arrays.deepToString(matrix));
//			System.err.println(Arrays.toString(vector));
			for (int i = 0; i <= r * g; i++) {
				matrix[i][i] -= 1;
			}
			for (int i = 0; i < r * g; i++) {
				for (int j = 0; j < r * g; j++) {
					matrix[i][j] -= matrix[r * g][j];
				}
				vector[i] -= vector[r * g];
			}
			gauss(r * g, matrix, vector, value);
			value[r * g] = 0;
//			System.err.println("V " + Arrays.toString(value) + " " + Arrays.toString(nvalue));
		}
//		System.err.println(Arrays.toString(value));
		double diff = 0;
		for (int i = 0; i <= r * g; i++) {
			double ans = 0;
			for (int j = 0; j < n; j++) {
				double cans = p[j] + value[min(i + 1, r * g)];
				if (i >= g) {
					cans = max(cans, nvalue[i - g]);
				}
				ans += cans;
			}
			nvalue[i] = ans / n;
			diff += nvalue[i] - value[i];
		}
		printCase();
		out.println(diff / (r * g + 1));
	}
	
	static void gauss(int n, double matrix[][], double vector[], double result[]) { // result * matrix + vector = 0
		for (int i = 0; i < n; i++) {
			int maxI = i;
			for (int j = i + 1; j < n; j++) {
				if (abs(matrix[j][i]) > abs(matrix[maxI][i])) {
					maxI = j;
				}
			}
			double t[] = matrix[i];
			matrix[i] = matrix[maxI];
			matrix[maxI] = t;
			double tt = vector[i];
			vector[i] = vector[maxI];
			vector[maxI] = tt;
			for (int j = i + 1; j < n; j++) {
				double mul = matrix[j][i] / matrix[i][i];
				matrix[j][i] = 0;
				for (int k = i + 1; k < n; k++) {
					matrix[j][k] -= mul * matrix[i][k];
				}
				vector[j] -= mul * vector[i];
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				double mul = matrix[j][i] / matrix[i][i];
				matrix[j][i] = 0;
				vector[j] -= mul * vector[i];
			}
		}
		for (int i = 0; i < n; i++) {
			result[i] = -vector[i] / matrix[i][i];
		}
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