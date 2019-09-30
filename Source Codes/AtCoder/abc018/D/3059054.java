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
        D solver = new D();
        solver.solve(1, in, out);
        out.close();
    }

    static class D {
        int n;
        int m;
        int p;
        int q;
        int r;
        int[] x;
        int[] y;
        int[] z;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            p = in.nextInt();
            q = in.nextInt();
            r = in.nextInt();
            x = new int[r];
            y = new int[r];
            z = new int[r];
            for (int i = 0; i < r; i++) {
                x[i] = in.nextInt() - 1;
                y[i] = in.nextInt() - 1;
                z[i] = in.nextInt();
            }
            out.println(calc(new int[p], 0, 0));
        }

        private int calc(int[] girls, int i, int f) {
            if (i == p) {
                // ==???==
                int[] s = new int[m];
                for (int j = 0; j < r; j++) {
                    if (Arrays.binarySearch(girls, x[j]) >= 0) {
                        s[y[j]] += z[j];
                    }
                }
                Arrays.sort(s);
                int ans = 0;
                for (int j = m - q; j < m; j++) {
                    ans += s[j];
                }
                return ans;
                // ==???==
            }
            int ans = 0;
            for (int j = f; j < n; j++) {
                girls[i] = j;
                ans = Math.max(ans, calc(girls, i + 1, j + 1));
            }
            return ans;
        }

    }
}