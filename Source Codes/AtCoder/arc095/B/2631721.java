import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        DBinomialCoefficients solver = new DBinomialCoefficients();
        solver.solve(1, in, out);
        out.close();
    }

    static class DBinomialCoefficients {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a);
            int col = a[n - 1];
            int min = col / 2;
            int max = min + (col % 2 == 0 ? 0 : 1);
            out.print(col);
            out.print(' ');
            int d = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                int cd = Math.min(Math.abs(max - a[i]), Math.abs(min - a[i]));
                if (cd < d) {
                    d = cd;
                } else {
                    out.println(a[i - 1]);
                    return;
                }
            }
            out.println(a[n - 1]);
        }

    }
}