import java.util.Arrays;
import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		int m = scanner.nextInt();
		cost = new long[n][n];
		dis = new long[n];
		num = new int[n];
		num[a-1] = 1;
		varsize = n;
		used = new boolean[n];
		for (long[] d : cost) {
			Arrays.fill(d, Integer.MAX_VALUE);
		}
		for (int i = 0; i < m; i++) {
			int x = scanner.nextInt() - 1;
			int y = scanner.nextInt() - 1;
			cost[x][y] = 1;
			cost[y][x] = 1;
		}
		dijkstra(a - 1);
		System.out.println(num[b - 1]);
	}

	static long[][] cost;
	static long[] dis;
	static boolean[] used;
	static int[] num;
	static int varsize;

	static void dijkstra(int s) {
		Arrays.fill(dis, Integer.MAX_VALUE);
		dis[s] = 0;

		while (true) {
			int var = -1;
			//?????????????????????????
			for (int u = 0; u < varsize; u++) {
				if (!used[u] && (var == -1 || dis[u] < dis[var]))
					var = u;
			}

			if (var == -1)
				break;
			used[var] = true;

			//??for????????var????u????????????
			for (int u = 0; u < varsize; u++) {
				if (dis[u] > (dis[var] + cost[var][u])) {
					dis[u] = Math.min(dis[u], dis[var] + cost[var][u]);
					num[u] = num[var];
				} else if (dis[u] == dis[var] + cost[var][u]) {
					num[u] += num[var];
					num[u] %= 1000000007;
				}
			}
		}
	}
}