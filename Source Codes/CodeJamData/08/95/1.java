import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.io.File;

public class E implements Runnable {
    public void solve() throws IOException {
        Scanner in = new Scanner(new File("E-small-attempt0.in"));
        PrintWriter out = new PrintWriter("E-small-attempt0.out");

        int tn = in.nextInt();
        for (int test = 1; test <= tn; test++) {
            int H = in.nextInt();
            int W = in.nextInt();
            char[][] f = new char[H][];
            for (int i = 0; i < H; i++) {
                f[i] = in.next().toCharArray();
            }

            int[][][] dp = new int[W + 1][H + 1][1 << H];
            boolean[][][] rch = new boolean[W + 1][H + 1][1 << H];
            dp[0][0][0] = 0;
            rch[0][0][0] = true;
            for (int i = 0; i < W; i++) {
                for (int j = 0; j < H; j++) {
                    for (int p = 0; p < (1 << H); p++) {
                        if (rch[i][j][p]) {
                            int q;
                            int v = dp[i][j][p];
                            switch (f[j][i]) {
                                case '#':
                                    q = p | (1 << j);
                                    v += 4;
                                    if (j > 0 && (p & (1 << (j - 1))) != 0) {
                                        v -= 2;
                                    }
                                    if ((p & (1 << j)) != 0) {
                                        v -= 2;
                                    }
                                    dp[i][j + 1][q] = Math.max(dp[i][j + 1][q], v);
                                    rch[i][j + 1][q] = true;
                                    break;
                                case '.':
                                    q = p & ~(1 << j);
                                    dp[i][j + 1][q] = Math.max(dp[i][j + 1][q], v);
                                    rch[i][j + 1][q] = true;
                                    break;
                                case '?':
                                    q = p | (1 << j);
                                    v += 4;
                                    if (j > 0 && (p & (1 << (j - 1))) != 0) {
                                        v -= 2;
                                    }
                                    if ((p & (1 << j)) != 0) {
                                        v -= 2;
                                    }
                                    dp[i][j + 1][q] = Math.max(dp[i][j + 1][q], v);
                                    rch[i][j + 1][q] = true;

                                    v = dp[i][j][p];
                                    q = p & ~(1 << j);
                                    dp[i][j + 1][q] = Math.max(dp[i][j + 1][q], v);
                                    rch[i][j + 1][q] = true;
                                    break;
                            }
                        }
                    }
                }
                System.arraycopy(dp[i][H], 0, dp[i + 1][0], 0, 1 << H);
                System.arraycopy(rch[i][H], 0, rch[i + 1][0], 0, 1 << H);
            }

            int ans = 0;
            for (int p = 0; p < 1 << H; p++) {
                if (rch[W][0][p]) {
                    ans = Math.max(ans, dp[W][0][p]);
                }
            }
            
            System.out.printf("Case #%d: %d\n", test, ans);
            out.printf("Case #%d: %d\n", test, ans);
        }

        in.close();
        out.close();
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static void main(String[] s) {
        new Thread(new E()).start();
    }
}
