import java.util.Scanner;

public class Main {
	static long ans = 0;

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		boolean[][] path = new boolean[n + 1][n + 1];
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			path[a][b] = true;
			path[b][a] = true;
		}
		sc.close();

		boolean[] flg = new boolean[n + 1];
		dfs(flg, path, 1);
		System.out.println(ans);
	}

	static void dfs(boolean[] flg, boolean[][] path, int node) {
		if (flg[node]) {
			return;
		}
		flg[node] = true;

		boolean judge = true;
		for (int i = 1; i < flg.length; i++) {
			if (!flg[i]) {
				judge = false;
				break;
			}
		}
		if (judge) {
			ans++;
			return;
		}

		for (int i = 1; i < path[node].length; i++) {
			if (path[node][i]) {
				boolean[] nextFlg = new boolean[flg.length];
				System.arraycopy(flg, 0, nextFlg, 0, flg.length);
				dfs(nextFlg, path, i);
			}
		}
	}
}