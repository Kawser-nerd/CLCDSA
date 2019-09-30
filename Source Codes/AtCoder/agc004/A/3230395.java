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
        ADivideACuboid solver = new ADivideACuboid();
        solver.solve(1, in, out);
        out.close();
    }

    static class ADivideACuboid {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            long a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
            out.println(a * b * c % 2 == 0 ? 0 : Math.min(a * b, Math.min(b * c, c * a)));
        }

    }
}