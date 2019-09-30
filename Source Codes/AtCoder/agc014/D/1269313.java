import java.util.ArrayDeque;
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
		int[] a = new int[N - 1];
		int[] b = new int[N - 1];
		int[] deg = new int[N];
		ArrayList<Integer>[] g = new ArrayList[N];
		for (int i = 0; i < N; ++i) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < N - 1; ++i) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			--a[i];
			--b[i];
			g[a[i]].add(b[i]);
			g[b[i]].add(a[i]);
			++deg[a[i]];
			++deg[b[i]];
		}

		ArrayDeque<Integer> que = new ArrayDeque<>();
		for (int i = 0; i < N; ++i) {
			if (deg[i] == 1) {
				que.add(i);
			}
		}
		boolean[] used = new boolean[N];
		while (!que.isEmpty()) {
			int v = que.poll();
			if (used[v])
				continue;
			boolean update = false;
			for (int dst : g[v]) {
				if (used[dst])
					continue;
				for (int u : g[dst]) {
					if (!used[u]) {
						--deg[u];
						if (deg[u] == 1) {
							que.add(u);
						}
					}
				}
				used[dst] = true;
				update = true;
				--deg[dst];
			}
			if (!update) {
				System.out.println("First");
				return;
			}
		}
		System.out.println("Second");
	}

	private static void tr(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.