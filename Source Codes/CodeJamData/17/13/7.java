package gcj.gcj2017.round1;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class C {
    private static final int INF = 1000000000;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int t = in.nextInt();
        for (int cs = 1 ; cs <= t ; cs++) {
            int dragonHP = in.nextInt();
            int dragonAtk = in.nextInt();
            int knightHP = in.nextInt();
            int knightAtk = in.nextInt();
            int buff = in.nextInt();
            int debuff = in.nextInt();
            out.println(String.format("Case #%d: %s", cs, solve(dragonHP, dragonAtk, knightHP, knightAtk, buff, debuff)));
        }
        out.flush();
    }

    private static String solve(int dragonHP, int dragonAtk, int knightHP, int knightAtk, int abuff, int adebuff) {
        dmax = dragonHP;
        kmax = knightHP;
        buff = abuff;
        debuff = adebuff;
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                for (int k = 0; k < 101; k++) {
                    Arrays.fill(dp[i][j][k], INF);
                }
            }
        }

        dp[kmax][knightAtk][dragonAtk][dmax] = 0;
        for (int kh = kmax ; kh >= 1 ; kh--) {
            for (int ka = knightAtk ; ka >= 0 ; ka--) {
                for (int da = dragonAtk; da <= 100; da++) {
                    for (int dh = 1 ; dh <= dmax ; dh++) {
                        if (dp[kh][ka][da][dh] == INF) {
                            continue;
                        }
                        int base = dp[kh][ka][da][dh];

                        // atk
                        {
                            int tkh = Math.max(0, kh-da);
                            int tdh = Math.max(0, dh-ka);
                            dp[tkh][ka][da][tdh] = Math.min(dp[tkh][ka][da][tdh], base+1);
                        }

                        // recover
                        {
                            int tdh = Math.max(0, dmax-ka);
                            dp[kh][ka][da][tdh] = Math.min(dp[kh][ka][da][tdh], base+1);
                        }

                        // buff
                        {
                            int tda = Math.min(100, da+buff);
                            int tdh = Math.max(0, dh-ka);
                            dp[kh][ka][tda][tdh] = Math.min(dp[kh][ka][tda][tdh], base+1);
                        }

                        // debuff
                        {
                            int tka = Math.max(0, ka-debuff);
                            int tdh = Math.max(0, dh-tka);
                            dp[kh][tka][da][tdh] = Math.min(dp[kh][tka][da][tdh], base+1);
                        }
                    }
                }
            }
        }

        int ret = INF;
        for (int ka = knightAtk ; ka >= 0 ; ka--) {
            for (int da = dragonAtk; da <= 100; da++) {
                for (int dh = 0 ; dh <= dmax; dh++) {
                    ret = Math.min(ret, dp[0][ka][da][dh]);
                }
            }
        }
        return ret >= INF ? "IMPOSSIBLE" : ret+"";
    }

    static int kmax;
    static int dmax;
    static int buff;
    static int debuff;
    static int[][][][] dp = new int[101][101][101][101];

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}



