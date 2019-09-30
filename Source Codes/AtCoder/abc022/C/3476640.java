import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n=scanner.nextInt();
		int m=scanner.nextInt();
		dist = new long[n+1][n+1];
		for(long[] d: dist){
			Arrays.fill(d, Integer.MAX_VALUE);
		}
		List<Integer>list=new ArrayList<>();
		for(int i=0;i<m;i++) {
			int u=scanner.nextInt();
			int v=scanner.nextInt();
			int l=scanner.nextInt();
			dist[u][v]=l;
			dist[v][u]=l;
			if(u==1)list.add(v);
			if(v==1)list.add(u);
		}
		warshallFloyd(n);
		long min=Integer.MAX_VALUE;
		for(int a:list) {
			for(int b:list) {
				if(a==b)continue;
				min=Math.min(min, dist[a][b]+dist[1][a]+dist[1][b]);
			}
		}
		System.out.println(min==Integer.MAX_VALUE?-1:min);
	}
	
	static long[][] dist;
	static void warshallFloyd(int n) {
		for (int k = 2; k <= n; k++) {
			for (int i = 2; i <= n; i++) {
				for (int j = 2; j <= n; j++) {
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
}