import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run();
	}
	int S = 3000, T = S * 4 + 1;
	boolean[][] map = new boolean[S * 4 + 1][S * 4 + 1];
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			//debug(o);
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt();
			for (int i = 0; i < S * 4 + 1; i++) fill(map[i], false);
			int x = S * 2, y = S * 2, dx = 1, dy = 0;
			for (int i = 0; i < n; i++) {
				char[] cs = sc.next().toCharArray();
				int m = sc.nextInt();
				for (int j = 0; j < m; j++) {
					for (char c : cs) {
						if (c == 'L') {
							int tx = dy * -1, ty = dx;
							dx = tx;
							dy = ty;
						} else if (c == 'R') {
							int tx = dy * 1, ty = -dx;
							dx = tx;
							dy = ty;
						} else {
							map[x][y] = map[x + dx][y + dy] = true;
							x += dx * 2;
							y += dy * 2;
						}
					}
				}
			}
			int res = 0;
			for (int i = 1; i < T; i += 2) {
				int last = -1;
				boolean in = false;
				for (int j = 0; j < T; j += 2) {
					if (map[i][j]) {
						if (in) {
							in = false;
							last = j;
						} else {
							in = true;
							if (last < 0) continue;
							for (int k = last + 1; k < j; k += 2) {
								if (!map[i][k]) res++;
								map[i][k] = true;
							}
						}
					}
				}
			}
			for (int j = 1; j < T; j += 2) {
				int last = -1;
				boolean in = false;
				for (int i = 0; i < T; i += 2) {
					if (map[i][j]) {
						if (in) {
							in = false;
							last = i;
						} else {
							in = true;
							if (last < 0) continue;
							for (int k = last + 1; k < i; k += 2) {
								if (!map[k][j]) res++;
								map[k][j] = true;
							}
						}
					}
				}
			}
			System.out.println(res);
		}
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
