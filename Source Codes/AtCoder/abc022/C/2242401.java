import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static int n,m;
	static long[][] graph;
	static long[] graph2;
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		n = sc.nextInt();m = sc.nextInt();
		graph = new long[n][n];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i==j) graph[i][j]=graph[j][i]=0;
				else graph[i][j]=graph[j][i]=10L*Integer.MAX_VALUE;
			}
		}
		for(int i = 0; i < m; i++) {
			int u = sc.nextInt()-1;
			int v = sc.nextInt()-1;
			long l = sc.nextLong();
			graph[u][v] = graph[v][u] = l;
		}
		graph2 = Arrays.copyOf(graph[0], n);
		for(int i = 0; i < n; i++) {
			graph[0][i] = graph[i][0] = 10L * Integer.MAX_VALUE;
		}
		long ans = 10L*Integer.MAX_VALUE;
		for (int k = 1; k < n; k++) {
			for(int i = 1; i < n; i++) {
				for(int j = 1; j < n; j++) {
					graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i!=j) {
					ans = Math.min(ans, graph2[i]+graph[i][j]+graph2[j]);
				}
			}
		}
		if(ans >= 10L*Integer.MAX_VALUE) {
			System.out.println(-1);
		} else {
			System.out.println(ans);
		}
	}
}