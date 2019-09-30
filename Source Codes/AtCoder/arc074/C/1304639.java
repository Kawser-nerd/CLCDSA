import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static boolean debug = false;
    private static boolean elapsed = false;

    private static PrintWriter _out = new PrintWriter(System.out);
    private static PrintWriter _err = new PrintWriter(System.err);

    private static int MOD = 1_000_000_007;

    private int N;
    private int M;
    private int[] l;
    private int[] r;
    private int[] x;

    private int[][][] dp;

    private List<List<Integer>> list = new ArrayList<>();

    private void solve(Scanner sc) {
        N = sc.nextInt();
        M = sc.nextInt();

        for (int i = 0; i <= N; ++i) {
            list.add(new ArrayList<>());
        }

        l = new int[M];
        r = new int[M];
        x = new int[M];
        for (int i = 0; i < M; ++i) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
            x[i] = sc.nextInt();

            list.get(r[i]).add(i);
        }

        dp = new int[N + 1][N + 1][N + 1];
        dp[0][0][0] = 1;

        for (int ri = 0; ri < N; ++ri) {
            for (int gi = 0; gi < N; ++gi) {
                for (int bi = 0; bi < N; ++bi) {
                    if (dp[ri][gi][bi] == 0) {
                        continue;
                    }
                    if (check(ri, gi, bi)) {
                        int d = max(ri, gi, bi);
                        dp[d + 1][gi][bi] = (int)(((long)dp[d + 1][gi][bi] + dp[ri][gi][bi]) % MOD);
                        dp[ri][d + 1][bi] = (int)(((long)dp[ri][d + 1][bi] + dp[ri][gi][bi]) % MOD);
                        dp[ri][gi][d + 1] = (int)(((long)dp[ri][gi][d + 1] + dp[ri][gi][bi]) % MOD);
                    }
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (check(N, i, j)) {
                    ans = (ans + dp[N][i][j] + dp[j][N][i] + dp[i][j][N]) % MOD;
                }
            }
        }
        _out.println(ans % MOD);
    }
    private boolean check(int ri, int gi, int bi) {
        int d = max(ri, gi, bi);

        int ci3 = min(ri, gi, bi);
        int ci1 = max(ri, gi, bi);
        int ci2 = ri ^ gi ^ bi ^ ci3 ^ ci1; // 3?????
        for (int i : list.get(d)) {
            if (x[i] == 1) {
                if (ci2 >= l[i]) {
                    return false;
                }
            } else if (x[i] == 2) {
                if (ci3 >= l[i] || l[i] > ci2) {
                    return false;
                }
            } else {
                if (l[i] > ci3) {
                    return false;
                }
            }
        }

        return true;
    }
    private static int max(int r, int g, int b) {
        return Math.max(r, Math.max(g, b));
    }
    private static int min(int r, int g, int b) {
        return Math.min(r, Math.min(g, b));
    }
    private static BigInteger C(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        for (long i = r; i > 1; --i) {
            res = res.divide(BigInteger.valueOf(i));
        }
        return res;
    }
    private static BigInteger P(long n, long r) {
        BigInteger res = BigInteger.ONE;
        for (long i = n; i > n - r; --i) {
            res = res.multiply(BigInteger.valueOf(i));
        }
        return res;
    }
    /*
     * 10^10 > Integer.MAX_VALUE = 2147483647 > 10^9
     * 10^19 > Long.MAX_VALUE = 9223372036854775807L > 10^18
     */
    public static void main(String[] args) {
        long S = System.currentTimeMillis();

        Scanner sc = new Scanner(System.in);
        new Main().solve(sc);
        _out.flush();

        long G = System.currentTimeMillis();
        if (elapsed) {
            _err.println((G - S) + "ms");
        }
        _err.flush();
    }
}