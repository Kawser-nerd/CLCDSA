package indy.codejam;

import java.io.*;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.*;
import java.math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Math.*;
import static java.lang.Double.parseDouble;
import static java.lang.Float.parseFloat;
import static java.lang.Long.parseLong;
import static java.lang.Integer.parseInt;

public class IncreasingSpeedLimits {

    public static void main(String[] args) throws Exception {
        String name = "C-small-attempt0";
        String path = "C:/codejam/";
        Scanner sc = new Scanner(new File(path + name + ".in"));
        PrintWriter pw = new PrintWriter(path + name + ".out");
        int N = sc.nextInt();
        for (int z = 1; z <= N; z++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            long X = sc.nextLong();
            long Y = sc.nextLong();
            long Z = sc.nextLong();

            long[] A = new long[m];
            for (int i = 0; i < m; i++) {
                A[i] = sc.nextInt();
            }

            long[] s = new long[n];
            for (int i = 0; i < n; i++) {
                s[i] = A[i % m];
                A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z;
            }

            long[] dp = new long[n];
            fill(dp, 1);

            for (int i = 0; i < n; i++) {
                for (int j = 1; j <= i; j++) {
                    if (s[i - j] < s[i]) {
                        dp[i] = (dp[i] + dp[i - j]) % 1000000007;
                    }
                }
            }

            long res = 0;
            for (int i = 0; i < n; i++) {
                res = (dp[i] + res) % 1000000007;
            }
            pw.print("Case #" + z + ": " + res);
            pw.println();
            pw.flush();
        }
        pw.close();
    }
}
