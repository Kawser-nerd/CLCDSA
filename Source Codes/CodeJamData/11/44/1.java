import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class D {
	Scanner sc = new Scanner(System.in);
	
	int INF = 1 << 29;
	
	void solve() {
		int N = sc.nextInt(), M = sc.nextInt();
		boolean[][] g = new boolean[N][N];
		for (int i = 0; i < M; i++) {
			String[] s = sc.next().split(",");
			int u = Integer.parseInt(s[0]), v = Integer.parseInt(s[1]);
			g[u][v] = g[v][u] = true;
		}
		int[] dist = new int[N];
		fill(dist, INF);
		Queue<Integer> que = new LinkedList<Integer>();
		dist[0] = 0;
		que.offer(0);
		while (!que.isEmpty()) {
			int v = que.poll();
			for (int u = 0; u < N; u++) if (g[v][u] && dist[u] > dist[v] + 1) {
				dist[u] = dist[v] + 1;
				que.offer(u);
			}
		}
		int len = dist[1];
		System.out.print(len - 1 + " ");
		int[] num = new int[len + 1];
		for (int i = 0; i < N; i++) if (dist[i] <= len) num[dist[i]]++;
		if (len == 1) {
			System.out.println(num[1]);
			return;
		}
		int[][] dp = new int[N][N];
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dp[i][j] = -INF;
		for (int i = 0; i < N; i++) if (dist[i] == 1) {
			dp[0][i] = 0;
			for (int j = 0; j < N; j++) if (j != 0 && j != i && (g[0][j] || g[i][j])) dp[0][i]++;
		}
		for (int d = 2; d < len; d++) {
			for (int i = 0; i < N; i++) if (dist[i] == d) {
				for (int u = 0; u < N; u++) if (dist[u] == d - 1 && g[u][i]) {
					dp[u][i] = 0;
					for (int v = 0; v < N; v++) if (dp[v][u] >= 0) {
						int tmp = dp[v][u] - 1;
						for (int j = 0; j < N; j++) if (j != v && j != u && j != i && (!g[v][j] && !g[u][j] && g[i][j])) {
							tmp++;
						}
						dp[u][i] = max(dp[u][i], tmp);
					}
				}
			}
		}
		int res = 0;
		for (int i = 0; i < N; i++) if (dist[i] == len - 1 && g[i][1]) {
			for (int j = 0; j < N; j++) res = max(res, dp[j][i]);
		}
		System.out.println(res);
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (D.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new D().run();
	}
}
