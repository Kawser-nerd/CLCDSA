import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	int N;
	long[] a;
	long[] sum;
	int s = 0;

	ArrayList<Integer> ans = new ArrayList<>();

	//i=0,1,2
	void erase(int i) {
		ans.add(i);
		if (s + i == N - 1) {
			--N;
			return;
		}
		if (i == 0) {
			s += 1;
			return;
		} else if (i == 1) {
			a[s + 2] += a[s];
			s += 2;
		} else if (i == 2) {
			a[s + 3] += a[s + 1];
			a[s + 2] = a[s];
			s += 2;
		}
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		a = new long[N];
		sum = new long[2];
		boolean[] f = new boolean[] { true, true };
		for (int i = 0; i < N; ++i) {
			a[i] = sc.nextLong();
			if (a[i] > 0)
				sum[i % 2] += a[i];
			f[i % 2] &= a[i] < 0;
		}
		if (f[0] && f[1]) {
			long max = -Long.MAX_VALUE / 3;
			for (int i = 0; i < N; ++i) {
				if (max < a[i]) {
					max = a[i];
				}
			}
			while (a[s] != max) {
				erase(0);
			}
			while (true) {
				if (s == N - 1)
					break;
				if (s == N - 2) {
					erase(1);
					break;
				}
				erase(2);
			}
			System.out.println(max);
		} else {
			if (sum[0] < sum[1]) {
				erase(0);
			}
			while (true) {
				if (s == N - 1)
					break;
				if (s == N - 2) {
					erase(1);
					break;
				}
				if (a[s] < 0) {
					erase(0);
					erase(0);
				} else if (a[s + 2] > 0) {
					erase(1);
				} else if (a[s + 2] <= 0) {
					erase(2);
				}
			}
			System.out.println(Math.max(sum[0], sum[1]));
		}
		System.out.println(ans.size());
		for (int v : ans) {
			System.out.println(v + 1);
		}
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}