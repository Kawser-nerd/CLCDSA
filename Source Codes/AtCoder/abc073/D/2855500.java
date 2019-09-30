import java.util.Scanner;

public class Main {

	static long ans = Integer.MAX_VALUE;
	static int[] u;
	static int[][] d;
	static int n, m, r;
	static boolean[] used = new boolean[9];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		r = sc.nextInt();
		u = new int[9];
		for(int i = 0; i < r; i++) u[i] = sc.nextInt() - 1;
		d = new int[201][201];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i != j) d[i][j] = Integer.MAX_VALUE / 10;
			}
		}
		for(int i = 0; i < m; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			int c = sc.nextInt();
			d[a][b] = d[b][a] = c;
		}
		for(int k = 0; k < n; k++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		dfs(0, -1, 0);
		System.out.println(ans);
	}

	static void dfs(int x, int last, int sum) {
		if(x == r) {
			ans = Math.min(sum, ans);
			return;
		}
		// ??????????
		for(int i = 0; i < r; i++) {
			if(!used[i]) {
				used[i] = true;
				if(last == -1) dfs(x + 1, i, 0);
				else dfs(x + 1, i, sum + d[u[last]][u[i]]);
				used[i] = false;
			}
		}
	}

}