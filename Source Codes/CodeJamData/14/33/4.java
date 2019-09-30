import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class C {
    private final Scanner in;
    private final PrintWriter out;

    public C(Scanner in, PrintWriter out) {
        this.in = in;
        this.out = out;
    }

    public static void main(String[] args) {
        try (Scanner in = new Scanner(new FileReader(new File("C-large.in")));
             PrintWriter out = new PrintWriter("C-large.out")) {
            new C(in, out).solve();
        } catch (Throwable t) {
            t.printStackTrace();
            System.exit(-1);
        }
    }

    private void solve() {
        int tests = in.nextInt();
        for (int test = 1; test <= tests; ++test) {
            System.out.println(test);

            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();


            out.println("Case #" + test + ": " + calc(Math.min(n, m), Math.max(n, m), k));
        }
    }

    final int INF = Integer.MAX_VALUE / 2;

    private int calc(int n, int m, int k) {
        int[][][] D = new int[2][n + 1][k];
        int c = 0;
        for (int j = 1; j <= n; ++j) {
            for (int s = 1; s < k; ++s) {
                D[c][j][s] = INF;
            }
            if (j < k) {
                D[c][j][j] = j;
            }
        }

        int ans = k;

//        System.out.println(0);
//        System.out.println(Arrays.deepToString(D[c]));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int s = k - 2; s >= 1; --s) {
                    D[c][j][s] = Math.min(D[c][j][s], D[c][j][s + 1]);
                }
            }

//            System.out.println(i - 1);
//            System.out.println(Arrays.deepToString(D[c]));

            if (i == m) break;

            c = 1 - c;

            for (int j = 1; j <= n; ++j) {
                for (int s = 1; s < k; ++s) {
                    D[c][j][s] = INF;
                }
            }

            for (int j = 1; j <= n; ++j) {
                for (int l = Math.max(1, j - 2); l <= n && l <= j + 2; ++l) {
                    int sb = l == 1 ? 1 : 2;

                    for (int s = k - 1; s >= 1; --s) {
                        int v = D[1 - c][j][s];
                        int ns = s + l;

                        int nv = v + sb;
                        if (ns < k) {
//                            System.out.println(i + " " + j + " " + s + " " + v + " " + l + " " + nv);
                            D[c][l][ns] = Math.min(D[c][l][ns], nv);
                        } else {
//                            if (v + l == 5) {
//                                System.out.println(i + " " + j + " " + s + " " + l + " " + v);
//                            }
                            ans = Math.min(ans, v + l);
                        }
                    }
                }
            }
        }

        return ans;
    }
}
