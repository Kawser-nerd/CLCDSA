import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		double[] x = new double[n];
		double[] y = new double[n];
		for (int i = 0; i < n; ++i) {
			x[i] = sc.nextDouble();
			y[i] = sc.nextDouble();
		}
		for (int i = 0; i < n; ++i) {
			double[] deg = new double[n - 1];
			int cnt = 0;
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;
				deg[cnt++] = (Math.atan2(y[j] - y[i], x[j] - x[i]));
			}
			Arrays.sort(deg);
			double ans = 0;
			for (int j = 0; j < n - 2; ++j) {
				ans = Math.max(ans, deg[(j + 1) % (n - 1)] - deg[j]);
			}
			ans = Math.max(ans, Math.PI * 2 + deg[0] - deg[n - 2]);
			ans = ans - Math.PI;
			if (ans <= 0)
				System.out.println(0);
			else
				System.out.println(String.format("%.20f", ans / (2 * Math.PI)));
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}