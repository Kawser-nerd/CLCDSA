import java.util.*;

public class Main {
    public static void main(String... args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] times = new int[n][n];
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int t = sc.nextInt();
            times[a - 1][b - 1] = t;
            times[b - 1][a - 1] = t;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && times[i][j] == 0) {
                    times[i][j] = 1000000;
                    times[j][i] = 1000000;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    times[j][k] = Math.min(times[j][k], times[j][i] + times[i][k]);
                    times[k][j] = times[j][k];
                }
            }
        }

        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int tmpmin = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) tmpmin = Math.max(tmpmin, times[i][j]);
            }
            min = Math.min(tmpmin, min);
        }
        System.out.println(min);
    }
}