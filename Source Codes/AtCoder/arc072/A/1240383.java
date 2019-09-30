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
		int[] sign = { -1, 1 };
		for (int f = 0; f <= 1; ++f) {
			long d = 0;
			long cnt = 0;
			for (int i = 0; i < n; ++i) {
				if (sign[(i + f) % 2] == sign(sum[i] + d))
					continue;
				cnt += Math.abs(sign[(i + f) % 2] - (sum[i] + d));
				d += sign[(i + f) % 2] - (sum[i] + d);
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