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
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt();
			boolean[][] g = new boolean[n][n];
			for (int i = 0; i < n-1; i++) {
				int v = sc.nextInt() - 1, u = sc.nextInt() - 1;
				g[v][u] = g[u][v] = true;
			}
			int m = sc.nextInt();
			boolean[][] f = new boolean[m][m];
			for (int i = 0; i < m-1; i++) {
				int v = sc.nextInt() - 1, u = sc.nextInt() - 1;
				f[v][u] = f[u][v] = true;
			}
			int[] id = new int[n];
			for (int i = 0; i < n; i++) id[i] = i;
			boolean ok = false;
			do {
				boolean tmp = true;
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < m; j++) {
						tmp &= g[id[i]][id[j]] == f[i][j];
					}
				}
				ok |= tmp;
			} while (nextPermutation(id));
			if (ok) System.out.println("YES");
			else System.out.println("NO");
		}
	}
	boolean nextPermutation(int[] is) {
		int n = is.length;
		for (int i = n - 1; i > 0; i--) {
			if (is[i - 1] < is[i]) {
				int j = n;
				while (is[i - 1] >= is[--j]);
				swap(is, i - 1, j);
				rev(is, i, n);
				return true;
			}
		}
		rev(is, 0, n);
		return false;
	}
	void swap(int[] is, int i, int j) {
		int t = is[i]; is[i] = is[j]; is[j] = t;
	}
	void rev(int[] is, int s, int t) {
		while (s < --t) swap(is, s++, t);
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
