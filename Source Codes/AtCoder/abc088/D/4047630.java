import java.awt.Point;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		char[][] c = new char[H][W];
		for(int i = 0; i < H; i++) {
			String s = sc.next();
			for(int j = 0; j < W; j++) {
				c[i][j] = s.charAt(j);
			}
		}
		sc.close();
		int sum = 0;
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				if(c[i][j] == '.') {
					sum++;
				}
			}
		}
		Queue<Point> queue = new ArrayDeque<Point>();
		queue.add(new Point(0, 0));
		int[] dx = {1, -1, 0, 0};
		int[] dy = {0, 0, 1, -1};
		int[][] d = new int[H][W];
		boolean[][] vis = new boolean[H][W];
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				if(c[i][j] == '.') {
					vis[i][j] = true;
				}else {
					vis[i][j] = false;
				}
			}
		}
		vis[0][0] = false;
		loop: while(!queue.isEmpty()) {
			Point p = queue.poll();
			for(int i = 0; i < 4; i++) {
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				if(nx >= 0 && nx < W && ny >= 0 && ny < H) {
					if(vis[ny][nx]) {
						d[ny][nx] = d[p.y][p.x] + 1;
						queue.add(new Point(nx, ny));
						vis[ny][nx] = false;
						if(ny == H - 1 && nx == W - 1) {
							break loop;
						}
					}
				}
			}
		}
		int ans = sum - d[H - 1][W - 1] - 1;
		if(d[H - 1][W - 1] == 0) {
			ans = -1;
		}
		System.out.println(ans);
	}
}