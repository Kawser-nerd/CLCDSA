import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	class Edge implements Comparable<Edge> {
		int[] id;
		int cost;

		public Edge(int id1_, int id2_, int cost_) {
			id = new int[] { id1_, id2_ };
			cost = cost_;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(cost, o.cost);
		}
	}

	int NIL = Integer.MAX_VALUE;

	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		DJSet ds = new DJSet(n);
		int[][][] lis = new int[2][n][];
		for (int i = 0; i < n; ++i) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			lis[0][i] = new int[] { x, i };
			lis[1][i] = new int[] { y, i };
		}
		int[][] ref = new int[2][n];
		Arrays.sort(lis[0], new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[0], o2[0]);
			}
		});
		Arrays.sort(lis[1], new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[0], o2[0]);
			}
		});
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		for (int t = 0; t < 2; ++t) {
			for (int i = 0; i + 1 < n; ++i) {
				pq.add(new Edge(lis[t][i][1], lis[t][i + 1][1], lis[t][i + 1][0] - lis[t][i][0]));
			}
		}

		long ans = 0;
		while (!pq.isEmpty()) {
			Edge e = pq.poll();
			if (ds.equiv(e.id[0], e.id[1])) {
				continue;
			}
			ans += e.cost;
			ds.setUnion(e.id[0], e.id[1]);
		}
		System.out.println(ans);
	}

	class DJSet {
		int n;
		int[] upper;

		public DJSet(int n_) {
			n = n_;
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
			if (x != y) {
				if (upper[x] < upper[y]) {
					int tmp = x;
					x = y;
					y = tmp;
				}
				upper[y] += upper[x];
				upper[x] = y;
			}
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}