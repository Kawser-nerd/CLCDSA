package gcj;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class MainB {
    static String s;
    static char[] cs;
    static long[][] memo;
    static boolean[][] vst;
    static int v;
    static int[][] pre;
    static boolean[][] prevst;

    static long dp(int ci, int fac) {

        if (vst[ci][fac])
            return memo[ci][fac];
        vst[ci][fac] = true;
        long res = 0;
        for (int i = ci; i < s.length(); i++) {
            if (ci == 0) {
                int x = mod(ci, i);
                long t1 = 0;
                if (i == s.length() - 1) {
                    if (x == fac)
                        res += 1;
                } else {
                    t1 = dp(i + 1, (fac - x + v + v) % v);
                    res += t1;
                }
            } else {
                int x1 = mod(ci, i);
                int x2 = (v + v - x1) % v;
                long t1 = 0;
                if (i == s.length() - 1) {
                    if (x1 == fac)
                        res += 1;
                    if (x2 == fac)
                        res += 1;
                } else {
                    t1 = dp(i + 1, (fac - x1 + v + v) % v);
                    res += t1;
                    t1 = dp(i + 1, (fac - x2 + v + v) % v);
                    res += t1;
                }
            }
        }
        memo[ci][fac] = res;
        return res;
    }

    static int mod(int i, int j) {
        if (prevst[i][j])
            return pre[i][j];
        prevst[i][j] = true;
        int res = 0;
        for (int k = i; k <= j; k++) {
            res = res * 10 + cs[k] - '0';
            res %= v;
        }
        pre[i][j] = res;
        return res;
    }

    public static void main(String[] args) throws NumberFormatException,
            IOException {
        BufferedReader cin = new BufferedReader(
                new InputStreamReader(
                        new FileInputStream(
                                "D:\\topcoder\\eclipse-workspace\\ACM\\gcj\\B-small.in")));
        PrintWriter out = new PrintWriter(
                "D:\\topcoder\\eclipse-workspace\\ACM\\gcj\\Bout.txt");
        int testcase = Integer.parseInt(cin.readLine());
        int[] d = { 2, 3, 5, 7 };
        for (int tst = 1; tst <= testcase; tst++) {
            long res = 0;
            s = cin.readLine();
            cs = s.toCharArray();
            for (int i = 1; i < (1 << 4); i++) {
                v = 1;
                for (int k = 0; k < 4; k++) {
                    if (((1 << k) & i) != 0) {
                        v *= d[k];
                    }
                }
                memo = new long[s.length()][v];
                vst = new boolean[s.length()][v];
                pre = new int[s.length()][s.length()];
                prevst = new boolean[s.length()][s.length()];
                if (Integer.bitCount(i) % 2 != 0) {
                    res += dp(0, 0);
                } else {
                    res -= dp(0, 0);
                }
            }
            out.println("Case #" + tst + ": " + res);
        }
        out.close();
    }
}
