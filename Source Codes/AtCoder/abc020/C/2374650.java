import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static int h, w, t, sx, sy, gx, gy;
	static int[] dx, dy;
	static String[][] s;
	static long[][] gragh;

	static class Pair {
		int x, y;
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		h = sc.nextInt();
		w = sc.nextInt();
		t = sc.nextInt();
		dx = new int[]{1, -1, 0, 0};
		dy = new int[]{0, 0, 1, -1};
		s = new String[h][w];
		gragh = new long[h][w];
		for(int i = 0 ; i < h ; i++) {
			String temp = sc.next();
			for(int j = 0 ; j < w ; j++) {
				s[i][j] = String.valueOf(temp.charAt(j));
			}
		}
		for(int i = 0 ; i < h ; i++) {
			for(int j = 0 ; j < w ; j++) {
				gragh[i][j] = Integer.MAX_VALUE;
				if(s[i][j].equals("S")) {
					gragh[i][j] = 0;
					sx = i;
					sy = j;
				} else if(s[i][j].equals("G")) {
					gx = i;
					gy = j;
				}
			}
		}
		int l = 0;
		int r = t;
		while(r - l > 1) {
			int mid = (l + r) / 2;
			if(bfs(mid) <= t) l = mid;
			else r = mid;
		}
		System.out.println(l);
	}

	static long bfs(int mid) {
		for(int i = 0 ; i < h ; i++) {
			for(int j = 0 ; j < w ; j++) {
				gragh[i][j] = Integer.MAX_VALUE;
				if(s[i][j].equals("S")) {
					gragh[i][j] = 0;
				}
			}
		}
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(sx, sy));
		while(!q.isEmpty()) {
			Pair p = q.poll();
			for(int j = 0 ; j < 4 ; j++) {
				int nx = p.x + dx[j];
				int ny = p.y + dy[j];
				if(0 <= nx && nx < h && 0 <= ny && ny < w) {
					if(s[nx][ny].equals(".") || s[nx][ny].equals("G")) {
						if(gragh[nx][ny] > gragh[p.x][p.y] + 1) {
							gragh[nx][ny] = gragh[p.x][p.y] + 1;
							q.add(new Pair(nx, ny));
						}
					} else if(s[nx][ny].equals("#")) {
						if(gragh[nx][ny] > gragh[p.x][p.y] + mid) {
							gragh[nx][ny] = gragh[p.x][p.y] + mid;
							q.add(new Pair(nx, ny));
						}
					}
				}
			}
		}
		return gragh[gx][gy];
	}

}