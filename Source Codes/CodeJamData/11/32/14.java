import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class R1CBLarge {

    /**
     * Google Code Jam Round 1C 2011 Problem A. Square Tiles
     * 
     * @author dkorduban
     */
    public static void main(String[] args) {
        try {
            new R1CBLarge().solve();
        } catch (Exception e) {
            e.printStackTrace();
            throw new IllegalStateException();
        }

    }

    private void solve() throws FileNotFoundException {
        // Scanner in = new Scanner(System.in);
        Scanner in = new Scanner(new File("B-large.in"));
        // PrintWriter out = new PrintWriter(System.out);
        PrintWriter out = new PrintWriter("B-large.out");
        int testCount = in.nextInt();
        for (int test = 1; test <= testCount; ++test) {
            System.err.println("test = " + test);
            int l = in.nextInt();
            long t = in.nextLong();
            int n = in.nextInt();
            int c = in.nextInt();
            int[] a = new int[c];
            for (int i = 0; i < a.length; i++) {
                a[i] = in.nextInt();
            }
            long[] b = new long[n];
            b[0] = a[0];
            for (int i = 1; i < n; ++i) {
                b[i] = b[i - 1] + a[i % c];
            }

            // L = 0
            if (l == 0) {
                out.printf("Case #%d: %d\n", test, 2 * b[n - 1]);
                continue;
            }

            for (int i = 0; i < n; ++i) {
                if (t < 2 * b[i]) {
                    // i is first candidate for booster
                    long profit1 = (2 * b[i] - t) / 2 + f(a, n, i + 1, l - 1);
                    long profit2 = f(a, n, i + 1, l);
                    long profit = Math.max(profit1, profit2);
                    out.printf("Case #%d: %d\n", test, 2 * b[n - 1] - profit);
                    break;
                }
            }

        }
        out.flush();
    }

    private long f(int[] a, int n, int from, int l) {
        int[] t = new int[n - from];
        for (int i = from; i < n; ++i) {
            t[i - from] = a[i % a.length];
        }
        Arrays.sort(t);
        long ans = 0;
        for (int i = t.length - 1; i >= 0 && l > 0; --i, --l) {
            ans += t[i];
        }
        return ans;
    }

}
