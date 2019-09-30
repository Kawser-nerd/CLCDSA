import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ABC_012_D solver = new ABC_012_D();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABC_012_D {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            long[][] bus = new long[n][n];
            int BIG = 10000000;
            int a, b, t;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j && bus[i][j] == 0) {
                        bus[i][j] = BIG;
                    }
                }
            }

            for (int i = 0; i < m; i++) {
                a = in.nextInt();
                b = in.nextInt();
                t = in.nextInt();
                bus[a - 1][b - 1] = t;
                bus[b - 1][a - 1] = t;
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j && bus[i][j] == 0) {
                        bus[i][j] = BIG;
                    }
                }
            }

            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        bus[i][j] = Math.min(bus[i][j], bus[i][k] + bus[k][j]);
                    }
                }
            }
            long ans = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                long max = -1;
                for (int j = 0; j < n; j++) {
                    max = Math.max(max, bus[i][j]);
                }

                ans = Math.min(ans, max);
            }

            out.print(ans);
        }

    }
}