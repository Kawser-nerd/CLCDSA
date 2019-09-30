import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) throws FileNotFoundException {
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).run();
	}

	int N, M;
	int[] A, B;
	int[] col;
	int[][] cnt;
	ArrayList<Integer>[] g;

	public void run() {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		A = new int[M];
		B = new int[M];
		col = new int[N];
		g = new ArrayList[N];
		boolean[][] connect = new boolean[N][N];
		cnt = new int[N][2];
		for (int i = 0; i < N; ++i)
			g[i] = new ArrayList<>();
		Arrays.fill(col, -1);
		for (int i = 0; i < M; ++i) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
			--A[i];
			--B[i];
			connect[A[i]][B[i]] = true;
			connect[B[i]][A[i]] = true;
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i != j && !connect[i][j]) {
					g[i].add(j);
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			if (col[i] == -1) {
				col[i] = 0;
				dfs(i, -1);
				++p;
			}
		}
		if (!flag) {
			System.out.println(-1);
			return;
		}
		boolean[][] ok = new boolean[1000][1000];
		ok[0][0] = true;
		for (int i = 0; i + 1 <= N; ++i) {
			for (int j = 0; j < 1000; ++j) {
				if (ok[i][j]) {
					if (ok[i + 1].length > j + cnt[i][0])
						ok[i + 1][j + cnt[i][0]] = ok[i][j];
					if (ok[i + 1].length > j + cnt[i][1])
						ok[i + 1][j + cnt[i][1]] = ok[i][j];
				}
			}
		}
		long ans = Long.MAX_VALUE / 3;
		for (int i = 0; i < ok[p].length; ++i) {
			if (ok[p][i]) {
				ans = Math.min(ans, i * (i - 1) / 2 + (N - i) * (N - i - 1) / 2);
			}
		}
		System.out.println(ans);
		System.exit(0);
	}

	int p = 0;
	boolean flag = true;

	void dfs(int cur, int par) {
		cnt[p][col[cur]]++;
		for (int dst : g[cur]) {
			if (dst == par)
				continue;
			if (col[dst] == -1) {
				col[dst] = col[cur] ^ 1;
				dfs(dst, cur);
			} else {
				if (col[dst] != (col[cur] ^ 1)) {
					// System.out.println(-1);
					// System.exit(-1);
					flag = false;
				}
			}
		}
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.