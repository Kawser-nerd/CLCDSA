import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		int c = sc.nextInt();
		int k = sc.nextInt();
		char[][] s = new char[r][c];
		for (int i = 0; i < r; i++) {
			String str = sc.next();
			s[i] = str.toCharArray();
		}
		sc.close();

		int[][] up = new int[r][c];
		for (int j = 0; j < c; j++) {
			int cnt = 0;
			for (int i = 0; i < r; i++) {
				if (s[i][j] == 'o') {
					cnt++;
					up[i][j] = cnt;
				} else {
					cnt = 0;
				}
			}
		}
		int[][] down = new int[r][c];
		for (int j = 0; j < c; j++) {
			int cnt = 0;
			for (int i = r - 1; i >= 0; i--) {
				if (s[i][j] == 'o') {
					cnt++;
					down[i][j] = cnt;
				} else {
					cnt = 0;
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				// ?
				int left = 0;
				for (int a = j; a >= 0; a--) {
					if (s[i][a] == 'x') {
						break;
					}
					if (up[i][a] < k - left) {
						break;
					}
					if (down[i][a] < k - left) {
						break;
					}
					left++;
					if (left == k) {
						break;
					}
				}
				// ?
				int right = 0;
				for (int a = j; a < c; a++) {
					if (s[i][a] == 'x') {
						break;
					}
					if (up[i][a] < k - right) {
						break;
					}
					if (down[i][a] < k - right) {
						break;
					}
					right++;
					if (right == k) {
						break;
					}
				}

				if (left == k && right == k) {
					ans++;
				}
			}
		}
		System.out.println(ans);
	}
}