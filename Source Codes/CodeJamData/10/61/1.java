package y2010.finals;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {

    private int[] a;

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
        String s = in.next();
        int n = s.length();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = s.charAt(i) - 'A';
        }
        mem = new int[n + 1][n + 1][3];
        for (int[][] ints : mem) {
            for (int[] anInt : ints) {
                Arrays.fill(anInt, -1);
            }
        }
        return "" + ((count(0, n, a[0]) + 1) * 2 + n);
    }

    int[][][] mem;

    private int count(int l, int r, int c) {
        if (mem[l][r][c] >= 0) {
            return mem[l][r][c];
        }
        int res = 1000000;
        if (l >= r) {
            res = 0;
        } else if (a[l] == c) {
            res = count(l + 1, r, c);
        } else if (a[r - 1] == c) {
            res = count(l, r - 1, c);
        } else {
            int cc = a[l];
            for (int j = l; j < r; j++) {
                res = Math.min(res, 1 + count(l, j + 1, cc) + count(j + 1, r, c));
            }
        }
        mem[l][r][c] = res;
        return res;
    }
}