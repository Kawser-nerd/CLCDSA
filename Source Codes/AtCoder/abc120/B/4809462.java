import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Eric
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BKThCommonDivisor solver = new BKThCommonDivisor();
        solver.solve(1, in, out);
        out.close();
    }

    static class BKThCommonDivisor {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int A = in.nextInt();
            int B = in.nextInt();
            int K = in.nextInt();
            int res = solve(A, B, K);
            out.println(res);
        }

        private int solve(int a, int b, int K) {
            int cur = 0;
            for (int i = 101; i >= 1; i--) {
                if (a % i == 0 && b % i == 0) {
                    cur++;
                    if (cur == K)
                        return i;
                }
            }
            throw new RuntimeException("Impossible");
        }

    }
}