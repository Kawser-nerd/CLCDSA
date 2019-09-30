import java.io.*;
import java.util.*;
import java.lang.reflect.*;


public class Main {

	static long CURRENT_TIME_NANO = System.nanoTime();

	public static void main(String[] args) throws Exception {

		int tests = next();

		for (int test = 1; test <= tests; test++) {
			int w = next();
			int h = next();

			int n = next() + 2;
			int[] x1 = new int[n];
			int[] y1 = new int[n];
			int[] x2 = new int[n];
			int[] y2 = new int[n];

			x1[0] = -1;
			x2[0] = -1;
			y1[0] = 0;
			y2[0] = h - 1;

			for (int i = 1; i < n - 1; i++) {
				x1[i] = next();
				y1[i] = next();
				x2[i] = next();
				y2[i] = next();
			}
			
			x1[n - 1] = w;
			x2[n - 1] = w;
			y1[n - 1] = 0;
			y2[n - 1] = h - 1;
			
			int[][] dist = new int[n][n];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					int distx = 0;
					if (x1[i] > x2[j]) distx = x1[i] - x2[j] - 1;
					else if (x1[j] > x2[i]) distx = x1[j] - x2[i] - 1;

					int disty = 0;
					if (y1[i] > y2[j]) disty = y1[i] - y2[j] - 1;
					else if (y1[j] > y2[i]) disty = y1[j] - y2[i] - 1;

					dist[i][j] = Math.max(distx, disty);
				}

			//sout(dist);
			
			int[] l = new int[n];
			int inf = 1000000000;
			Arrays.fill(l, inf);
			l[0] = 0;
			boolean[] fin = new boolean[n];
			for (int i = 0; i < n; i++) {
				int min_i = 0;
				int min = inf;
				for (int j = 0; j < n; j++) if (!fin[j] && l[j] < min) {
					min = l[j];
					min_i = j;
				}

				fin[min_i] = true;

				for (int j = 0; j < n; j++) if (!fin[j])
					l[j] = Math.min(l[j], l[min_i] + dist[j][min_i]);
			}

			out.println("Case #" + test + ": " + l[n - 1]);
		}

		out.close();
	}
	
	static void printtime() {System.out.println((System.nanoTime() - CURRENT_TIME_NANO)*1e-9);}
	static void nexttime() {printtime(); CURRENT_TIME_NANO = System.nanoTime();}
	static PrintWriter out = new PrintWriter(System.out);
	
	static BufferedReader bufferedreader = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer in = new StringTokenizer("");

	static String nextToken() throws Exception {
		if (!in.hasMoreTokens()) in = new StringTokenizer(bufferedreader.readLine());
		return in.nextToken();
	}

	static int next()  throws Exception {return Integer.parseInt(nextToken());};
	static int[] next(int n) throws Exception {
		int[] x = new int[n];
		for (int i = 0; i < n; i++) x[i] = next();
		return x;
	}
	static int[][] next(int n, int m) throws Exception {
		int[][] x = new int[n][];
		for (int i = 0; i < n; i++) x[i] = next(m);
		return x;
	}

	static long nextl() throws Exception {return Long.parseLong(nextToken());};
	static long[] nextl(int n) throws Exception {
		long[] x = new long[n];
		for (int i = 0; i < n; i++) x[i] = nextl();
		return x;
	}
	static long[][] nextl(int n, int m) throws Exception {
		long[][] x = new long[n][];
		for (int i = 0; i < n; i++) x[i] = nextl(m);
		return x;
	}

	static double nextd() throws Exception {return Double.parseDouble(nextToken());};
	static double[] nextd(int n) throws Exception {
		double[] x = new double[n];
		for (int i = 0; i < n; i++) x[i] = nextd();
		return x;
	}
	static double[][] nextd(int n, int m) throws Exception {
		double[][] x = new double[n][];
		for (int i = 0; i < n; i++) x[i] = nextd(m);
		return x;
	}

	static String nextline() throws Exception {
		in = new StringTokenizer("");
		return bufferedreader.readLine();
	}

	static void sout(long x) {System.out.println(x);}
	static void sout(String s) {System.out.println(s);}
	static void sout(int[] x) {for (int xx : x) System.out.print(xx + " "); System.out.println();}
	static void sout(long[] x) {for (long xx : x) System.out.print(xx + " "); System.out.println();}
	static void sout(int[][] x) {for (int[] xx : x) sout(xx); System.out.println();}
	static void sout(long[][] x) {for (long[] xx : x) sout(xx); System.out.println();}


}