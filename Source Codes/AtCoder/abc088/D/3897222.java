import java.util.*;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int[][] grid = new int[w][h];
		int wCount = 0;
		for (int i = 0; i < h; i++) {
			String s = sc.next();
			for (int j = 0; j < w; j++) {
				if (s.charAt(j) == '.') {
					grid[j][i] = -1;
					wCount++;
				} else {
					grid[j][i] = Integer.MIN_VALUE;
				}
			}
		}
		grid[0][0] = 0;
		for (int i = 0; i < wCount; i++) {
			for (int j = 0; j < w; j++) {
				for (int k = 0; k < h; k++) {
					if (grid[j][k] == i) {
						if (j != 0) {
							if (grid[j - 1][k] == -1) {
								grid[j - 1][k] = i + 1;
							}
						}
						if (j != w - 1) {
							if (grid[j + 1][k] == -1) {
								grid[j + 1][k] = i + 1;
							}
						}
						if (k != 0) {
							if (grid[j][k - 1] == -1) {
								grid[j][k - 1] = i + 1;
							}
						} 
						if (k != h - 1) {
							if (grid[j][k + 1] == -1) {
								grid[j][k + 1] = i + 1;
							}
						}
					}
				}
			}
			if (grid[w - 1][h - 1] != -1) {
				System.out.println(wCount - grid[w - 1][h - 1] - 1);
				return;
			}
		}
		System.out.println(-1);
	}
}