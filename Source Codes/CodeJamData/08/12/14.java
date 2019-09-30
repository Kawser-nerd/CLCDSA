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
			int n = sc.nextInt(), m = sc.nextInt();
			int[] num = new int[m];
			int[][] is = new int[m][n];
			for (int i = 0; i < m; i++) {
				int t = sc.nextInt();
				num[i] = 0;
				while (t-- > 0) {
					int x = sc.nextInt() - 1, y = sc.nextInt();
					is[i][x] = y + 1;
					if (y == 0) num[i]++;
				}
			}
			boolean ok = true;
			boolean damepo = false;
			int[] res = new int[n];
			boolean[] used = new boolean[m];
			while (ok) {
				ok = false;
				for (int i = 0; i < m; i++) if (!used[i]) {
					if (num[i] > 0) continue;
					if (num[i] < 0) {
						damepo = true;
						break;
					}
					int k = -1;
					for (int j = 0; j < n; j++) if (is[i][j] == 2) k = j;
					if (k < 0) {
						damepo = true;
					} else {
						res[k] = 1;
						for (int j = 0; j < m; j++) {
							if (is[j][k] == 1) {
								is[j][k] = 0;
								num[j]--;
							} else if (is[j][k] == 2) {
								is[j][k] = 0;
								used[j] = true;
							}
						}
						ok = true;
					}
					break;
				}
				if (!ok && !damepo) {
					for (int i = 0; i < m; i++) if (!used[i]) {
						boolean b = false;
						for (int j = 0; j < n && !b; j++) {
							b |= is[i][j] - 1 == res[j];
						}
						if (!b) {
							int k = -1;
							for (int j = 0; j < n; j++) if (is[i][j] == 2) k = j;
							if (k < 0) {
								damepo = true;
							} else {
								res[k] = 1;
								for (int j = 0; j < m; j++) {
									if (is[j][k] == 1) {
										is[j][k] = 0;
										num[j]--;
									} else if (is[j][k] == 2) {
										is[j][k] = 0;
										used[j] = true;
									}
								}
								ok = true;
							}
							break;
						}
					}
				}
			}
			if (damepo) System.out.println("IMPOSSIBLE");
			else {
				for (int i = 0; i < n; i++) {
					if (i > 0) System.out.print(" ");
					System.out.print(res[i]);
				}
				System.out.println();
			}
		}
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
