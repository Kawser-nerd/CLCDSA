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
        B solver = new B();
        solver.solve(1, in, out);
        out.close();
    }

    static class B {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int d = Math.abs(in.nextInt() - in.nextInt());
            int c = 0;
            while (d > 0) {
                if (d >= 8) {
                    c++;
                    d -= 10;
                    d = Math.abs(d);
                } else if (d >= 4) {
                    c++;
                    d -= 5;
                    d = Math.abs(d);
                } else {
                    c += d;
                    d = 0;
                }
            }
            out.println(c);
        }

    }
}