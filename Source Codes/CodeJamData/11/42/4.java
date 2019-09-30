import java.io.*;
import java.util.*;

public class B_as implements Runnable {
    public void solve() throws IOException {
        Scanner in = new Scanner(new File("B-large.in"));
        PrintWriter out = new PrintWriter(new File("B-large.out"));

        long time = System.currentTimeMillis();
        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            int r = in.nextInt();
            int c = in.nextInt();
            long d = in.nextInt();
            long[][] w = new long[r][c];
            for (int i = 0; i < r; i++) {
                String s = in.next();
                for (int j = 0; j < c; j++) {
                    w[i][j] = d + s.charAt(j) - '0';
                }
            }
            long[][] sum = new long[r + 1][c + 1];
            long[][] sumr = new long[r + 1][c + 1];
            long[][] sumc = new long[r + 1][c + 1];
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    sum[i][j] = w[i - 1][j - 1];
                    sum[i][j] += sum[i][j - 1];
                    sum[i][j] += sum[i - 1][j];
                    sum[i][j] -= sum[i - 1][j - 1];

                    sumr[i][j] = sum[i][j];
                    sumr[i][j] += sumr[i][j - 1];
                    sumc[i][j] = sum[i][j];
                    sumc[i][j] += sumc[i - 1][j];
                }
            }


            int best = -1;
            for (int k = 3; k <= Math.min(r, c); k++) {
                boolean ok = false;
                search:
                for (int i = 0; i < r - k + 1; i++) {
                    for (int j = 0; j < c - k + 1; j++) {
                        long wr = sumr[i + k][j + k]
                                - sumr[i + k][j] - sum[i + k][j] * k
                                - sumr[i][j + k]
                                + sumr[i][j] + sum[i][j] * k;
                        wr = wr - w[i + k - 1][j + k - 1] - w[i][j + k - 1] - w[i + k - 1][j] * k - w[i][j] * k;
                        long s = sum[i + k][j + k] - sum[i + k][j] - sum[i][j + k] + sum[i][j]
                                - w[i][j] - w[i + k -1][j] - w[i + k - 1][j + k - 1] - w[i][j + k - 1];

                        long wc = sumc[i + k][j + k]
                                - sumc[i + k][j]
                                - sumc[i][j + k] - sum[i][j + k] * k
                                + sumc[i][j] + sum[i][j] * k;
                        wc = wc - w[i + k - 1][j + k - 1] - w[i][j + k - 1] * k - w[i + k - 1][j] - w[i][j] * k;
                        if (2 * wr == s * (1 + k) && 2 * wc == s * (1 + k)) {
                            ok = true;
                            break search;
                        }
                    }
                }
                if (ok) {
                    best = k;
                }
            }
            out.println("Case #" + test + ": " + (best == -1 ? "IMPOSSIBLE" : "" + best));
        }

        in.close();
        out.close();

        System.err.println(System.currentTimeMillis() - time);
    }

    public void run() {
        try {
            solve();
        } catch (IOException e) {
            System.exit(1);
        }
    }

    public static void main(String[] s) {
        Locale.setDefault(Locale.US);
        new Thread(new B_as()).start();
    }
}