package y2010.finals;

import java.awt.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class B {
    private int[] q;
    private int[] w;
    private int[] e;
    private int m;
    private boolean[][] a;
    private int n;

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
        n = in.nextInt();
        a = new boolean[n][n];
        a[0][1] = true;
        a[1][0] = true;
        a[0][2] = true;
        a[2][0] = true;
        a[1][2] = true;
        a[2][1] = true;

        m = (n - 2) * 3;
        q = new int[m];
        w = new int[m];
        e = new int[m];
        q[0] = 0; q[1] = 1; q[2] = 2;
        w[0] = 1; w[1] = 2; w[2] = 0;
        e[0] = 2; e[1] = 0; e[2] = 1;
        m = 3;
        for (int i = 3; i < n; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            a[i][x] = true;
            a[x][i] = true;
            a[i][y] = true;
            a[y][i] = true;
            q[m] = i; w[m] = x; e[m] = y; m++;
            q[m] = x; w[m] = y; e[m] = i; m++;
            q[m] = y; w[m] = i; e[m] = x; m++;
        }
        for (int i = 0; i < m; i++) {
            int x = q[i];
            int z = e[i];
            q[i] = Math.min(x, z);
            e[i] = Math.max(x, z);
        }
        mem = new int[m];
        int res = 0;
        for (int i = 0; i < m; i++) {
            res = Math.max(res, calc(i) + 2);
        }        
        return "" + res;
    }

    int[] mem;

    private int calc(int i) {
        if (mem[i] > 0) return mem[i];
        int x = q[i];
        int y = w[i];
        int z = e[i];
        int m1 = 0;
        int m2 = 0;
        for (int j = 0; j < m; j++) {
            if (q[j] == Math.min(x, y) && e[j] == Math.max(x, y) && w[j] != z) {
                m1 = Math.max(m1, calc(j));
            }
            if (q[j] == Math.min(z, y) && e[j] == Math.max(z, y) && w[j] != x) {
                m2 = Math.max(m2, calc(j));
            }
        }
        int res = m1 + m2 + 1;
        mem[i] = res;
        return res;
    }
}