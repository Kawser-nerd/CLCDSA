import java.io.*;
import java.util.*;

public class C implements Runnable {
	private static String fileName = C.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		
		long[][] c = new long[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			c[i][0] = c[i][i] = 1;
			for (int j = 1; j < i; j++) {
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			}
		}
		
		double[] p = new double[n + 1];
		double[] t = new double[n + 1];
		p[0] = 1;
		for (int i = 0; i < n; i++) {
			double pstay = c[i][k] * 1.0 / c[n][k];
			if (p[i] == 0)
				continue;
			for (int j = 1; j <= k; j++) {
				double pmove = c[i][k - j] * c[n - i][j] * 1.0 / c[n][k];
				if (pmove == 0)
					continue;
				int ii = i + j;
				double pp = p[i] * pmove / (1 - pstay);
				double tt = t[i] + 1 / (1 - pstay);
				t[ii] = (p[ii] * t[ii] + pp * tt) / (p[ii] + pp);
				p[ii] = p[ii] + pp;
			}
		}
		out.println(t[n]);
	}

	public void run() {
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			solve();
		}
	}

	public static void main(String[] args) throws IOException, InterruptedException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		Thread thread = new Thread(new C());
		thread.start();
		thread.join();
		in.close();
		out.close();
	}
}
