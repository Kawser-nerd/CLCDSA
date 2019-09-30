import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		new C().run();
	}
	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int o = 1; o <= n; o++) {
			double f = sc.nextDouble(), R = sc.nextDouble(), t = sc.nextDouble(), r = sc.nextDouble(), g = sc.nextDouble();
			double res = 0;
			for (int i = 0; i < 1100; i++) {
				for (int j = 0; j < 1100; j++) {
					res += calc((g + r * 2) * i + r + f, (g + r * 2) * i + r + g - f, (g + r * 2) * j + r + f, (g + r * 2) * j + r + g - f, R - t - f);
				}
			}
			System.out.printf("Case #%d: %.8f%n", o, 1 - res * 4 / (PI * R * R));
		}
	}
	double calc(double left, double right, double down, double up, double r) {
		if (left >= right || down >= up) return 0;
		if (left * left + down * down >= r * r) return 0;
		if (right * right + up * up <= r * r) return (right - left) * (up - down);
		return calc(left, down, r) - calc(left, up, r) - calc(right, down, r);
	}
	double calc(double x, double y, double r) {
		if (x * x + y * y >= r * r) return 0;
		double xx = sqrt(r * r - y * y), yy = sqrt(r * r - x * x);
		return (r * r * (atan2(yy, x) - atan2(y, xx)) - (x * (yy - y) + (xx - x) * y)) / 2;
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
