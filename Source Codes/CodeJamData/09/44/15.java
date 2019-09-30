import java.io.*;
import java.util.*;

public class D implements Runnable {
	private static final double eps = 1e-9;
	private static String fileName = D.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	int n;
	int[] x;
	int[] y;
	int[] r;
	double x1, y1, x2, y2, rr;
	boolean ok, cool;
	boolean[] alive;
	
	private void solve() {
		double low = 0;
		double high = 2000;
		n = in.nextInt();
		x = new int[n];
		y = new int[n];
		r = new int[n];
		alive = new boolean[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
			r[i] = in.nextInt();
			low = Math.max(low, r[i]);
		}
		while (low + eps < high) {
			rr = (low + high) * 0.5;
			ok = false;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == j) {
						x1 = x[i];
						y1 = y[i];
						checkFirst();
						continue;
					}
					double c = Math.hypot(x[i] - x[j], y[i] - y[j]);
					double a = rr - r[i];
					double b = rr - r[j];
					if (a + b < c) {
						continue;
					}
					double cos = (a*a + c*c - b*b) / (2 * a * c);
					double beta = Math.acos(cos);
					double theta = Math.atan2(y[j] - y[i], x[j] - x[i]);
					theta += beta;
					x1 = x[i] + a * Math.cos(theta);
					y1 = y[i] + a * Math.sin(theta);
					checkFirst();
				}
			}
			if (ok) {
				high = rr;
			} else {
				low = rr;
			}
		}
		out.println(rr);
	}

	private void checkFirst() {
		boolean any = false;
		for (int i = 0; i < n; i++) {
			any |= (alive[i] = (Math.hypot(x[i] - x1, y[i] - y1) + r[i] > rr + eps));
		}
		if (!any) {
			ok = true;
			return;
		}
		cool = false;
		for (int i = 0; i < n; i++) {
			if (!alive[i]) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (!alive[j]) {
					continue;
				}
				if (i == j) {
					x2 = x[i];
					y2 = y[i];
					checkSecond();
					continue;
				}
				double c = Math.hypot(x[i] - x[j], y[i] - y[j]);
				double a = rr - r[i];
				double b = rr - r[j];
				if (a + b < c) {
					continue;
				}
				double cos = (a*a + c*c - b*b) / (2 * a * c);
				double beta = Math.acos(cos);
				double theta = Math.atan2(y[j] - y[i], x[j] - x[i]);
				theta += beta;
				x2 = x[i] + a * Math.cos(theta);
				y2 = y[i] + a * Math.sin(theta);
				checkSecond();
			}
		}
		if (cool) {
			ok = true;
		}
	}

	private void checkSecond() {
		for (int i = 0; i < n; i++) {
			if (!alive[i]) {
				continue;
			}
			if (Math.hypot(x[i] - x2, y[i] - y2) + r[i] > rr + eps) {
				return;
			}
		}
		cool = true;
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
		Thread thread = new Thread(new D());
		thread.start();
		thread.join();
		in.close();
		out.close();
	}
}
