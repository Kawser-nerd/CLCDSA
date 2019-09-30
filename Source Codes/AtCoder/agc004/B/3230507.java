import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.LongStream;
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
        BColorfulSlimes solver = new BColorfulSlimes();
        solver.solve(1, in, out);
        out.close();
    }

    static class BColorfulSlimes {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            long x = in.nextLong();
            long[][] a = new long[n][n];
            a[0] = LongStream.range(0, n).map(z -> in.nextInt()).toArray();
            long ans = LongStream.of(a[0]).sum();
            for (int k = 1; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    a[k][i] = Math.min(a[k - 1][(i + n - 1) % n], a[0][i]);
                }
                ans = Math.min(ans, LongStream.of(a[k]).sum() + k * x);
            }
            out.println(ans);
        }

    }
}