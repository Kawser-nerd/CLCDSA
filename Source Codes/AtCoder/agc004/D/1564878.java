import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) throws FileNotFoundException {
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
	}

	public void run() {
		input();
	}

	void input() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = sc.nextInt();
			--a[i];
		}
		solver(n, k, a);
	}

	int ans = 0;

	void solver(int n, int k, int[] a) {
		// i->a[i]
		ArrayList<Integer>[] g = new ArrayList[n];
		for (int i = 0; i < g.length; ++i)
			g[i] = new ArrayList<>();
		for (int i = 1; i < n; ++i) {
			g[a[i]].add(i);
		}
		if (a[0] != 0) {
			++ans;
			a[0] = 0;
		}
		depth = new int[n];
		dfs(0, -1, g, k);
		System.out.println(ans);
	}

	int[] depth;

	void dfs(int cur, int par, ArrayList<Integer>[] g, int K) {
		depth[cur] = 0;
		for (int dst : g[cur]) {
			dfs(dst, cur, g, K);
			depth[cur] = Math.max(depth[dst] + 1, depth[cur]);
		}
		if (depth[cur] == K - 1 && par != 0 && cur != 0) {
			++ans;
			depth[cur] = -1;
		}
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.