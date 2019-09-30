import java.io.*;
import java.util.*;

/**
 * @author Mikhail Dvorkin
 */
public class C implements Runnable {
	private Scanner in;
	private PrintWriter out;

	private void solve(int testCase) {
		int n = in.nextInt();
		double[][] x = new double[n][3];
		long[] p = new long[n];
		for (int i = 0; i < n; i++) {
			x[i][0] = in.nextInt();
			x[i][1] = in.nextInt();
			x[i][2] = in.nextInt();
			p[i] = in.nextInt();
		}
		double inf = 1e8;
		double low = 0;
		double high = 10000000;
		while (low + 1e-9 < high) {
			double mid = (low + high) * 0.5;
			double[] a = new double[8];
			Arrays.fill(a, inf);
			for (int i = 0; i < n; i++) {
				for (int m = 0; m < 8; m++) {
					double lim = mid * p[i];
					for (int j = 0; j < 3; j++) {
						int sign = ((m & (1 << j)) > 0) ? 1 : -1;
						lim += x[i][j] * sign;
					}
					a[m] = Math.min(a[m], lim);
				}
			}
			boolean ok = true;
			for (int m = 0; m < 8; m++) {
				double lim = a[m] + a[m ^ 7];
				if (lim < 0)
					ok = false;
			}
			if (ok)
				high = mid;
			else
				low = mid;
		}
		out.printf("Case #%d: %.8f\n", testCase, high);
//		out.println("Case #" + testCase + ": " + high);
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Thread(new C()).start();
	}

	public void run() {
		try {
			in = new Scanner(new FileReader("c.in"));
			out = new PrintWriter("c.out");
			int n = in.nextInt();
			for (int i = 1; i <= n; i++)
				solve(i);
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
