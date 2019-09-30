import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		int Q = scanner.nextInt();
		int[] L = new int[M];
		int[] R = new int[M];
		for(int i = 0; i < M; i++){
			L[i] = scanner.nextInt();
			R[i] = scanner.nextInt();
		}
		int[][] count = new int[N+1][N+1];
		for(int i = 0; i < M; i++){
			count[L[i]][R[i]]++;
		}
		for(int i = 1; i <= N; i++){
			for(int j = 0; j <= N; j++){
				count[i][j] = count[i][j] + count[i-1][j];
			}
		}
		for(int i = 0; i <= N; i++){
			for(int j = 1; j <= N; j++){
				count[i][j] = count[i][j] + count[i][j-1];
			}
		}
		int[] p = new int[Q];
		int[] q = new int[Q];
		for(int i = 0; i < Q; i++){
			p[i] = scanner.nextInt();
			q[i] = scanner.nextInt();
			int ans = count[q[i]][q[i]]+count[p[i]-1][p[i]-1]-count[q[i]][p[i]-1]-count[p[i]-1][q[i]];
			System.out.println(ans);
		}

	}
}