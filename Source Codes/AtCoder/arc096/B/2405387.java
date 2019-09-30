import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ZYCSwing
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        private static final int N = (int) 1e5 + 10;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            long c = in.nextLong();
            long[] x = new long[N];
            long[] y = new long[N];
            int[] v = new int[N];

            long[] ldp = new long[N];
            long[] rdp = new long[N];

            for (int i = 1; i <= n; ++i) {
                x[i] = in.nextLong();
                y[i] = c - x[i];
                v[i] = in.nextInt();
            }

            long res = 0;

            x[0] = 0;
            x[n + 1] = c;
            ldp[0] = 0;
            for (int i = 1; i <= n; ++i) {
                ldp[i] = ldp[i - 1] + v[i] - (x[i] - x[i - 1]);
                res = Math.max(res, ldp[i]);
            }

            y[0] = c;
            y[n + 1] = 0;
            rdp[n + 1] = 0;
            for (int i = n; i >= 1; --i) {
                rdp[i] = rdp[i + 1] + v[i] - (y[i] - y[i + 1]);
                res = Math.max(res, rdp[i]);
            }

            long[] lldp = new long[N];
            long[] rrdp = new long[N];

            lldp[0] = 0;
            for (int i = 1; i <= n; ++i) {
                lldp[i] = Math.max(lldp[i - 1], ldp[i] - x[i]);
            }

            rrdp[0] = 0;
            for (int i = n; i >= 1; --i) {
                rrdp[i] = Math.max(rrdp[i + 1], rdp[i] - y[i]);
            }

            for (int l = 1, r = n + 1; l < n; ++l) {
                while (x[l] >= y[r]) {
                    --r;
                }
                while (x[l] < y[r]) {
                    ++r;
                }
                res = Math.max(res, ldp[l] + rrdp[Math.max(r, l + 1)]);
            }

            for (int l = 0, r = n; r > 1; --r) {
                while (x[l] < y[r]) {
                    ++l;
                }
                while (x[l] >= y[r]) {
                    --l;
                }
                res = Math.max(res, lldp[Math.min(l, r - 1)] + rdp[r]);
            }

            out.println(res);
        }

    }
}