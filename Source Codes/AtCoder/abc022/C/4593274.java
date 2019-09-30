import java.util.*;

public class Main {
	
	final static long INF = Integer.MAX_VALUE;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        
        long[][] v = new long[N][N];
        for (int i = 0; i < N; i++) {
        	for (int j = 0; j < N; j++) {
        		if (i != j) {
        			v[i][j] = INF;
        		}
        	}
        }
        
        for (int i = 0; i < M; i++) {
        	int u1 = sc.nextInt() - 1;
        	int u2 = sc.nextInt() - 1;
        	int l = sc.nextInt();
        	
        	v[u1][u2] = l;
        	v[u2][u1] = l;
        }
        
        for (int k = 1; k < N; k++) {
        	for (int i = 1; i < N; i++) {
        		for (int j = 1; j < N; j++) {
        			v[i][j] = Math.min(v[i][j], v[i][k] + v[k][j]);
        		}
        	}
        }
        
        long ans = INF;
        for (int i = 1; i < N; i++) {
        	for (int j = 1; j < N; j++) {
        		
        		if (i == j) {
        			continue;
        		}
        		
        		long sum = v[i][j] + v[0][i] + v[0][j];
        		ans = Math.min(ans, sum);
        	}
        }
        
        System.out.println(ans < INF ? ans : -1);
    }
}