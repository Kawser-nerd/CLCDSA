import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int z = sc.nextInt();
		int w = sc.nextInt();
		int[] a = new int[n + 2];
		for (int i = 0; i < n; ++i) {
			a[i + 2] = sc.nextInt();
		}
		a[0] = z;
		a[1] = w;
		// ??????
		// ??????
		System.out.println(f(1, 1, a));
	}

	long[] max = new long[2002];
	long[] min = new long[2002];
	{
		for (int i = 0; i < max.length; ++i) {
			max[i] = -Long.MAX_VALUE / 3;
			min[i] = Long.MAX_VALUE / 3;
		}
	}

	// b=0:??????
	// b=1:??????
	long f(int pre, int b, int[] a) {
		if (b == 0 && min[pre] < Integer.MAX_VALUE / 3) {
			return min[pre];
		}
		if (b == 1 && max[pre] > 0) {
			return max[pre];
		}
		long ret = b == 0 ? Long.MAX_VALUE / 3 : -Long.MAX_VALUE / 3;
		for (int i = pre + 1; i < a.length; ++i) {
			boolean f = i == a.length - 1;
			if (b == 0) {
				if (f) {
					ret = Math.min(ret, Math.abs(a[pre] - a[a.length - 1]));
				} else
					ret = Math.min(ret, f(i, b ^ 1, a));
			} else {
				if (f) {
					ret = Math.max(ret, Math.abs(a[pre] - a[a.length - 1]));
				} else
					ret = Math.max(ret, f(i, b ^ 1, a));
			}
		}
		if (b == 0)
			min[pre] = ret;
		else
			max[pre] = ret;
		return ret;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}