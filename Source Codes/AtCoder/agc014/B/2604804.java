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
        BUnplannedQueries solver = new BUnplannedQueries();
        solver.solve(1, in, out);
        out.close();
    }

    static class BUnplannedQueries {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[] f = new int[n];
            for (int i = 0; i < m; i++) {
                f[in.nextInt() - 1]++;
                f[in.nextInt() - 1]++;
            }
            for (int i : f) {
                if (i % 2 != 0) {
                    out.println("NO");
                    return;
                }
            }
            out.println("YES");
        }

    }
}