import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int C = sc.nextInt();
		int[][]D = new int[C][C];
		int[][]c = new int[N][N];
		for(int i = 0; i < C; i++) {
			for(int j = 0; j < C; j++) {
				D[i][j] = sc.nextInt();
			}
		}
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				c[i][j] = sc.nextInt() - 1;
			}
		}
		sc.close();
		int[][] g = new int[C][3];
		for(int i = 0; i < C; i++) {
			for(int j = 0; j < N; j++) {
				for(int k = 0; k < N; k++) {
					if(c[j][k] != i) {
						g[i][(j + k) % 3] += D[c[j][k]][i];
					}
				}
			}
		}
		int min = Integer.MAX_VALUE;
		for(int i = 0; i < C; i++) {
			for(int j = 0; j < C; j++) {
				for(int k = 0; k < C; k++) {
					if(i == j || i == k || j == k) continue;
					min = Math.min(min, g[i][0] + g[j][1] + g[k][2]);
				}
			}
		}
		System.out.println(min);
	}
}