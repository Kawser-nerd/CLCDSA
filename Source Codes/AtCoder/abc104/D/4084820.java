import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.PrintWriter;

import java.util.Arrays;

@SuppressWarnings("unchecked")
public class Main {
    static final int INF = 1000000007;
    static final char Q = '?';
    static final String ABC = "ABC";

    // a?b??????mod??(a + b mod p)
    static int modadd(int a, int b) {
        return (a + b) % INF;
    }

    // a?b??????mod??(a * b mod p)
    static int modmulti(int a, int b) {
        int res = 0;
        int mod = a % INF;
        while (b > 0) {
            if ((b & 1) == 1) {
                res += mod;
                if (res > INF) res -= INF;
            }
            mod <<= 1;
            if (mod > INF) mod -= INF;
            b >>= 1;
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        final String S;

        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            S = reader.readLine();
        }

        PrintWriter out = new PrintWriter(System.out);

        int len = S.length();

        int[][] dp = new int[len + 1][ABC.length() + 1];

        for (int i = 0; i < len + 1; i++) Arrays.fill(dp[i], 0);

        dp[len][ABC.length()] = 1;

        for (int i = len - 1; 0 <= i; i--) {
            int n = 1;
            boolean q = false;

            if (S.charAt(i) == Q) {
                n = ABC.length();
                q =  true;
            }

            for (int j = 0; j <= ABC.length(); j++) {
                // ? 3
                if (j == ABC.length())
                    dp[i][j] =
                        modadd(dp[i][j], modmulti(dp[i + 1][j], n));
                // ? 3 ??
                else {
                    int m = 1;

                    if (!q && ABC.charAt(j) != S.charAt(i)) m = 0;

                    dp[i][j] =
                        modadd(dp[i][j], modmulti(dp[i + 1][j], n));

                    dp[i][j] =
                        modadd(dp[i][j], modmulti(dp[i + 1][j + 1], m));
                }
            }
        }

        out.println(dp[0][0]);

        out.flush();
    }
}