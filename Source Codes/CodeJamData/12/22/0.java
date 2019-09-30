
import sun.jvm.hotspot.debugger.amd64.AMD64ThreadContext;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(B.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(B.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new B().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int h = in.nextInt();
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] c = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i][j] = in.nextInt();
            }
        }
        int[][] f = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[i][j] = in.nextInt();
            }
        }

        int[][] t = new int[n][m];
        boolean[][] z = new boolean[n][m];
        for (int[] ints : t) {
            Arrays.fill(ints, 1000000000);
        }
        t[0][0] = 0;

        while (true) {
            int ii = -1;
            int jj = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!z[i][j]) {
                        if (ii == -1 || t[i][j] < t[ii][jj]) {
                            ii = i;
                            jj = j;
                        }
                    }
                }
            }
            if (ii == -1) break;
            z[ii][jj] = true;
//            System.out.println(ii + " " + jj);
            int[] di = {-1, 1, 0, 0};
            int[] dj = {0, 0, -1, 1};
            for (int d = 0; d < 4; d++) {
                int iii = ii + di[d];
                int jjj = jj + dj[d];
                if (iii >= 0 && iii < n && jjj >= 0 && jjj < m) {
                    int tt = t[ii][jj];
                    if (f[ii][jj] <= c[iii][jjj] - 50 &&
                            f[iii][jjj] <= c[iii][jjj] - 50 &&
                            f[iii][jjj] <= c[ii][jj] - 50) {
                        int hh = c[iii][jjj] - 50;
                        tt = Math.max(tt, h - hh);
                        int ttt;
                        if (tt == 0) {
                            ttt = 0;
                        } else if (h - tt >= f[ii][jj] + 20) {
                            ttt = tt + 10;
                        } else {
                            ttt = tt + 100;
                        }
                        t[iii][jjj] = Math.min(t[iii][jjj], ttt);
                    }
                }
            }
        }
        return "" + (t[n - 1][m - 1] * 0.1);
    }
}