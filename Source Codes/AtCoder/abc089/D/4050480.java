import java.awt.Point;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int D = sc.nextInt();
		int[][] A = new int[H][W];
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				A[i][j] = sc.nextInt() - 1;
			}
		}
		int Q = sc.nextInt();
		int[] L = new int[Q];
		int[] R = new int[Q];
		for(int i = 0; i < Q; i++) {
			L[i] = sc.nextInt() - 1;
			R[i] = sc.nextInt() - 1;
		}
		sc.close();
		Point[] p = new Point[H * W];
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				p[A[i][j]] = new Point(j, i);
			}
		}
		int l = H * W / D + 1;
		int[][] dp = new int[D][l];
		for(int i = 0; i < D; i++) {
			for(int j = 0; j < l; j++) {
				int t = i + D * j;
				if(t + D >= H * W) break;
				Point v1 = p[t];
				Point v2 = p[t + D];
				dp[i][j + 1] = dp[i][j] + Math.abs(v1.x - v2.x) + Math.abs(v1.y - v2.y);
			}
		}
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < Q; i++) {
			int a = L[i];
			int b = R[i];
			int idx = a % D;
			int ans = dp[idx][b / D] - dp[idx][a / D];
			sb.append(ans).append("\n");
		}
		System.out.print(sb.toString());
	}
}