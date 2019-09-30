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
        ACookieExchanges solver = new ACookieExchanges();
        solver.solve(1, in, out);
        out.close();
    }

    static class ACookieExchanges {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
            for (int i = 0; ; i++) {
                if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
                    out.println(i);
                    return;
                } else if (a == b && b == c) {
                    out.println(-1);
                    return;
                }
                int na = b + c, nb = c + a, nc = a + b;
                a = na / 2;
                b = nb / 2;
                c = nc / 2;
            }
        }

    }
}