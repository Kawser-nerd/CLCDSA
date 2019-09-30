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
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt(), h = in.nextInt();
            long a = in.nextLong(), b = in.nextLong(), c = in.nextLong(), d = in.nextLong(), e = in.nextLong();

            long s = b + e, t = d + e, u = e * n - h;
            long ans = Long.MAX_VALUE;
            int y = 0;
            for (int x = n; x >= 0; x--) {
                while (s * x + t * y <= u) {
                    y++;
                }
                if (x + y > n) {
                    break;
                }
                ans = Math.min(ans, a * x + c * y);
            }
            out.println(ans);
        }

    }
}