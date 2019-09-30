
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
        int q = in.nextInt();
        int n = in.nextInt();
        int[] h = new int[n];
        int[] g = new int[n];
        int max = 3;
        for (int i = 0; i < n; i++) {
            h[i] = in.nextInt();
            g[i] = in.nextInt();
            max += (h[i] + q - 1) / q;
        }
        int[] x = new int[201];
        int[] y = new int[201];
        for (int i = 1; i <= 200; i++) {
            int j = i;
            while ((j - 1) % q + 1 > p) {
                j -= p;
                x[i]++;
            }
            if (j < 0) {
                x[i] = -1;
            } else {
                y[i] = j / q;
                if (j % q == 0) y[i]--;
            }
        }
        int[][] d = new int[n + 1][max];
        for (int[] ints : d) {
            Arrays.fill(ints, -1);
        }
        d[0][1] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < max; j++) if (d[i][j] >= 0) {
                int jj = j + (h[i] + q - 1) / q;
                d[i + 1][jj] = Math.max(d[i + 1][jj], d[i][j]);
                int xx = x[h[i]];
                int yy = y[h[i]];
                if (xx >= 0) {
                    jj = j + yy - (xx + 1);
                    if (jj >= 0) {
                        d[i + 1][jj] = Math.max(d[i + 1][jj], d[i][j] + g[i]);
                    }
                }
            }
        }
        int res = 0;
        for (int j = 0; j < max; j++) {
            res = Math.max(res, d[n][j]);
        }
        return "" + res;
    }
}