import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
            String as = in.next();
            String bs = in.next();
            int n = as.length();
            int[] a = new int[n];
            int[] b = new int[n];
            boolean ahas1 = false;
            boolean bhas1 = false;
            for (int i = 0; i < n; i++) {
                a[i] = as.charAt(i) == '1' ? 1 : 0;
                b[i] = bs.charAt(i) == '1' ? 1 : 0;
                if (a[i] == 1) {
                    ahas1 = true;
                }
                if (b[i] == 1) {
                    bhas1 = true;
                }
            }

            if (!bhas1) {
                if (ahas1) {
                    out.println(-1);
                    return;
                }
                out.println(0);
                return;
            }

            int[] findL = new int[n];
            int[] findR = new int[n];
            for (int i = 0; i < n; i++) {
                int j = i;
                while (b[j] != 1) {
                    findL[i]++;
                    j = (j + n - 1) % n;
                }
                j = i;
                while (b[j] != 1) {
                    findR[i]++;
                    j = (j + 1) % n;
                }
            }

            int ans = Integer.MAX_VALUE;
            int[] c = new int[n];
            int[] l = new int[n];
            int[] r = new int[n];

            int[] need = new int[n];
            for (int sh = 0; sh < n; sh++) {
                int swp = 0;
                for (int i = 0; i < n; i++) {
                    c[i] = a[(sh + i) % n];
                    if (c[i] == b[i]) {
                        l[i] = 0;
                        r[i] = 0;
                    } else {
                        l[i] = findL[i];
                        r[i] = findR[i];
                        swp++;
                    }
                }


                // L
                Arrays.fill(need, 0);
                for (int i = 0; i < n; i++) {
                    if (r[i] <= sh) {
                        continue;
                    }
                    need[l[i] - 1] = Math.max(need[l[i] - 1], r[i] - sh);
                }

                for (int i = n - 2; i >= 0; i--) {
                    need[i] = Math.max(need[i], need[i + 1]);
                }

                for (int i = 0; i < n; i++) {
                    int val = sh + swp + 2 * (i + need[i]);
                    if (val < ans) {
                        ans = val;
                    }
                }

                // R
                int zh = n - sh;
                Arrays.fill(need, 0);
                for (int i = 0; i < n; i++) {
                    if (l[i] <= zh) {
                        continue;
                    }
                    need[r[i] - 1] = Math.max(need[r[i] - 1], l[i] - zh);
                }

                for (int i = n - 2; i >= 0; i--) {
                    need[i] = Math.max(need[i], need[i + 1]);
                }

                for (int i = 0; i < n; i++) {
                    int val = zh + swp + 2 * (i + need[i]);
                    if (val < ans) {
                        ans = val;
                    }
                }
            }

            out.println(ans);
        }

    }
}