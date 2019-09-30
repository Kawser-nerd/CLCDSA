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
        ABC097_A solver = new ABC097_A();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABC097_A {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int a, b, c, d;
            a = in.nextInt();
            b = in.nextInt();
            c = in.nextInt();
            d = in.nextInt();

            if (Math.abs(c - a) <= d) {
                out.print("Yes");
                return;
            }

            if (Math.abs(c - b) <= d && Math.abs(b - a) <= d) {
                out.print("Yes");
                return;
            }

            out.print("No");
        }

    }
}