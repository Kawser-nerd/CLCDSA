package round2;

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
        int p = in.nextInt();
        int n = 1 << p;
        int[] m = new int[n];
        for (int i = 0; i < n; i++) m[i] = in.nextInt();
        int[] pr = new int[n - 1];
        for (int i = 0; i < n - 1; i++) pr[i] = in.nextInt();

        long[][] d = new long[2 * n - 1][p + 1];
        for (long[] ints : d) {
            Arrays.fill(ints, 1000000000000L);
        }

        for (int i = 0; i < n; i++) {
            for (int j = p - m[i]; j <= p; j++) {
                d[2 * n - 2 - i][j] = 0;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= p; j++) {
                long d1 = d[2 * i + 1][j] + d[2 * i + 2][j];
                d[i][j] = Math.min(d[i][j], d1);
                if (j < p) {
                    long d2 = pr[n - 2 - i] + d[2 * i + 1][j + 1] + d[2 * i + 2][j + 1];
                    d[i][j] = Math.min(d[i][j], d2);
                }
            }
        }
//        for (int[] ints : d) {
//            System.out.println(Arrays.toString(ints));
//        }


        return "" + d[0][0];
    }
}