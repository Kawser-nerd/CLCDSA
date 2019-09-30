import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int Q = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		--A;
		--B;
		int[] x = new int[Q];
		for (int i = 0; i < Q; ++i) {
			x[i] = sc.nextInt();
			--x[i];
		}
		long[] f = new long[N];
		Arrays.fill(f, Long.MAX_VALUE / 16);
		Seg sAdd = new Seg(N);
		Seg sSub = new Seg(N);
		f[B] = Math.abs(A - x[0]);
		f[A] = Math.abs(B - x[0]);
		sAdd.setVal(A, f[A] + A);
		sAdd.setVal(B, f[B] + B);
		sSub.setVal(A, f[A] - A);
		sSub.setVal(B, f[B] - B);
		long pending = 0;
		for (int i = 1; i < Q; ++i) {
			long add = Math.abs(x[i] - x[i - 1]);
			pending += add;
			long cur = f[x[i]];// pending????
			cur = Math.min(cur, -x[i] + sAdd.query(x[i], N) - add);
			cur = Math.min(cur, x[i] + sSub.query(0, x[i]) - add);
			f[x[i - 1]] = cur;
			sAdd.setVal(x[i - 1], f[x[i - 1]] + x[i - 1]);
			sSub.setVal(x[i - 1], f[x[i - 1]] - x[i - 1]);
		}
		long ans = Long.MAX_VALUE / 16;
		for (int i = 0; i < N; ++i) {
			ans = Math.min(ans, f[i] + pending);
		}
		System.out.println(ans);
	}

	class Seg {
		int n;
		long[] v;

		public Seg(int n_) {
			n = 1;
			while (n < n_)
				n *= 2;
			v = new long[2 * n - 1];
			Arrays.fill(v, Long.MAX_VALUE / 16);
		}

		void setVal(int k, long val) {
			k += n - 1;
			v[k] = val;
			while (k > 0) {
				k = (k - 1) / 2;
				v[k] = Math.min(v[2 * k + 1], v[2 * k + 2]);
			}
		}

		long query(int a, int b) {
			return query(0, n, a, b, 0);
		}

		long query(int l, int r, int a, int b, int k) {
			if (r <= a || b <= l) {
				return Long.MAX_VALUE / 16;
			} else if (a <= l && r <= b) {
				return v[k];
			} else {
				long vl = query(l, (l + r) / 2, a, b, 2 * k + 1);
				long vr = query((l + r) / 2, r, a, b, 2 * k + 2);
				return Math.min(vl, vr);
			}
		}

	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}