import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class FlySwatter {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("C-large.in"));
		// BufferedReader br = new BufferedReader(new
		// InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter("C.out");
		Locale.setDefault(Locale.US);

		int n = Integer.parseInt(br.readLine());
		for (int cs = 0; cs < n; cs++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			double f = Double.parseDouble(st.nextToken());
			double R = Double.parseDouble(st.nextToken());
			double t = Double.parseDouble(st.nextToken());
			double r = Double.parseDouble(st.nextToken());
			double g = Double.parseDouble(st.nextToken());
			double p = 0;
			if (g < 2 * f)
				p = 1;
			else {
				double free = 0;
				double d = g - 2 * f;
				int k = 2000;
				for (double x1 = r + f; x1 * x1 < (R - t - f) * (R - t - f); x1 += g
						+ 2 * r) {
					while (k >= 0
							&& !inside(x1 + d, r + f + k * (g + 2 * r) + d, R
									- t - f))
						k--;
					free += d * d * (k + 1);
					for (double y1 = r + f + (k + 1) * (g + 2 * r); x1 * x1
							+ y1 * y1 < (R - t - f) * (R - t - f); y1 += g + 2
							* r) {
						double p1x = x1 + d, p1y = y1 + d, p2x = x1 + d, p2y = y1
								+ d;
						if (inside(x1 + d, y1 + d, R - t - f))
							free += d * d;
						else {
							if (inside(x1 + d, y1, R - t - f)) {
								p1x = x1 + d;
								p1y = Math.sqrt((R - t - f) * (R - t - f) - p1x
										* p1x);
							} else {
								p1y = y1;
								p1x = Math.sqrt((R - t - f) * (R - t - f) - p1y
										* p1y);
							}
							if (inside(x1, y1 + d, R - t - f)) {
								p2y = y1 + d;
								p2x = Math.sqrt((R - t - f) * (R - t - f) - p2y
										* p2y);
							} else {
								p2x = x1;
								p2y = Math.sqrt((R - t - f) * (R - t - f) - p2x
										* p2x);
							}
							free += sq(x1, y1, p1x, p1y) + sq(x1, y1, p2x, p2y)
									- sq(x1, y1, p2x, p1y)
									+ triangle(p1x, p1y, p2x, p2y, p2x, p1y);
							free += getsec(p1x, p1y, p2x, p2y, (R - t - f));
						}
					}
				}

				p = 1 - 4 * free / (Math.PI * R * R);
			}
			pw.println("Case #" + (cs + 1) + ": " + p);
		}

		pw.close();
	}

	private static double triangle(double x1, double y1, double x2, double y2,
			double x3, double y3) {
		double a = Math.hypot(x1 - x2, y1 - y2);
		double b = Math.hypot(x1 - x3, y1 - y3);
		double c = Math.hypot(x2 - x3, y2 - y3);
		double p = (a + b + c) / 2;
		double s = Math.sqrt(p * (p - a) * (p - b) * (p - c));
		return s;
	}

	private static double getsec(double x1, double y1, double x2, double y2,
			double r) {
		double c = Math.hypot(x1 - x2, y1 - y2);
		double ang = Math.acos(1 - c * c / (2 * r * r));
		return r * r * ang / 2 - c * Math.sqrt(r * r - c * c / 4) / 2;
	}

	private static boolean inside(double x, double y, double r) {
		return x * x + y * y < r * r;
	}

	private static double sq(double x1, double y1, double x2, double y2) {
		return Math.abs((x1 - x2) * (y1 - y2));
	}
}
