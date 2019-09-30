import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long [][] dist = new long[n + 1][n + 1];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                long a = scanner.nextInt();
                dist[i][j] = a;
            }
        }
        long totalLength = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                boolean isNecessary = true;
                for (int k = 1; k <= n; ++k) {
                    if (i == k || j == k) {
                        continue;
                    }
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        System.out.println(-1);
                        return;
                    } else if (dist[i][k] + dist[k][j] == dist[i][j]) {
                        isNecessary = false;
                        break;
                    }
                }
                if (isNecessary) {
                    totalLength += dist[i][j];
                }
            }
        }
        System.out.println(totalLength);
    }
}