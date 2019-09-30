import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	long maxflow(long[][] cap) {
		int n = cap.length;
		int[][] flow = new int[n][n];
		long ret = 0;
		int s = n - 2;
		int t = n - 1;
		while (true) {
			int[] pre = new int[n];
			Arrays.fill(pre, -1);
			ArrayDeque<Integer> q = new ArrayDeque<>();
			q.add(s);
			out: while (!q.isEmpty()) {
				int v = q.pollFirst();
				for (int i = 0; i < n; ++i) {
					if (cap[v][i] - flow[v][i] <= 0 || pre[i] != -1 || i == s) {
						continue;
					}
					pre[i] = v;
					if (i == t)
						break out;
					q.addLast(i);
				}
			}
			if (pre[t] == -1)
				break;
			long inc = Long.MAX_VALUE / 3;
			for (int i = t; i != s; i = pre[i]) {
				inc = Math.min(inc, cap[pre[i]][i] - flow[pre[i]][i]);
			}
			for (int i = t; i != s; i = pre[i]) {
				flow[pre[i]][i] += inc;
				flow[i][pre[i]] -= inc;
			}
			ret += inc;
		}
		return ret;
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		long base = 0;
		for (int i = 0; i < n; ++i) {
			a[i] = sc.nextLong();
			if (a[i] > 0)
				base += a[i];
		}
		long[][] cap = new long[n + 2][n + 2];
		for (int i = 1; i <= n; ++i) {
			for (int j = 2 * i; j <= n; j += i) {
				cap[i - 1][j - 1] = Long.MAX_VALUE / 3;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (a[i] >= 0) {
				cap[i][n + 1] = a[i];
			} else {
				cap[n][i] = -a[i];
			}
		}
		System.out.println(base - maxflow(cap));

	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}