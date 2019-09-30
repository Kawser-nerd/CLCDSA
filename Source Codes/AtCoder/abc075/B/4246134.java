import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int h = sc.nextInt();
		int w = sc.nextInt();

		int[][] ans = new int[h][w];
		for (int i = 0; i < h; i++) {
			String s = sc.next();
			for (int j = 0; j < w; j++) {
				if (s.charAt(j) != '#') {
					continue;
				}
				ans[i][j] = -99;
				for (int k = i - 1; k <= i + 1; k++) {
					if (k < 0 || h <= k) {
						continue;
					}
					for (int l = j - 1; l <= j + 1; l++) {
						if (l < 0 || w <= l || (k == i && l == j)) {
							continue;
						}
						ans[k][l]++;
					}
				}
			}
		}

		for (int[] arr : ans) {
			for (int n : arr) {
				System.out.print(n < 0 ? "#" : n);
			}
			System.out.println();
		}

		sc.close();
	}
}