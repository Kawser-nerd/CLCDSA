import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int base = 0;
		int n = sc.nextInt();
		int[] b = new int[n];
		for (int i = 0; i < n; ++i) {
			b[i] = sc.nextInt();
			if (b[i] == 0)
				++base;
		}
		int Q = sc.nextInt();
		int[][] q = new int[Q][2];
		for (int i = 0; i < Q; ++i) {
			q[i][0] = sc.nextInt();
			q[i][1] = sc.nextInt();
		}
		Arrays.sort(q, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[0], o2[0]);
			}
		});
		RMQ rmq = new RMQ(n + 1);
		rmq.set(0, 0);
		int p = 0;
		for (int i = 0; i < Q; ++i) {
			while (q[i][0] - p > 1) {
				int c = b[p] == 1 ? 1 : -1;
				rmq.set(p + 1, Math.min(c + rmq.query(p), rmq.query(p + 1)));
				++p;
			}
			rmq.set(q[i][1], rmq.query(p, q[i][1] + 1));
		}
		while (n - p > 0) {
			int c = b[p] == 1 ? 1 : -1;
			rmq.set(p + 1, Math.min(c + rmq.query(p), rmq.query(p + 1)));
			++p;
		}
		System.out.println(base + rmq.query(n));
	}

	class RMQ {
		int n;
		int[] v;

		public RMQ(int n_) {
			n = 1;
			while (n < n_)
				n *= 2;
			v = new int[2 * n];
			Arrays.fill(v, Integer.MAX_VALUE / 3);
		}

		void add(int k, int val) {
			k += n;
			v[k] += val;
			while (k > 1) {
				k = k / 2;
				v[k] = Math.min(v[2 * k], v[2 * k + 1]);
			}
		}

		void set(int k, int val) {
			k += n;
			v[k] = val;
			while (k > 1) {
				k = k / 2;
				v[k] = Math.min(v[2 * k], v[2 * k + 1]);
			}
		}

		int query(int a) {
			return v[a + n];
		}

		int query(int a, int b) {
			a += n;
			b += n;
			int ret = Integer.MAX_VALUE / 3;
			while (a < b) {
				if (a % 2 == 1) {
					ret = Math.min(ret, v[a++]);
				}
				if (b % 2 == 1) {
					ret = Math.min(ret, v[--b]);
				}
				a /= 2;
				b /= 2;
			}
			return ret;
		}

	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}