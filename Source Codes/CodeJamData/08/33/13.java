package gcj;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class MainC {
    static long[][] memo;
    static boolean[][] vst;
    static int[] p;

    public static long dp(int ci, int pre) {
        if (ci == p.length) {
            return 1;
        }
        if (vst[ci][pre])
            return memo[ci][pre];
        vst[ci][pre] = true;
        long res = 1;
        for (int i = ci; i < p.length; i++) {
            if (p[i] > p[pre]) {
                res += dp(i + 1, i);
                res%=1000000007;
            }
        }
        memo[ci][pre] = res%1000000007;
        return res;
    }

    public static void main(String[] args) throws NumberFormatException,
            IOException {
        BufferedReader cin = new BufferedReader(
                new InputStreamReader(
                        new FileInputStream(
                                "D:\\topcoder\\eclipse-workspace\\ACM\\gcj\\C-small.in")));
        PrintWriter out = new PrintWriter(
                "D:\\topcoder\\eclipse-workspace\\ACM\\gcj\\Cout.txt");
        int testcase = Integer.parseInt(cin.readLine());
        for (int tst = 1; tst <= testcase; tst++) {
            int n, m;
            long X, Y, Z;
            StringTokenizer st = new StringTokenizer(cin.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            X = Long.parseLong(st.nextToken());
            Y = Long.parseLong(st.nextToken());
            Z = Long.parseLong(st.nextToken());
            long[] A = new long[m];
            for (int i = 0; i < m; i++) {
                A[i] = Long.parseLong(cin.readLine());
            }
            p = new int[n + 1];
            for (int i = 0; i < n; i++) {
                p[i + 1] = (int) A[i % m];
                A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z;
            }
            p[0] = -1;
            memo = new long[p.length][p.length];
            vst = new boolean[p.length][p.length];
            long res = 0;
            res = dp(1, 0);
            res--;
            out.println("Case #" + tst + ": " + res);
        }
        out.close();
    }
}
