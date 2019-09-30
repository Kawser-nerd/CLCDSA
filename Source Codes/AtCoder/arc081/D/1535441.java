import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int[][] s = new int[h][w];
		for (int i = 0; i < h; ++i) {
			char[] S = new char[w];
			S = sc.next().toCharArray();
			for (int j = 0; j < w; ++j) {
				if (S[j] == '#') {
					s[i][j] = 1;
				}
			}
		}
		int[][] map = new int[h - 1][w - 1];
		for (int i = 0; i + 1 < h; ++i) {
			for (int j = 0; j + 1 < w; ++j) {
				if ((s[i][j] + s[i + 1][j] + s[i + 1][j + 1] + s[i][j + 1]) % 2 != 0) {
					++map[i][j];
				}
			}
		}
		int ans = solver(map);
		ans = Math.max(ans, h);
		ans = Math.max(ans, w);
		System.out.println(ans);
	}

	int solver(int[][] map) {
		int h = map.length;
		int w = map[0].length;
		int[][] cum = new int[2][w];
		int ans = 2;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				int c = map[i][j];// c==0?????
				if (c == 0) {
					cum[i % 2][j] = (i > 0 ? cum[(i - 1) % 2][j] : 0) + 1;
				} else {
					cum[i % 2][j] = 0;
				}
			}
			ans = Math.max(ans, calc(cum[i % 2], w));

		}
		return ans;
	}

	int calc(int[] cum, int w) {
		int ans = 2;
		ArrayDeque<List<Integer>> stack = new ArrayDeque<>();
		for (int j = 0; j < w; ++j) {
			ans = Math.max(ans, cum[j]);
			int d = j;
			while (!stack.isEmpty() && (cum[j] == 0 || stack.peekLast().get(0) > cum[j])) {
				List<Integer> pair = stack.pollLast();
				ans = Math.max(ans, (pair.get(0) + 1) * (j - pair.get(1) + 1));
				d = Math.min(d, pair.get(1));
			}
			if (cum[j] == 0)
				continue;
			stack.addLast(Arrays.asList(cum[j], d));
		}
		while (!stack.isEmpty()) {
			List<Integer> pair = stack.pollLast();
			ans = Math.max(ans, (pair.get(0) + 1) * (w - pair.get(1) + 1));
		}
		return ans;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}