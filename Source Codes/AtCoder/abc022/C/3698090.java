import java.util.*;

public class Main {
	static long dist[][];
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int u[] = new int[M];
		int v[] = new int[M];
		int l[] = new int[M];
		dist = new long[N][N];
		for(int i = 0; i < N; i++) {
			Arrays.fill(dist[i], Integer.MAX_VALUE);
		}
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i = 0; i < M; i++) {
			u[i] = sc.nextInt() - 1;
			v[i] = sc.nextInt() - 1;
			l[i] = sc.nextInt();
			dist[u[i]][v[i]] = l[i];
			dist[v[i]][u[i]] = l[i];
			if(u[i] == 0) list.add(v[i]);
			if(v[i] == 0) list.add(u[i]);
		}
		
		WarshallFloyd(N);
		
		long min = Integer.MAX_VALUE;
		for(int i = 0; i < list.size(); i++) {
			for(int j = 0; j < list.size(); j++) {
				if(list.get(i) == list.get(j)) continue;
				min = Math.min(min, dist[0][list.get(i)] + dist[list.get(i)][list.get(j)] + dist[list.get(j)][0]);
			}
		}
		System.out.println(min == Integer.MAX_VALUE ? -1 : min);
	}
	
	static void WarshallFloyd(int N) {
		for(int k = 1; k < N; k++) {
			for(int i = 1; i < N; i++) {
				for(int j = 1; j < N; j++) {
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
}