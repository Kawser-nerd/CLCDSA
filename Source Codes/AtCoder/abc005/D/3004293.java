import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            /* 1. LOAD : O(n^2) */
            int n = in.nextInt();
            int[][] d = new int[n + 1][n + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + in.nextInt();
                }
            }

            /* 2. MAP1 : O(n^4) */
            int[] c = new int[n * n + 1];
            for (int x1 = 1; x1 <= n; x1++) {
                for (int x2 = x1; x2 <= n; x2++) {
                    for (int y1 = 1; y1 <= n; y1++) {
                        for (int y2 = y1; y2 <= n; y2++) {
                            int s = (x2 - x1 + 1) * (y2 - y1 + 1);
                            c[s] = Math.max(c[s], d[x2][y2] - d[x2][y1 - 1] - d[x1 - 1][y2] + d[x1 - 1][y1 - 1]);
                        }
                    }
                }
            }

            /* 3. MAP2 : O(n) */
            for (int i = 1; i <= n * n; i++) {
                c[i] = Math.max(c[i - 1], c[i]);
            }

            /* 4. SAVE : O(m) */
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                out.println(c[in.nextInt()]);
            }
        }

    }
}