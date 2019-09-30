import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// new Main().run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; ++i) {
			arr[i] = sc.nextInt();
		}
		solve(n, arr);
	}

	int n;
	int[] p;
	SegTree[] seg;

	public void solve(int n_, int[] p_) {
		n = n_;
		p = p_;
		int[] ref = new int[n + 1];
		Arrays.fill(ref, -1);
		for (int i = 0; i < n; ++i) {
			ref[p[i]] = i;
		}
		seg = new SegTree[2];
		for (int i = 0; i < 2; ++i) {
			seg[i] = new SegTree(n);
		}
		for (int i = 0; i < n; ++i) {
			seg[i % 2].v[i + seg[i % 2].n - 1] = p[i];
		}
		for (int t = 0; t < 2; ++t) {
			for (int i = seg[t].n - 2; i >= 0; --i) {
				seg[t].v[i] = Math.min(seg[t].v[2 * i + 1], seg[t].v[2 * i + 2]);
			}
		}
		ArrayList<Integer> ans = new ArrayList<>();
		PriorityQueue<Interval> pq = new PriorityQueue<>();
		pq.add(new Interval(0, n, seg[0].query(0, n)));
		while (!pq.isEmpty()) {
			Interval I = pq.poll();
			if (I.r - I.l <= 1)
				continue;
			int v = I.v;
			int vIdx = ref[v];
			int u = seg[1 - I.l % 2].query(vIdx + 1, I.r);
			int uIdx = ref[u];
			seg[I.l % 2].setVal(vIdx, Integer.MAX_VALUE / 10);
			seg[1 - I.l % 2].setVal(uIdx, Integer.MAX_VALUE / 10);
			pq.add(new Interval(I.l, vIdx, seg[I.l % 2].query(I.l, vIdx)));
			pq.add(new Interval(vIdx + 1, uIdx, seg[(vIdx + 1) % 2].query(vIdx + 1, uIdx)));
			pq.add(new Interval(uIdx + 1, I.r, seg[(uIdx + 1) % 2].query(uIdx + 1, I.r)));
			ans.add(v);
			ans.add(u);
		}
		for (int i = 0; i < ans.size(); ++i) {
			System.out.print(ans.get(i) + (i == ans.size() - 1 ? "\n" : " "));
		}
	}

	class Interval implements Comparable<Interval> {
		int l, r;
		int v;

		public Interval(int l_, int r_, int v_) {
			l = l_;
			r = r_;
			v = v_;
		}

		@Override
		public int compareTo(Interval o) {
			return Integer.compare(v, o.v);
		}
	}

	class SegTree {
		int n;
		int[] v;

		public SegTree(int n_) {
			n = 1;
			while (n < n_) {
				n *= 2;
			}
			v = new int[2 * n - 1];
			Arrays.fill(v, Integer.MAX_VALUE / 10);
		}

		void setVal(int k, int val) {
			k += n - 1;
			v[k] = val;
			while (k > 0) {
				k = (k - 1) / 2;
				v[k] = Math.min(v[2 * k + 1], v[2 * k + 2]);
			}
		}

		int query(int a, int b, int l, int r, int k) {
			if (a <= l && r <= b) {
				return v[k];
			} else if (r <= a || b <= l) {
				return Integer.MAX_VALUE / 10;
			} else {
				int vl = query(a, b, l, (l + r) / 2, 2 * k + 1);
				int vr = query(a, b, (l + r) / 2, r, 2 * k + 2);
				return Math.min(vl, vr);
			}
		}

		int query(int a, int b) {
			return query(a, b, 0, n, 0);
		}
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}