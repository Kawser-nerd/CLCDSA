import java.util.*;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class D {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("D.in"));
        PrintWriter out = new PrintWriter("D.out");

        int t = in.nextInt();
        in.nextLine();
        for (int tn = 0; tn < t; tn++) {
            out.println("Case #" + (tn + 1) + ": " + solve(in));
        }

        out.close();

    }

    private static String solve(Scanner in) {
        int n = in.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        int[] r = new int[n];
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
            r[i] = in.nextInt();
            s[i] = in.nextInt();
        }
        boolean[][] a = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) <= r[i] * r[i]) {
                    a[i][j] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    a[j][k] = a[j][k] || a[j][i] && a[j][k];
                }
            }
        }
        int res = 0;
        outer:for (int m = 0; m < (1 << n); m++) {
            boolean[] z = new boolean[n];
            for (int i = 0; i < n; i++) z[i] = ((m >> i) & 1) > 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] && z[i] && !z[j]) {
                        continue outer;
                    }
                }
            }
            int ss = 0;
            for (int i = 0; i < n; i++) if (z[i]) ss += s[i];
            res = Math.max(res, ss);
        }
        return "" + res;
    }

}
