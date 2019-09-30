import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Math.PI;
import static java.lang.Math.atan2;
import static java.lang.Math.sin;
import static java.lang.System.arraycopy;
import static java.util.Arrays.sort;

import java.io.*;
import java.math.BigInteger;
import java.util.Comparator;
import java.util.Locale;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solveTest() throws Exception {
		int n = nextInt();
		int m = nextInt();
		double xx[] = new double[n];
		double yy[] = new double[n];
		for (int i = 0; i < n; i++) {
			xx[i] = nextDouble();
			yy[i] = nextDouble();
		}
		final double x[] = new double[n];
		final double y[] = new double[n];
		Integer intssrc[] = new Integer[n];
		for (int i = 0; i < n; i++) {
			intssrc[i] = i;
		}
		Integer ints[] = new Integer[n];
		Comparator<Integer> acmp = new Comparator<Integer>() {

			public int compare(Integer o1, Integer o2) {
				double x1 = x[o1];
				double y1 = y[o1];
				double x2 = x[o2];
				double y2 = y[o2];
				if (y1 > 0) {
					if (y2 > 0) {
						//
					} else {
						return 1;
					}
				} else if (y1 < 0) {
					if (y2 < 0) {
						//
					} else {
						return -1;
					}
				} else {
					return y2 > 0 ? -1 : y2 < 0 ? 1 : 0;
				}
				double a1 = x1 / y1;
				double a2 = x2 / y2;
				return a1 > a2 ? -1 : a1 < a2 ? 1 : 0;
			}
		};
		int stack[] = new int[n];
		double stackPos[] = new double[n];
		for (int mm = 0; mm < m; mm++) {
			double ans = 0;
			FindAns: {
				double cx = nextDouble();
				double cy = nextDouble();
				for (int i = 0; i < n; i++) {
					x[i] = xx[i] - cx;
					y[i] = yy[i] - cy;
				}
				double x0 = x[0];
				double y0 = y[0];
				double mul = normsqr(x0, y0);
				for (int i = 0; i < n; i++) {
					double xi = x[i];
					double yi = y[i];
					x[i] = xi * x0 + yi * y0;
					y[i] = yi * x0 - xi * y0;
				}
				arraycopy(intssrc, 0, ints, 0, n);
				sort(ints, acmp);
//				System.out.print("Normalized points:");
//				for (int i = 0; i < n; i++) {
//					System.out.print(" (" + x[ints[i]] + ", " + y[ints[i]] + ")");
//					if (i < n - 1) {
//						System.out.print(",");
//					}
//				}
//				System.out.println();
				int stackSize = 0;
				for (int i = 0; i < n; i++) {
					int cur = ints[i];
					double curX = x[cur];
					double curY = y[cur];
					{
						double sqr = normsqr(curX, curY);
						curX /= sqr;
						curY /= sqr;
					}
					while (stackSize > 0) {
						int prev = stack[stackSize - 1];
						double prevX = x[prev];
						double prevY = y[prev];
						{
							double sqr = normsqr(prevX, prevY);
							prevX /= sqr;
							prevY /= sqr;
						}
						if (curY * prevX - curX * prevY <= 0) {
							break FindAns;
						}
						// posCur, posPrev
						// curX, -prevX, prevY - curY
						// curY, -prevY, curX - prevX
						double det = curX * (-prevY) - curY * (-prevX);
						double detCur = (prevY - curY) * (-prevY) - (curX - prevX) * (-prevX);
						double detPrev = curX * (curX - prevX) - curY * (prevY - curY);
						double posCur = detCur / det;
						double posPrev = detPrev / det;
						if (stackSize == 1 || posPrev < stackPos[stackSize - 1]) {
							stackPos[stackSize] = posCur;
							break;
						} else {
							--stackSize;
						}
					}
					stack[stackSize++] = cur;
				}
				double x1 = 0, y1 = 0, x2, y2;
				for (int i = 0; i < stackSize; i++) {
					if (i < stackSize - 1) {
						double curX = x[stack[i + 1]];
						double curY = y[stack[i + 1]];
						double sqr = normsqr(curX, curY);
						curX /= sqr;
						curY /= sqr;
						x2 = curX - curY * stackPos[i + 1];
						y2 = curY + curX * stackPos[i + 1];
						sqr = 2 / normsqr(x2, y2);
						x2 *= sqr;
						y2 *= sqr;
					} else {
						x2 = 0;
						y2 = 0;
					}
					ans += y1 * x2 - x1 * y2;
					double xi = x[stack[i]];
					double yi = y[stack[i]];
					double cos = (x1 - xi) * (x2 - xi) + (y1 - yi) * (y2 - yi);
					double sin = (y1 - yi) * (x2 - xi) - (x1 - xi) * (y2 - yi);
					double r2 = normsqr(xi, yi);
//					System.out.println("Segment from (" + x1 + ", " + y1 + ") to (" + x2 + ", " + y2 + ") (center: (" + xi + ", " + yi + "), radius: " + sqrt(r2) + ")");
					double angle = atan2(sin, cos);
					if (angle < 0) {
						angle += 2 * PI;
					}
					ans += r2 * (angle - sin(angle));
					x1 = x2;
					y1 = y2;
				}
				ans /= mul;
			}
			out.printf(Locale.US, "%.7f", ans / 2);
			if (mm < m - 1) {
				out.print(' ');
			}
		}
		out.println();
	}
	
	static double normsqr(double x, double y) {
		return x * x + y * y;
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
		}
	}

	public static void main(String[] args) throws Exception {
		System.out.print("Enter filename: ");
		System.out.flush();
		String filename = new BufferedReader(new InputStreamReader(System.in)).readLine();
		in = new BufferedReader(new InputStreamReader(
			new FileInputStream(new File(filename + ".in"))));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
			new FileOutputStream(new File(filename + ".out")))));
		solve();
		in.close();
		out.close();
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}
}