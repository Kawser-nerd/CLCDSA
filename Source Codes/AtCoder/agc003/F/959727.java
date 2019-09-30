import java.util.*;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		solver();
	}

	final long MODULO = 1_000_000_000 + 7;

	void solver() {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		long K = sc.nextLong();
		char[][] map = new char[H][W];
		for (int i = 0; i < H; ++i) {
			map[i] = sc.next().toCharArray();
		}

		int a = 0;// ??????
		int b = 0;// ?????????????????
		int c = 0;// ??????

		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (map[i][j] == '#')
					++a;
			}
		}

		for (int i = 0; i < H; ++i) {
			if (map[i][0] == map[i][W - 1] && map[i][0] == '#')
				++c;
		}

		int d = 0;
		for (int i = 0; i < W; ++i) {
			if (map[0][i] == map[H - 1][i] && map[0][i] == '#')
				++d;
		}

		if (c > 0 && d > 0) {
			System.out.println(1);
			return;
		} else if (c == 0 && d == 0) {
			long[][] mx = new long[][] { { a } };
			mx = pow(mx, K - 1);
			System.out.println(mx[0][0]);
			return;
		}

		if (d > 0) {
			map = rev(map);
			c = d;
			d = 0;
			int tmp = H;
			H = W;
			W = tmp;
		}

		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W - 1; ++j) {
				if (map[i][j] == map[i][j + 1] && map[i][j] == '#') {
					++b;
				}
			}
		}

		long[][] mx = new long[][] { { a, -b }, { 0, c } };
		long[][] v = new long[][] { { 1 }, { 1 } };
		mx = pow(mx, K - 1);
		v = mul(mx, v);
		System.out.println(v[0][0]);

	}

	long[][] mul(long[][] a, long[][] b) {
		long[][] ret = new long[a.length][b[0].length];

		for (int i = 0; i < b[0].length; ++i) {
			for (int j = 0; j < a.length; ++j) {
				for (int k = 0; k < a[0].length; ++k) {
					ret[j][i] += a[j][k] * b[k][i] % MODULO;
					ret[j][i] = (ret[j][i] + MODULO) % MODULO;
				}

			}
		}
		return ret;
	}

	long[][] pow(long[][] a, long n) {
		int len = a.length;
		long[][] ret = new long[len][len];
		for (int i = 0; i < len; ++i) {
			ret[i][i] = 1;
		}
		for (; n > 0; n >>= 1, a = mul(a, a)) {
			if (n % 2 == 1)
				ret = mul(a, ret);
		}
		return ret;
	}

	char[][] rev(char[][] map) {
		char[][] ret = new char[map[0].length][map.length];
		for (int i = 0; i < map.length; ++i) {
			for (int j = 0; j < map[0].length; ++j) {
				ret[j][i] = map[i][j];
			}
		}
		return ret;
	}

	void showMap(char[][] map) {
		int H = map.length;
		int W = map[0].length;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}
	}

	void tr(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
}