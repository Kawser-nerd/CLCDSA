import java.util.Scanner;

public class Main {

	static int n, m;
	static int[] u, v, l;
	static long[][] gragh;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		u = new int[m];
		v = new int[m];
		l = new int[m];
		gragh = new long[n][n];
		for(int i = 0 ; i < m ; i++) {
			u[i] = sc.nextInt() - 1;
			v[i] = sc.nextInt() - 1;
			l[i] = sc.nextInt();
		}
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < n ; j++) {
				if(i == j) gragh[i][j] = 0;
				else gragh[i][j] = Long.MAX_VALUE / 10;
			}
		}
		for(int i = 0 ; i < m ; i++) gragh[u[i]][v[i]] = gragh[v[i]][u[i]] = l[i];
		for(int k = 1 ; k < n ; k++) {
			for(int i = 1 ; i < n ; i++) {
				for(int j = 1 ; j < n ; j++) {
					gragh[i][j] = Math.min(gragh[i][j], gragh[i][k] + gragh[k][j]);
				}
			}
		}
		long ans = Long.MAX_VALUE / 10;
		for(int i = 1 ; i < n ; i++) {
			for(int j = 1 ; j < n ; j++) {
				if(i != j) ans = Math.min(ans, gragh[0][i] + gragh[0][j] + gragh[i][j]);
			}
		}
		if(ans >= Long.MAX_VALUE / 10) System.out.println(-1);
		else System.out.println(ans);
	}
}