import java.io.*;
import java.util.*;

public class Main {
	static int sx = -1, sy = -1;
	static int gx = -1, gy = -1;

	public static void main(String[] args) throws java.io.IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String[] ia = in.readLine().split(" ");
		final int N = Integer.parseInt(ia[0]);

		char[][] map = new char[N][];
		for (int i = 0; i < N; ++i) {
			map[i] = in.readLine().toCharArray();
		}
		in.close();

		if (!hasRoute(map)) {
			System.out.println(-1);
			return;
		}

		double r = 10.0, l = 0.0;
		while (r - l > 1e-9) {
			double mid = (l + r) / 2.0;
			if (solve(map, mid)) {
				l = mid;
			} else {
				r = mid;
			}
			System.gc();
		}

		System.out.println(String.format("%.9f", l));
	}

	private static boolean hasRoute(char[][] map) {
		int[][] cost = new int[map.length][map[0].length];
		for (int i = 0; i < cost.length; ++i) {
			for (int j = 0; j < cost[i].length; ++j) {
				cost[i][j] = Integer.MAX_VALUE;
				if (map[i][j] == 's') {
					sx = j;
					sy = i;
					cost[i][j] = 0;
				} else if (map[i][j] == 'g') {
					gx = j;
					gy = i;
				}
			}
		}

		ArrayDeque<Integer> ad = new ArrayDeque<>();
		ad.add((sy << 16) + sx);
		int[][] diff = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		while (!ad.isEmpty()) {
			int x = ad.removeFirst();
			int y = x >> 16;
			x %= 1 << 16;
			for (int d = 0; d < diff.length; ++d) {
				int x_new = x + diff[d][0];
				int y_new = y + diff[d][1];
				if (0 <= x_new && x_new < map[0].length && 0 <= y_new && y_new < map.length && cost[y][x] + 1 < cost[y_new][x_new]) {
					if (map[y_new][x_new] == '#') {
						continue;
					} else if (map[y_new][x_new] == 'g') {
						return true;
					}
					if (cost[y_new][x_new] == Integer.MAX_VALUE) {
						cost[y_new][x_new] = cost[y][x] + 1;
						ad.addLast((y_new << 16) + x_new);
					}
				}
			}
		}

		return false;
	}

	private static boolean solve(char[][] map, double lim) {
		int[][] cost = new int[map.length][map[0].length];
		for (int i = 0; i < cost.length; ++i) {
			Arrays.fill(cost[i], Integer.MAX_VALUE);
		}
		cost[sy][sx] = 0;
		ArrayDeque<Integer> ad = new ArrayDeque<>();
		ad.add((sy << 16) + sx);
		int[][] diff = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		while (!ad.isEmpty()) {
			int x = ad.removeFirst();
			int y = x >> 16;
			x %= 1 << 16;
			int t = cost[y][x];
			for (int d = 0; d < diff.length; ++d) {
				int x_new = x + diff[d][0];
				int y_new = y + diff[d][1];
				if (!(0 <= x_new && x_new < map[0].length && 0 <= y_new && y_new < map.length)) {
					continue;
				}
				if (map[y_new][x_new] == '#') {
					continue;
				}
				if (cost[y_new][x_new] != Integer.MAX_VALUE) {
					continue;
				}
				if (y_new == gy && x_new == gx) {
					return true;
				}
				double new_ans;
				new_ans = Math.pow(0.99, t + 1) * (map[y_new][x_new] - '0');
				if (lim < new_ans) {
					ad.addLast((y_new << 16) + x_new);
					cost[y_new][x_new] = t + 1;
				} else {
					cost[y_new][x_new] = Integer.MAX_VALUE - 1;
				}
			}
		}
		return false;
	}

}