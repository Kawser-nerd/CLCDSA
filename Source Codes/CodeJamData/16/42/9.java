package gcj.gcj2016.round2;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by hama_du on 5/1/16.
 */
public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int T = in.nextInt();
        for (int t = 1 ; t <= T ; t++) {
            int n = in.nextInt();
            int k = in.nextInt();
            double[] p = new double[n];
            for (int i = 0; i < n ; i++) {
                p[i] = in.nextDouble();
            }
            out.println(String.format("Case #%d: %.9f", t, solve(n, k, p)));
        }
        out.flush();
    }

    private static double solve(int n, int k, double[] p) {
        Arrays.sort(p);
        double best = 0.0d;
        for (int ul = 0 ; ul <= k ; ul++) {
            int dl = k-ul;
            double[] pw = new double[k];
            int pi = 0;
            for (int i = 0 ; i < ul ; i++) {
                pw[pi++] = p[i];
            }
            for (int i = n-1 ; i >= n - dl ; i--) {
                pw[pi++] = p[i];
            }
            Arrays.sort(pw);
            double pp = doit(pw, k);
            if (best < pp) {
                best = pp;
            }
        }
        return best;
    }

    private static double doit(double[] pw, int k) {
        Arrays.sort(pw);

        double[][] dp = new double[k+1][k+1];
        dp[0][0] = 1.0d;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j <= k/2 ; j++) {
                double base = dp[i][j];
                double okRate = pw[i];
                double ngRate = 1.0d - okRate;
                dp[i+1][j+1] += base * okRate;
                dp[i+1][j] += base * ngRate;
            }
        }

        return dp[k][k/2];
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}
