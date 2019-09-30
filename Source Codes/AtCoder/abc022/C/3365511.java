import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
	static final int INF = 1 << 27;
	static final int WHITE = 0;
	static final int GRAY = 1;
	static final int BLACK = 2;
	static int N, M;
	static int[][]d;
	static List<int[]> sList;
	static Map<Integer, List<int[]>> adj = new HashMap<Integer, List<int[]>>();
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		N = scan.nextInt();
		M = scan.nextInt();
		int[]u = new int[M];
		int[]v = new int[M];
		int[]l = new int[M];
		for(int i = 0; i < M; i++) {
			u[i] = scan.nextInt();
			v[i] = scan.nextInt();
			l[i] = scan.nextInt();
		}
		scan.close();
		d = new int[N + 1][N + 1];
		for(int i = 2; i <= N; i++) {
			for(int j = 2; j <= N; j++) {
				d[i][j] = INF;
			}
		}
		List<int[]> list = new ArrayList<int[]>();
		for(int i = 0; i < M; i++) {
			if(u[i] != 1) {
				d[u[i]][v[i]] = l[i];
				d[v[i]][u[i]] = l[i];
			}else {
				int[]p = {v[i], l[i]};
				list.add(p);
			}
		}
		warshallFloyd();
		int ans = INF;
		int len = list.size();
		for(int i = 0; i < len; i++) {
			for(int j = 0; j < len; j++) {
				if(i == j) continue;
				int t1 = list.get(i)[0];
				int t2 = list.get(j)[0];
				int c1 = list.get(i)[1];
				int c2 = list.get(j)[1];
				ans = Math.min(ans, d[0][t1] + d[t1][t2] + d[t2][0] + c1 + c2);
			}
		}
		if(ans == INF) {
			System.out.println(-1);
		}else {
			System.out.println(ans);
		}
	}
	static void warshallFloyd() {
		for(int k = 2; k <= N; k++) {
			for(int i = 2; i <= N; i++) {
				if(d[i][k] == INF) continue;
				for(int j = 2; j <= N; j++) {
					if(d[k][j] == INF) continue;
					d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
}