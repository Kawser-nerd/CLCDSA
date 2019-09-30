import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class D {
	public static void main(String[] args) {
		new D().run();
	}
	
	int INF = 1 << 29;
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt(), m = sc.nextInt();
			char[][] map = new char[n][];
			for (int i = 0; i < n; i++) {
				map[i] = sc.next().toCharArray();
			}
			int[][] min1 = bfs(map, 0, 0);
			int[][] min2 = new int[n][m];
			for (int i = 0; i < n; i++) fill(min2[i], INF);
			int d = -1;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (i > 0 || j > 0) {
						if (map[i][j] == 'T') {
							min2 = bfs(map, i, j);
							d = min1[i][j];
						}
					}
				}
			}
			int res = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) if (map[i][j] != '.') {
					res += min(min1[i][j], min2[i][j]);
				}
			}
			if (d > 0) {
				res += d;
				for (int i = 1; i < d; i++) res += i - min(i, d - i);
			}
			System.out.println(res);
		}
	}
	int[] lx = {-1, 0, 0, 1}, ly = {0, -1, 1, 0};
	int[][] bfs(char[][] cs, int x, int y) {
		int n = cs.length, m = cs[0].length;
		int[][] min = new int[n][m];
		for (int i = 0; i < n; i++) fill(min[i], INF);
		Queue<Integer> qx = new LinkedList<Integer>(), qy = new LinkedList<Integer>();
		qx.offer(x); qy.offer(y);
		min[x][y] = 0;
		while (!qx.isEmpty()) {
			x = qx.poll(); y = qy.poll();
			for (int i = 0; i < lx.length; i++) {
				int nx = x + lx[i], ny = y + ly[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && cs[nx][ny] != '.' && min[x][y] + 1 < min[nx][ny]) {
					min[nx][ny] = min[x][y] + 1;
					qx.offer(nx); qy.offer(ny);
				}
			}
		}
		return min;
	}
	void debug(Object... os) {
		System.err.println(deepToString(os));
	}
}
