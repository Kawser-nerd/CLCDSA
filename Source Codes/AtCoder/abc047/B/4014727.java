import java.util.*;

public class Main {
	
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int w = sc.nextInt();
		int h = sc.nextInt();
		int n = sc.nextInt();
		boolean[][] fields = new boolean[h][w];
		for (int v = 0; v < n; v++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			int a = sc.nextInt();
			switch (a) {
				case 1:
				for (int i = 0; i < x; i++) {
					for (int j = 0; j < h; j++) {
						fields[j][i] = true;
					}
				}
				break;
				case 2:
				for (int i = x; i < w; i++) {
					for (int j = 0; j < h; j++) {
						fields[j][i] = true;
					}
				}
				break;
				case 3:
				for (int i = 0; i < w; i++) {
					for (int j = 0; j < y; j++) {
						fields[j][i] = true;
					}
				}
				break;
				case 4:
				for (int i = 0; i < w; i++) {
					for (int j = y; j < h; j++) {
						fields[j][i] = true;
					}
				}
				break;
			}
		}
		int cnt = 0;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (!fields[j][i]) {
					cnt++;
				}
			}
		}
		System.out.println(cnt);
	}
}