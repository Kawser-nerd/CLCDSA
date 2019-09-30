import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class Deasy implements Runnable {

	public static void main(String[] args) {
		new Thread(new Deasy()).start();
	}

	public void run() {
		try {
			solve();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private void solve() throws Exception {
		Locale.setDefault(Locale.US);
		BufferedReader br = new BufferedReader(new FileReader("d.in"));
		PrintWriter pw = new PrintWriter("d.out");
		
		int tests = Integer.parseInt(br.readLine().trim());
		for (int test = 1; test <= tests; test++) {
			int n = Integer.parseInt(br.readLine().trim());
			double[] x = new double[n];
			double[] y = new double[n];
			double[] r = new double[n];
			for (int i = 0; i < n; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				x[i] = Integer.parseInt(st.nextToken());
				y[i] = Integer.parseInt(st.nextToken());
				r[i] = Integer.parseInt(st.nextToken());
			}
			
			double result = 0;

			if (n == 1) {
				result = r[0];
			} else if (n == 2) {
				result = Math.max(r[0], r[1]);
			} else {
				double result0 = Math.max(r[0], solve2(x[1], y[1], r[1], x[2], y[2], r[2])); 
				double result1 = Math.max(r[1], solve2(x[0], y[0], r[0], x[2], y[2], r[2])); 
				double result2 = Math.max(r[2], solve2(x[1], y[1], r[1], x[0], y[0], r[0]));
				result = Math.min(result0, Math.min(result1, result2));
			}
			
			pw.printf("Case #%d: %.6f\n", test, result);
		}
		
		br.close();
		pw.close();
	}

	private double solve2(double x1, double y1, double r1, double x2, double y2, double r2) {
		double d = Math.hypot(x1 - x2, y1 - y2);
		if (d + r1 < r2) {
			return r2;
		}
		if (d + r2 < r1) {
			return r1;
		}
		return (d + r1 + r2) / 2;
	}

}
