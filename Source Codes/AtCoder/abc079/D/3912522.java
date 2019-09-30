import java.util.*;

public class Main {
	static int[][] c = new int[10][10];

	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				c[i][j] = sc.nextInt();
			}
		}
		int[] arr = new int[10];
		for (int i = 0; i < 10; i++) {
			if (i == 1) {
				continue;
			}
			int ceiling = c[i][1];
			for (int j = 0; j < 10; j++) {
				if (j == i || j == 1) {
					continue;
				}
				int ret = costCheck(j, c[i][j], ceiling);
				if (ret < ceiling) {
					ceiling = ret;
				}
			}
			arr[i] = ceiling;
		}
		int total = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int x = sc.nextInt();
				if (x != -1) {
					total += arr[x];
				}
			}
		}
		System.out.println(total);
	}
	
	public static int costCheck(int select, int cost, int ceiling) {
		int direct = c[select][1] + cost;
		for (int i = 0; i <= 9; i++) {
			if (i != 1 && i != select) {
				if (direct > c[select][i] + cost && cost + c[select][i] < ceiling) {
					int ret = costCheck(i, cost + c[select][i], ceiling);
					if (ret < direct) {
						direct = ret;
					}
				}
			}
		}
		if (direct < ceiling) {
			return direct;
		} else {
			return ceiling;
		}
	}
}