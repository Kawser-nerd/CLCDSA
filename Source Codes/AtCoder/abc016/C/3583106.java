import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int friend[][] = new int[N][N];
		int A[] = new int[M];
		int B[] = new int[M];
		for(int i = 0; i < M; i++) {
			A[i] = sc.nextInt() - 1;
			B[i] = sc.nextInt() - 1;
			friend[A[i]][B[i]] = 1;
			friend[B[i]][A[i]] = 1;
		}
		
		for(int i = 0; i < N; i++) {
			int cnt[] = new int[N];
			for(int j = 0; j < N; j++) {
				if(i == j) continue;
				if(friend[i][j] == 1) {
					for(int k = 0; k < N; k++) {
						if(i == k || j == k) continue;
						if(friend[j][k] == 1) {
							cnt[k] = 1;
						}
					}
				}
			}
			int ans = 0;
			for(int j = 0; j < N; j++) {
				if(friend[i][j] == 1) {
					//System.out.println("test" + i + j);
					cnt[j] = 0;
				}
				if(cnt[j] == 1) {
					ans++;
				}
			}
			System.out.println(ans);
		}
	}
}