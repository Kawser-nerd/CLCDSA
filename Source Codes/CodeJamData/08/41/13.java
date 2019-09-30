import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * @author Pavel Mavrin
 * @id {Id}
 */
public class A {

    static Scanner in;
    static PrintWriter out;
    private static final int INF = 1000000000;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("input.txt"));
        out = new PrintWriter("output.txt");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new A().solve());
        }
        out.close();
    }

    private Object solve() {
        int m = in.nextInt();
        int v = in.nextInt();
        int mm = (m - 1) / 2;
        int[] g = new int[mm];
        int[] c = new int[mm];
        for (int i = 0; i < mm; i++) {
            g[i] = in.nextInt();
            c[i] = in.nextInt();
        }
        int[] q = new int[mm + 1];
        for (int i = 0; i < mm + 1; i++) {
            q[i] = in.nextInt();
        }

        int[][] d = new int[m][2];
        for (int i = mm; i < m; i++) {
            int t = q[i - mm];
            d[i][t] = 0;
            d[i][1 - t] = INF;
        }

        for (int i = mm - 1; i >= 0; i--) {
            d[i][0] = INF;
            d[i][1] = INF;
            for (int a = 0; a < 2; a++) if (d[2 * i + 1][a] < INF) {
                for (int b = 0; b < 2; b++) if (d[2 * i + 2][b] < INF) {
                    for (int gg = 0; gg < 2; gg++) if (gg == g[i] || c[i] == 1) {
                        int r = (gg == 1) ? a & b : a | b;
                        d[i][r] = Math.min(d[i][r], d[2 * i + 1][a] + d[2 * i + 2][b] + (gg ^ g[i]));
                    }
                }
            }
        }
        return d[0][v] < INF ? "" + d[0][v] : "IMPOSSIBLE";
    }
}
