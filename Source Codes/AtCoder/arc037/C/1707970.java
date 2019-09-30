import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// System.err.println(System.currentTimeMillis() - t);
	}

	// middle?????k?????
	boolean check(long[] a, long[] b, long middle, int k) {
		int n = a.length;
		long sum = 0;
		int h = n - 1;
		for (int i = 0; i < n; ++i) {
			while (h > 0 && a[i] * b[h] > middle) {
				--h;
			}
			if (a[i] * b[h] <= middle)
				sum += h + 1;
		}
		return sum >= k;
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		long[] a = new long[n];
		long[] b = new long[n];
		for (int i = 0; i < n; ++i) {
			a[i] = sc.nextLong();
		}
		for (int i = 0; i < n; ++i) {
			b[i] = sc.nextLong();
		}
		Arrays.sort(a);
		Arrays.sort(b);
		long ng = 0;
		long ok = a[n - 1] * b[n - 1];
		while (ok - ng > 1) {
			long middle = (ok + ng) / 2;
			if (check(a, b, middle, k)) {
				ok = middle;
			} else {
				ng = middle;
			}
		}
		System.out.println(ok);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}