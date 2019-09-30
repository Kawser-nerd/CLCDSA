import java.util.*;

public class Main {
    static int n, m;
    static long INF = Long.MAX_VALUE / 10;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();

        long d[][] = new long[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) d[i][j] = 0;
                else       d[i][j] = INF;
            }
        }

        for(int i = 0; i < m; i++) {
            int source = in.nextInt()-1;
            int dest   = in.nextInt()-1;
            int len    = in.nextInt();
            d[source][dest] = d[dest][source] = len;
        }

        for(int k = 1; k < n; k++) {
            for(int i = 1; i < n; i++) {
                for(int j = 1; j < n; j++) {
                    d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        long dist = INF;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < n; j++) {
                if(i != j){
                    dist = Math.min(dist, d[0][i] + d[i][j] + d[j][0]);
                }
            }
        }

        if(dist == INF) System.out.println(-1);
        else            System.out.println(dist);
    }

}