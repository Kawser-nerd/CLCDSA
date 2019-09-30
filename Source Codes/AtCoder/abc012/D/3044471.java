import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.OptionalInt;

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
            int n = in.nextInt(), m = in.nextInt();
            int[][] dist = new int[n][n];
            for (int i = 0; i < n; i++) {
                Arrays.fill(dist[i], 1000000000);
                dist[i][i] = 0;
            }
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1, t = in.nextInt();
                dist[a][b] = t;
                dist[b][a] = t;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        dist[j][k] = Math.min(dist[j][k], dist[j][i] + dist[i][k]);
                    }
                }
            }

            int ans = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                ans = Math.min(ans, IntStream.of(dist[i]).max().orElse(Integer.MAX_VALUE));
            }
            out.println(ans);
        }

    }
}