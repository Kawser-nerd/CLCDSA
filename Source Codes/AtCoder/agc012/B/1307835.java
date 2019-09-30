import java.io.PrintWriter;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);

		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] a = new int[M];
		int[] b = new int[M];

		for(int i=0; i<M; i++) {
			a[i] = sc.nextInt()-1;
			b[i] = sc.nextInt()-1;
		}

		int MAXD = 10;
		int[][] dp = new int[N][MAXD+1];
		
		int Q = sc.nextInt();
		int[] c = new int[Q+1];
		for(int i=0; i<Q; i++) {
			int v = sc.nextInt()-1;
			int d = sc.nextInt();
			c[i+1] = sc.nextInt();
			dp[v][d] = Math.max(dp[v][d], i+1);
		}
		
		for(int i=MAXD; i>0; i--) {
			for(int j=0; j<M; j++) {
				dp[a[j]][i-1] = Math.max(dp[a[j]][i-1], dp[b[j]][i]);
				dp[b[j]][i-1] = Math.max(dp[b[j]][i-1], dp[a[j]][i]);
			}
			for(int j=0; j<N; j++) {
				dp[j][i-1] = Math.max(dp[j][i-1], dp[j][i]);
			}
		}
		
		for(int i=0; i<N; i++)
			pw.println(c[dp[i][0]]);
		
		sc.close();
		pw.close();
	}
}