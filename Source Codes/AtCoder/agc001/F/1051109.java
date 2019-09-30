import java.util.*;

public class Main {
	static boolean[] vis;
	static SegTree seg;
	static int n, k;
	static int idx = 0;
	static int[] ans;
	static int[] p;
	static int[] q;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		p = new int[n];
		vis = new boolean[n];
		ans = new int[n];
		for (int i = 0; i < n; ++i) {
			p[i] = sc.nextInt() - 1;
		}
		q = new int[n];
		for (int i = 0; i < n; ++i) {
			q[p[i]] = i;
		}
		seg = new SegTree(n);
		for (int i = 0; i < n; ++i) {
			seg.val[i + seg.n - 1] = q[i];
		}
		for (int i = seg.n - 2; i >= 0; --i) {
			seg.val[i] = Math.min(seg.val[2 * i + 1], seg.val[2 * i + 2]);
		}
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				dfs(i);
			}
		}
		StringBuilder sb = new StringBuilder();
		int[] t = new int[n];
		for (int i = 0; i < n; ++i) {
			t[ans[i]] = i;
		}
		ans = Arrays.copyOf(t, t.length);
		for (int i : ans) {
			sb.append((i + 1) + "\n");
		}
		System.out.println(sb);
	}

	static void dfs(int i) {
		while (true) {
			int min = seg.query(0, p[i]);
			if (min < i + k) {
				dfs(min);
			} else
				break;
		}
		ans[idx++] = i;
		vis[i] = true;
		seg.setVal(p[i], Integer.MAX_VALUE / 10);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	static class SegTree {
		int n = 1;
		int[] val;

		public SegTree(int n_) {
			while (n < n_) {
				n *= 2;
			}
			val = new int[2 * n - 1];
		}

		void setVal(int k, int v) {
			k += n - 1;
			val[k] = v;
			while (k > 0) {
				k = (k - 1) / 2;
				val[k] = Math.min(val[2 * k + 1], val[2 * k + 2]);
			}
		}

		int query(int a, int b) {
			return query(a, b, 0, n, 0);
		}

		int query(int a, int b, int l, int r, int k) {
			if (a <= l && r <= b) {
				return val[k];
			} else if (r <= a || b <= l) {
				return Integer.MAX_VALUE / 10;
			} else {
				int vl = query(a, b, l, (l + r) / 2, 2 * k + 1);
				int vr = query(a, b, (l + r) / 2, r, 2 * k + 2);
				return Math.min(vl, vr);
			}
		}
	}

}