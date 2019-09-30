import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int t = sc.nextInt();
		int[] dx = {1, -1, 0, 0};
		int[] dy = {0, 0, 1, -1};
		char[][] c = new char[h][w];
		for(int i = 0 ; i < h ; i++) c[i] = sc.next().toCharArray();
		int s = 0, g = 0;
		// h:2 w:3
		// 0 1 2
		// 3 4 5
		for(int i = 0 ; i < h ; i++) {
			for(int j = 0 ; j < w ; j++) {
				if(c[i][j] == 'S') s = i * w + j;
				if(c[i][j] == 'G') g = i * w + j;
			}
		}
		int l = 0, r = t;
		while(r - l > 1) {
			int mid = (l + r) / 2;
			long[][] gragh = new long[h * w][h * w];
			for(int i = 0 ; i < h * w ; i++) {
				for(int j = 0 ; j < h * w ; j++) {
					if(i == j) gragh[i][j] = 0;
					else gragh[i][j] = Long.MAX_VALUE / 10;
				}
			}
			for(int i = 0 ; i < h ; i++) {
				for(int j = 0 ; j < w ; j++) {
					for(int k = 0 ; k < 4 ; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if(0 <= nx && nx < h && 0 <= ny && ny < w) {
							if(c[nx][ny] == '#') gragh[i * w + j][nx * w + ny] = mid;
							else gragh[i * w + j][nx * w + ny] = 1;
						}
					}
				}
			}
			for(int k = 0 ; k < h * w ; k++) {
				for(int i = 0 ; i < h * w ; i++) {
					for(int j = 0 ; j < h * w ; j++) {
						gragh[i][j] = Math.min(gragh[i][j], gragh[i][k] + gragh[k][j]);
					}
				}
			}
			if(gragh[s][g] <= 1L * t) l = mid;
			else r = mid;
		}
		System.out.println(l);
	}
}