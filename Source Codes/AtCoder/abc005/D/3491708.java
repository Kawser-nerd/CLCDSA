import java.util.*;
import java.util.stream.IntStream;

public class Main {
    static int n;
    static int[][] d;
    static int[][] cum;


    static Scanner sc;

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        n = sc.nextInt();

        d = new int[n][n];
        cum = new int[n + 1][n + 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = sc.nextInt();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cum[i + 1][j + 1] = cum[i + 1][j] + cum[i][j + 1] + d[i][j]- cum[i][j];
            }
        }

        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int p = sc.nextInt();
            int best = 0;
            for (int j = 0; j < p; j++) {
                int x = p - j;
                int y = p / x;
                y = Math.min(y, n);
                best = Math.max(best, f(x, y));
            }
            System.out.println(best);
        }
    }

    static int f(int x, int y) {
        int best = 0;
        for (int i = 0; i < n - x+1; i++) {
            for (int j = 0; j < n - y+1; j++) {
                best = Math.max(best, cum[i+x][j+y] - cum[i+x][j] - cum[i][j+y] + cum[i][j]);
            }
        }
        return best;
    }

}