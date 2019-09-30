import java.lang.reflect.Array;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// System.err.println(System.currentTimeMillis() - t);
	}

	int[] g(char cw, char cl, char[][] map) {
		int c0 = 0, c1 = 0;
		int[] di = { 1, 0, 1, 1 };
		int[] dj = { 0, 1, 1, -1 };
		for (int i = 0; i < 19; ++i) {
			for (int j = 0; j < 19; ++j) {
				if (map[i][j] == '.')
					continue;
				for (int k = 0; k < 4; ++k) {
					int d = 1;
					for (int ni = i + di[k], nj = j + dj[k]; d < 5 && ni < 19 && nj < 19 && ni >= 0 && nj >= 0; ++d) {
						if (map[ni][nj] != map[i][j])
							break;
						ni += di[k];
						nj += dj[k];
					}
					if (d == 5) {
						if (map[i][j] == cw)
							++c0;
						else if (map[i][j] == cl)
							++c1;
					}
				}
			}
		}
		return new int[] { c0, c1 };
	}

	boolean pend(char[][] map) {
		int[] a = g('o', 'x', map);
		return a[0] == 0 && a[1] == 0;
	}

	boolean win(char cw, char cl, char[][] map) {
		int[] a = g(cw, cl, map);
		return a[0] > 0 && a[1] == 0;
	}

	boolean check(char cw, char cl, char[][] map) {
		if (!win(cw, cl, map)) {
			return false;
		}

		for (int i = 0; i < 19; ++i) {
			for (int j = 0; j < 19; ++j) {
				if (map[i][j] == cw) {
					map[i][j] = '.';
					if (pend(map)) {
						return true;
					}
					map[i][j] = cw;
				}
			}
		}
		return false;
	}

	void solve(char[][] map) {
		int c0 = 0, c1 = 0;
		for (int i = 0; i < 19; ++i) {
			for (int j = 0; j < 19; ++j) {
				if (map[i][j] == 'o') {
					++c0;
				} else if (map[i][j] == 'x') {
					++c1;
				}
			}
		}
		// c0:??
		// c1:??
		if (c0 - c1 != 0 && c0 - c1 != 1) {
			System.out.println("NO");
			return;
		}
		boolean f;
		if (pend(map)) {
			f = true;
		} else if (c0 == c1 + 1) {
			f = check('o', 'x', map);
		} else if (c0 == c1) {
			f = check('x', 'o', map);
		} else {
			throw new AssertionError();
		}
		System.out.println(f ? "YES" : "NO");
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		char[][] map = new char[19][19];
		for (int i = 0; i < 19; ++i) {
			map[i] = sc.next().toCharArray();
		}
		solve(map);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}