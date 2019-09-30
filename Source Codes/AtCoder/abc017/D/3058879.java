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
            int n = in.nextInt(), m = in.nextInt();
            int[] lastIndex = new int[m + 1];
            long[] dp = new long[n + 1];
            dp[0] = 1;
            int k = 0;
            for (int i = 1; i <= n; i++) {
                int f = in.nextInt();
                k = Math.max(k, lastIndex[f]);
                lastIndex[f] = i;
                for (int j = k; j < i; j++) {
                    dp[i] += dp[j];
                }
                dp[i] %= 1000000007;
            }
            out.println(dp[n]);
        }

    }
}