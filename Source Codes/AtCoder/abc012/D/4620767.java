import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] dist = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(dist[i], Integer.MAX_VALUE / 3);
			dist[i][i] = 0;
		}
		int m = sc.nextInt();
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int t = sc.nextInt();
			dist[a - 1][b - 1] = t;
			dist[b - 1][a - 1] = t;
		}
		
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
					dist[j][i] = dist[i][j];
				}
			}
		}
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < n; i ++) {
			int max = 0;
			for (int j = 0; j < n; j++) {
				if (max < dist[i][j]) {
					max = dist[i][j];
				}
			}
			if (min > max) {
				min = max;
			}
		}
		System.out.println(min);
	}
}