import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[][] x = new int[N][2];
		for (int i = 0; i < N; ++i) {
			x[i][0] = sc.nextInt();
			x[i][1] = sc.nextInt();
		}

		int ng = 1_000_000_000 + 1;
		int ok = 0;
		while (ng - ok > 1) {
			int middle = (ok + ng) / 2;
			if (f(N, x, middle)) {
				ok = middle;
			} else {
				ng = middle;
			}
		}
		System.out.println(ok);
	}

	Comparator<int[]> comp = new Comparator<int[]>() {
		@Override
		public int compare(int[] o1, int[] o2) {
			if (o1[0] != o2[0]) {
				return Integer.compare(o1[0], o2[0]);
			} else {
				return Integer.compare(o1[1], o2[1]);
			}

		}
	};

	boolean f(int N, int[][] x, int d) {
		int sz = 1;
		while (sz < 2 * N)
			sz *= 2;
		int[][] arr = new int[2 * N][];
		for (int i = 0; i < N; ++i) {
			arr[i] = new int[] { x[i][0], i };
			arr[i + N] = new int[] { x[i][1], i };
		}
		Arrays.sort(arr, comp);
		ArrayList<Integer>[] lis = new ArrayList[N];
		for (int i = 0; i < N; ++i) {
			lis[i] = new ArrayList<>();
		}
		for (int i = 0; i < 2 * N; ++i) {
			lis[arr[i][1]].add(i);
		}
		ArrayList<Integer>[] g = new ArrayList[2 * sz + sz - 1];
		for (int i = 0; i < g.length; ++i) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < N; ++i) {
			int xId = lis[i].get(0);
			int yId = lis[i].get(1);
			g[xId + sz - 1].add(yId + 2 * sz - 1);
			g[xId + 2 * sz - 1].add(yId + sz - 1);
			g[yId + sz - 1].add(xId + 2 * sz - 1);
			g[yId + 2 * sz - 1].add(xId + sz - 1);
		}
		for (int i = 0; i < sz - 1; ++i) {
			g[i].add(2 * i + 1);
			g[i].add(2 * i + 2);
		}

		for (int i = 0; i < arr.length; ++i) {
			arr[i][1] = i;
		}
		for (int i = 0; i < arr.length; ++i) {
			int v = arr[i][0];
			IntervalConnect(new int[] { v - d + 1, -Integer.MAX_VALUE }, new int[] { v, i - 1 }, 0, sz - 1, 0, g, arr,
					i + 2 * sz - 1);
			IntervalConnect(new int[] { v, i + 1 }, new int[] { v + d - 1, Integer.MAX_VALUE }, 0, sz - 1, 0, g, arr,
					i + 2 * sz - 1);
		}

		int[] col = new int[2 * sz + sz - 1];
		stronglyConnectedComponent(g, col);
		System.gc();
		for (int i = 0; i < 2 * N; ++i) {
			if (col[i + sz - 1] == col[i + 2 * sz - 1]) {
				return false;
			}
		}
		return true;
	}

	// [a,b],[L,R]
	void IntervalConnect(int[] a, int[] b, int l, int r, int k, ArrayList<Integer>[] g, int[][] arr, int src) {
		if (l >= arr.length) {
			return;
		} else if (r >= arr.length) {
			IntervalConnect(a, b, l, (l + r) / 2, 2 * k + 1, g, arr, src);
			IntervalConnect(a, b, (l + r) / 2 + 1, r, 2 * k + 2, g, arr, src);
			return;
		}
		int[] L = arr[l];
		int[] R = arr[r];
		if (comp.compare(a, L) <= 0 && comp.compare(R, b) <= 0) {
			g[src].add(k);
			return;
		} else if (comp.compare(b, L) < 0 || comp.compare(R, a) < 0) {
			return;
		} else {
			IntervalConnect(a, b, l, (l + r) / 2, 2 * k + 1, g, arr, src);
			IntervalConnect(a, b, (l + r) / 2 + 1, r, 2 * k + 2, g, arr, src);
			return;
		}
	}

	class State {
		int i;
		int j;
		int parent;

		public State(int i_, int j_, int parent_) {
			i = i_;
			j = j_;
			parent = parent_;
		}
	}

	int stronglyConnectedComponent(ArrayList<Integer>[] g, int[] col) {
		int n = g.length;
		int order = 0;
		int cols = 0;
		int[] ord = new int[n];
		int[] low = new int[n];
		Arrays.fill(col, -1);
		Arrays.fill(ord, -1);
		Arrays.fill(low, -1);
		ArrayDeque<State> stk = new ArrayDeque<>();
		ArrayDeque<Integer> pnd = new ArrayDeque<>();
		for (int ii = 0; ii < n; ++ii) {
			if (ord[ii] != -1) {
				continue;
			}
			stk.add(new State(ii, 0, -1));
			while (!stk.isEmpty()) {
				State s = stk.pollFirst();
				if (ord[s.i] == -1) {
					low[s.i] = (ord[s.i] = order++);
					pnd.addFirst(s.i);
				}
				if (s.j - 1 >= 0 && g[s.i].get(s.j - 1) != s.parent && col[g[s.i].get(s.j - 1)] == -1) {
					low[s.i] = Math.min(low[s.i], low[g[s.i].get(s.j - 1)]);
				}
				if (s.j == g[s.i].size() && low[s.i] == ord[s.i]) {
					while (true) {
						int v = pnd.pollFirst();
						col[v] = cols;
						if (v == s.i)
							break;
					}
					++cols;
					continue;
				}
				if (s.j == g[s.i].size()) {
					continue;
				}
				stk.addFirst(new State(s.i, s.j + 1, s.parent));
				int dst = g[s.i].get(s.j);
				if (ord[dst] == -1) {
					stk.addFirst(new State(dst, 0, s.i));
				} else if (col[dst] == -1) {
					low[s.i] = Math.min(low[s.i], low[dst]);
				}
			}
		}
		return cols;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.