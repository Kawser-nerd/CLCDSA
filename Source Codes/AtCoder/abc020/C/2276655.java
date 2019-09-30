import java.util.Scanner;

public class Main {

	static int h, w, t, s, g;
	static char[][] c;
	static int[] dx = {0, 0, -1, 1};
	static int[] dy = {1, -1, 0, 0};

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		h = sc.nextInt();
		w = sc.nextInt();
		t = sc.nextInt();
		c = new char[100][100];
		for(int i = 0 ; i < h ; i++) {
			c[i] = sc.next().toCharArray();
		}
		for(int i = 0 ; i < h ; i++) {
			for(int j = 0 ; j < w ; j++) {
				if(c[i][j] == 'S') {
					s = i * w + j;
				}
			}
		}
		for(int i = 0 ; i < h ; i++) {
			for(int j = 0 ; j < w ; j++) {
				if(c[i][j] == 'G') {
					g = i * w + j;
				}
			}
		}
		long l = 0, r = t + 1;
		while(r - l > 1) {
			long mid = (l + r) / 2;
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
						int x = i + dx[k];
						int y = j + dy[k];
						if(0 <= x && x < h && 0 <= y && y < w) {
							gragh[i * w + j][x * w + y] = c[x][y] == '#' ? mid : 1;
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