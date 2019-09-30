package y2010.finals;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D2 {
    private long f;
    private long res;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(D2.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(D2.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new D2().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        long[] x = new long[n];
        for (int i = 0; i < n; i++) x[i] = in.nextLong();
        f = in.nextLong();
        Arrays.sort(x);
        int n1 = n / 2;
        int n2 = n - n1;
        long[] x1 = new long[n1];
        long[] x2 = new long[n2];
        for (int i = 0; i < n1; i++) x1[i] = x[i];
        for (int i = 0; i < n2; i++) x2[i] = -x[n - i - 1];

        long[] r1 = new long[1 << 20];
        long[] r2 = new long[1 << 20];
        int[] c1 = new int[1];
        int[] c2 = new int[1];

        long res = -1;

        for (int d = 1; d <= n1; d++) {
            long zz = d * 2 * (-x2[n2 - 1] - x1[n1 - 1]);
            c1[0] = 0;
            c2[0] = 0;
            bt(x1, n1, 1, 0, 1, r1, c1, d);
            bt(x2, n2, 1, 0, 1, r2, c2, d);
            if (c1[0] == 0 || c2[0] == 0) continue;
            Arrays.sort(r1, 0, c1[0]);
            Arrays.sort(r2, 0, c2[0]);
            if (r1[0] + r2[0] > f) continue;
            int j = c2[0] - 1;
            for (int i = 0; i < c1[0]; i++) {
                while (j >= 0 && r1[i] + r2[j] + zz  > f) j--;
                if (j < 0) break;
                res = Math.max(res, r1[i] + r2[j] + zz);
            }
        }
               
        return res == -1 ? "NO SOLUTION" : ("" + res);
    }

    long u = 0;

    private void bt(long[] x, int n, int i, long s, int j, long[] r, int[] c, int d) {
        if (j + (n - i) < d) return;
        if (j - (n - i) > d) return;
        if (i == n) {
            r[c[0]] = s;
            c[0]++;
            return;
        }
        long ss = s + (x[i] - x[i - 1]) * 2 * j;
        if (j > 1) bt(x, n, i + 1, ss, j - 1, r, c, d);
        bt(x, n, i + 1, ss, j, r, c, d);
        bt(x, n, i + 1, ss, j + 1, r, c, d);
    }
}