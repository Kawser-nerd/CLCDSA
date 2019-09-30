import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static int N;
    static int M;
    static Edge[] E;
    static final int INF = 10000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        E = new Edge[M];
        for (int i = 0; i < M; i++) {
            E[i] = new Edge(sc.nextInt()-1, sc.nextInt()-1, sc.nextInt());
        }
        System.out.println( solve() );
    }

    private static long solve() {
        int[][] dist = new int[N][N];
        for (int[] array : dist) {
            Arrays.fill(array, INF);
        }
        for (Edge edge : E) {
            dist[edge.a][edge.b] = edge.cost;
            dist[edge.b][edge.a] = edge.cost;
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                if( dist[i][k] == INF ) continue;
                for (int j = 0; j < N; j++) {
                    if( dist[k][j] == INF ) continue;

                    if( dist[i][k] + dist[k][j] < dist[i][j] ) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int ans = 0;
        for (Edge edge : E) {
            if( dist[edge.a][edge.b] < edge.cost ) ans++;
        }
        return ans;
    }

    static class Edge {
        private final int a;
        private final int b;
        private final int cost;

        public Edge(int a, int b, int cost) {
            this.a = a;
            this.b = b;
            this.cost = cost;
        }
    }
}