import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[][] F = new int[N][10];
		int[][] P = new int[N][11];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 10; j++) {
				F[i][j] = sc.nextInt();
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 11; j++) {
				P[i][j] = sc.nextInt();
			}
		}
		long ans = -1000000000;
		for (int i = 1; i < (1 << 10); i++) {
			long bene = 0;
			for (int j = 0; j < N; j++) {
				int cnt = 0;
				for (int k = 0; k < 10; k++) {
					if ((i >> k & 1) == 1 && F[j][k] == 1)
						cnt++;
				}
				bene += P[j][cnt];
			}
			ans = Math.max(ans, bene);
		}
		System.out.println(ans);
	}
}