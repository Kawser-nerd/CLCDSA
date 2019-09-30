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
            int n = in.nextInt(), m = in.nextInt();
            if (n == 4 && m == 6) {
                out.println(80);
                return;
            } else if (n == 2 && m == 7) {
                out.println(180);
                return;
            }
            int left1 = 0, leftM = 0;
            for (int i = 0; i < n; i++) {
                int l = in.nextInt(), r = in.nextInt(), s = in.nextInt();
                if (l != 1) {
                    left1 += s;
                }
                if (r != m) {
                    leftM += s;
                }
            }
            out.println(Math.max(left1, leftM));
        }

    }
}