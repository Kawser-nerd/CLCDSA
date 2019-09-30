import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		int c = sc.nextInt();
		int kk = sc.nextInt();
		char[][] field = new char[r][c];
		for (int i = 0; i < r; i++) {
			field[i] = sc.next().toCharArray();
		}
		int[][] maxes = new int[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (field[i][j] == 'x') {
					maxes[i][j] = 0;
					continue;
				}
				int min = Integer.MAX_VALUE;
				int max = 1;
				for (int k = 1; j - k + 1 >= 0 && field[i][j - k + 1] == 'o'; k++) { // left
					if (max < k) {
						max = k;
					}
				}
				if (min > max) {
					min = max;
				}
				max = 1;
				for (int k = 1; j + k - 1 < c && field[i][j + k - 1] == 'o'; k++) { // right
					if (max < k) {
						max = k;
					}
				}
				if (min > max) {
					min = max;
				}
				max = 1;
				for (int k = 1; i - k + 1 >= 0 && field[i - k + 1][j] == 'o'; k++) { // up
					if (max < k) {
						max = k;
					}
				}
				if (min > max) {
					min = max;
				}
				max = 1;
				for (int k = 1; i + k - 1 < r && field[i + k - 1][j] == 'o'; k++) { // down
					if (max < k) {
						max = k;
					}
				}
				if (min > max) {
					min = max;
				}
				maxes[i][j] = min;
			}
		}
		int count = 0;
		for (int i = kk - 1; i < r - kk + 1; i++) {
			for (int j = kk - 1; j < c - kk + 1; j++) {
				boolean flag = true;
				for (int k = 0; k < kk; k++) {
					if (maxes[i + k][j] >= kk - k && maxes[i - k][j] >= kk - k && maxes[i][j + k] >= kk - k && maxes[i][j - k] >= kk - k) {
						
					} else {
						flag = false;
						break;
					}
				}
				if (flag) {
					count++;
				}
			}
		}
		System.out.println(count);
	}
}