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
            int[] l = new int[n + 1];
            l[0] = -1;
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                int m = in.nextInt();
                for (int j = 1; j <= i; j++) {
                    if (l[j - 1] == 0) {
                        break;
                    } else if (l[j - 1] < m) {
                        if (l[j] == 0) {
                            l[j] = m;
                            ans = Math.max(ans, j);
                        } else {
                            l[j] = Math.min(l[j], m);
                        }
                    }
                }
            }
            out.println(n - ans);
        }

    }
}