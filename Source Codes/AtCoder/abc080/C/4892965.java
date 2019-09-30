import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[][] F = new int[N][10];
		int[][] P = new int[N][11];
		int ans = Integer.MIN_VALUE;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < 10; j++)
				F[i][j] = sc.nextInt();
		}
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < 11; j++)
				P[i][j] = sc.nextInt();
		}
		for(int i = 1; i < 1 << 10; i++) {
			int sum = 0;
			for(int j = 0; j < N; j++) {
				int count = 0;
				for(int k = 0; k < 10; k++) {
					if((1 & (i >> k)) >= 1 && F[j][k] == 1)
						count++;
				}
				sum += P[j][count];
			}
			ans = Math.max(ans, sum);
		}
		System.out.println(ans);
	}

}