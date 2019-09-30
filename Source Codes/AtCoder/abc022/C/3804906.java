import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[][] adj = new int[N][N];
        for(int i=0; i<N; ++i) for(int j=0; j<N; ++j)
            adj[i][j] = 1<<30;
        for(int i=0; i<M; ++i) {
            int u = sc.nextInt()-1;
            int v = sc.nextInt()-1;
            int w = sc.nextInt();
            adj[u][v] = adj[v][u] = w;
        }
        int minD = 1<<30;
        for(int s=0; s<N; ++s) {
            if(adj[s][0] == 1<<30) continue;
            int[] dist = new int[N];
            Arrays.fill(dist, 1<<30);
            boolean[] visited = new boolean[N];
            dist[s] = adj[0][s];
            adj[0][s] = 1<<30;
            adj[s][0] = 1<<30;
            
            while(true) {
                int minC = 1<<30;
                int u = -1;
                for(int n=0; n<N; ++n) {
                    if (!visited[n] && dist[n] < minC) {
                        minC = dist[n];
                        u = n;
                    }
                }
                if(u == -1) break;
                visited[u] = true;
                for(int v=0; v<N; ++v) {
                    if(dist[u] + adj[u][v] < dist[v]) {
                        dist[v] = dist[u] + adj[u][v];
                    }
                }
            }
            minD = Math.min(minD, dist[0]);
            adj[0][s] = dist[s];
            adj[s][0] = dist[s];
        }
        if(minD == 1<<30) {
            System.out.println(-1);
        }
        else {
            System.out.println(minD);
        }
    }
}