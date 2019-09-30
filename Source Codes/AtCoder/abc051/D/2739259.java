import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[] a = new int[m];
        int[] b = new int[m];
        int[] c = new int[m];

        for (int i = 0; i < m; i++) {
            a[i] = sc.nextInt() - 1; // so that indices start at 0
            b[i] = sc.nextInt() - 1;
            c[i] = sc.nextInt();
        }

        int[][] dist = new int[n][n];

        // Initializing distances to be infinite (unless the two edges are equal).
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dist[i][j] = 0;
                } else {
                    dist[i][j] = Integer.MAX_VALUE >> 1;
                }
            }
        }

        // Filling in the edges that were provided in the input data
        for (int i = 0; i < m; i++) {
            dist[a[i]][b[i]] = Math.min(dist[a[i]][b[i]], c[i]);
            dist[b[i]][a[i]] = Math.min(dist[b[i]][a[i]], c[i]);
        }

        // Dijkstra magic
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Counting edges NOT included in the shortest path
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (dist[a[i]][b[i]] != c[i]) {
                count++;
            }
        }
        System.out.println(count);
    }
}