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
            int r = in.nextInt(), g = in.nextInt(), b = in.nextInt();
            int minAns = Integer.MAX_VALUE;
            for (int gr = -1000; gr < 1000; gr++) {
                int gl = 1 + gr - g;
                int ans = calc(0, gl, gr);
                int rl = -r / 2 - 100, rr = (r - 1) / 2 - 100;
                int bl = -b / 2 + 100, br = (b - 1) / 2 + 100;
                if (rr >= gl) {
                    int d = rr - gl + 1;
                    rl -= d;
                    rr -= d;
                }
                if (gr >= bl) {
                    int d = gr - bl + 1;
                    bl += d;
                    br += d;
                }
                ans += calc(-100, rl, rr);
                ans += calc(100, bl, br);
                minAns = Math.min(minAns, ans);
            }
            out.println(minAns);
        }

        private static int calc(int orig, int left, int right) {
            int l = left - orig;
            int r = right - orig;
            if (l <= 0 && 0 <= r) {
                return (l * (l - 1) + r * (r + 1)) / 2;
            } else if (r < 0) {
                return (l * (l - 1) - r * (r + 1)) / 2;
            } else {
                return (r * (r + 1) - l * (l - 1)) / 2;
            }
        }

    }
}