import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] f = new int[n][10];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				f[i][j] = sc.nextInt();
			}
		}
		int[][] p = new int[n][11];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 11; j++) {
				p[i][j] = sc.nextInt();
			}
		}
		sc.close();

		int ans = Integer.MIN_VALUE;
		for (int k = 1; k < 1024; k++) {
			String str = Integer.toBinaryString(k);
			StringBuilder sb = new StringBuilder(str);
			while (sb.length() < 10) {
				sb.insert(0, '0');
			}
			int sum = 0;
			for (int i = 0; i < n; i++) {
				int cnt = 0;
				for (int j = 0; j < 10; j++) {
					int flg = sb.charAt(j) - '0';
					if (flg == 1 && flg == f[i][j]) {
						cnt++;
					}
				}
				sum += p[i][cnt];
			}
			ans = Math.max(ans, sum);
		}
		System.out.println(ans);
	}
}