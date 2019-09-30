import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.PrintWriter;

@SuppressWarnings("unchecked")
public class Main {
    static final int INF = 1000000007;

    public static void main(String[] args) throws IOException {
        final String s;

        try (
            BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in))) {
            s = reader.readLine();
        }

        PrintWriter out = new PrintWriter(System.out);

        final String[] sl = s.split(" ");
        int H = Integer.parseInt(sl[0]);
        int W = Integer.parseInt(sl[1]);
        int K = Integer.parseInt(sl[2]);

        int[][] dp = new int[H + 1][W];
        dp[0][0] = 1;

        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                for (int k = 0; k < 1 << (W - 1); k++) {
                    boolean ok = true;

                    for (int l = 0; l < W - 2; l++)
                        if ((k >> l & 1) == 1 && (k >> l + 1 & 1) == 1)
                            ok = false;

                    if (ok) {
                        if (x >= 1 && (k >> x - 1 & 1) == 1) {
                            dp[y + 1][x - 1] += dp[y][x];
                            dp[y + 1][x - 1] %= INF;
                        } else if (x <= W - 2 && (k >> x & 1) == 1) {
                            dp[y + 1][x + 1] += dp[y][x];
                            dp[y + 1][x + 1] %= INF;
                        } else {
                            dp[y + 1][x] += dp[y][x];
                            dp[y + 1][x] %= INF;
                        }
                    }
                }
            }
        }

        out.println(dp[H][K - 1]);

        out.flush();
    }
}