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
            int n = in.nextInt();
            int max = 0;
            int dest = 0;
            for (int i = 2; i <= n; i++) {
                out.println("? 1 " + i);
                out.flush();
                int dist = in.nextInt();
                if (max < dist) {
                    max = dist;
                    dest = i;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (i == dest) {
                    continue;
                }
                out.println("? " + dest + " " + i);
                out.flush();
                max = Math.max(max, in.nextInt());
            }
            out.println("! " + max);
        }

    }
}