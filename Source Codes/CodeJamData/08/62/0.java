import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run();
	}
	void run() {
		
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();		
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			n = sc.nextInt();
			m = sc.nextInt();
			si = sc.nextInt()-1;
			sj = sc.nextInt()-1;
			int[][] is = new int[m][n];
			for (int j = 0; j < m; j++) {
				for (int i = 0; i < n; i++) {
					is[j][i] = sc.nextInt();
				}
			}
			int res = dfs(is);
			if (res >= INF) System.out.println("forever");
			else System.out.printf("%d day(s)%n", res);
		}
	}
	int INF = 1 << 29;
	int m, n, si, sj;
	int dfs(int[][] is) {
		int[][] js = move(is);
		if (js[sj][si] == 0) return 0;
		int res = 0;
		for (int k = 0; k < 4; k++) {
			int i2 = si + di[k], j2 = sj + dj[k];
			if (i2 < 0 || i2 >= n || j2 < 0 || j2 >= m) continue;
			if (js[j2][i2] > 0) {
				res = max(res, 1 + dfs(change(js, i2, j2, is[sj][si])));
			}
		}
		if (res == 0) return INF;
		return res;
	}
	int[][] change(int[][] is, int i, int j, int v) {
		int[][] js = new int[m][n];
		for (int k = 0; k < m; k++) js[k] = is[k].clone();
		js[j][i] = max(0, js[j][i] - v);
		return js;
	}
	int[] di = {0, -1, 1, 0}, dj = {-1, 0, 0, 1};
	int[][] move(int[][] is) {
		int[][] js = new int[m][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				js[j][i] = is[j][i];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) if (i != si || j != sj) {
				int p = -1, max = 0;
				for (int k = 0; k < 4; k++) {
					int i2 = i + di[k], j2 = j + dj[k];
					if (i2 < 0 || i2 >= n || j2 < 0 || j2 >= m) continue;
					if (is[j2][i2] > max) {
						max = is[j2][i2];
						p = k;
					}
				}
				if (p >= 0) {
					int i2 = i + di[p], j2 = j + dj[p];
					js[j2][i2] = max(0, js[j2][i2] - is[j][i]);
				}
			}
		}
		return js;
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
