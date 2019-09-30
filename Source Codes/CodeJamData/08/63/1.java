import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		new C().run();
	}
	void run() {
		
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();		
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt();
			double p = sc.nextDouble();
			int x = sc.nextInt();
			double[] crt = new double[3];
			crt[0] = 0;
			crt[1] = p;
			crt[2] = 1;
			for (int i = 2; i < n; i++) {
				double[] next = new double[(1 << i) + 1];
				int d = next.length, e = crt.length;
				for (int j = 0; j < d; j++) {
					for (int k = 0; k <= j && j + k <= d; k++) {
						int up = (j + k) / 2, down = (j - k) / 2;
						if (up >= e) up = e - 1;
						double tmp = p * crt[up] + (1 - p) * crt[down];
						if (next[j] < tmp) next[j] = tmp;
					}
				}
				crt = next;
			}
			if (n == 1) {
				System.out.printf("%.10f%n", crt[f(x, n)]);
			} else {
				int j = f(x, n);
				int d = (1 << n) + 1, e = crt.length;
				double res = 0;
				for (int k = 0; k <= j && j + k <= d; k++) {
					int up = (j + k) / 2, down = (j - k) / 2;
					if (up >= e) up = e - 1;
					double tmp = p * crt[up] + (1 - p) * crt[down];
					if (res < tmp) res = tmp;
				}
				System.out.printf("%.10f%n", res);
			}
		}
	}
	int f(long x, int n) {
		int d = 1 << n;
		x = x * d / 1000000;
		return (int) x;
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
