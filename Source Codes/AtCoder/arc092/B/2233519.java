import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] a = new long[N];
		long[] b = new long[N];
		for (int i = 0; i < N; ++i) {
			a[i] = sc.nextLong();
		}
		for (int i = 0; i < N; ++i) {
			b[i] = sc.nextLong();
		}
		long ans = 0;
		for (int k = 0; k <= 28; ++k) {
			long[] a_ = new long[N];
			long[] b_ = new long[N];
			long T = 1 << k;
			for (int i = 0; i < N; ++i) {
				a_[i] = a[i] % (2 * T);
				b_[i] = b[i] % (2 * T);
			}
			Arrays.sort(a_);
			Arrays.sort(b_);
			long c = 0;
			//[s,t)
			int s = 0;
			int t = 0;
			for (int i = N - 1; i >= 0; --i) {
				while (t < N && a_[i] + b_[t] < 2 * T)
					++t;
				while (s < N && a_[i] + b_[s] < T)
					++s;
				c ^= (t - s) % 2;
			}
			s = 0;
			t = 0;
			for (int i = N - 1; i >= 0; --i) {
				while (t < N && a_[i] + b_[t] < 4 * T)
					++t;
				while (s < N && a_[i] + b_[s] < 3 * T)
					++s;
				c ^= (t - s) % 2;
			}
			ans |= T * c;
		}
		System.out.println(ans);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}