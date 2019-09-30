import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * @author Pavel Mavrin
 * @id {Id}
 */
public class C {

    static Scanner in;
    static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("c.in"));
        out = new PrintWriter("c.out");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new C().solve());
        }
        out.close();
    }

    int n;
    int k;
    boolean[][] a;

    private Object solve() {
        n = in.nextInt();
        k = in.nextInt();
        a = new boolean[n][n];
        for (int i = 0; i < n - 1; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            a[x][y] = true;
            a[y][x] = true;
        }
        return dfs(0, -1, k);
    }

    private static final long MOD = 1000000009;


    private long dfs(int i, int pp, int kk) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] && j != pp) c++;
        }
        long res = 1;
        if (kk < c) return 0;
        for (int j = 0; j < c; j++) {
            res *= (kk - j);
            res %= MOD;
        }
        for (int j = 0; j < n; j++) {
            if (a[i][j] && j != pp) {
                res *= dfs(j, i, k - c - (pp == -1 ? 0 : 1));
                res %= MOD;
            }
        }
        System.out.println("" + i + " " + res);
        return res;
    }
}
