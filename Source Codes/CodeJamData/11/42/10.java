
import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class b {
    public static void main(String[] args) {
        Scanner s = new Scanner(new BufferedInputStream(System.in));

        int T = s.nextInt();
        for (int casenumber = 1; casenumber <= T; ++casenumber) {
            int r = s.nextInt();
            int c = s.nextInt();
            s.nextInt();

            int[][] masses = new int[r][c];
            for (int i = 0; i < r; ++i) {
                String temp = s.next();
                for (int j = 0; j < c; ++j) {
                    masses[i][j] = temp.charAt(j) - '0';
                }
            }

            int[][] pr = new int[r][c];
            int[][] pc = new int[r][c];

            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    pr[i][j] = masses[i][j] * i;
                    pc[i][j] = masses[i][j] * j;
                }
            }

            int[][] m_cached = cache(masses, r, c);
            int[][] pr_cached = cache(pr, r, c);
            int[][] pc_cached = cache(pc, r, c);

            String ans = "IMPOSSIBLE";

outer:
            for (int k = r + c; k >= 3; --k) {
                int ks = k - 1;
                for (int i = 0; i + k <= r; ++i) {
                    for (int j = 0; j + k <= c; ++j) {
                        int local_m  = uncache(m_cached,  i, j, i + k, j + k) - masses[i][j] - masses[i + ks][j] - masses[i][j + ks] - masses[i + ks][j + ks];
                        int local_pr = uncache(pr_cached, i, j, i + k, j + k) - pr[i][j] - pr[i + ks][j] - pr[i][j + ks] - pr[i + ks][j + ks];
                        int local_pc = uncache(pc_cached, i, j, i + k, j + k) - pc[i][j] - pc[i + ks][j] - pc[i][j + ks] - pc[i + ks][j + ks];

                        // System.out.format("(%d,%d) %d:  %d %d %d%n", i, j, k, local_pr, local_pc, local_m);
                        if ((local_pr * 2 == local_m * (2 * i + k - 1)) && (local_pc * 2 == local_m * (2 * j + k - 1))) {
                            ans = Integer.toString(k);
                            // System.out.println("this one");
                            break outer;
                        }
                    }
                }
            }

            System.out.format("Case #%d: %s%n", casenumber, ans);
        }
    }

    private static int[][] cache(int[][] a, int r, int c) {
        int[][] ans = new int[r + 1][c + 1];

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                ans[i + 1][j + 1] = ans[i + 1][j] + ans[i][j + 1] - ans[i][j] + a[i][j];
            }
        }

        return ans;
    }

    private static int uncache(int[][] cache, int r1, int c1, int r2, int c2) {
        return cache[r2][c2] - cache[r1][c2] - cache[r2][c1] + cache[r1][c1];
    }
}
