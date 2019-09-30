import java.util.Arrays;
import java.util.Scanner;

public class Main {

    int n, m;
    boolean[][] g;

    void run() {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        g = new boolean[n][n];

        for (int i = 0; i < m; i++) {
            int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
            g[a][b] = true;
            g[b][a] = true;
        }

        int ans = 1;

        for (int i = 0; i < (1 << n); i++) {
            if (check(i)) {
                ans = Math.max(ans, Integer.bitCount(i));
            }
        }

        System.out.println(ans);
    }

    boolean check(int S) {
        for (int t = 0; t < n; t++) for (int s = t + 1; s < n; s++) {
            if (((S >> t) & 1) == 1 && ((S >> s) & 1) == 1) {
                if (!g[t][s]) {
                    return false;
                }
            }
        }
        return true;
    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        new Main().run();
    }
}