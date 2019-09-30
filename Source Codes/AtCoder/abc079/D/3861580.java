import java.util.*;
public class Main {
	static long dist[][];
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		int c[][] = new int[10][10];
		dist = new long[10][10];
		for(int i = 0; i < 10; i++) {
			Arrays.fill(dist[i], Integer.MAX_VALUE);
		}
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < 10; j++) {
				c[i][j] = sc.nextInt();
				dist[i][j] = c[i][j];
			}
		}
		int A[][] = new int[H][W];
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				A[i][j] = sc.nextInt();
			}
		}
		
		WarshallFloyd(10);
		
		int ans = 0;
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				if(A[i][j] != -1 && A[i][j] != 1) {
					ans += dist[A[i][j]][1];
				}
			}
		}
		
		System.out.println(ans);
	}
	
	static void WarshallFloyd(int N) {
		for(int k = 0; k < N; k++) {
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
}