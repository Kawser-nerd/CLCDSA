import java.util.Scanner;

public class Main {

	private static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int w = sc.nextInt(), h = sc.nextInt(), n = sc.nextInt();
		boolean[][] sq = new boolean[h][w];
		for (int i = 0; i < n; i++) {
			int x = sc.nextInt(), y = sc.nextInt(), a = sc.nextInt();
			switch (a) {
				case 1:
					for (int j = 0; j < h; j++) {
						for (int k = 0; k < x; k++) {
							sq[j][k] = true;
						}
					}
					break;
				case 2:
					for (int j = 0; j < h; j++) {
						for (int k = x; k < w; k++) {
							sq[j][k] = true;
						}
					}
					break;
				case 3:
					for (int j = 0; j < y; j++) {
						for (int k = 0; k < w; k++) {
							sq[j][k] = true;
						}
					}
					break;
				case 4:
					for (int j = y; j < h; j++) {
						for (int k = 0; k < w; k++) {
							sq[j][k] = true;
						}
					}
					break;
			}
		}
		int ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!sq[i][j]) {
					ans++;
				}
			}
		}
		System.out.println(ans);
	}
}