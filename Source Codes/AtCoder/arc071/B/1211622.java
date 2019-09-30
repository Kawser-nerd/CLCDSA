import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	long MODULO = 1_000_000_000 + 7;

	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		long[] x = new long[n];
		long[] y = new long[m];
		for (int i = 0; i < n; ++i) {
			x[i] = sc.nextLong();
		}
		for (int i = 0; i < m; ++i) {
			y[i] = sc.nextLong();
		}
		System.out.println(cnt(x) * cnt(y) % MODULO);

	}

	long cnt(long[] arr) {
		int n = arr.length;
		long ret = 0;
		for (int i = 0; i < arr.length; ++i) {
			ret = ret + arr[i] * (-(n - 1 - i) + i) % MODULO;
			ret %= MODULO;
		}
		return ret;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}