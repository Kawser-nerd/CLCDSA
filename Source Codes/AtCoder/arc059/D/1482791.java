import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// new Main().run();
	}

	final long MODULO = (long) (1e9 + 7);

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String S = sc.next();
		long[][] f = new long[n + 1][n + 1];
		f[0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int curLen = 0; curLen <= n; ++curLen) {
				if (curLen + 1 <= n) {
					f[i][curLen + 1] += 2 * f[i - 1][curLen];
					f[i][curLen + 1] %= MODULO;
				}
				if (curLen > 0) {
					f[i][curLen - 1] += f[i - 1][curLen];
					f[i][curLen - 1] %= MODULO;
				} else {
					f[i][curLen] += f[i - 1][curLen];
					f[i][curLen] %= MODULO;
				}
			}
		}
		long ans = f[n][S.length()] * inv(pow(2, S.length())) % MODULO;
		System.out.println(ans);
	}

	long pow(long a, long n) {
		long ret = 1;
		for (; n > 0; n >>= 1, a = (a * a) % MODULO) {
			if (n % 2 == 1) {
				ret = (ret * a) % MODULO;
			}
		}
		return ret;
	}

	long inv(long a) {
		// a * u + mod * v = x
		// a * p + mod * q = y
		long u = 1, v = 0, p = 0, q = 1, x = a, y = MODULO;
		while (x > 1) {
			u -= x / y * p;
			v -= x / y * q;
			x -= x / y * y;
			long d = u;
			u = p;
			p = d;
			d = v;
			v = q;
			q = d;
			d = x;
			x = y;
			y = d;
		}
		if (u < 0) {
			u += MODULO;
		}
		return u;
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}