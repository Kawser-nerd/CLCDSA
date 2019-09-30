import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	long toKey(int a, int b) {
		if (a < b) {
			return (long) b << 32 | a;
		} else {
			return (long) a << 32 | b;
		}
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		Set<Integer>[] g = new Set[N];
		for (int i = 0; i < N; ++i) {
			g[i] = new HashSet<>();
		}
		int[] rep = new int[N];
		for (int i = 0; i < N; ++i) {
			rep[i] = i;
		}
		ArrayDeque<Long> pend = new ArrayDeque<>();
		for (int i = 0; i < 2 * (N - 1); ++i) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			--a;
			--b;
			if (g[a].contains(b)) {
				pend.add(toKey(a, b));
			}
			g[a].add(b);
			g[b].add(a);
		}
		DJSet ds = new DJSet(N);
		while (!pend.isEmpty()) {
			long key = pend.poll();
			int a = (int) (key >> 32);
			int b = (int) (key);
			a = rep[ds.root(a)];
			b = rep[ds.root(b)];
			if (ds.equiv(a, b))
				continue;
			ds.setUnion(a, b);
			if (g[a].size() < g[b].size()) {
				int tmp = a;
				a = b;
				b = tmp;
			}
			g[a].remove(b);
			g[b].remove(a);
			for (int v : g[b]) {
				g[v].remove(b);
				g[v].add(a);
				if (g[a].contains(v)) {
					pend.add(toKey(v, a));
				}
				g[a].add(v);
			}
			g[b].clear();
			rep[ds.root(b)] = a;
		}
		if (ds.size(0) == N) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}

	class DJSet {
		int n;
		int[] upper;

		public DJSet(int n) {
			this.n = n;
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		void setUnion(int x, int y) {
			x = root(x);
			y = root(y);
			if (x == y)
				return;
			if (size(x) < size(y)) {
				int tmp = x;
				x = y;
				y = tmp;
			}
			upper[x] += upper[y];
			upper[y] = x;
		}

		int size(int x) {
			return -upper[root(x)];
		}
	}

	private static void tr(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.