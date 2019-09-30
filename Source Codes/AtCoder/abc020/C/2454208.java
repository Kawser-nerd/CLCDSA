import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static class Pair {
		int x, y;
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static int x, y, t, sx, sy, gx, gy;
	static char[][] c;
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	static long[][] graph;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		x = sc.nextInt();
		y = sc.nextInt();
		t = sc.nextInt();
		c = new char[x][y];
		graph = new long[x][y];
		for(int i = 0 ; i < x ; i++) c[i] = sc.next().toCharArray();
		for(int i = 0 ; i < x ; i++) {
			for(int j = 0 ; j < y ; j++) {
				if(c[i][j] == 'S') {
					sx = i;
					sy = j;
				}
				if(c[i][j] == 'G') {
					gx = i;
					gy = j;
				}
			}
		}
		graph[sx][sy] = 0;
		int l = 0, r = t;
		while(r - l > 1) {
			int mid = (l + r) / 2;
			for(int i = 0 ; i < x ; i++) {
				for(int j = 0 ; j < y ; j++) {
					graph[i][j] = Long.MAX_VALUE;
				}
			}
			graph[sx][sy] = 0;
			Queue<Pair> q = new LinkedList<>();
			q.add(new Pair(sx, sy));
			while(!q.isEmpty()) {
				Pair p = q.poll();
				for(int i = 0 ; i < 4 ; i++) {
					int nx = p.x + dx[i];
					int ny = p.y + dy[i];
					if(0 <= nx && nx < x && 0 <= ny && ny < y) {
						if(c[nx][ny] == '.' || c[nx][ny] == 'G') {
							if(graph[nx][ny] > graph[p.x][p.y] + 1) {
								graph[nx][ny] = graph[p.x][p.y] + 1;
								q.add(new Pair(nx, ny));
							}
						} else {
							if(graph[nx][ny] > graph[p.x][p.y] + mid) {
								graph[nx][ny] = graph[p.x][p.y] + mid;
								q.add(new Pair(nx, ny));
							}
						}
					}
				}
			}
			if(graph[gx][gy] <= t) l = mid;
			else r = mid;
		}
		System.out.println(l);
	}

}