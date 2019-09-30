import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Ivan Romanov
 */
public class B {

    private static final String PROBLEM = "B";

    //private static final String TEST = "small-attempt0";
    private static final String TEST = "large";

    private static final int MAXV = 333;

    private static final int BESK = Integer.MAX_VALUE >> 2;

    private String solve() throws IOException {
        int d = nextInt();
        int c = nextInt();
        int m = nextInt();
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }

        int[][] r = new int[n + 1][MAXV];
        for (int[] z : r) {
            Arrays.fill(z, BESK);
        }
        Arrays.fill(r[0], 0);
        for (int i = 0; i < n; i++) {
            for (int srcP = 0; srcP < MAXV; srcP++) {
                for (int dstP = 0; dstP < MAXV; dstP++) {
                    int cheapest = BESK;
                    int cost, dif;

                    // use deletion
                    dif = Math.abs(dstP - srcP) + m - 1;
                    if (m == 0) {
                        dif = dstP == srcP ? 0 : BESK;
                    } else {
                        dif /= m;
                        dif *= c;
                    }
                    cost = d + dif;
                    cheapest = Math.min(cheapest, cost);

                    // don't delete
                    dif = Math.max(0, Math.abs(dstP - srcP) - 1);
                    if (m == 0) {
                        dif = dstP == srcP ? 0 : BESK;
                    } else {
                        dif /= m;
                        dif *= c;
                    }
                    cost = Math.abs(a[i] - dstP) + dif;
                    cheapest = Math.min(cheapest, cost);

                    r[i + 1][dstP] = Math.min(r[i + 1][dstP], r[i][srcP] + cheapest);
                }
            }
        }
        int ans = BESK;
        for (int i = 0; i <= n; i++) {
            for (int p = 0; p < MAXV; p++) {
                ans = Math.min(ans, r[i][p] + (n - i) * d);
            }
        }
        return "" + ans;
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private void run() throws IOException {
        reader = new BufferedReader(new FileReader(PROBLEM + "-" + TEST + ".in"));
        PrintWriter writer = new PrintWriter(new File(PROBLEM + "-" + TEST + ".out"));
        try {
            int n = nextInt();
            for (int i = 0; i < n; i++) {
                writer.print("Case #" + (i + 1) + ": ");
                writer.print(solve());
                writer.println();
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new B().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}