import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[][] adj = new int[N][N];
        for(int i=0; i<N; ++i) for(int j=0; j<N; ++j)
            adj[i][j] = 1<<28;
        for(int i=0; i<M; ++i) {
            int u = sc.nextInt()-1;
            int v = sc.nextInt()-1;
            int w = sc.nextInt();
            adj[u][v] = adj[v][u] = w;
        }
        for(int k=1; k<N; ++k) {
            for(int i=1; i<N; ++i) {
                for(int j=1; j<N; ++j) {
                    if(adj[i][j] > adj[i][k] + adj[k][j]) {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
        
        int minD = 1<<28;
        for(int i=1; i<N; ++i) {
            for(int j=i+1; j<N; ++j) {
                if(adj[0][i]==1<<28 || adj[0][j]==1<<28) continue;
                minD = Math.min(minD, adj[0][i]+adj[0][j]+adj[i][j]);
            }
        }
        if(minD == 1<<28) {
            System.out.println(-1);
        }
        else {
            System.out.println(minD);
        }
    }
}