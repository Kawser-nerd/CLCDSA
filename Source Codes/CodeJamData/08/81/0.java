import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;


public class TaskA {

	public static void main(String[] args) throws IOException {
		new TaskA().run();
	}

	BufferedReader br;
	PrintWriter pw;

	private void run() throws IOException {
		Locale.setDefault(Locale.US);
		br = new BufferedReader(new FileReader("a.in"));
		pw = new PrintWriter("a.out");

		int tests = Integer.parseInt(br.readLine().trim());
		for (int test = 1; test <= tests; test++) {
			pw.print("Case #" + test + ": ");
			runtest();
		}

		br.close();
		pw.close();
	}

	private void runtest() throws IOException {

		long[] x1 = new long[3];
		long[] y1 = new long[3];
		long[] x2 = new long[3];
		long[] y2 = new long[3];

		StringTokenizer st = new StringTokenizer(br.readLine());
		x1[0] = Long.parseLong(st.nextToken());
		y1[0] = Long.parseLong(st.nextToken());
		x1[1] = Long.parseLong(st.nextToken());
		y1[1] = Long.parseLong(st.nextToken());
		x1[2] = Long.parseLong(st.nextToken());
		y1[2] = Long.parseLong(st.nextToken());

		st = new StringTokenizer(br.readLine());
		x2[0] = Long.parseLong(st.nextToken());
		y2[0] = Long.parseLong(st.nextToken());
		x2[1] = Long.parseLong(st.nextToken());
		y2[1] = Long.parseLong(st.nextToken());
		x2[2] = Long.parseLong(st.nextToken());
		y2[2] = Long.parseLong(st.nextToken());

		int[][] perms = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

		for (int[] per : perms) {
			if (check(x1, y1, x2, y2, per)) {
				long xn = x1[0];
				long yn = y1[0];
				long axn = x1[1] - x1[0];
				long ayn = y1[1] - y1[0];
				long bxn = x1[2] - x1[0];
				long byn = y1[2] - y1[0];

				long xm = x2[per[0]];
				long ym = y2[per[0]];
				long axm = x2[per[1]] - x2[per[0]];
				long aym = y2[per[1]] - y2[per[0]];
				long bxm = x2[per[2]] - x2[per[0]];
				long bym = y2[per[2]] - y2[per[0]];

				long a = axn - axm;
				long b = bxn - bxm;
				long c = xm - xn;
				long d = ayn - aym;
				long e = byn - bym;
				long f = ym - yn;

				double p = 0.0;
				double q = 0.0;

				if (a * e != b * d) {
					p = (1.0 * c * e - b * f) / (1.0 * a * e - b * d);
					q = (1.0 * a * f - c * d) / (1.0 * a * e - b * d);
				}

				pw.printf("%.6f %.6f\n", xn + p * axn + q * bxn, yn + p * ayn + q * byn);

				return;
			}
		}

		System.exit(1);
	}

	private boolean check(long[] x1, long[] y1, long[] x2, long[] y2, int[] per) {
		double d1 = Math.hypot(x1[0] - x1[1], y1[0] - y1[1]);
		double d2 = Math.hypot(x1[0] - x1[2], y1[0] - y1[2]);
		double d3 = Math.hypot(x1[1] - x1[2], y1[1] - y1[2]);
		double e1 = Math.hypot(x2[per[0]] - x2[per[1]], y2[per[0]] - y2[per[1]]);
		double e2 = Math.hypot(x2[per[0]] - x2[per[2]], y2[per[0]] - y2[per[2]]);
		double e3 = Math.hypot(x2[per[1]] - x2[per[2]], y2[per[1]] - y2[per[2]]);
		double eps = 1e-6;
		return Math.abs(d1 * e2 - d2 * e1) < eps &&
		Math.abs(d1 * e3 - d3 * e1) < eps &&
		Math.abs(d2 * e3 - d3 * e2) < eps;
	}

}
