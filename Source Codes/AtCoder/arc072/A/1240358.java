import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.SynchronousQueue;

class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; ++i) {
			a[i] = sc.nextLong();
		}
		long[] sum = new long[n];
		for (int i = 0; i < n; ++i) {
			sum[i] = (i > 0 ? sum[i - 1] : 0) + a[i];
		}

		long ans = Long.MAX_VALUE / 16;
		long[] first = { -1, 1, a[0] };
		out: for (long f : first) {
			long cnt = 0;
			long d = f - a[0];
			cnt = Math.abs(d);
			for (int i = 1; i < n; ++i) {
				if (sign(sum[i] + d) * sign(sum[i - 1] + d) < 0) {
					continue;
				}
				if (sum[i - 1] + d > 0 && sum[i] + d >= 0) {
					cnt += sum[i] + d + 1;
					d -= sum[i] + d + 1;
				} else if (sum[i - 1] + d < 0 && sum[i] + d <= 0) {
					cnt += -(sum[i] + d) + 1;
					d += -(sum[i] + d) + 1;
				} else {
					continue out;
				}
			}
			ans = Math.min(ans, cnt);
		}
		System.out.println(ans);

	}

	int sign(long x) {
		return Long.compare(x, 0);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}