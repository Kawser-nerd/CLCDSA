import java.util.*;
import java.util.stream.*;

public class Main {
	static final int[] dy = {1, 0, -1, 0};
	static final int[] dx = {0, 1, 0, -1};
	static int h, w, t;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		h = in.nextInt();
		w = in.nextInt();
		t = in.nextInt();
		char[][] map = new char[h][w];
		int sy = 0, sx = 0, gy = 0, gx = 0;
		in.nextLine();
		for (int y = 0; y < h; y++) {
			map[y] = in.nextLine().toCharArray();
		}
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (map[y][x] == 'S') {
					sy = y;
					sx = x;
				}
				if (map[y][x] == 'G') {
					gy = y;
					gx = x;
				}
			}
		}
		long left = 0, right = Integer.MAX_VALUE;
		while (left < right) {
			long cost = (left + right) / 2;
			long score = getScore(map, cost, sy, sx, gy, gx);
			if (t < score) {
				right = cost;
			} else {
				left = cost + 1;
			}
		}
		if (t < getScore(map, (int) left, sy, sx, gy, gx)) {
			left--;
		}
		System.out.println(left);
	}

	public static long getScore(char[][] map, long cost, int sy, int sx, int gy, int gx) {
		Queue<Point> que = new PriorityQueue<>(Comparator.comparing(Point::getScore));
		long[][] score = new long[h][w];
		for(long[] arr : score) {
			Arrays.fill(arr, Integer.MAX_VALUE * 3);
		}
		score[sy][sx] = 0;
		que.add(new Point(sy, sx, 0));
		while(0 < que.size()) {
			Point p = que.poll();
			if(score[p.y][p.x] < p.score) {
				continue;
			}
			for (int k = 0; k < 4; k++) {
				int my = p.y + dy[k];
				int mx = p.x + dx[k];
				if(isOutPos(my, mx)) {
					continue;
				}
				long c = map[my][mx] == '#' ? cost : 1;
				if(score[p.y][p.x] + c < score[my][mx]) {
					score[my][mx] = score[p.y][p.x] + c;
					que.add(new Point(my, mx, score[my][mx]));
				}
			}
		}
		return score[gy][gx];
	}

	public static boolean isOutPos(int y, int x) {
		return y < 0 || h <= y || x < 0 || w <= x;
	}
}

class Point {
	int y, x;
	long score;

	public Point(int y, int x, long score) {
		this.y = y;
		this.x = x;
		this.score = score;
	}

	public long getScore() {
		return score;
	}
}