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
            int n = in.nextInt();
            int[] c = new int[n];
            int[] s = new int[n];
            for (int i = 0; i < n; i++) {
                c[i] = in.nextInt();
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j && c[i] % c[j] == 0) {
                        s[i]++;
                    }
                }
            }

            double ans = 0;
            for (int i = 0; i < n; i++) {
                ans += s[i] % 2 == 0 ? (s[i] + 2.0) / (2 * s[i] + 2.0) : 0.5;
            }
            out.println(ans);
        }

    }
}