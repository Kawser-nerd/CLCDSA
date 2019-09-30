import sun.text.normalizer.IntTrie;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class Boxes implements Runnable {
    public static final int MACX = 101;
    final Scanner in;
    final PrintWriter out;

    public Boxes() throws FileNotFoundException {
        out = new PrintWriter(getClass().getName().toLowerCase() + ".out");
        in = new Scanner(new File(getClass().getName().toLowerCase() + ".in"));
    }

    public static void main(String[] args) {
        try {
            new Boxes().run();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void run() {
        int tests = in.nextInt();
        in.nextLine();
        for (int testcase = 1; testcase <= tests; testcase++) {
            int n = in.nextInt();
            int m = in.nextInt();

            long[] a = new long[n];
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextLong();
                x[i] = in.nextInt() - 1;
            }
            long[] b = new long[m];
            int[] y = new int[m];
            for (int i = 0; i < m; i++) {
                b[i] = in.nextLong();
                y[i] = in.nextInt() - 1;
            }

            long[][] d = new long[n + 1][m + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    d[i][j] = Math.max(d[i - 1][j], d[i][j - 1]);

                    long[] cnt1 = new long[MACX];
                    for (int k = i - 1; k >= 0; k--) {
                        cnt1[x[k]] += a[k];
                        long maxMatch = 0;

                        long[] cnt2 = new long[MACX];
                        for (int l = j - 1; l >= 0; l--) {
                            int color = y[l];
                            cnt2[color] += b[l];
                            long match = Math.min(cnt2[color], cnt1[color]);
                            if (match > maxMatch) {
                                maxMatch = match;
                            }
                            d[i][j] = Math.max(d[i][j], d[k][l] + maxMatch);
                        }
                    }
                }
            }

            out.println("Case #" + testcase + ": " + d[n][m]);
        }


        out.close();
        in.close();
    }
}
