package round2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(A.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(A.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new A().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int m = 2 * n - 1;
        int[][] a = new int[m][m];
        for (int[] ints : a) {
            Arrays.fill(ints, -1);
        }
        for (int i = 0; i < m; i++) {
            int h = i < n ? i + 1 : 2 * n - 1 - i;
            int d = n - h; 
            for (int j = 0; j < h; j++) {
                int c = in.nextInt();
                a[i][d + j * 2] = c;
            }
        }

//        for (int[] ints : a) {
//            System.out.println(Arrays.toString(ints));
//        }

        boolean[] rs = new boolean[m];
        for (int r = 0; r < m; r++) {
            rs[r] = true;
            for (int i = 0; i < m; i++) {
                int ii = (2 * r - i);
                if (ii < 0 || ii >= m) continue;
                for (int j = 0; j < m; j++) {
                    if (a[i][j] >= 0 && a[ii][j] >= 0 && a[i][j] != a[ii][j]) {
                        rs[r] = false;
                        break;
                    }
                }
                if (!rs[r]) break;
            }
        }
        boolean[] cs = new boolean[m];
        for (int c = 0; c < m; c++) {
            cs[c] = true;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    int jj = (2 * c - j);
                    if (jj < 0 || jj >= m) continue;
                    if (a[i][j] >= 0 && a[i][jj] >= 0 && a[i][j] != a[i][jj]) {
                        cs[c] = false;
                        break;
                    }
                }
                if (!cs[c]) break;
            }
        }

        int[] rv = {0, n - 1, n - 1, 2 * n - 2};
        int[] cv = {n - 1, 0, 2 * n - 2, n - 1};

        int res = 10000;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) if (rs[i] && cs[j]) {
                int d = 0;
                for (int q = 0; q < 4; q++) {
                    d = Math.max(d, Math.abs(rv[q] - i) + Math.abs(cv[q] - j));
                }
                res = Math.min(res, d);
            }
        }

        //System.out.println(res);

        res = (res + 1) * (res + 1) - (n * n);
        
        return "" + res;
    }
}