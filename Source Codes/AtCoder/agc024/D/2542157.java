import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	ArrayList<Integer>[] g;
	int[][] dist;

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		g = new ArrayList[2 * N - 1];
		dist = new int[2 * N - 1][2 * N - 1];
		for (int i = 0; i < 2 * N - 1; ++i)
			for (int j = 0; j < 2 * N - 1; ++j)
				if (i != j)
					dist[i][j] = Integer.MAX_VALUE / 3;
		for (int i = 0; i < g.length; ++i)
			g[i] = new ArrayList<>();
		for (int i = 0; i < N - 1; ++i) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			g[a].add(N + i);
			g[N + i].add(a);
			g[b].add(N + i);
			g[N + i].add(b);
			dist[a][N + i] = 1;
			dist[N + i][a] = 1;
			dist[b][N + i] = 1;
			dist[N + i][b] = 1;
		}
		N = 2 * N - 1;
		for (int k = 0; k < N; ++k)
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);

		int A = Integer.MAX_VALUE / 3;
		long B = Long.MAX_VALUE / 3;
		for (int root = 0; root < N; ++root) {
			int R = 0;
			for (int v = 0; v < N; ++v)
				R = Math.max(R, dist[root][v]);
			int a = R / 2 + 1;
			long L = 1;
			for (int dep = 0; dep < R; ++dep) {
				int mx = 0;
				for (int v = 0; v < N; ++v) {
					if (dep != dist[root][v])
						continue;
					mx = Math.max(mx, g[v].size());
				}
				if (dep != 0)
					--mx;
				L *= mx;
			}
			if (A > a || (A == a && L < B)) {
				A = a;
				B = L;
			}
		}
		System.out.println(A + " " + B);

	}

	public static void main(String[] args) {
		new Main().run();
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.